/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Bibliotheque d'action a realisé sur notre liked liste:
Insertion d'un nouvel element
Parcours de la liste et affichage des elements
*/

#include <stdio.h>


// declaration des struct
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
// fonction d'insertion, entre le premier et le second element
{
    
    nouveau->next = liste_couleurs->first->next;
    liste_couleurs->first->next = nouveau;
}

void parcours (struct Liste_couleurs *liste_couleurs)
// fonction de parcours de la liste et affichage des elements
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



