#include <stdio.h>

/*  Nous testons les valeur rencoyer par les differents pointeurs. 
En utilisant de l'encapsulation de pointeur */
int main(){
    printf("taille de int : %li\n",sizeof(int));
    printf("taille de int *: %li\n",sizeof(int *));
    printf("taille de int ** : %li\n",sizeof(int **));
    printf("taille de char * : %li\n",sizeof(char *)); 
    printf("taille de char ** : %li\n",sizeof(char **)); 
    printf("taille de char *** : %li\n",sizeof(char ***)); 
    printf("taille de float * : %li\n",sizeof(float *)); 
    printf("taille de float ** : %li\n",sizeof(float **)); 
    printf("taille de float *** : %li\n",sizeof(float ***));  
}