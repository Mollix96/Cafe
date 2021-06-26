#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/* Gesisce i figli terminati */
void handler(int signo)
{
    int status;

    while (waitpid(-1, &status, WNOHANG) > 0)
        ;
}

int main(void)
{
    pid_t pid; /* Process ID */
    int status;
    int n1p1[2];

    /* Evita processi zombie */
    signal(SIGCHLD, handler);

    pid = fork();
    if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        /* Figlio */
        pipe(n1p1); // Inizializzando qui la pipe non dovra' chiuderla il processo genitore
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            /* Nipote */
            close(STDIN_FILENO);        // Deve ricevere l'input dalla pipe, non da stdin
            dup(n1p1[STDIN_FILENO]);    // Collega stdin alla pipe
            close(n1p1[STDIN_FILENO]);  // Chiude l'input della pipe: gia' collegato a stdin
            close(n1p1[STDOUT_FILENO]); // Chiude l'output della pipe: deve usare stdout

            /* SECONDO comando */
            execlp("cut", "cut", "-f", "1", "-d", ",", NULL);
            perror("exec");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* Figlio */
            close(STDOUT_FILENO);       // Deve mandare l'output sulla pipe, non a stdout
            dup(n1p1[STDOUT_FILENO]);   // Collega stdout alla pipe
            close(n1p1[STDIN_FILENO]);  // Chiude l'input della pipe: deve usare stdin
            close(n1p1[STDOUT_FILENO]); // Chiude l'output della pipe: gia' collegato a stdin

            /* PRIMO comando */
            execlp("echo", "echo", "Hello, World!", NULL);

            perror("exec");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Genitore */

        /* NOTA: pipe gia' chiusa */

        wait(&status);
    }
}
