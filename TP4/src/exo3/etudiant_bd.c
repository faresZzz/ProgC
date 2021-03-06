/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON

Programme permettant de venir stocker les parametres des etudiants saisis par l'utilisateur
dans un fichier.

./edudiant_bd  Path X
Path: chemin vers le fichier
X: nb d'etudiant que l'on vas vouloir stocker
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

//On déclare les éléments à afficher
typedef struct etudiant{
    char nom[10];
    char prenom[30];
    char ville[30];
    int progC;
    int systeme;
}etudiant;

void emptybuff()
/*
fonction permettant de vider le buffer entre 2 scanf
*/
{
    int c;
    while((c = getchar()) != '\n' && c !=EOF){ }
}

void enregistrement(char *nom_fichier, int numEtudiant, char nom[], char prenom[], char rue[], char ville[], int note1, int note2)
/*
fonction qui formatte les donnes et viens appeler notre fonction d'ecriture dans le fichier
*/
{
    char data[1024];
    memset(data, 0, sizeof(data));
    sprintf(data, "Etudiant numero : %d\n\tNom: %s, Prenom: %s, Adresse: %s, %s, Note: ProgC %d, Systeme %d\n", numEtudiant, nom, prenom, rue, ville, note1, note2);
    ecrire_dans_fichier(nom_fichier, data);
}

int main(int argc, char **argv)
{

     if (argc < 3)
    {
        printf("Veuillez saisir les information: ./etudiant_bd 'Nom fichier' nombre d'etudiant'\n");
        exit(0);
    }

    int nb_etudiants = atoi(argv[2]);
    char message[300];
    char nom[10];
    char prenom[30];
    char rue [100];
    char ville[100];
    int progC;
    int systeme;

    for (int etudiant = 0; etudiant < nb_etudiants; etudiant++)
    // boucle qui pour chaque etudiant demande a l'utilisteurs de fournir les informations du l'eleve.

    {
        printf("veuillez saisir les informations de l'etudiant:\n");

        printf("Nom: ");
        scanf("%s", nom);
        emptybuff();

        printf("Prenom: ");
        scanf("%s", prenom);
        emptybuff();

        printf("Rue: ");
        scanf("%s", rue);
        emptybuff();

        printf("Ville: ");
        scanf("%s", ville);
        emptybuff();

        printf("Note ProgC: ");
        scanf("%d", &progC);
        emptybuff();

        printf("Note Système: ");
        scanf("%d", &systeme);
        emptybuff();

        // appel de la fonction d'enregistrement pour venir mettre un nouvel eleve
        enregistrement(argv[1], etudiant+1, nom, prenom, rue, ville, progC, systeme);
    }

    return 0;

}