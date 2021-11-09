/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Calcul de factorielle n
*/

#include <stdio.h>

int factorielle(int num)
{
    if(num == 0)
    {
        return 1;
    }
    else
    {
        return (num * factorielle(num - 1));
    }
}


int main()
{
    int num ;
    printf("Entrez votre nombre: ");
    scanf("%d", &num);
    printf("%d! = %d\n", num, factorielle(num));

    return 0;
}



