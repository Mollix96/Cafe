#ifndef FILM_H
#define FILM_H

#include <inttypes.h>

#include "attore.h"
#include "regista.h"

// Struct film.
typedef struct _film
{
    char *titolo;
    uint16_t anno;   // Anno di produzione.
    uint16_t durata; // Durata in minuti.
    Regista *regista;
    Attore *attoreProtagonista;
} Film;

// Prototipi.
extern Film *newFilm(char *newTitolo, uint16_t newAnno, uint16_t newDurata, Regista *newRegista, Attore *newAttoreProtagonista); // Costruttore.
extern void stampaFilm(Film *film);
extern void freeFilm(Film *film); // Decostruttore.

#endif
