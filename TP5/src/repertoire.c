#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "repertoire.h"

void lire_dossier(char *nom_dossier) {
    /*
    if (argc < 2) {
        printf("Usage: readdir path\n");
        return(EXIT_FAILURE);
    }
    */

    DIR *dirp = opendir(nom_dossier);

    if (dirp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent * element;
    int nb_fichiers = 0;

    while(1) {
        element = readdir(dirp);
        if (element == NULL) {
            break;
        }
        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0)){
        nb_fichiers++;
        printf("Element %3d: %s\n", nb_fichiers, element->d_name);
        }
    }

    closedir(dirp);
}