#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0))
        {
            nb_fichiers++;
            printf("Element %3d: %s\n", nb_fichiers, element->d_name);
        }
    }

    closedir(dirp);
}


void lire_dossier_recursif(char *nom_dossier)
{


//la fonction ci-dessous ne marche pas tjs, bizarre



void lire_dossier_recursif(char *nom_dossier, int niveau) {

    DIR *dirp = opendir(nom_dossier);

    if (dirp == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent * element;

    int nb_fichiers = 0;
    int nb_elements = 0;


    while(1) {
        element = readdir(dirp);
        if (element == NULL) {
            break;
        }

        if((strcmp(element->d_type, "DT_DIR") != 0))
        {
            lire_dossier_recursif(element->d_type);
        }
        else
        {
            if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0))
            {
                nb_fichiers++;
                printf("Element %3d: %s\n", nb_fichiers, element->d_name);
            }
        }
    }

    closedir(dirp);
}


int main (int argc, char ** argv){

    if (argc < 2) {
    printf("Usage: readdir path\n");
    }


    lire_dossier(argv[1]);
    return 0;

        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0)){
            nb_elements++;
            char indentation[20];
            indentation[0] = '\0';
            for (int compteur = 0; compteur < niveau; compteur++ ) {
                strcat(indentation, "--");
            }
            switch (element->d_type){

            case DT_DIR:


                printf("%s-dossier: %s\n", indentation, element->d_name);
                int longueur_nom = strlen(element->d_name) + strlen(nom_dossier) + 2; //On calcule la taille de mémoire à allouer
                int *ptr_nom_dossier = malloc(longueur_nom); //On alloue la mémoire
                strcat(nom_dossier, "/"); //On crée le chemin complet du dossier à ouvrir
                strcat(nom_dossier, element->d_name);
                lire_dossier_recursif(nom_dossier, niveau+1); //A faire : il faut mettre en argument dossierdu dessus/element->d_name
                break;

            case DT_REG:
                printf("%s-fichier: %s\n", indentation, element->d_name);
                break;

            default:
                printf("%s-inconnu: %s\n", indentation, element->d_name);
            }
        }
    }

    closedir(dirp);

}