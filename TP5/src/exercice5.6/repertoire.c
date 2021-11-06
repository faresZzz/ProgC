#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>



int lire_fichier(char *fichier)
{
    char content[2];
    int fd, size, result;

    fd = open(fichier, O_RDONLY);       // fichier: ./etudiant/X/noteX.txt

    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", fichier);
        close(fd);
        exit(0);
    }
    size = read(fd, content, 2);
    if (size < 1 )
    {
        close(fd);
        return -1;
    }

    sscanf(content, "%d", &result);
    close(fd);
    return result;
}


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
    int nb_dossiers = 0;

    while(1)
    {
        element = readdir(dirp);
        if (element == NULL)
        {
            break;
        }
        if( (strcmp(element->d_name, ".") != 0) && (strcmp(element->d_name, "..") != 0) && element->d_type == DT_DIR ) //On vérifie que l'élément n'est pas le dossier"." ou ".."
        {
            nb_dossiers++;

        }
    }

    closedir(dirp);
    printf("%d", nb_dossiers);
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




//fonction de l'exercice 5.3
void lire_dossier_iteratif( char *directory )
{
    DIR* dirp;
    struct dirent* direntp;

    char liste_chemins[50][1024] = {}; //On crée une liste pour stocker les chemins vers les sous-dossiers
    int ptr = 0; //Compteur qui indique le nombre de sous-dossiers présents dans la liste
    strcpy(liste_chemins[ptr] , directory);
    ptr++;

    // On continue le traitement tant qu'il reste des dossiers à traiter
    while (ptr>0)
    {
        dirp = opendir( liste_chemins[0] );
        if( dirp == NULL )
        {
            perror( "Nom de dossier invalide");
        }
        while(1)
        {
            direntp = readdir( dirp );
            if( direntp == NULL )
            {
                break;
            }
            if ((strcmp(direntp->d_name , ".")!=0) && (strcmp(direntp->d_name , "..")!=0));
            {
                printf( "%s\n", direntp->d_name );
            }
            if ((direntp-> d_type == DT_DIR) && strcmp(direntp->d_name , ".")!=0 && strcmp(direntp->d_name , "..")!=0)
            {
                char path[128]= "" ;
                strcpy(path,liste_chemins[0]);
                strcat(path,"/");
                strcat(path,direntp->d_name);
                strcpy(liste_chemins[ptr],path); //On ajoute à la liste le chemin du dossier courant
                ptr++;
            }

        }
        char liste_tampon[50][1024]={}; // les 2 boucles for servent à supprimer le premier élément de la liste des chemins qui a été affiché pour afficher le suivant
        for (int i = 1; i <= ptr-1 ; i++)
        {
            strcpy(liste_tampon[i-1],liste_chemins[i]);
        }

        for (int i = 0; i <= ptr-2; i++)
        {
            strcpy(liste_chemins[i],liste_tampon[i]);
        }
         printf("\tchemin: %s\n",liste_chemins[0]);
        closedir( dirp );
        ptr--;
    }

}
