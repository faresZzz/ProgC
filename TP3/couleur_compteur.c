#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/* creation de la strucure des couleurs */
typedef struct couleurs
{
    char valeur[30];
    int occurence;
}couleurs;



int main()
{
    /*  creation du tableau de 100 couleurs, partager par Alexandre Burlot */
    char tab_color[][30] = {
        "0x6d 0xf7 0x55 0x91","0x89 0xff 0x13 0x02","0xea 0x7b 0xaa 0x00","0xff 0xff 0xff 0xee","0xff 0xff 0xff 0xee",
        "0x89 0xff 0x13 0x02","0x37 0x99 0xbb 0x98","0xff 0xff 0xff 0xee","0xaa 0xaa 0xaa 0xaa","0x6d 0xf7 0x55 0x91",
        "0xbb 0xca 0x62 0xa7","0xbb 0xca 0x62 0xa7","0xbb 0xca 0x62 0xa7","0xaa 0xaa 0xaa 0xaa","0xff 0xff 0xff 0xee",
        "0x6d 0xf7 0x55 0x91","0xff 0xff 0xff 0xee","0x89 0xff 0x13 0x02","0xaa 0xaa 0xaa 0xaa","0x89 0xff 0x13 0x02",
        "0xaa 0xaa 0xaa 0xaa","0xea 0x7b 0xaa 0x00","0xff 0xff 0xff 0xee","0xbb 0xca 0x62 0xa7","0xaa 0xaa 0xaa 0xaa",
        "0xaa 0xaa 0xaa 0xaa","0xbb 0xca 0x62 0xa7","0xaa 0xaa 0xaa 0xaa","0x6d 0xf7 0x55 0x91","0xff 0xff 0xff 0xee",
        "0xff 0xff 0xff 0xee","0xff 0xff 0xff 0xee","0x89 0xff 0x13 0x02","0xff 0xff 0xff 0xee","0x6d 0xf7 0x55 0x91",
        "0xbb 0xca 0x62 0xa7","0xff 0xff 0xff 0xee","0xea 0x7b 0xaa 0x00","0x37 0x99 0xbb 0x98","0xbb 0xca 0x62 0xa7",
        "0xbb 0xca 0x62 0xa7","0xea 0x7b 0xaa 0x00","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa","0xea 0x7b 0xaa 0x00",
        "0xaa 0xaa 0xaa 0xaa","0xff 0xff 0xff 0xee","0xbb 0xca 0x62 0xa7","0x6d 0xf7 0x55 0x91","0xaa 0xaa 0xaa 0xaa",
        "0xbb 0xca 0x62 0xa7","0x89 0xff 0x13 0x02","0x6d 0xf7 0x55 0x91","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa",
        "0xea 0x7b 0xaa 0x00","0xaa 0xaa 0xaa 0xaa","0xbb 0xca 0x62 0xa7","0xbb 0xca 0x62 0xa7","0xbb 0xca 0x62 0xa7",
        "0xaa 0xaa 0xaa 0xaa","0xbb 0xca 0x62 0xa7","0xff 0xff 0xff 0xee","0x89 0xff 0x13 0x02","0xff 0xff 0xff 0xee",
        "0xff 0xff 0xff 0xee","0xff 0xff 0xff 0xee","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa","0xff 0xff 0xff 0xee",
        "0x6d 0xf7 0x55 0x91","0x89 0xff 0x13 0x02","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa",
        "0xff 0xff 0xff 0xee","0x89 0xff 0x13 0x02","0x6d 0xf7 0x55 0x91","0xaa 0xaa 0xaa 0xaa","0x89 0xff 0x13 0x02",
        "0xea 0x7b 0xaa 0x00","0x37 0x99 0xbb 0x98","0xbb 0xca 0x62 0xa7","0xaa 0xaa 0xaa 0xaa","0xaa 0xaa 0xaa 0xaa",
        "0x6d 0xf7 0x55 0x91","0xaa 0xaa 0xaa 0xaa","0xea 0x7b 0xaa 0x00","0xff 0xff 0xff 0xee","0x6d 0xf7 0x55 0x91",
        "0x6d 0xf7 0x55 0x91","0xbb 0xca 0x62 0xa7","0xff 0xff 0xff 0xee","0x89 0xff 0x13 0x02","0xaa 0xaa 0xaa 0xaa",
        "0xea 0x7b 0xaa 0x00","0x89 0xff 0x13 0x02","0xaa 0xaa 0xaa 0xaa","0x6d 0xf7 0x55 0x91","0xaa 0xaa 0xaa 0xaa"
    };

    /* Creation d'une liste de structure de taille 100; car dans le pire des cas aucune couleur n'est repetee */
    couleurs liste_couleur[100];
    int stack_couleur = 0;/* pile couleur, permet de connaitre le nombre de couleur reference dans la liste struct */
    int present;


    /* boucle de recherche */
    for (int i = 0; i < 100; i++)
    {
        int j;
        for ( j = 0; j < stack_couleur; j++)
        {
            if (strcmp(liste_couleur[j].valeur, tab_color[i]) == 0)/* si la couleur a deja ete repertoriee */
            {
                present = 1;
                break;
            }

        }

        if (present)/*  ajoute 1 au nombre d'occurence de la couleur */
        {
            liste_couleur[j].occurence ++;
            present = 0;
        }
        else/* sinon cree une nouvelle structure dans la liste des couleur */
        {
            strcpy(liste_couleur[stack_couleur].valeur, tab_color[i]);
            liste_couleur[stack_couleur]. occurence = 1;
            stack_couleur ++;

        }

    }

    /* affiche des couleurs repertoriee et leur occurence */
    printf("LISTE DES COULEURS AVEC LEURS OCCURENCES\n\n");
    for (int i = 0; i< stack_couleur; i++)
    {
        printf(" couleur: (%s)\toccurence: %d\n", liste_couleur[i].valeur, liste_couleur[i].occurence);
    }

    return 0;
}