#include <iostream>
#include <stdlib.h>

#include "matrice.h"

using namespace std;

int main()
{
    Matrice myMatrice(3, 3); // Matrice 3x3

    myMatrice.stampa();

    // Matrice identita' di ordine 3
    myMatrice.scrivi(0, 0, 1);
    myMatrice.scrivi(1, 1, 1);
    myMatrice.scrivi(2, 2, 1);

    cout << endl;
    myMatrice.stampa();

    // Prodotto scalare
    myMatrice.prodottoScalare(3.0);

    cout << endl;
    myMatrice.stampa();

    // Altri valori per test trasposta
    myMatrice.scrivi(0, 1, 4);
    myMatrice.scrivi(1, 2, 3);

    cout << endl;
    myMatrice.stampa();

    // Trasposta
    cout << endl;
    Matrice myTrasposta = myMatrice.trasposta();
    myTrasposta.stampa();

    return EXIT_SUCCESS;
}
