#include "attore.h"

#include <stdio.h>
#include <stdlib.h>

Attore *newAttore(char *newNome, char *newCognome, uint16_t newAnnoNascita)
{
    // Alloca un nuovo attore.
    Attore *newAttore = (Attore *)malloc(sizeof(Attore));

    // Inizializza i dati del nuovo attore.
    newAttore->nome = newNome;
    newAttore->cognome = newCognome;
    newAttore->annoNascita = newAnnoNascita;

    return newAttore;
}

void stampaAttore(Attore *attore)
{
    printf("Nome: %s\nCognome: %s\nAnno di nascita: %u", attore->nome, attore->cognome, attore->annoNascita);
}

void freeAttore(Attore *attore)
{
    free(attore);
}