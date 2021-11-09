/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
// #include "liste.h"


struct couleur{
   int R;
   int G;
   int B;
   int A;
 struct couleur *next;
}couleur;


struct Liste_couleurs {
    struct couleur *first;
};

void insertion (struct couleur *nouveau, struct Liste_couleurs *liste_couleurs)
{
    nouveau->next = liste_couleurs->first->next;
    liste_couleurs->first->next = nouveau;
}

void parcours (struct Liste_couleurs *liste_couleurs)
{
    struct couleur *couleur = liste_couleurs->first;
    while(1) { //navigation
        printf( "couleur: (%d, %d, %d, %d)\n", couleur->R, couleur->G, couleur->B, couleur->A);

        if (couleur->next == NULL)
        {
            break;
        }
        couleur = couleur->next; //couleur suivante
    }
}



