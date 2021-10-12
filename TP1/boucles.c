#include <stdio.h>


int main()
{
    //Définition de la taille de la "pyramide"
    int compteur = 5 ;

    //Deux premières lignes
    printf("*\n**\n");

    //Autres lignes
    for(int i = 2; i < compteur-1; i++)
    {   
        printf("*");
        for(int j = 0; j < i; j++)
        {
            printf("#");
        }
        printf("*\n");
        
    }

    //Dernière ligne
    for (int k = 0; k < compteur; k++)
    {
        printf("*");
    }
    printf("\n");
    
}