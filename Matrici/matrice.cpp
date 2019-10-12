#include "matrice.h"

// Costruttore
Matrice::Matrice(int newColonne, int newRighe)
{
    this->colonne = newColonne;
    this->righe = newRighe;

    // Alloca la matrice
    elementi = new elem_t *[this->righe];
    for (int i = 0; i < this->righe; i++)
    {
        this->elementi[i] = new elem_t[this->colonne];
    }

    // Inizializza gli elementi
    for (int i = 0; i < this->righe; i++)
    {
        for (int j = 0; j < this->colonne; j++)
        {
            this->elementi[i][j] = 0.0;
        }
    }
}

// Restituisce un elemento date le sue coordinate
elem_t Matrice::leggi(int r, int c)
{
    return (this->elementi[r][c]);
}

// Scrive un nuovo elemento dato l'elemento e le coordinate
void Matrice::scrivi(int r, int c, elem_t newElem)
{
    this->elementi[r][c] = newElem;
}

// Stampa a schermo la matrice
void Matrice::stampa()
{
    for (int i = 0; i < this->righe; i++)
    {
        for (int j = 0; j < this->colonne; j++)
        {
            cout << this->elementi[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrice::prodottoScalare(double scalare)
{
    for (int i = 0; i < this->righe; i++)
    {
        for (int j = 0; j < this->colonne; j++)
        {
            this->elementi[i][j] *= scalare;
        }
    }
}

Matrice Matrice::trasposta()
{
    Matrice trasposta(this->colonne, this->righe);

    for (int i = 0; i < trasposta.righe; i++)
    {
        for (int j = 0; j < trasposta.colonne; j++)
        {
            trasposta.elementi[i][j] = this->elementi[j][i];
        }
    }
    return trasposta;
}

// Decostruttore
Matrice::~Matrice()
{
    // TODO
}
