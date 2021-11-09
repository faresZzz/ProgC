/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Programme de l'exercice 2 adapté a notre cas
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"


int wc_maison(char *nom_fichier)
/*
fonction qui compte le nombre de ligne dans le fichier en comptant le nombre de \n presents
*/
{
    char content[100];
    int fd, size, compteur = 0;

    fd = open(nom_fichier, O_RDONLY);
    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", nom_fichier);
        exit(0);
    }
    while(1)
    {
        size = read(fd, content, 1);
        if (size < 1 )
        {
            break;
        }
        else if (strncmp(content, "\n", 2)==0)
        {
            compteur++;
        }

    }

    close(fd);
    return compteur;

}

int lire_fichier(char *nom_fichier, char * data, int offset)
/*
fonction qui lit dans le fichier jusqu'au premier \n qui signifi que l'on a fini notre ligne
*/
{
    char content[100];
    int fd, size;

    fd = open(nom_fichier, O_RDONLY);
    // deplacement du pointeur dans le fichier pour eviter de lire tout le temps la meme ligne
    lseek(fd, offset, SEEK_SET);
    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\\n", nom_fichier);
        close(fd);
        exit(0);
    }
    while(1)
    {
        size = read(fd, content, 1);
        offset++;

        if (size < 1 || strncmp(content, "\n", 2)==0 )
        {
            break;
        }

        strcat(data, content);



    }


    close(fd);
    // renvoi la valeur du nb de carateres lu
    return offset;

}

void ecrire_dans_fichier(char *nom_fichier, char *message)
{
    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}

