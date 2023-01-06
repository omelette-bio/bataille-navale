#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(int hauteur, int largeur/*, char tableau[]*/){
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
               printf("~");

               /*if ((tableau[((i-1)*largeur)+(j/2)]==1)||(tableau[((i-1)*largeur)+(j/2)]==0))
                  printf("~");
               else{
                  printf("%c",tableau[((i-1)*largeur)+(j/2)]);
               }*/
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

int main(int argc, char **argv){
   int hauteur, largeur;
   /*display(hauteur,largeur);*/

   if (strcmp(argv[1],"-f")==0){

      int taille_tampon = 100;
      char* tampon = malloc(taille_tampon * sizeof(char));
      FILE* f = fopen(argv[2],"r");

      while ( fgets(tampon, taille_tampon, f) != NULL ){
         char *words[10];
         int j,i=0;

         char *word = strtok(tampon, " \n");
         while (word != NULL) {
            words[i++] = word;
            word = strtok(NULL, " \n");
         }

         for (j = 0; j < i; j++) {
            if (strcmp(words[j],"Projet")==0){
               int num_elements;
               int *numbers = decomp_donnees(words[j+1], &num_elements);
               hauteur = numbers[0];
               largeur = numbers[1];

               /* Don't forget to free the memory when you're done*/
               free(numbers);
            }
            if (strcmp(words[j],"Afficher")==0){
               display(hauteur,largeur);
            }
            if ((strcmp(words[j],"J1")==0)||(strcmp(words[j],"J2")==0)){
               if (strcmp(words[j+1],"P")){

               }
               else if (strcmp(words[j+1],"T")){

               }
            }
         }
      }
      fclose(f);
   }
   return 0;
}