#include <stdio.h>


int main()
{
    //On déclare les nom, prénom, ville et notes de chaque étudiant
    char nom[5][10] ={"Pierre", "Paul", "Jack", "Moi", "Hugo"};
    char prenom[5][30] ={"Quiroule", "Enta", "Adit", "Sissure", "Le"};
    char ville[5][30] ={"Paris", "Lyon", "Marseille", "Lille", "Gaule"};
    int progC[5] ={10, 11, 12, 13, 14};
    int systeme[5] ={10, 9, 8, 7, 6};
    
    //Pour chaque étudiant, on affiche une phrase de description
    for (int i = 0; i < 5; i++)
    {
        printf("Bonjour je suis %s %s, j\'habite à %s, mes notes en Programmation en C et Système d'exploitation sont: %d, %d\n", nom[i], prenom[i], ville[i], progC[i], systeme[i]);
    }
    
    
    
    
    printf("\n");
    return 0;
    
}