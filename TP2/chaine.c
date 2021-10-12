#include <stdio.h>


int main()
{
    //On initialise la chaîne
    char chaine[] ="Bonjour à tous";
    
    //On calcule la taille de la chaîne
    int taille = sizeof(chaine)/sizeof(char);
    printf("taille de la chaîne \"%s\": %lu\n", chaine, sizeof(chaine)/sizeof(char)-1);
    
    /////////////////////////////////////////////////////////
    char copie_chaine[taille];
    int taille_copie = sizeof(copie_chaine)/sizeof(char);

    //On copie la chaîne dans la variable *copie_chaine*
    for(int i = 0; i < taille; i++)
    {
        copie_chaine[i] = chaine[i];
    }
    
    printf("Copie: %s\n", copie_chaine);
    
    /////////////////////////////////////////////////////////
    char concatenation[taille+taille_copie];
    int j;

    //On concatène *chaine* à *copie_chaine* pour obtenir *concatenation*
    for (j = 0; j<taille-1; j++)
    {
        concatenation[j] = chaine[j];
    }
    
    for (int k = 0; k < taille_copie; k++ )
    {
        concatenation[k + j] = copie_chaine[k];
    }
    printf("Concaténation: %s\n", concatenation);
    printf("\n");
    return 0;
    
}