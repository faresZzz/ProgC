#include <stdio.h>

int main(){
    int num1;
    num1 = 11;
    int num2;
    num2 = 17;
    char op = '*';

    printf("a = %d\n", num1);
    printf("b = %d\n", num2);

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

        case '|' :
            printf("a|b = %d\n", num1|num2);
            break;

        case '~' :
            printf("a~b = %d\n", ~num1);
            break;
    }
}