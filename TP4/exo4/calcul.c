#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"




int main(int argc, char ** argv)
{
    char op;
    char *ptr_op = &op;
    int num1, num2;

    if (argc > 1)
    {
        strcpy(ptr_op, argv[1]);



        switch(op)
        {
        case '+' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d + %d = %d\n", num1, num2, somme(num1, num2));
            break;

        case '-' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d - %d = %d\n", num1, num2, difference(num1, num2));
            break;

        case '*' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d * %d = %d\n", num1, num2, produit(num1, num2));
            break;

        case '/' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d / %d = %d\n", num1, num2, quotient(num1, num2));
            break;

        case '%' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d %% %d = %d\n", num1, num2, modulo(num1, num2));
            break;

        case '&' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d & %d = %d\n", num1, num2, etLogique(num1, num2));
            break;

        case '|' :
            num1 = atoi(argv[2]);
            num2 = atoi(argv[3]);
            printf("%d | %d = %d\n", num1, num2, ouLogique(num1, num2));
            break;

        case '!' :
            num1 = atoi(argv[2]);
            printf("!%d = %d\n", num1, negation(num1));
            break;
        default:
            printf("Wrong operator!\n ");
        }
    }
    else
    {
        printf("Erreur veuillez entrer des parametres\n");
    }

    return 0;
}