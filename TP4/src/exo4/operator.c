/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Bibliotheque d'operations:
Somme: +
Difference: -
Multiplication: *
Division: /
Modulo: %
Et Logique: &&
Ou Logique: ||
Negation: !
*/

#include <stdio.h>


int somme(int num1, int num2)
{
    return num1 + num2;
}

int difference(int num1, int num2)
{
    return num1 - num2;
}

int produit(int num1, int num2)
{
    return num1 * num2;
}

int quotient(int num1, int num2)
{
    return num1 / num2;
}

int modulo(int num1, int num2)
{
    return num1 % num2;
}

int etLogique(int num1, int num2)
{
    return num1 && num2;
}

int ouLogique(int num1, int num2)
{
    return num1 || num2;
}

int negation(int num1)
{
    return !num1;
}
