
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/tour.h"
#include "../header/affichages.h"


//fonction d'affichage d'une carte dans un rectangle donné
extern void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher){
  SDL_Surface* carte_s;
  SDL_Texture* carte_t;
  printf("BBBBBBBBBBBBBB\n");
  switch(carte){
    case 0 : carte_s = IMG_Load("../img/img_cartes/carte0.png"); break;
    case 1 : carte_s = IMG_Load("../img/img_cartes/carte1.png"); break;
    case 2 : carte_s = IMG_Load("../img/img_cartes/carte2.png"); break;
    case 3 : carte_s = IMG_Load("../img/img_cartes/carte3.png"); printf("CCCCCCCCCCCCCCCCCCC\n"); break;
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

