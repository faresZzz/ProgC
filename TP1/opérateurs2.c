/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>

int main(){

    //On peut changer les valeurs de a et de b et l'opération à effectuer ci-dessous :
    int num1;
    num1 = 11;
    int num2;
    num2 = 17;
    char op = '*';

    //On commence par afficher les valeurs de a et de b
    printf("a = %d\n", num1);
    printf("b = %d\n", num2);

    //L'opérateur est sélectionné
    switch(op){
        case '+' :
            printf("a+b = %d\n", num1+num2);
            break;

        case '-' :
            printf("a-b = %d\n", num1-num2);
            break;

        case '*' :
            printf("a*b = %d\n", num1*num2);
            break;

        case '/' :
            printf("a/b = %d\n", num1/num2);
            break;

        case '%' :
            printf("a%%b = %d\n", num1%num2);
            break;

        case '&' :
            printf("a&b = %d\n", num1&num2);
            break;

        case '||' :
            printf("a|b = %d\n", num1||num2);
            break;

        case '~' :
            printf("a~b = %d\n", !num1);
            break;
    }
}