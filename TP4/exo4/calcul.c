#include <stdio.h>
#include <string.h>
#include "operator.h"




int main(int argc, char ** argv)
{
    char op;
    int num1, num2;

    if (argc > 1)
    {
        strcpy(op, argv[1]);
        num1 = (int) *argv[2];
        num2 = (int) *argv[3];

        switch(op)
        {
        case '+' :
            printf("a+b = %d\n", somme(num1, num2));
            break;

        case '-' :
            printf("a-b = %d\n", difference(num1, num2));
            break;

        case '*' :
            printf("a*b = %d\n", produit(num1, num2));
            break;

        case '/' :
            printf("a/b = %d\n", quotient(num1, num2));
            break;

        case '%' :
            printf("a%%b = %d\n", modulo(num1, num2));
            break;

        case '&' :
            printf("a&b = %d\n", etLogique(num1, num2));
            break;

        case '|' :
            printf("a|b = %d\n", ouLogique(num1, num2));
            break;

        case '~' :
            printf("a~b = %d\n", negation(num1));
            break;
        }
    }
    else
    {
        printf("Erreur veuillez entrer des parametres\n");
    }

    return 0;
}