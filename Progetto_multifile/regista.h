#ifndef REGISTA_H
#define REGISTA_H

#include <inttypes.h>

// Struct regista.
typedef struct _regista
{
    char *nome;
    char *cognome;
    uint16_t annoNascita;
} Regista;

// Prototipi.
extern Regista *newRegista(char *newNome, char *newCognome, uint16_t newAnnoNascita); // Costruttore.
extern void stampaRegista(Regista *regista);
extern void freeRegista(Regista *regista); // Decostruttore.

#endif
