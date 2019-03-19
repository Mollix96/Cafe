#include <stdio.h>
#include <stdlib.h>

#define LATO 4

typedef struct _quadrato Quadrato;

Quadrato *new_Quadrato(int newLato); /* Costruttore */
int _getArea(Quadrato *quadrato);
void _print(Quadrato *quadrato);
void free_Quadrato(Quadrato *quadrato); /* Decostruttore */

struct _quadrato
{
    int lato;

    /* Funzioni */
    int (*getArea)(Quadrato *);
    void (*print)(Quadrato *);
};

int main(void)
{
    /* Istanzia un nuovo quadrato. */
    Quadrato *myQuadrato = new_Quadrato(LATO);

    myQuadrato->print(myQuadrato);

    /* Deallocazione del quadrato. */
    free_Quadrato(myQuadrato);

    return EXIT_SUCCESS;
}

Quadrato *new_Quadrato(int newLato)
{
    /* Costruisce un nuovo quadrato */
    Quadrato *newQuadrato = (Quadrato *)malloc(sizeof(Quadrato));

    /* Lato */
    newQuadrato->lato = newLato;

    /* Area */
    newQuadrato->getArea = &_getArea;

    /* Stampa */
    newQuadrato->print = &_print;

    return newQuadrato;
}

int _getArea(struct _quadrato *quadrato)
{
    return (quadrato->lato * quadrato->lato);
}

void _print(Quadrato *quadrato)
{
    printf("Lato: %d\nArea: %d\n", quadrato->lato, quadrato->getArea(quadrato));
}

void free_Quadrato(Quadrato *quadrato)
{
    free(quadrato);
}
