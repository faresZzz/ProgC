/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>

int main(){

//Initialisation des variables
    char a = "a";
    short b = 10;
    int c = 50;
    long int d = 123456789;
    long long int e = 12345678909987654321;
    float f = 3.14;
    double g = 145.4;
    long double h = 123.44;

    unsigned char i = "z";
    unsigned short j = 12;
    unsigned int k = 1234;
    unsigned long int l = 245523;
    unsigned long long int m = 4353324;

//Affichage des valeurs des variables
    printf("char : %ld\n", sizeof(a));
    printf("short : %ld\n", sizeof(b));
    printf("int : %ld\n", sizeof(c));
    printf("long int : %ld\n", sizeof(d));
    printf("long long int : %ld\n", sizeof(e));
    printf("float : %ld\n", sizeof(f));
    printf("double : %ld\n", sizeof(g));
    printf("long double : %ld\n", sizeof(h));

    printf("unsigned char : %ld\n", sizeof(i));
    printf("unsigned short : %ld\n", sizeof(j));
    printf("unsigned int : %ld\n", sizeof(k));
    printf("unsigned long int : %ld\n", sizeof(l));
    printf("unsigned long long int : %ld\n", sizeof(m));
}