/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Reutilisation du programme TP2
*/

#include <stdio.h>
#include <string.h>
#include "couleur.h"

//Initialisation du struct
// struct couleur{
//     int R;
//     int G;
//     int B;
//     int A;
//     struct couleur *next;
// };


void creation_couleurs(int tab_couleur[][4], struct couleur *liste_couleur)
{

    //On remplit liste_couleur avec les éléments RGBA du tableau
    for (int i = 0; i < 10; i++)
    {

       liste_couleur[i].R = tab_couleur[i][0];
       liste_couleur[i].G = tab_couleur[i][1];
       liste_couleur[i].B = tab_couleur[i][2];
       liste_couleur[i].A = tab_couleur[i][3];
    }

}


void affichageliste(struct couleur *liste_couleur)
{
    //On affiche les couleurs en notation hex
    for (int i = 0; i < 10; i++)
    {
        printf("couleur (R,G,B,A), (0x%x, 0x%x, 0x%x, 0x%x),\n", liste_couleur[i].R, liste_couleur[i].G, liste_couleur[i].B, liste_couleur[i].A);
    }

    printf("\n");

}