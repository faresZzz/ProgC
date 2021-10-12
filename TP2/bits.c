#include <stdio.h>


int main()
{
    int chiffre = 1572847; //2097151 
    int vingt;
    int quatre;
    
    vingt = chiffre >>20;
    quatre = chiffre >>4;
    
    if (vingt%2 == 1 && quatre % 2 == 1)
    {
        printf("Le 20° et le 4° bit du chiffre(%d) sont à 1",chiffre);
    }
    else
    {
        printf("les bits ne correspondent pas");    
    }
    return 0;
    
}