
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/tour.h"
#include "../header/affichages.h"
#include "../header/init_jeu_solo.h"



//fonction d'affichage du background
void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture){
  // Le fond de la fenêtre sera blanc
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);

  SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);
}

void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv){
  //creation de rectangle du joueur
  SDL_SetRenderDrawColor( renderer_jeu, 0, 213, 255, 255 ); //renderer passe en bleu pour le rectangle de la zone joueur
  SDL_RenderDrawRect(renderer_jeu, rect_joueur);

  //creation du rectangle de l'adversaire
  SDL_SetRenderDrawColor( renderer_jeu, 219, 0, 0, 255 ); //renderer passe en rouge pour le rectangle de la zone adversaire
  SDL_RenderDrawRect(renderer_jeu, rect_adv);
}

//fonction d'affichage des rectangles de la main
void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]){
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255); //on passe en jaune
  for(int i = 0; i < *taille_main; i++){
    SDL_RenderDrawRect(renderer_jeu, &tab_rect_main[i]);
  }
}



//affiche les cartes qu'il y a dans la main du joueur != cartes sur le plateau
void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, int tab_main[], SDL_Rect tab_rect_main[]){
    int i;
    for(i = 0; i < *taille_main; i++){

      afficher_carte(renderer_jeu, tab_main[i], tab_rect_main[i]);
    }
}


//fonction d'affichage d'une carte dans un rectangle donné
void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher){
  SDL_Surface* carte_s;
  SDL_Texture* carte_t;
  switch(carte){
    case -1 : break; //s'il n'y à aucune carte
    case 0 : carte_s = IMG_Load("../img/img_cartes/carte0.png"); break;
    case 1 : carte_s = IMG_Load("../img/img_cartes/carte1.png"); break;
    case 2 : carte_s = IMG_Load("../img/img_cartes/carte2.png"); break;
    case 3 : carte_s = IMG_Load("../img/img_cartes/carte3.png"); break;
    case 4 : carte_s = IMG_Load("../img/img_cartes/carte4.png"); break;
    case 5 : carte_s = IMG_Load("../img/img_cartes/carte5.png"); break;
    case 6 : carte_s = IMG_Load("../img/img_cartes/carte6.png"); break;
    case 7 : carte_s = IMG_Load("../img/img_cartes/carte7.png"); break;
    case 8 : carte_s = IMG_Load("../img/img_cartes/carte8.png"); break;
    case 9 : carte_s = IMG_Load("../img/img_cartes/carte9.png"); break;
    case 10 : carte_s = IMG_Load("../img/img_cartes/carte10.png"); break;
    case 11 : carte_s = IMG_Load("../img/img_cartes/carte11.png"); break;
    case 12 : carte_s = IMG_Load("../img/img_cartes/carte12.png"); break;
  }
    carte_t = SDL_CreateTextureFromSurface(renderer_jeu, carte_s);
    SDL_FreeSurface(carte_s);
    SDL_RenderCopy(renderer_jeu, carte_t, NULL, &rect_afficher);
}



//fonction d'affichage des rectangles de formation
void afficher_rectangles_formation(SDL_Renderer* renderer_jeu, int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[15]){
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
        afficher_carte(renderer_jeu,tab_formation_cartesJ[x][y],tab_rect_formationJ[i]) ;
      }
      if(tab_formation_cartesADV[x][2-y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[i]);
      }
      else if(tab_formation_cartesADV[x][2-y] == -1) {
      }
      else{
        afficher_carte(renderer_jeu,tab_formation_cartesADV[x][2-y],tab_rect_formationAdv[i]) ;
      }
    }
}


void affichage_jeu (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect *rect_txt_deck_j,SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[15],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[15] , int * taille_main, SDL_Rect tab_rect_main[12],int tab_main[]){

    SDL_RenderClear(renderer_jeu);



    affichage_BG(renderer_jeu, img_jeu_Texture);
    printf("test 1 \n");



    affichage_gros_rectangles(renderer_jeu, rect_joueur, rect_adv);

    afficher_rectangles_formation(renderer_jeu, tab_formation_cartesJ, tab_rect_formationJ, tab_formation_cartesADV, tab_rect_formationAdv);


    afficher_rectangles_main(taille_main,renderer_jeu, tab_rect_main);

    affichage_main(taille_main,renderer_jeu, tab_main, tab_rect_main);

    //On fait le rendu !
    SDL_RenderPresent(renderer_jeu);
}

//a mettre dans fichier séparé
void supprimer_carte_tab(int tab_main[], int indice_main, int* taille_main){
  for(int i = indice_main - 1; i < *taille_main - 1; i++){
    tab_main[i] = tab_main[i+1];
  }
}

//a mettre dans fichier séparé
void suppression_carte_main(int tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main){
  //suppression de la carte dans tab_main
  (*taille_main)--;
  supprimer_carte_tab(tab_main, indice_main, taille_main);
  //mise à jour des rectangles
  creation_main(taille_main, tab_rect_main);
}



//fonction qui tranfère une carte de la main du joueur sur le plateau                       //MAJ               //MAJ                                                                                              
void transfert_carte(SDL_Renderer* renderer_jeu, SDL_Rect rect_plateau, int tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main){
  //mises à jour des tableaux
  if(tab_formation_cartesJ[colone][ligne] == -2){ //si on peut placer une carte (-2 représente un endroit où on peut)
    //mise à jour de notre formation,on remplace le -2 par l'id de la carte
    tab_formation_cartesJ[colone][ligne] = tab_main[indice_main]; 
    //mise à jour de notre main, on supprime la carte en question, et on arrete de l'afficher dans la main ainsi que son rectangle avec
    suppression_carte_main(tab_main, indice_main, tab_rect_main, taille_main); 
  }
}