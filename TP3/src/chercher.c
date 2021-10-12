/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    /* instantiation des variables */
    int tab_int[100];
    int *ptr_int = tab_int;
    int chercher;
    int present = 0;

    /*  remplissage du tableau */
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%100;

    }
    /*  Demande a l'utilisateur la valeur a chercher */
   printf("Entrer le nombre à chercher:");
   scanf("%d", &chercher);

    /* Recherche dans le tableau */
    for (int i = 0; i < 100; i++)
    {
        if (*(ptr_int + i) == chercher)
        {
           present = 1;
           break;
        }

    }

    /* affichage du tableau pour controle */
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");

    /* Reponse  */
    if (present)
    {
         printf("L'entier recherché est présent dans le tableau");
    }
    else
    {
        printf("L'entier recherché ne se trouve pas dans le tableau");
    }





    printf("\n");
    return 0;

}