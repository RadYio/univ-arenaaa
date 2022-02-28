#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"

//fonction de jeu en solo, a programmer : les méchaniques de jeu, le bot
void jeu_solo(SDL_Renderer* renderer_menu, SDL_Window * pWindow){
    //manipulations de renderer--------------------------------------------------------------------------------------------------------------
    SDL_RenderClear(renderer_menu); //on arrete d'afficher tout ce qu'il est en lien avec le menu
    SDL_Renderer* renderer_jeu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //creation d'un nouveau renderer pour le jeu
    
    if(renderer_jeu == NULL){
		fprintf(stderr, "Erreur à la création du renderer de jeu\n");
		exit(EXIT_FAILURE);
	}
    
	/* DECLARATION BG_JEU*/
	SDL_Surface* img_jeu_Surface = IMG_Load("../img/BG_JEU.jpg");

	if(!img_jeu_Surface){
		fprintf(stderr, "Probleme chargement du background jeu: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
    //creation de tecture à partir de surface
    SDL_Texture* img_jeu_Texture = SDL_CreateTextureFromSurface(renderer_jeu, img_jeu_Surface);
    SDL_FreeSurface(img_jeu_Surface); /* on a la texture, plus besoin de l'image */

	if(!img_jeu_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image ''CHOIX'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

}