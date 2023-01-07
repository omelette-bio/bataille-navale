/*typedef enum {J1,J2} joueurs;*/

typedef struct bateaux_struct{
   char *joueur;
   int *coords;
}bateaux;

bateaux creer_bateaux(char joueur[], int *pos);

void afficher_bateau(bateaux bateau);

void placer_bateau(bateaux bateau,int* tab, int largeur);

int tirer(int *pos, int *tab_jeu, int largeur);