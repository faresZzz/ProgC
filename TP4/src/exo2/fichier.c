/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"



void lire_fichier(char *nom_fichier)
/*
fonction de lecture de fichier
*/
{
    char content[100];
    int fd, size;

    fd = open(nom_fichier, O_RDONLY);

    if (fd < 0)
    // on verifie que le fichier a bien ete ouvert
    {
        printf("Erreur impossible d'acceder au fichier \"%s\"\n", nom_fichier);
        close(fd);
        exit(0);
    }
    while(1)
    {
        // on lit caractere par caractere dans le fichier avant de les afficher
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
/*
fonction d'ecriture
*/
{
    int fd, count, size;
    fd = open (nom_fichier, O_CREAT|O_WRONLY|O_APPEND, S_IRUSR|S_IWUSR);
    size = write(fd, message, strlen(message));
    close(fd);
}

