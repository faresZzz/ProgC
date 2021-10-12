#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>


////////////////////////////////////////////////////////////////////////////////
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

void dichotomie(int *ptr_tab, int size, int chercher)
{
    int *ptrA = ptr_tab;
    int *ptrB = ptr_tab + size;
    int *ptrM = ptrA + (ptrB - ptrA)/2;
    
    while(ptrA < ptrM)
    {
        if (chercher > *ptrM )
        {
            ptrA = ptrM;
            ptrM = ptrA + (ptrB - ptrA)/2;
        }
        else if(chercher < *ptrM)
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
    int tab_int[100];
    int *ptr_int = tab_int;
    int chercher;
    int present = 0;
    
    srand(time(NULL));
    for (int i = 0; i < 100; i++)
    {
        *(ptr_int + i) = rand()%100;
       
    }
    triPlus(tab_int, sizeof(tab_int)/sizeof(int));    
   printf("Entrer le nombre à chercher:");
   scanf("%d", &chercher);
    
    
    for (int i = 0; i < 100; i++)
    {
        printf("%d\t",*(ptr_int + i));
    }
    printf("\n");
    dichotomie(tab_int, sizeof(tab_int)/sizeof(int), chercher);
   
    
    
    
    
    printf("\n");
    return 0;
    
}