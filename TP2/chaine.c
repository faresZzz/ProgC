#include <stdio.h>


int main()
{
    char chaine[] ="Bonjour à tous";
    int taille = sizeof(chaine)/sizeof(char);
    printf("taille de la chaîne \"%s\": %lu\n", chaine, sizeof(chaine)/sizeof(char)-1);
    
    /////////////////////////////////////////////////////////
    char copie_chaine[taille];
    int taille_copie = sizeof(copie_chaine)/sizeof(char);

    for(int i = 0; i < taille; i++)
    {
        copie_chaine[i] = chaine[i];
    }
    
    printf("Copie: %s\n", copie_chaine);
    
    /////////////////////////////////////////////////////////
    char concatenation[taille+taille_copie];
    int j;
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