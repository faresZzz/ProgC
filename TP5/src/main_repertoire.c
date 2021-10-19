#include <stdio.h>
#include "repertoire.h"

int main (int argc, char ** argv){

    if (argc < 2) {
    printf("Usage: readdir path\n");
    }

    lire_dossier(argv[1]);
    return 0;
}