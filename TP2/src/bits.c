/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>


int main()
{
    //On choisit le nombre à "analyser"
    int chiffre = 1572847; //2097151
    int vingt;
    int quatre;

    //Opérateurs de décalage de 20 bits et de 4 bits
    vingt = chiffre >>20;
    quatre = chiffre >>4;

    //On teste si les 4° et 20° bits de *chiffre* sont bien à 1 et on affiche le résultat
    if (vingt%2 == 1 && quatre % 2 == 1)
    {
        printf("Le 20° et le 4° bit du chiffre(%d) sont à 1",chiffre);
    }
    else
    {
        printf("les bits ne correspondent pas");
    }
    return 0;

}