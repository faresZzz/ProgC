/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>


int main()
{
    //déclaration des variables
    float rayon = 5;
    float PI = 3.1415;
    
    //traitement et affichage
    printf("L'aire du cercle vaut: %f cm², le perimetre du cercle vaut: %f cm", PI*rayon*rayon, 2*rayon*PI );
    return 0;
}