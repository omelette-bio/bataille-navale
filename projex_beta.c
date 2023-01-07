#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "annexe.h"
#include "bateau.h"
#include "suivi_tab.h"
#include "strtrim.h"
#define BOARD_SIZE_BUFFER_LENGTH 100
#define INPUT_BUFFER_LENGTH 100
#define TEMP_BUFFER_LENGTH 100
#define MAX_NUM_WORDS 10




int main(int argc, char **argv){
   int hauteur, largeur, result, vies_j1, vies_j2, nb_bateaux;
   int *tab_jeu_j1,*tab_jeu_j2;

   char taille_plateau[BOARD_SIZE_BUFFER_LENGTH];
   char lecture_str[INPUT_BUFFER_LENGTH];

   bateaux bat0;

   srand(time(0));

   /*display(hauteur,largeur);*/


   if (strcmp(argv[1],"-i")==0){
      int num_elements;
      int *numbers;
      int i;
      int coord_alea[2];

      printf("quelle taille pour le plateau ?\n");
      printf("(écrire en format NxM)\n");
      scanf("%s",taille_plateau);

      numbers = decomp_donnees(taille_plateau, &num_elements);
      tab_jeu_j1 = creer_tab_suivi_jeu(numbers[0], numbers[1]);
      tab_jeu_j2 = creer_tab_suivi_jeu(numbers[0], numbers[1]);

      hauteur = numbers[0];
      largeur = numbers[1];

      printf("Combien de bateaux à placer bébou ? : ");
      scanf("%d", &nb_bateaux);
      vies_j1 = nb_bateaux;
      vies_j2 = nb_bateaux;

      for (i=0;i<nb_bateaux;i++){
         printf("bateau %d : \n",i+1);

         printf("coordonnées : (format X:Y, A1=0:0)\n");
         scanf("%s",lecture_str);

         numbers = decomp_donnees(lecture_str, &num_elements);
         bat0=creer_bateaux("J1",numbers);
         placer_bateau(bat0,tab_jeu_j1,largeur);

         coord_alea[0]=rand()%largeur;
         coord_alea[1]=rand()%hauteur;

         bat0=creer_bateaux("J2",coord_alea);
         placer_bateau(bat0,tab_jeu_j2,largeur);
      }

      display(hauteur,largeur,tab_jeu_j1,0);
      display(hauteur,largeur,tab_jeu_j2,0);

      while(1){
         printf("(format X:Y, A1=0:0)\n");
         printf("J1 tire en : ");
         scanf("%s",lecture_str);

         numbers = decomp_donnees(lecture_str, &num_elements);

         result = tirer(numbers,tab_jeu_j2,largeur);

         if (result==1){
            printf("Coulé ! ");
            if ((--vies_j2)==0){
               printf("J1 gagne !\n");
               return 0;
            }
         }

         display(hauteur,largeur,tab_jeu_j2,0);

         coord_alea[0]=rand()%largeur;
         coord_alea[1]=rand()%hauteur;

         result = tirer(coord_alea,tab_jeu_j1,largeur);

         printf("L'ia tire en : %d:%d \n",coord_alea[0],coord_alea[1]);

         if (result==1){
            printf("Coulé ! ");
            if ((--vies_j1)==0){
               printf("J2 gagne !\n");
               return 0;
            }
         }

         display(hauteur,largeur,tab_jeu_j1,1);
      }

      free(numbers);
      return 0;
   }

   if (strcmp(argv[1],"-f")==0){

      int taille_tampon = 100;
      char* tampon = malloc(taille_tampon * sizeof(char));
      FILE* f = fopen(argv[2],"r");

      while ( fgets(tampon, taille_tampon, f) != NULL ){
         char *words[10];
         int j,k,i=0;

         char *word = strtok(tampon, " \n");
         while (word != NULL) {
            words[i++] = word;
            word = strtok(NULL, " \n");
         }

         for (j = 0; j < i; j++) {
            char *trimmed_word = strtrim(words[j]);

            if (strcmp(trimmed_word,"Projet")==0){
               int num_elements;
               int *numbers = decomp_donnees(words[j+1], &num_elements);
               tab_jeu_j1 = creer_tab_suivi_jeu(numbers[0], numbers[1]);
               tab_jeu_j2 = creer_tab_suivi_jeu(numbers[0], numbers[1]);
               hauteur = numbers[0];
               largeur = numbers[1];
               

               /* Don't forget to free the memory when you're done*/
               free(numbers);
            }

            else if (strcmp(trimmed_word,"Afficher")==0){
               display(hauteur,largeur,tab_jeu_j1,0);
               display(hauteur,largeur,tab_jeu_j2,0);
               printf("\n");
            }

            else if ((strcmp(trimmed_word,"J1")==0)||(strcmp(trimmed_word,"J2")==0)){

               if (strcmp(words[j+1],"P")==0){
                  int num_elements;
                  int *numbers=decomp_donnees(words[j+2],&num_elements);

                  bat0=creer_bateaux(words[j],numbers);
                  /*afficher_bateau(bat0);*/

                  if ((strcmp(trimmed_word,"J1")==0)){
                     placer_bateau(bat0,tab_jeu_j1,largeur);
                  } else {
                     placer_bateau(bat0,tab_jeu_j2,largeur);
                  }

                  free(numbers);
               }

               else if (strcmp(words[j+1],"T")==0){
                  int num_elements;
                  int *numbers=decomp_donnees(words[j+2],&num_elements);

                  if ((strcmp(trimmed_word,"J1")==0)){
                     result = tirer(numbers,tab_jeu_j2,largeur);
                     if (result==1){
                        vies_j2--;
                        if (vies_j2==0){
                           display(hauteur,largeur,tab_jeu_j1,1);
                           display(hauteur,largeur,tab_jeu_j2,1);
                           printf("J1 gagne !\n");
                           return 0;
                        }
                     }
                  } else {
                     result = tirer(numbers,tab_jeu_j1,largeur);
                     if (result==1){
                        vies_j1--;
                        if (vies_j1==0){
                           display(hauteur,largeur,tab_jeu_j1,1);
                           display(hauteur,largeur,tab_jeu_j2,1);
                           printf("J2 gagne !");
                           return 0;
                        }
                     }
                  }
                  
                  free(numbers);
               }
            }

            else if (strcmp(words[j],"Jouer")==0){
               continue;
            }

         }
      }
      free(tab_jeu_j1);
      free(tab_jeu_j2);
      free(tampon);
      fclose(f);
   }

   return 0;
}