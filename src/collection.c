#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#include "../header/window.h"
#include "../header/carte.h"


int test_collec(){
  printf("test\n");
}

char * nom_carte = "../img/Carte_Leo.png";

/*
*/
int collection(SDL_Window * pWindow, SDL_Texture* img_Collec_BG, SDL_Renderer* renderer_collec, int* running){




  /* DECLARATION BG_CHOIX*/
  SDL_Surface* img_Planche_Collec_S = IMG_Load("../img/planche_collec.png");

  if(!img_Planche_Collec_S){
		fprintf(stderr, "Erreur à la création du texte ''img_Planche_Collec_S'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  //Déclaration image planche
  SDL_Texture* img_Planche_Collec_T = SDL_CreateTextureFromSurface(renderer_collec, img_Planche_Collec_S);
  SDL_FreeSurface(img_Planche_Collec_S); // on a la texture, plus besoin de l'image
  if(!img_Planche_Collec_T){
		fprintf(stderr, "Erreur à la création du rendu ''img_Planche_Collec_T'' : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  /* DECLARATION carte*/
  SDL_Surface* img_Carte_Leo_S = IMG_Load(nom_carte);

  if(!img_Carte_Leo_S){
		fprintf(stderr, "Erreur à la création du texte ''img_Carte_Leo_S'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  //Déclaration image carte
  SDL_Texture* img_Carte_Leo_T = SDL_CreateTextureFromSurface(renderer_collec, img_Carte_Leo_S);
  SDL_FreeSurface(img_Carte_Leo_S); // on a la texture, plus besoin de l'image
  if(!img_Carte_Leo_T){
		fprintf(stderr, "Erreur à la création du rendu ''img_Carte_Leo_T'' : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  //Déclaration de la zone dans laquelle vont être listées les cartes
  SDL_Rect planche_R;
	planche_R.x=10;
	planche_R.y=10;
	planche_R.w=800;
	planche_R.h=1000;


  //Déclaration des rectangles dans lesquels vont être stockées les cartes

  SDL_Rect nom_carte1;
	nom_carte1.x=10;
	nom_carte1.y=10;
	nom_carte1.w=800;
	nom_carte1.h=1000;

  SDL_Rect nom_carte2;
	nom_carte2.x=10;
	nom_carte2.y=10;
	nom_carte2.w=800;
	nom_carte2.h=1000;

  SDL_Rect nom_carte3;
	nom_carte3.x=30;
	nom_carte3.y=30;
	nom_carte3.w=800;
	nom_carte3.h=3000;  
  
  SDL_Rect nom_carte4;
	nom_carte4.x=40;
	nom_carte4.y=40;
	nom_carte4.w=800;
	nom_carte4.h=4000;
  
  SDL_Rect nom_carte5;
	nom_carte5.x=50;
	nom_carte5.y=50;
	nom_carte5.w=800;
	nom_carte5.h=1000;  
  
  SDL_Rect nom_carte6;
	nom_carte6.x=60;
	nom_carte6.y=60;
	nom_carte6.w=800;
	nom_carte6.h=1000;

  SDL_Rect nom_carte7;
	nom_carte7.x=70;
	nom_carte7.y=70;
	nom_carte7.w=800;
	nom_carte7.h=1000;  
  
  SDL_Rect nom_carte8;
	nom_carte8.x=80;
	nom_carte8.y=80;
	nom_carte8.w=800;
	nom_carte8.h=8000;
  
  SDL_Rect nom_carte8;
	nom_carte8.x=10;
	nom_carte8.y=10;
	nom_carte8.w=800;
	nom_carte8.h=1000;

  SDL_Rect nom_carte9;
	nom_carte9.x=10;
	nom_carte9.y=10;
	nom_carte9.w=800;
	nom_carte9.h=1000;
  
  SDL_Rect nom_carte10;
	nom_carte10.x=10;
	nom_carte10.y=10;
	nom_carte10.w=800;
	nom_carte10.h=1000;

  SDL_Rect nom_carte11;
	nom_carte11.x=10;
	nom_carte11.y=10;
	nom_carte11.w=800;
	nom_carte11.h=1000;


  




  //Déclaration du rectangle dans lequel vont être listées les cartes
  SDL_Rect Carte_R;
	Carte_R.x=900;
	Carte_R.y=200;
	Carte_R.w=500;
	Carte_R.h=800;

  //Attention je l'ai placé ici, mais il faudra le déplacer pour faire ce qu'il doit faire
  SDL_SetRenderDrawColor(renderer_collec, 255, 255, 255, 255);
  //printf("Test2222\n\n\n\n");
  SDL_RenderClear(renderer_collec);

  SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
  SDL_RenderCopy(renderer_collec, img_Planche_Collec_T, NULL, &planche_R);
  SDL_RenderCopy(renderer_collec, img_Carte_Leo_T, NULL, &Carte_R);
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
/*


                  SDL_SetRenderDrawColor(renderer_collec, 255, 255, 255, 255);
                  //printf("Test2222\n\n\n\n");
                  SDL_RenderClear(renderer_collec);

                  SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
                  SDL_RenderCopy(renderer_collec, img_Planche_Collec_T, NULL, &planche_R);
                  //printf("test 2\n");
                  SDL_RenderPresent(renderer_collec);
                  //printf("test 3\n");
*/
                break;
              }

    				}
          }
        }
      }
























}
