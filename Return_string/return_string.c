/* Esempio di come restituire una stringa come valore di ritorno di una funzione. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Prototipi. */
char *getHelloWorldString(); /* Restituisce la stringa "Hello, World!". */

/* Main. */
int main(void)
{
    char *myString = getHelloWorldString();

    printf("%s\n", myString);

    /* Deallocazione della stringa. */
    free(myString);

    return EXIT_SUCCESS;
}

/* Restituisce la stringa "Hello, World!". */
char *getHelloWorldString()
{
    /* Alloca una stringa di 14 caratteri. */
    char *string = (char *)malloc(14 * sizeof(char));

    /* Inizializza la stringa. */
    strcpy(string, "Hello, World!\0");

    return string;
}
