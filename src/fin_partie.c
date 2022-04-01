#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/carte.h"
#include "../header/collection.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/window.h"
#include "../header/affichage.h"
#include "../header/client.h"
#include "../header/init_jeu_solo.h"



/*void victoire(SDL_Renderer* renderer_jeu){
    SDL_Color couleurJaune = {255, 215, 0};
    SDL_Surface* txt_victoire = TTF_RenderUTF8_Blended(police, "Victoire !!", couleurJaune);
    affichage_victoire(renderer_jeu, txt_victoire);
}


void defaite(SDL_Renderer* renderer_jeu){
    SDL_Color couleurRouge = {255, 0, 0};
    SDL_Surface* txt_victoire = TTF_RenderUTF8_Blended(police, "Défaite...", couleurRouge);
    affichage_victoire(renderer_jeu, txt_victoire);
}


void affichage_victoire(SDL_Renderer* renderer_jeu, SDL_Surface* txt){
    //creation du rectangle d'affichage du texte
    SDL_Rect rect_txt = creer_rectangle(500, 250, 400, 600);
    //mise en place du texte sur l'ecran
    SDL_Texture* txt_victoire_t = SDL_CreateTextureFromSurface(renderer_jeu, txt_victoire);
    SDL_FreeSurface(txt);
    SDL_RenderCopy(renderer_jeu, txt_victoire_t, NULL, &rect_txt);
    SDL_DestroyTexture(txt_victoire_t);
}*/





              