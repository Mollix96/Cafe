#ifndef ATTORE_H
#define ATTORE_H

#include <inttypes.h>

// Struct attore.
typedef struct _attore
{
    char *nome;
    char *cognome;
    uint16_t annoNascita;
} Attore;

// Prototipi.
extern Attore *newAttore(char *newNome, char *newCognome, uint16_t newAnnoNascita); // Costruttore.
extern void stampaAttore(Attore *attore);
extern void freeAttore(Attore *attore); // Decostruttore.

#endif
