#include <stdio.h>


int main()
{
    int compteur = 5 ;
    printf("*\n**\n");
    for(int i = 2; i < compteur-1; i++)
    {   
        printf("*");
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("*\n");
        
    }
    for (int k = 0; k < compteur; k++)
    {
        printf("*");
    }
    printf("\n");
    
}