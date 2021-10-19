#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"



int calcul(char op, int num1, int num2)
{

    switch(op)
    {
    case '+' :
        return somme(num1, num2);
        break;

    case '-' :
        return difference(num1, num2);
        break;

    case '*' :
        return produit(num1, num2);
        break;

    case '/' :
        return quotient(num1, num2);
        break;

    case '%' :
        return modulo(num1, num2);
        break;

    case '&' :
        return etLogique(num1, num2);
        break;

    case '|' :
        return ouLogique(num1, num2);
        break;

    case '!' :
        return negation(num1);
        break;
    default:
        return(EXIT_FAILURE);
    }

}