#include <stdio.h>
#include "fichier.h"



int main()
{
    char read_write;
    char fichier;
    char *ptr_fichier = &fichier;
    char message[100];
    char *ptr_message = message;

    printf("donner le nom du fichier:");
    scanf("%s", &fichier);

    printf("\n Donner l'action a executer [r/w]:");
    scanf("%c", &read_write);

    switch (read_write)
    {
    case 'r':
        lire_fichier(ptr_fichier);
        break;

    case 'w':

        printf("Entrer votre phrase:");
        scanf("%[^\n]", &message);
        ecrire_dans_fichier(ptr_fichier, ptr_message);
        break;
    default:
        printf("la commende entree ne correspond pas\n");
    }
}