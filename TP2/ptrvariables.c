#include <stdio.h>

int main(){

    //On déclare des variables de plusieurs types et à chaque fois un pointeur leur correspondant
    char a = 19;
    char *ptr_char =&a;

    short b = 14;
    short *ptr_short = &b;

    int c = 17;
    int *ptr_int = &c;

    long int d = 90867;
    long int *ptr_longint = &d;

    long long int e = 15291072;
    long long int *ptr_longlongint = &e;

    float f = 34.3;
    float *ptr_float = &f;

    double g = 2.373;
    double *ptr_double = &g;

    long double h = 9.01986139;
    long double *ptr_longdouble = &h;


    //On affiche pour chaque variable son adresse et sa valeur avec son pointeur
    printf("char adresse : %p\n",ptr_char);
    printf("char : %i\n\n", *ptr_char);

    printf("short adresse : %p\n", ptr_short);
    printf("short : %i\n\n", *ptr_short);

    printf("int adresse : %p\n", ptr_int);
    printf("int : %i\n\n", *ptr_int);

    printf("long int adresse : %p\n", ptr_longint);
    printf("long int : %li\n\n", *ptr_longint);

    printf("long long int adresse : %p\n", ptr_longlongint);
    printf("long long int : %lli\n\n", *ptr_longlongint);
    
    printf("float adresse : %p\n", ptr_float);
    printf("float : %f\n\n", *ptr_float);

    printf("double adresse : %p\n", ptr_double);
    printf("double : %f\n\n", *ptr_double);

    printf("short long double: %p\n", ptr_longdouble);
    printf("long double : %Lf\n\n", *ptr_longdouble);

}