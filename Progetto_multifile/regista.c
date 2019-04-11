#include "regista.h"

#include <stdio.h>
#include <stdlib.h>

Regista *newRegista(char *newNome, char *newCognome, uint16_t newAnnoNascita)
{
    // Alloca un nuovo regista.
    Regista *newRegista = (Regista *)malloc(sizeof(Regista));

    // Inizializza i dati del nuovo regista.
    newRegista->nome = newNome;
    newRegista->cognome = newCognome;
    newRegista->annoNascita = newAnnoNascita;

    return newRegista;
}

void stampaRegista(Regista *regista)
{
    printf("Nome: %s\nCognome: %s\nAnno di nascita: %u", regista->nome, regista->cognome, regista->annoNascita);
}

void freeRegista(Regista *regista)
{
    free(regista);
}
