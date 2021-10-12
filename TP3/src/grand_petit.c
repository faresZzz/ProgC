#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


/* Dans se programme nous cherchons la valeur la plus grand et la plus petite d'un tableau. */

int main()
{
    /* Initialisation des differents parametres */
    int tab_int[100];
    int *ptr_int = tab_int;

    int min;
    int max;
    srand(time(NULL));

   /* assignation de valeur random [0;500[ dans le tableau  */
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%500;

    }

    max = *(ptr_int);
    min = *(ptr_int);
    /* Boucle for qui parcour le tableau complet
    et comprare a chaque fois si la i-eme valeur
    est plus grand que le max ou plus petite que le min */
    for (int i = 0; i < 100; i++)
    {
        if (*(ptr_int + i) > max)
        {
            max = *(ptr_int + i);
        }
        if (*(ptr_int + i) < min)
        {
            min = *(ptr_int + i);
        }

    }
    /* Affichage du tableau et du min et max */
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");
    printf("max: %d\tmin: %d", max, min);




    printf("\n");
    return 0;

}