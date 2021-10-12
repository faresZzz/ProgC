/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>


int main()
{
    //On utilise la structure switch/case pour choisir la question
    //Ici, la question 3 est choisie
    int question = 3;
    switch(question)
    {
        case 1: printf("Nombres divisibles par 2 et 15\n ");    
                for(int i = 0; i < 1000; i++)
                {   
                    if ((i % 2) == 0 && (i % 15) == 0 )   
                    {
                        printf("%d\t", i);
                    }
                    
                }
                printf("\n");
                break;  
            
        case 2:  printf("Nombres divisibles par 103 ou 107\n ");   
                for(int i = 0; i < 1000; i++)
                {   
                    if ((i % 103) == 0 || (i % 107) == 0 )   
                    {
                        printf("%d\t", i);
                    }
                    
                }
                printf("\n");
                break;
            
        case 3:  printf("Nombres divisibles par 7 et 5 mais pas 3\n ");   
                for(int i = 0; i < 1000; i++)
                {   
                    if ((i % 7) == 0 && (i % 5) == 0 && (i % 3) == 1)   
                    {
                        printf("%d\t", i);
                    }
                    
                }
                printf("\n");
    }
        
    
    
}