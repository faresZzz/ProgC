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
        printf("Le 20eme et le 4eme bit du chiffre(%d) sont a 1",chiffre);
    }
    else
    {
        printf("les bits ne correspondes pas");    
    }
    return 0;
    
}