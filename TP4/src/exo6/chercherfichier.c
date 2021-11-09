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

/*


*/


int main(int argc, char **argv)         // argv: ./chercherficher NomFichier Expression
{
     if (argc < 3)
    {
        printf("Veuillez saisir les information: ./chercherficher 'NomFichier' 'Expression'\n");
        exit(0);
    }
    char data[1024];
    memset(data, 0, sizeof(data));
    char *mot = argv[2];
    int offset = 0;
    int compteur = 0;
    int valide = 0;
    int nbligne = wc_maison(argv[1]);
    for (int ligne = 1; ligne <= nbligne; ligne++)
    {
        offset = lire_fichier(argv[1], data, offset);
        if (strlen(data) >= strlen(argv[2]))
        {
            for (int i = 0; i < (strlen(data) -strlen(mot)); i++)
            {
                for (int j = 0; j<strlen(argv[2]); j++)
                {
                    if (data[i+j] == argv[2][j])
                    {
                        valide ++;
                        if (valide == (strlen(argv[2])))
                        {
                            compteur++;
                        }
                    }
                }

                valide = 0;
            }
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
