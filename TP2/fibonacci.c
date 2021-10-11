#include <stdio.h>


int main()
{
    int longeur = 10;
    int u0 = 0; 
    int u1 = 1; 
    int temp;  
    
    printf("Suite de fibonacci:\n%d\t%d\t ", u0, u1);
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