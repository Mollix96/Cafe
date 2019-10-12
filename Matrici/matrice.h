#ifndef MATRICE_H
#define MATRICE_H

#include <iostream>
using namespace std;

typedef double elem_t;

class Matrice
{
public:
    Matrice(int, int); // Costruttore
    ~Matrice();        // Decostruttore

    elem_t leggi(int, int);
    void scrivi(int, int, elem_t);
    void stampa();
    void prodottoScalare(double);
    Matrice *trasposta();

private:
    int righe;   // Numero righe
    int colonne; // Numero colonne
    elem_t **elementi;
};

#endif
