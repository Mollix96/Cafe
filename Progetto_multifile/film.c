#include "film.h"

#include <stdio.h>
#include <stdlib.h>

Film *newFilm(char *newTitolo, uint16_t newAnno, uint16_t newDurata, Regista *newRegista, Attore *newAttoreProtagonista)
{
    // Alloca un nuovo film.
    Film *newFilm = (Film *)malloc(sizeof(Film));

    // Inizializza i dati del nuovo film.
    newFilm->titolo = newTitolo;
    newFilm->anno = newAnno;
    newFilm->durata = newDurata;
    newFilm->regista = newRegista;
    newFilm->attoreProtagonista = newAttoreProtagonista;

    return newFilm;
}

void stampaFilm(Film *film)
{
    printf("Titolo: %s\nAnno di produzione: %u\nDurata in minuti: %u\n\n", film->titolo, film->anno, film->durata);
    printf("=== Regista ===\n");
    stampaRegista(film->regista);
    printf("\n\n=== Attore protagonista ===\n");
    stampaAttore(film->attoreProtagonista);
    printf("\n");
}

void freeFilm(Film *film)
{
    free(film);
}