typedef struct liste_couleurs {
    int R;
    int G;
    int B;
    int A;
    struct couleur *next;
}liste_couleurs;

void insertion (struct couleur *, struct liste_couleurs *);
void parcours (struct liste_couleurs *);