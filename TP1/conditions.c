#include <stdio.h>


int main()
{
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