#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "../header/window.h"
#include "../header/carte.h"


int test_collec(){
  printf("test\n");
}


/*
*/
int collection(SDL_Window * pWindow,SDL_Texture* img_Collec_Texture){


	SDL_Renderer* renderer_collec = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);



	if(!img_Collec_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image ''CHOIX'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  /* DECLARATION BG_CHOIX*/
  SDL_Surface* img_Planche_Collec = IMG_Load("../img/planche_collec.png");


  SDL_Texture* img_Planche_Texture = SDL_CreateTextureFromSurface(renderer_collec, img_Planche_Collec);
  SDL_FreeSurface(img_Planche_Collec); /* on a la texture, plus besoin de l'image */



    if(pWindow){
      int running = 1;
      while(running) {
        SDL_Event e;
        while(SDL_PollEvent(&e)) {
          switch(e.type) {
            case SDL_QUIT: running = 0;
            break;
            case SDL_WINDOWEVENT:
              switch(e.window.event){
                case SDL_WINDOWEVENT_EXPOSED:
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                case SDL_WINDOWEVENT_RESIZED:
                case SDL_WINDOWEVENT_SHOWN:


                  // Le fond de la fenêtre sera blanc
                  SDL_SetRenderDrawColor(renderer_collec, 255, 255, 255, 255);
                  SDL_RenderClear(renderer_collec);

                  SDL_RenderCopy(renderer_collec, img_Collec_Texture, NULL, NULL);
                  SDL_RenderCopy(renderer_collec, img_Planche_Texture, NULL, NULL);
                  printf("test 2\n");
                  SDL_RenderPresent(renderer_collec);
                  printf("test 3\n");

                break;
              }

    				}
          }
        }
      }
























}
