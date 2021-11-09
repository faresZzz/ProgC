/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

struct couleur{
    int R;
    int G;
    int B;
    int A;
    struct couleur *next;
};

void creation_couleurs(int tab_couleur[][4], struct couleur *liste_couleur);

void affichageliste(struct couleur *liste_couleur);