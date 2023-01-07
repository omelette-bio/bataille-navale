/*fonction permettant de créer un tableau initialisé à 0 permettant de stocker les informations de chaque case du plateau*/
int * creer_tab_suivi_jeu(int hauteur, int largeur);

/*permet d'assigner une valeur à une case du plateau x étant une case lettrée (en chiffres) et y les chiffres à gauche,*/
/*par exemple, si on avait un tableau à 2 dimension ce serait tab[posy][posx]*/
void assigner(int *tab, int posX, int posY, int largeur, int valeur);

/*permet d'afficher un tableau, sert uniquement à debugger*/
void afficher_tableau(char tab[], int taille);

/*fonction permettant de libérer la mémoire utilisée par le tableau*/
void liberer(int tableau[]);