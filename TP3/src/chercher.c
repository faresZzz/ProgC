#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int tab_int[100];
    int *ptr_int = tab_int;
    int chercher;
    int present = 0;
    
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%100;
       
    }
    
   printf("Entrer le nombre à chercher:");
   scanf("%d", &chercher);
    
    for (int i = 0; i < 100; i++)
    {
        if (*(ptr_int + i) == chercher)
        {
           present = 1;
           break;
        }
       
    }
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");
    if (present)
    {
         printf("L'entier recherché est présent dans le tableau");
    }
    else
    {
        printf("L'entier recherché ne se trouve pas dans le tableau");
    }
    printf("\n");
   
    
    
    
    
    printf("\n");
    return 0;
    
}