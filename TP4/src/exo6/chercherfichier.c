/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Programme qui compte le nombre d'occurence par ligne qu'une chaine
de caractere est présente.

Nous venons lire ligne par ligne le fichier en utilisant la bibliotheque fichier contenu dans "data".
Puis nous venons observer si la substring est contenue dans cette ligne.

./chercherfichier Path_fichier substring
Path_fichier: chemin vers le fichier a parcourir
substring: chaine de caratere a chercher

*/

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
    if (argc < 3)
    // on verifier d'avoir tous les information nessessaire pour faire la recherche
    {
        printf("Veuillez saisir les informations: ./chercherficher 'NomFichier' 'Expression'\n");
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
        /*
         lecture ligne par ligne, puis recuperation de la position du pointeur dans le fichier
         contenu dans offset. Prochaine lecteure nous lirons la ligne suivante et non la meme
        */
        offset = lire_fichier(argv[1], data, offset);

        if (strlen(data) >= strlen(argv[2]))
        {
            for (int i = 0; i < (strlen(data) -strlen(mot)); i++)
            // on boucle sur les caractere de la ligne
            {
                for (int j = 0; j<strlen(argv[2]); j++)
                // on boucle sur les caracteres de la substring
                {
                    if (data[i+j] == argv[2][j])
                    {
                        valide ++;
                        if (valide == (strlen(argv[2])))
                        // si l'on a autant de carateres valides d'affile que la taille du mot ca veut dire que l'on a le mot
                        {
                            compteur++;
                        }
                    }
                }

                valide = 0;
            }
        }
        if (compteur > 0)
        // si on a au moins 1 fois le mot dans la ligne on print
            {
                printf("Ligne %d, %d fois\n", ligne, compteur);
            }

            compteur = 0;
        memset(data, 0, sizeof(data));
    }
    printf("Fin de fichier\n");
    return 0;
}
