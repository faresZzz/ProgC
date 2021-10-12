#include <stdio.h>


int main()
{
    //On choisit la longueur de la suite à afficher
    int longeur = 10;

    //On initialise la suite
    int u0 = 0; 
    int u1 = 1; 
    int temp;  
    
    printf("Suite de fibonacci:\n%d\t%d\t ", u0, u1);

    //On lance le calcul et l'impression des différents termes
    for (int i = 2; i < longeur; i++)
    {
        
        temp = u1;
        u1 += u0 ;
        u0 = temp ;
        printf("%d\t", u1);
    }
    printf("\n");
    return 0;
    
}