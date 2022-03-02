#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"

//fonction de jeu en solo, a programmer : les méchaniques de jeu, le bot
void jeu_solo(SDL_Renderer* renderer_menu, SDL_Window * pWindow){ //a rajouter : deck de la main
    //manipulations de renderer-------------------------------------------------------------------------------------------------------------------------------------------------------------
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
    //creation de texture à partir de surface
    SDL_Texture* img_jeu_Texture = SDL_CreateTextureFromSurface(renderer_jeu, img_jeu_Surface);
    SDL_FreeSurface(img_jeu_Surface); /* on a la texture, plus besoin de l'image */

	if(!img_jeu_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image ''CHOIX'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	




















	//gestion des evenements


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
              				SDL_SetRenderDrawColor(renderer_menu, 255, 255, 255, 255);
              				SDL_RenderClear(renderer_menu);

              				SDL_RenderCopy(renderer_menu, img_Menu_Texture, NULL, NULL);
              				SDL_RenderCopy(renderer_menu, img_Choix_Texture, NULL, NULL);
							//Render de toutes les options du menu principal
								//OPTION 1
								SDL_RenderCopy(renderer_menu, txt_optn1_T, NULL, &txt_optn1_R);

								//OPTION 2
								SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
								//OPTION 3
								SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
								//OPTION 4
								SDL_RenderCopy(renderer_menu, txt_optn4_T, NULL, &txt_optn4_R);
              			//On fait le rendu !
              			SDL_RenderPresent(renderer_menu);

            			break;
          }
        case SDL_MOUSEBUTTONDOWN:
					printf("x: %i\ny: %i\n",e.button.x,e.button.y);
          if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
            //Si on clique sur le bouton 1

          }
					case SDL_MOUSEMOTION:
						//SOURIS QUI HOVER SUR LE BOUTON 1
						if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
							SDL_RenderCopy(renderer_menu, txt_optn1_Hover_T, NULL, &txt_optn1_R);
							SDL_RenderPresent(renderer_menu);
							//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
							oldHover=1;
						}
						//SOURIS QUI HOVER SUR LE BOUTON 2
						else if(e.button.x >= txt_optn2_R.x && e.button.x <= txt_optn2_R.x+txt_optn2_R.w && e.button.y >= txt_optn2_R.y && e.button.y <= txt_optn2_R.y+txt_optn2_R.h){
							SDL_RenderCopy(renderer_menu, txt_optn2_Hover_T, NULL, &txt_optn2_R);
							SDL_RenderPresent(renderer_menu);
							//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
							oldHover=1;
						}
						//SOURIS QUI HOVER SUR LE BOUTON 3
						else if(e.button.x >= txt_optn3_R.x && e.button.x <= txt_optn3_R.x+txt_optn3_R.w && e.button.y >= txt_optn3_R.y && e.button.y <= txt_optn3_R.y+txt_optn3_R.h){
							SDL_RenderCopy(renderer_menu, txt_optn3_Hover_T, NULL, &txt_optn3_R);
							SDL_RenderPresent(renderer_menu);
							//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
							oldHover=1;
						}
						//SOURIS QUI HOVER SUR LE BOUTON 4
						else if(e.button.x >= txt_optn4_R.x && e.button.x <= txt_optn4_R.x+txt_optn4_R.w && e.button.y >= txt_optn4_R.y && e.button.y <= txt_optn4_R.y+txt_optn4_R.h){
							// On clear le render, et on raffiche tout ici, car on modifie le texte du quitter qui devient noooo, sinon même chose que les autres detections 1/2/3
							SDL_RenderClear(renderer_menu);
							SDL_RenderCopy(renderer_menu, img_Menu_Texture, NULL, NULL);
							SDL_RenderCopy(renderer_menu, img_Choix_Texture, NULL, NULL);
							SDL_RenderCopy(renderer_menu, txt_optn1_T, NULL, &txt_optn1_R);
							SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
							SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
							SDL_RenderCopy(renderer_menu, txt_optn4_Hover_T, NULL, &txt_optn4_R);
							//On fait le rendu !
							SDL_RenderPresent(renderer_menu);
							//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
							oldHover=1;
						}
						//Si on a deja effectué des hovers
						else if(oldHover){
								SDL_RenderClear(renderer_menu);
								SDL_RenderCopy(renderer_menu, img_Menu_Texture, NULL, NULL);
	              SDL_RenderCopy(renderer_menu, img_Choix_Texture, NULL, NULL);
								//Render de toutes les options du menu principal
								//OPTION 1
								SDL_RenderCopy(renderer_menu, txt_optn1_T, NULL, &txt_optn1_R);

								//OPTION 2
								SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
								//OPTION 3
								SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
								//OPTION 4
								SDL_RenderCopy(renderer_menu, txt_optn4_T, NULL, &txt_optn4_R);
	              //On fait le rendu !
	              SDL_RenderPresent(renderer_menu);
								//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
								oldHover=0;
								printf("Reset actuel\n\n\n");
						}
        	break;
      }
    }
  }
} else {
  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
}
}