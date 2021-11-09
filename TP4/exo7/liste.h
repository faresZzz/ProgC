/*
Auteurs : Farès ZAGHOUANE, Maxime CURRAL
Rendu le 09/11/2021 dans le cadre du module "Programmation en C"
CPE LYON
*/

struct liste_couleurs {
    int R;
    int G;
    int B;
    int A;
    struct couleur *next;
};

struct Liste_couleurs {
    struct couleur *first;
};

void insertion (struct couleur *nouveau, struct Liste_couleurs *liste_couleurs);
void parcours (struct Liste_couleurs *liste_couleurs);
