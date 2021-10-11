#include <stdio.h>


int main()
{
    char nom[5][10] ={"Pierre", "Paul", "Jack", "Moi", "Hugo"};
    char prenom[5][30] ={"Quiroule", "Enta", "Adit", "Sissure", "le"};
    char ville[5][30] ={"Paris", "Lyon", "Marseille", "Lille", "Gaule"};
    int progC[5] ={10, 11, 12, 13, 14};
    int systeme[5] ={10, 9, 8, 7, 6};
    
    for (int i = 0; i < 5; i++)
    {
        printf("Bonjour je suis %s %s, j\'habite a %s, mes notes en programmation en C et Systeme sont: %d, %d\n", nom[i], prenom[i], ville[i], progC[i], systeme[i]);
    }
    
    
    
    
    printf("\n");
    return 0;
    
}