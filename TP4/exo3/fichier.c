#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(char *nom_fichier)
{
    char content[100];
    int fd, size;

    fd = open(nom_fichier, O_RDONLY);

    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", nom_fichier);
        close(fd);
        exit(0);
    }
    while(1)
    {
        size = read(fd, content, 1);
        if (size < 1 )
        {
            break;
        }
        printf("%s", content);
    }
    printf("\n");
    close(fd);

}

void ecrire_dans_fichier(char *nom_fichier, char *message)
{
    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    if (fd < 0)
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", nom_fichier);
        close(fd);
        exit(0);
    }
    size = write(fd, message, strlen(message));
    close(fd);
}

