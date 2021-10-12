/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////////////////////////
/* fonction de tri du tableau par ordre croissant */
void triPlus(int *ptr_tab, int size)
{
    int temp;
    for(int i = 0; i < size; i++)
    {
        for( int j = i; j < 100; j++)
        {
            if (*(ptr_tab + i) > *(ptr_tab + j) )
            {
                temp = *(ptr_tab + i);
                *(ptr_tab + i) = *(ptr_tab + j);
                *(ptr_tab + j) = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/*  fonction de recherche d'une valeur dans le tableau en utilisant le methode de dichotomie */
void dichotomie(int *ptr_tab, int size, int chercher)
{
    int *ptrA = ptr_tab;
    int *ptrB = ptr_tab + size;
    int *ptrM = ptrA + (ptrB - ptrA)/2;

    while(ptrA < ptrM)/*  condition d'arret, dans le cas ou l'entier n'est pas dans le tableau */
    {   /* reduction des fenetres de recherche */
        if (chercher > *ptrM ) /*  si l'entier rechercher est plus grand que notre milieu de fenetre de recherche */
        {
            ptrA = ptrM;
            ptrM = ptrA + (ptrB - ptrA)/2;
        }
        else if(chercher < *ptrM)/*  si l'entier rechercher est plus petit que notre milieu de fenetre de recherche */
        {
            ptrB = ptrM;
            ptrM = ptrA + (ptrB - ptrA)/2;
        }
        else
        {
            printf("L'entier recherché est présent dans le tableau");
            exit(0);
        }

    }
    printf("L'entier recherché n\'est pas dans le tableau");

}
int main()
{
    /* Instantiation */
    int tab_int[100];
    int *ptr_int = tab_int;
    int chercher;
    int present = 0;

    /* remplissage du tableau */
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%100;

    }
    /* tri du tableau */
    triPlus(tab_int, sizeof(tab_int)/sizeof(int));

    /* Demande a l'utilisateur */
    printf("Entrer le nombre à chercher:");
    scanf("%d", &chercher);

    /* affichage du tableau  pour controle*/
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");

    /* recherche par dichotomie */
    dichotomie(tab_int, sizeof(tab_int)/sizeof(int), chercher);

    printf("\n");
    return 0;

}