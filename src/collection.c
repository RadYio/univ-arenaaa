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
int collection(SDL_Window * pWindow, SDL_Texture* img_Collec_BG, SDL_Renderer* renderer_collec, int* running){




  /* DECLARATION BG_CHOIX*/
  SDL_Surface* img_Planche_Collec_S = IMG_Load("../img/planche_collec.png");

  if(!img_Planche_Collec_S){
		fprintf(stderr, "Erreur à la création du texte ''img_Planche_Collec_S'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


  SDL_Texture* img_Planche_Collec_T = SDL_CreateTextureFromSurface(renderer_collec, img_Planche_Collec_S);
  SDL_FreeSurface(img_Planche_Collec_S); // on a la texture, plus besoin de l'image
  if(!img_Planche_Collec_T){
		fprintf(stderr, "Erreur à la création du rendu ''img_Planche_Collec_T'' : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


  //Attention je l'ai placé ici, mais il faudra le déplacer pour faire ce qu'il doit faire
  SDL_SetRenderDrawColor(renderer_collec, 255, 255, 255, 255);
  //printf("Test2222\n\n\n\n");
  SDL_RenderClear(renderer_collec);

  SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
  SDL_RenderCopy(renderer_collec, img_Planche_Collec_T, NULL, NULL);
  //printf("test 2\n");
  SDL_RenderPresent(renderer_collec);
  //printf("test 3\n");


    if(pWindow){
      while(*running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
          switch(e.type){
            case SDL_QUIT: *running = 0;
            break;
            case SDL_WINDOWEVENT:
              switch(e.window.event){
                case SDL_WINDOWEVENT_EXPOSED:
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                case SDL_WINDOWEVENT_RESIZED:
                case SDL_WINDOWEVENT_SHOWN:



                  SDL_SetRenderDrawColor(renderer_collec, 255, 255, 255, 255);
                  //printf("Test2222\n\n\n\n");
                  SDL_RenderClear(renderer_collec);

                  SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
                  SDL_RenderCopy(renderer_collec, img_Planche_Collec_T, NULL, NULL);
                  //printf("test 2\n");
                  SDL_RenderPresent(renderer_collec);
                  //printf("test 3\n");

                break;
              }

    				}
          }
        }
      }
























}
