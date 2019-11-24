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
        pipe(n1p1);
        pid = fork();
        if (pid < 0)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (pid == 0)
        {
            /* Nipote */
            close(STDIN_FILENO);
            dup(n1p1[0]);
            close(n1p1[0]); // Chiude l'input della pipe
            close(n1p1[1]); // Chiude l'output della pipe

            /* SECONDO comando */
            execlp("cut", "cut", "-f", "1", "-d", ",", NULL);
            perror("exec");
            exit(EXIT_FAILURE);
        }
        else
        {
            /* Figlio */
            close(STDOUT_FILENO);
            dup(n1p1[1]);
            close(n1p1[0]); // Chiude l'input della pipe
            close(n1p1[1]); // Chiude l'output della pipe

            /* PRIMO comando */
            execlp("echo", "echo", "Hello, World!", NULL);

            perror("exec");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        /* Genitore */
        wait(&status);
    }
}
