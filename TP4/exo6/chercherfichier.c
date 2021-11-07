#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"

/* 
marche mais pas pour tous les mot: marche pour juste ne marche pas pour B

*/


int main(int argc, char **argv)         // argv: ./chercherficher NomFichier Expression
{
    char data[1024];
    memset(data, 0, sizeof(data));
    char mot[] = "juste";
    int offset = 0;
    int compteur = 0;
    int valide = 0;
    int nbligne = wc_maison(argv[1]);
    for (int ligne = 1; ligne <= nbligne; ligne++)
    {
        offset = lire_fichier(argv[1], data, offset);          // probleme d'offset lit toujours la meme ligne

        for (int i = 0; i < (strlen(data) -strlen(mot)); i++)
        {
            for (int j = 0; j<strlen(mot); j++)
            {
                if (data[i+j] == mot[j])
                {
                    valide ++;
                    if (valide == strlen(mot))
                    {
                        compteur++;
                    }
                }
            }

            valide = 0;
        }
        if (compteur > 0)
            {
                printf("Ligne %d, %d fois\n", ligne, compteur);
            }

            compteur = 0;
        memset(data, 0, sizeof(data));
    }
    printf("Fin de fichier\n");
    return 0;
}
