/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <string.h>

//On déclare les éléments à afficher
typedef struct etudiant{
    char nom[10];
    char prenom[30];
    char ville[30];
    int progC;
    int systeme;
}etudiant;

int main()
{
    //On déclare les nom, prénom, ville et notes de chaque étudiant
    char nom[5][10] ={"Pierre", "Paul", "Jack", "Moi", "Hugo"};
    char prenom[5][30] ={"Quiroule", "Enta", "Adit", "Sissure", "le"};
    char ville[5][30] ={"Paris", "Lyon", "Marseille", "Lille", "Gaule"};
    int progC[5] ={10, 11, 12, 13, 14};
    int systeme[5] ={10, 9, 8, 7, 6};

    etudiant liste_etudiant[5];

    //Pour chaque étudiant , on remplit liste_etudiant avec les bonnes informations
    for (int i = 0; i < 5; i++)
    {
        strcpy(liste_etudiant[i].nom, nom[i]);
        strcpy(liste_etudiant[i].prenom, prenom[i]);
        strcpy(liste_etudiant[i].ville, ville[i]);
        liste_etudiant[i].progC = progC[i];
        liste_etudiant[i].systeme = systeme[i];
    }

    //On affiche les phrases descriptives des étudiants grâce à struct
    for (int i = 0; i < 5; i++)
    {
        printf("Bonjour je suis %s %s, j\'habite à %s, mes notes en Programmation en C et Système d'exploitation sont: %d, %d\n", liste_etudiant[i].nom, liste_etudiant[i].prenom, liste_etudiant[i].ville, liste_etudiant[i].progC, liste_etudiant[i].systeme);
    }




    printf("\n");
    return 0;

}