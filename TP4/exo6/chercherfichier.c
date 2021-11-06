#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "fichier.h"




int main(int argc, char **argv)         // argv: ./chercherficher NomFichier Expression
{
    char data[1024];
    memset(data, 0, sizeof(data));
    char mot[] = "juste";
    char path[] = "fichier.txt";
    int offset = 0;
    int ligne = 1;
    int compteur = 0;
    int valide = 0;
    // while(1)
    // {
        for (int o = 0; o < 4; o++)
        {
        lire_fichier(path, data, &offset);          // probleme d'offset lit toujours la meme ligne

        if (data)
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
                else
                {
                    break;
                }
            }

            if (compteur > 0)
            {
                printf("Ligne %d, %d fois\n", ligne, compteur);
            }
            valide = 0;
            compteur = 0;
        }

        ligne++;
        }


    // }
}