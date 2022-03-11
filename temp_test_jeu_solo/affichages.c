
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
//#include "../header/tour.h"
#include "../header/affichages.h"

//fonction d'affichage du background
void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture){
  // Le fond de la fenêtre sera blanc
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);

  SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);
}


//fonction d'affichages des textes au dessus des 2 grands rectangles
void affichage_texte(SDL_Renderer* renderer_jeu, SDL_Rect* rect_txt_deck_j, SDL_Texture* txt_titre_joueur_T, SDL_Rect* rect_txt_deck_adv, SDL_Texture* txt_titre_adv_T){
  //creation texte de deck
    SDL_RenderCopy(renderer_jeu, txt_titre_joueur_T, NULL, rect_txt_deck_j);
    SDL_RenderCopy(renderer_jeu, txt_titre_adv_T, NULL, rect_txt_deck_adv);
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
void afficher_rectangles_main(int taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]){
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255); //on passe en jaune
  for(int i = 0; i < taille_main; i++){
    SDL_RenderDrawRect(renderer_jeu, &tab_rect_main[i]);
  }
}



//affiche les cartes qu'il y a dans la main du joueur != cartes sur le plateau
void affichage_main(int taille_main,SDL_Renderer* renderer_jeu, int deck_main[], SDL_Rect tab_rect_main[12]){
    int i;
    for(i = 0; i < taille_main; i++){
      printf("i = %i\n", i);
        afficher_carte(renderer_jeu, deck_main[i], tab_rect_main[i]);
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
  
  
    //on va parcourir les 2 matrices de formation, et là où il y à un -2, on affichera un rectangle
    //à mettre dans une fonction séparé car long et moche :(
    //affichage colone 1 joueur
    if(tab_formation_cartesJ[0][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[0]); 
    if(tab_formation_cartesJ[1][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[1]);
    if(tab_formation_cartesJ[2][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[2]);
    if(tab_formation_cartesJ[3][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[3]);
    if(tab_formation_cartesJ[4][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[4]);
    //affichage colone 2 joueur
    if(tab_formation_cartesJ[0][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[5]);
    if(tab_formation_cartesJ[1][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[6]);
    if(tab_formation_cartesJ[2][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[7]);
    if(tab_formation_cartesJ[3][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[8]);
    if(tab_formation_cartesJ[4][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[9]);
    //affichage colone 3 joueur
    if(tab_formation_cartesJ[0][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[10]);
    if(tab_formation_cartesJ[1][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[11]);
    if(tab_formation_cartesJ[2][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[12]);
    if(tab_formation_cartesJ[3][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[13]);
    if(tab_formation_cartesJ[4][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[14]);

    //affichage colone 1 adversaire
    if(tab_formation_cartesADV[0][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[0]);
    if(tab_formation_cartesADV[1][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[1]);
    if(tab_formation_cartesADV[2][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[2]);
    if(tab_formation_cartesADV[3][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[3]);
    if(tab_formation_cartesADV[4][2] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[4]);
    //affichage colone 2 adversaire
    if(tab_formation_cartesADV[0][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[5]);
    if(tab_formation_cartesADV[1][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[6]);
    if(tab_formation_cartesADV[2][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[7]);
    if(tab_formation_cartesADV[3][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[8]);
    if(tab_formation_cartesADV[4][1] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[9]);
    //affichage colone 3 adversaire
    if(tab_formation_cartesADV[0][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[10]);
    if(tab_formation_cartesADV[1][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[11]);
    if(tab_formation_cartesADV[2][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[12]);
    if(tab_formation_cartesADV[3][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[13]);
    if(tab_formation_cartesADV[4][0] == -2) SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[14]);
}
