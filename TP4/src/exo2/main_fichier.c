/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Ce programe vient lire ou ecrire dans le fichier en fonction de la commande de l'utilisateur.

./main_fichier Path_fichier r/w( en fonction de la lecture ou de l'ecriture)
*/

#include <stdio.h>
#include "fichier.h"



int main(int argc, char **argv)
{
    char read_write;
    char message[100];

    // differentiation entre la lecture et l'ecriture.
    switch (*argv[2])
    {
    case 'r':
        lire_fichier(argv[1]);
        break;

    case 'w':

        printf("Entrer votre phrase:");
        fgets( message, sizeof(message), stdin);
        ecrire_dans_fichier(argv[1], message);
        break;
    default:
        printf("la commande entree ne correspond pas\n");
    }
}