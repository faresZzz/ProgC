#include <stdio.h>

int puiss(int x, int y)
{
    //Cette fonction multiplie x par lui-même y fois
    int valeur = 1;
    for (int i = 0; i < y; i++)
    {
        valeur *= x;
    }
    return valeur;
}
int main()
{
    //On initialise les variables
    int a = 2; 
    int b = 7;
    
    //On cacule a à la puissance b et on affiche le résultat
    printf("%d^%d = %d\n", a, b, puiss(a,b));
    
    return 0;
    
}