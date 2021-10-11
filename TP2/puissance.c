#include <stdio.h>

int puiss(int x, int y)
{
    int valeur = 1;
    for (int i = 0; i < y; i++)
    {
        valeur *= x;
    }
    return valeur;
}
int main()
{
    int a = 2; 
    int b = 7;
    
    printf("%d^%d = %d\n", a, b, puiss(a,b));
    
    return 0;
    
}