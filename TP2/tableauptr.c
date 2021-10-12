#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>




int main()
{
    //On crée les tableaux et les pointeurs correspondants
    int tab_int[10];
    int *ptr_int = tab_int;
    
    float tab_float[10];
    float *ptr_float = tab_float;
  
    //On remplit les tableaux aléatoirement
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
    {
        *(ptr_int + i) = rand()%100;
        *(ptr_float + i) = (rand()%100);
    }
    
    //On parcourt les indices et à chaque fois qu'il y en un pair, on multiplie par 3 la valeur qu'il pointe
    for (int i = 0; i < 10; i++)
    {
        if ((i % 2) == 0)
        {
            *(ptr_int + i) *= 3;
            *(ptr_float + i) *= 3;
        }
    }

    //On affiche les tableaux
    printf("int\tfloat\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t%.2f\n",*(ptr_int + i), *(ptr_float + i));
    }
    
    
    
    
    printf("\n");
    return 0;
    
}