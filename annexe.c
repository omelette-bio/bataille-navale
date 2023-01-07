#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annexe.h"

void display(int hauteur, int largeur, int tableau[], int montrer_bateaux){
   /*variables permettant de faire des boucles sur les lignes et les colonnes du plateau*/
   int i;
   int j;
   /*initialise les variables de hauteur largeur pour avoir les dimensions précises*/
   int hauteur0=hauteur+2; /*ajoute 2 pour les lignes en dessous et au dessus du plateau*/
   int largeur0=(largeur*2)+1; /*multiplie par deux pour pouvoir séparer plus facilement les colonnes*/
   
   for (i=0;i<hauteur0;i++){
      /*commence par écrire la ligne avec les lettres au-dessus du plateau*/
      if (i==0){
         printf("  "); /*met un espace de 2 caractères afin de bien aligner le tableau*/
         /*écrit les différentes lettres avec l'utilisation du %c*/
         for (j=0;j<largeur;j++){
            printf(" %c",j+65);
         }
         printf("\n");
      }
      
      /*la suite du plateau*/
      for (j=0;j<largeur0;j++){
         /*partie du code permettant la mise en page de la première ligne du plateau*/
         if ((i==0)||(i==hauteur0-1)){
            /*si le programme en est à la première ligne, et à la première ou dernière colonne, on place un +, */
            /*avec un espacement pour bien aligner*/
            if (j==0){
               printf("  +");
            } else if (j==largeur0-1){
               printf("+");
            }
            /*une colonne sur deux, place un - ou un + */
            else if (j%2!=0){
               printf("-");
            } else if (j%2==0){
               printf("+");
            }
         /*si le programme est à la 1ere colonne du plateau, écrit les numero des lignes à gauche du plateau*/
         } else if (j==0){
            printf("%02d|",i);
         /*si le programme est à la dernière, place juste un trait*/
         } else if (j==largeur0-1){
            printf("|");
         /*crée les vides dans le tableau*/
         } else {
            if (j%2!=0){
               if (tableau[((i-1)*largeur)+(j/2)]==3){
                  printf("#");
               }
               else if (tableau[((i-1)*largeur)+(j/2)]==2){
                  printf("X");
               }
               else if ((tableau[((i-1)*largeur)+(j/2)]==1)&(montrer_bateaux==1)){
                  printf("B");
               }
               else {
                  printf("~");
               }
            } else if (j%2==0){
               printf(" ");
            }
         }
      }
      printf("\n");
   }
}

int *decomp_donnees(char *str, int *num_elements){
   /* Create an array to store the numbers */
  int *numbers = malloc(sizeof(int) * 2);
  /* Split the string into tokens using "x" as the delimiter */
  char *token = strtok(str, "x:");
  *num_elements = 0;

  while (token != NULL) {
    /* Convert the token to an integer and add it to the array */
    numbers[(*num_elements)++] = atoi(token);

    /* Get the next token */
    token = strtok(NULL, "x:");
  }

  return numbers;
}
