#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(char *nom_fichier, char * data, int* offset)
{
    char content[100];
    int fd, size;

    fd = open(nom_fichier, O_RDONLY);
    lseek(fd, *offset, SEEK_SET);
    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", nom_fichier);
        close(fd);
        exit(0);
    }
    while(1)
    {
        size = pread(fd, content, 1, *offset);
        if (size < 1 || strncmp(content, "\n", 2)==0 )
        {
            break;
        }
        (*offset)++;
        strcat(data, content);
        // printf("%s", content);
    }
    // printf("\n");

    close(fd);

}

void ecrire_dans_fichier(char *nom_fichier, char *message)
{
    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}

