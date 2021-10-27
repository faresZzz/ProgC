#include <stdio.h>


typedef struct liste_couleurs {
    
    struct couleur *next;
}liste_couleurs;

void insertion (struct couleur *, struct liste_couleurs *)
{

    while (liste_couleurs.next != NULL)
    {
        liste_couleurs = liste_couleurs.next;
    }

    liste_couleurs->next = couleur

}
void parcours (struct liste_couleurs *);
{
    while(liste_couleurs->next != NULL) { //navigation
        printf( "cptr->bleu: %hhx\n", cptr->bleu);
        cptr = cptr->next; //couleur suivante
    }
}