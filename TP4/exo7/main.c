#include <stdio.h>

#include "liste.h"
#include "couleur.h"

// typedef struct couleur{
//     int R;
//     int G;
//     int B;
//     int A;
//     struct couleur *next;
// }couleur;

// typedef struct Liste_couleurs {
//     couleur *first;
// }Liste_couleurs;


int main()
{
    int tab_couleur[10][4] ={
        {0xFF, 0x57, 0x33, 0xA8},
        {0xC7, 0xFF, 0x33, 0x12},
        {0x5B, 0xA6, 0x65, 0xFF},
        {0x3B, 0xCA, 0xAB, 0x42},
        {0x12, 0x14, 0x66, 0xCD},
        {0x9B, 0x29, 0xAB, 0xD2},
        {0xDD, 0x28, 0xF5, 0x52},
        {0x37, 0xAF, 0x10, 0x66},
        {0x0E, 0xF3, 0xBF, 0x8A},
        {0x4C, 0x5A, 0x57, 0x6D},

    };
    struct couleur liste_couleurs[10];

    creation_couleurs(tab_couleur, liste_couleurs);

    struct Liste_couleurs nouvelle_liste;

    nouvelle_liste.first = &liste_couleurs[0];

    for (int i = 1; i < 10; i++)
    {
        insertion(&liste_couleurs[i], &nouvelle_liste);
    }

    parcours(&nouvelle_liste);




}