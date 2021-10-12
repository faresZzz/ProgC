#include <stdio.h>
#include "operator.h"



int main()
{

    int num1 = 11;
    int num2 = 17;
    char op = '*';

    printf("a = %d\n", num1);
    printf("b = %d\n", num2);

    switch(op){
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