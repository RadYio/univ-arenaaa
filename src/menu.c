#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>




int menu(SDL_Window * pWindow){
  //mise en place graphique (possiblement a mettre dans une fonction/fichier séparé)--------------------------------------------------------
  SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //creation de renderer
  if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		return -1;
	}
  /* DECLARATION IMG*/
  SDL_Surface* img_Menu_Surface = IMG_Load("./menu.png");

  if(!img_Menu_Surface){
    fprintf(stderr, "importation de l'image de background impossible : %s\n", SDL_GetError());
    return -1;
  }

  SDL_Texture* img_Menu_Texture = SDL_CreateTextureFromSurface(renderer, img_Menu_Surface);

  if(!img_Menu_Texture){
    fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
    return -1;
  }


  SDL_FreeSurface(img_Menu_Surface); /* on a la texture, plus besoin de l'image */


}
