#include <stdio.h>

// probleme sur certain chiffres comme 2048 ou 4096
int main()
{
    int valeur = 208;
    int binaireval[8*sizeof(int)]; 
    int i;
    printf("la valeur binaire de %d est: ", valeur);
    for( i = 0; i < 8*sizeof(int); i++)
    {   
       if (valeur > 0)
       {
            binaireval[i] = valeur%2;
            valeur = valeur/2;
       }
       else
       {
           break;
       }
       
       
    }
    for (i-1 ; i >= 0; i-- )
   {
       printf("%d", binaireval[i]);
   }
    printf("\n");
    return 0;
    
        
    
    
}