#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//fonction de l'exercice 5.1
void lire_dossier(char *nom_dossier)
{
    DIR *dirp = opendir(nom_dossier); //On ouvre le dossier passé en argument

    //On vérifie que le dossier existe
    if (dirp == NULL)
    {
        perror("Nom de dossier invalide");
        exit(EXIT_FAILURE);
    }

    struct dirent * element;
    int nb_fichiers = 0;

    while(1)
    {
        element = readdir(dirp);
        if (element == NULL)
        {
            break;
        }
        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0)) //On vérifie que l'élément n'est pas le dossier"." ou "."
        {
            nb_fichiers++;
            printf("Element %3d: %s\n", nb_fichiers, element->d_name); //On affiche le nom de l'élément
        }
    }

    closedir(dirp);
}




//fonction de l'exercice 5.2
void lire_dossier_recursif(char *nom_dossier, int niveau) {

    DIR *dirp = opendir(nom_dossier); //On ouvre le dossier passé en argument

    //On vérifie que le dossier existe
    if (dirp == NULL) {
        perror("Nom de dossier invalide");
        exit(EXIT_FAILURE);
    }

    struct dirent * element;
    int nb_elements = 0;

    while(1) {
        element = readdir(dirp);
        if (element == NULL) {
            break;
        }
        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0)) //On vérifie que l'élément n'est pas le dossier"." ou "."
        {
            //On gère l'indentation : à chaque niveau, on ajoute une tabulation
            nb_elements++;
            char indentation[20];
            indentation[0] = '\0';
            for (int compteur = 0; compteur < niveau; compteur++ ) {
                strcat(indentation, "\t");
            }

            //En fonction du type d'élément présent dans le dossier, on adapte le traitement
            switch (element->d_type){

            //Cas où l'élément est un dossier
            case DT_DIR:

                printf("%sdossier: %s\n", indentation, element->d_name);
                int longueur_nom = strlen(element->d_name) + strlen(nom_dossier) + 2; //On calcule la taille de mémoire à allouer
                int *ptr_nom_dossier = malloc(longueur_nom); //On alloue la mémoire
                strcat(nom_dossier, "/"); //On crée le chemin complet du dossier à ouvrir
                strcat(nom_dossier, element->d_name);
                lire_dossier_recursif(nom_dossier, niveau+1); //On appelle la fonction de manière récursive avec le nom du dossier en argument
                break;

            //Cas où l'élément est un fichier
            case DT_REG:
                printf("%sfichier: %s\n", indentation, element->d_name);
                break;

            default:
                printf("%sinconnu: %s\n", indentation, element->d_name);
            }
        }
    }
}