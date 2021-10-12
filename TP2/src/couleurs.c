/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <string.h>

//Initialisation du struct
typedef struct couleur{
   int R;
   int G; 
   int B;
   int A;
}couleur;

int main()
{
    //Déclaration des couleurs
    int tab_couleur[10][4] ={
        {0xFF, 0x57, 0x33, 0xA8},
        {0xC7, 0xFF, 0x33, 0x12},
        {0x5B, 0xA6, 0x65, 0xFF},
        {0x3B, 0xCA, 0xAB, 0x42},
        {0x12, 0x14, 0x66, 0xCD},
        {0x9B, 0x29, 0xAB, 0xD2},
        {0xDD, 0x28, 0xF5, 0x52},
        {0x37, 0xAF, 0x10, 0x66},
        {0x0E, 0xF3, 0xBF, 0x8A},
        {0x4C, 0x5A, 0x57, 0x6D},
        
        
    };
  
    
    couleur liste_couleur[10];
    
    //On remplit liste_couleur avec les éléments RGBA du tableau
    for (int i = 0; i < 10; i++)
    {
        
       liste_couleur[i].R = tab_couleur[i][0];
       liste_couleur[i].G = tab_couleur[i][1];
       liste_couleur[i].B = tab_couleur[i][2];
       liste_couleur[i].A = tab_couleur[i][3];
    }

    //On affiche les couleurs en notation hex
    for (int i = 0; i < 10; i++)
    {
        printf("couleur (R,G,B,A), (0x%x, 0x%x, 0x%x, 0x%x)\n", liste_couleur[i].R, liste_couleur[i].G, liste_couleur[i].B, liste_couleur[i].A);
    }
    
    
    
    
    printf("\n");
    return 0;
    
}