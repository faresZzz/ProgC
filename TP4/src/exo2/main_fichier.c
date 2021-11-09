/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include "fichier.h"



int main(int argc, char **argv)
{
    char read_write;
    char message[100];

    // printf("\n Donner l'action a executer [r/w]:");
    // scanf("%c", &read_write);

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
        printf("la commende entree ne correspond pas\n");
    }
}