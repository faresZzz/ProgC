#include <stdio.h>
#include "repertoire.h"

int main (int argc, char ** argv){

    if (argc < 2) {
    printf("Usage: readdir path\n");
    }

    //lire_dossier(argv[1]);
    int niveau = 0; //Initialise le niveau de l'arborescence pour l'indentation
    lire_dossier_recursif(argv[1], niveau);

    return 0;
}