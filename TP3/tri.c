#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

//Nous avons réalisé 3 méthodes de tri différentes pour cet exercice.

/* Fonction permetant de trouver le min d'un tableau */
int *pmin( int *tab_min, int size_min)
{
    int *ptr_min = tab_min;

    for (int i = 0; i < size_min; i++)
    {
        if (*(tab_min + i) < *ptr_min)
        {
            ptr_min = tab_min + i;
        }

    }

    return ptr_min;
}

/* Fonction permetant de trouver le max d'un tableau*/
int *pmax( int *tab_max, int size_max)
{
    int *ptr_max = tab_max;

    for (int i = 0; i < size_max; i++)
    {
        if (*(tab_max + i) > *ptr_max)
        {
            ptr_max = tab_max + i;
        }
    }
    return ptr_max;
}
/////////////////////////////////////////////////////////////////////////////////
/* Dans cete fonction de tri nous faisons 2 boucle sur tout le tableau et echangons les valeurs au fur et mesure */
void triBasic(int *ptr_tab, int size)
{
    int temp;
    for(int i = 0; i < size; i++)
    {
        for( int j = 0; j < 100; j++)
        {
            if (*(ptr_tab + i) < *(ptr_tab + j) )
            {
                temp = *(ptr_tab + i);
                *(ptr_tab + i) = *(ptr_tab + j);
                *(ptr_tab + j) = temp;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////
/* Le tri se fait a l'aide d'une boucle i qui parcourt 1 fois le tableau, et d'un boucle j qui parcourt plusiseurs
fois le tableau entre i et la fin et comprare la valeur en i et celle en j pour echanger si besoin */
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
/*  tri en utilisant les fonction min et max, a chaque tour de boucle nous trouvons le min et max du tableau
et le placons respt au debut et a la fin du tableau et recommencons avec un tableau "plus petit" */
void triTop(int *ptr_debut, int size)
{
    int *ptr_fin = ptr_debut + size;
    int temp_min;
    int temp_max;
    int *ptr_min;
    int *ptr_max;
    for(int i = 0; i < size; i++)
    {
        if (ptr_debut < ptr_fin)
        {
            temp_min = *ptr_debut;
            ptr_min = pmin(ptr_debut, size-i );
            *ptr_debut = *ptr_min;
            *ptr_min = temp_min;


            temp_max = *(ptr_fin);
            ptr_max = pmax(ptr_debut, size - i );
            *(ptr_fin) = *ptr_max;
            *ptr_max = temp_max;

            ptr_debut++;
        }
        else
        {
            break;
        }
    }
}

/* Fonction principal: instantiations des variables et remplissage du tableau, appel de la fonction, affichage du tableau */
int main()
{
    int tab_int[100];
    int *ptr_int = tab_int;

    int min;
    int max;
    srand(time(NULL));

    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%100;

    }

    triPlus( tab_int, sizeof(tab_int)/sizeof(int));

    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");





    printf("\n");
    return 0;

}