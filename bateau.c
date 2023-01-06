#include <stdio.h>
#include <stdlib.h>
#include "bateau.h"

bateaux creer_bateaux(joueurs joueur, int posX, int posY){
   bateaux bat;
   bat.joueur = joueur;
   bat.posX = posX;
   bat.posY = posY;
   return bat;
}

