#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"
#include "suivi_tab.h"

bateaux creer_bateaux(char joueur[], int* pos){
   bateaux bat;
   bat.joueur = joueur;
   bat.coords = pos;
   return bat;
}

void afficher_bateau(bateaux bateau){
   printf("%s,%d,%d\n", bateau.joueur, bateau.coords[0], bateau.coords[1]);
}

void placer_bateau(bateaux bateau,int* tab, int largeur){
   assigner(tab, bateau.coords[0], bateau.coords[1], largeur, 1);
}

int tirer(int *pos, int *tab_jeu, int largeur){
   if (tab_jeu[(pos[1])*largeur+pos[0]]==1){
      assigner(tab_jeu, pos[0], pos[1], largeur, 2);
      return 1;
   } else {
      assigner(tab_jeu, pos[0], pos[1], largeur, 3);
      return 0;
   }
}

