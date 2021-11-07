#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"


int wc_maison(char *nom_fichier)
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
{
    char content[100];
    int fd, size;

    fd = open(nom_fichier, O_RDONLY);
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
        //printf("carractere: %d '%s'\n", offset, content);


    }
    // printf("\n");

    close(fd);
    return offset;

}

void ecrire_dans_fichier(char *nom_fichier, char *message)
{
    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}

