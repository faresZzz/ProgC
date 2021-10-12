#include <stdio.h>
#include <stdlib.h>


int compareStr(char *mot1, int taille_mot1, char *mot2, int taille_mot2)
{
    int valide = 1;
    if (taille_mot1 == taille_mot2)
    {
        for (int i = 0; i < taille_mot1; i++ )
        {
            if (((*(mot1 + i) == NULL)  && (*(mot2 + i) != NULL)) ||  ((*(mot1 + i) != NULL)  && (*(mot2 + i) == NULL)))
            {
                valide = 0; 
                break;
            }
            else if (((*(mot1 + i) == NULL)  && (*(mot2 + i) == NULL)))
            {
                break;
            }
            else
            {
                if (*(mot1 + i) != *(mot2 + i) )
                { 
                    valide = 0;
                    break;
                }
            }
        }
    }
    else
    {
        valide = 0;
    }

    return valide;
}


int main()
{
    char tab_phrase[10][50] = {"Bonjour à tous",
                            "Comment allez-vous",
                            "Hello world",
                            "come on guys", 
                            "Je suis passe chez so", 
                            "Michel aime se promener",
                            "Je suis pas venu pour rien",
                            "Il faut se connecter avec la nature",
                            "Pour la daronne",
                            "N'est pas ingénieur qui veut"
                            };


    // char *ptr_mot = &tab_phrase[0];
    
    char cherche[50];
    int valide;

    printf("Entrer la phrase à chercher: ");
    scanf("%[^\n]", &cherche);

    for (int i = 0; i < 10; i++)
    {
        valide =  compareStr(cherche, sizeof(cherche)/sizeof(char), tab_phrase[i], sizeof(tab_phrase[i])/sizeof(char));
        if (valide)
        {
            printf("La phrase est présente dans la liste \n");
            exit(0);
        }
    }
    printf("La phrase n'est pas présente dans la liste\n");
    return 0;
}