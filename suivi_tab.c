#include <stdio.h>
#include <stdlib.h>
#include "suivi_tab.h"

int * creer_tab_suivi_jeu(int hauteur, int largeur){
   /*on utilise calloc afin de créer directement un tableau de hauteur*largeur cases rempli de 0*/
   int *tab0 = calloc(hauteur*largeur,sizeof(int));
   return tab0;
}

void assigner(int *tab,int posX, int posY, int largeur, int valeur){
   tab[((posY)*largeur)+((posX)%largeur)]=valeur;
}

void liberer(int tableau[]){
   free(tableau);
}
