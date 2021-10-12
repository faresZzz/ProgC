/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 12/10/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*  fonction strcmp qui permet de comparer 2 chaine de character */
int compareStr(char *mot1, int taille_mot1, char *mot2, int taille_mot2)
{
    int valide = 1;
    if (taille_mot1 == taille_mot2)/* pas utile dans notre cas car nous avons instantier les 2 a la meme taille, mais plus generique pour futur utilisation */
    {
        /* boucle qui comprer character a character */
        for (int i = 0; i < taille_mot1; i++ )
        {
            if (( ( (*(mot1 + i)) == NULL )  && ( (*(mot2 + i)) != NULL )) ||  (( (*(mot1 + i)) != NULL )  && ((*(mot2 + i)) == NULL)))
            {/* si une des chaine est en fin de mot et pas l'autre,, alors elles sont differente */
                valide = 0;
                break;
            }
            else if (( ( (*(mot1 + i)) == NULL )  && ((*(mot2 + i)) == NULL)))
            {/* si nous n'avons pas break et que les 2 chaines sont fini alors elles sont egales */
                break;
            }
            else
            {
                if ((*(mot1 + i)) != (*(mot2 + i)) )/* verifie si les 2 character sont egaux */
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
    /* tableau des phrases */
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




    char cherche[50];
    int valide;

    /* demande a l'utilisateur */
    printf("Entrer la phrase à chercher: ");
    scanf("%[^\n]", &cherche);

    /* boucle sur tab_phrase pour voir si une phrase correspond a celle recherchee */
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