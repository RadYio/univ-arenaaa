
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/affichage.h"
#include "../header/init_jeu_solo.h"



//fonction d'affichage du background
void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture){
  // Le fond de la fenêtre sera blanc
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);

  SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);
}

void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j){
  //creation de rectangle du joueur
  SDL_SetRenderDrawColor( renderer_jeu, 0, 213, 255, 255 ); //renderer passe en bleu pour le rectangle de la zone joueur
  SDL_RenderDrawRect(renderer_jeu, rect_joueur);

  //creation du rectangle de l'adversaire
  SDL_SetRenderDrawColor( renderer_jeu, 219, 0, 0, 255 ); //renderer passe en rouge pour le rectangle de la zone adversaire
  SDL_RenderDrawRect(renderer_jeu, rect_adv);

  SDL_SetRenderDrawColor( renderer_jeu, 0, 219, 0, 255 ); //renderer passe en vert pour le rectangle de la zone adversaire
  SDL_RenderDrawRect(renderer_jeu, rect_aff_carte_j);
}

//fonction d'affichage des rectangles de la main
void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]){
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255); //on passe en jaune
  for(int i = 0; i < *taille_main; i++){
    SDL_RenderDrawRect(renderer_jeu, &tab_rect_main[i]);
  }
}



//affiche les cartes qu'il y a dans la main du joueur != cartes sur le plateau
void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[]){
    int i;
    for(i = 0; i < *taille_main; i++){

      affichage_carte(renderer_jeu, tab_main[i], tab_rect_main[i]);
    }
}



void affichage_carte(SDL_Renderer* renderer_jeu,carte_t carte,SDL_Rect rect_afficher){
  SDL_Surface* carte_s;
  SDL_Texture* carte_t;
  carte_s = IMG_Load(carte.chemin_carte);
  carte_t = SDL_CreateTextureFromSurface(renderer_jeu, carte_s);
  SDL_FreeSurface(carte_s);
  SDL_RenderCopy(renderer_jeu, carte_t, NULL, &rect_afficher);
}


//fonction d'affichage des rectangles de formation
void afficher_rectangles_formation(SDL_Renderer* renderer_jeu,carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[15]){
  //creation des rectangles pour les lieux de placement des cartes
    SDL_SetRenderDrawColor(renderer_jeu, 255, 215, 0, 255); //renderer passe en jaune pour ces rectangles
    int x=0,y=0;
  
    //on va parcourir les 2 matrices de formation, et là où il y à un -2, on affichera un rectangle
    //à mettre dans une fonction séparé car long et moche :(
    //affichage colone 1 joueur
    for(int i=0; i < 15;i++){
      if(x == 4 && y < 2)y++;
      x =  i%5;
      if(tab_formation_cartesJ[x][y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[i]);
      }
      else if(tab_formation_cartesJ[x][y] == -1) {
      }
      else {
        printf("id : %i \n",tab_formation_cartesJ[x][y]);
        affichage_carte(renderer_jeu,tab_cartes_total[ (tab_formation_cartesJ[x][y]) ],tab_rect_formationJ[i]) ;
      }
      if(tab_formation_cartesADV[x][2-y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[i]);
      }
      else if(tab_formation_cartesADV[x][2-y] == -1) {
      }
      else{
        affichage_carte(renderer_jeu,tab_cartes_total[(tab_formation_cartesADV[x][2-y])],tab_rect_formationAdv[i]) ;
      }
    }
}


void affichage_jeu (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[15],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[15] , int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[]){

    SDL_RenderClear(renderer_jeu);



    affichage_BG(renderer_jeu, img_jeu_Texture);



    affichage_gros_rectangles(renderer_jeu, rect_joueur, rect_adv,rect_aff_carte_j);

    afficher_rectangles_formation(renderer_jeu,tab_cartes_total,tab_formation_cartesJ, tab_rect_formationJ, tab_formation_cartesADV, tab_rect_formationAdv);


    afficher_rectangles_main(taille_main,renderer_jeu, tab_rect_main);

    affichage_main(taille_main,renderer_jeu, tab_main, tab_rect_main);

    //On fait le rendu !
    SDL_RenderPresent(renderer_jeu);
}

//a mettre dans fichier séparé
void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main){
  for(int i = indice_main - 1; i < *taille_main; i++){
    tab_main[i] = tab_main[i+1];
  }
}

//a mettre dans fichier séparé
void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main){
  //suppression de la carte dans tab_main
  (*taille_main)--;
  supprimer_carte_tab(tab_main, indice_main, taille_main);
  //mise à jour des rectangles
  creation_main(taille_main, tab_rect_main);
}



//fonction qui tranfère une carte de la main du joueur sur le plateau                       //MAJ               //MAJ                                                                                              
void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main){
  //mises à jour des tableaux
  if(tab_formation_cartesJ[colone][ligne] == -2){ //si on peut placer une carte (-2 représente un endroit où on peut)
    //mise à jour de notre formation,on remplace le -2 par l'id de la carte
    printf("nb 1 %i\n",tab_formation_cartesJ[colone][ligne]);
    tab_formation_cartesJ[colone][ligne] = tab_main[indice_main].id_image; 
    printf("nb 2 %i\n",tab_formation_cartesJ[colone][ligne]);

    //mise à jour de notre main, on supprime la carte en question, et on arrete de l'afficher dans la main ainsi que son rectangle avec
    suppression_carte_main(tab_main, indice_main, tab_rect_main, taille_main); 
  }
}