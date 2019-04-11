#include <stdio.h>
#include <stdlib.h>

#include "attore.h"
#include "film.h"
#include "regista.h"

// Driver.
int main(void)
{
    Attore *myAttore = newAttore("Mario", "Attori", 1990);
    Regista *myRegista = newRegista("Paolo", "Registi", 1986);
    Film *myFilm = newFilm("<insert_title_here>", 2019, 140, myRegista, myAttore);

    stampaFilm(myFilm);

    freeFilm(myFilm);
    freeRegista(myRegista);
    freeAttore(myAttore);

    return EXIT_SUCCESS;
}
