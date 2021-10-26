#include <stdio.h>
#include "repertoire.h"

int main (int argc, char ** argv){

    if (argc < 2) {
    printf("Usage: readdir path\n");
    }

<<<<<<< HEAD
    lire_dossier_recursif(argv[1]);
=======
    //lire_dossier(argv[1]);
    int niveau = 0; //Initialise le niveau de l'arborescence pour l'indentation
    lire_dossier_recursif(argv[1], niveau);

>>>>>>> f0c5ab703b9c21eb841bb034f1c617ea4f4997cf
    return 0;
}