
#include <stdio.h>
#include "repertoire.h"
#include "repertoire.c"

void main (int argc, char ** argv)
{

    const int exercice = 2; //On choisit l'exercice : 1 pour 5.1, 2 pour 5.2 et 3 pour 5.3

    //On vérifie que l'utilisateur a entré un nom de dossier en paramètre
    if (argc < 2)
    {
    printf("Pas assez d'arguments\n");
    }

    switch (exercice){

        case 1:
            lire_dossier(argv[1]);
            break;
        case 2:;
            int niveau = 0; //Initialise le niveau de l'arborescence pour l'indentation
            lire_dossier_recursif(argv[1], niveau);
            break;
    }
}