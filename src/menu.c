#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"


typedef struct button_s{
	int x;
	int y;
	int hauteur;
	int largeur;
}button_t;

int menu(SDL_Window * pWindow){

  //initialisations de base------------------------------------------------------------------------------------------------------
  button_t button1;
	button1.x=20;
	button1.y=100;
	button1.hauteur=20;
	button1.largeur=100;

	// Variable de couleur
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Color couleurGold = {255, 215, 0};

	// Le pointeur vers notre police
	TTF_Font* police = NULL;


	//Le pointeur vers la fenetre
	//SDL_Window* pWindow = NULL;


	/* Création de la fenêtre */
	//pWindow = SDL_CreateWindow("univ-arenaaa",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	/* renderer */
	SDL_Renderer* renderer_menu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

	if(renderer_menu == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}


	/* DECLARATION BG_MENU*/
	SDL_Surface* img_Menu_Surface = IMG_Load("../img/BG_MENU.png");

	if(!img_Menu_Surface){
		fprintf(stderr, "Probleme chargement du background menu: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  SDL_Texture* img_Menu_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Menu_Surface);
  SDL_FreeSurface(img_Menu_Surface); /* on a la texture, plus besoin de l'image */

	if(!img_Menu_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image ''CHOIX'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}


  /* DECLARATION BG_CHOIX*/
	SDL_Surface* img_Choix_Surface = IMG_Load("../img/BG_CHOIX.png");

	if(!img_Menu_Surface){
		fprintf(stderr, "Probleme chargement du choix menu: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  SDL_Texture* img_Choix_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Choix_Surface);
  SDL_FreeSurface(img_Choix_Surface); /* on a la texture, plus besoin de l'image */

	if(!img_Menu_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image ''CHOIX'' : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  /* Initialisation TTF - POLICE */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Choix de la police */
	if((police = TTF_OpenFont("../font/ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}

	/*Surface du bouton jouer en solo*/
	SDL_Surface* txt_optn1_S = TTF_RenderUTF8_Blended(police, "JOUER EN SOLO", couleurNoire);
	SDL_Surface* txt_optn1_Hover_S = TTF_RenderUTF8_Blended(police, "JOUER EN SOLO", couleurGold);

	if(!txt_optn1_S || !txt_optn1_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 1 '': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Texture du bouton jouer en solo*/
	SDL_Texture *txt_optn1_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn1_S);
	SDL_Texture *txt_optn1_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn1_Hover_S);
	if(!txt_optn1_T || !txt_optn1_Hover_T){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(txt_optn1_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_optn1_Hover_S); /* on a la texture, plus besoin du texte via surface */

	SDL_Rect txt_optn1_R;
	txt_optn1_R.x=1015;
	txt_optn1_R.y=140;
	txt_optn1_R.w=265;
	txt_optn1_R.h=105;






	/*Surface du bouton jouer en multi*/
	SDL_Surface* txt_optn2_S = TTF_RenderUTF8_Blended(police, "JOUER EN LIGNE", couleurNoire);
	SDL_Surface* txt_optn2_Hover_S = TTF_RenderUTF8_Blended(police, "JOUER EN LIGNE", couleurGold);

	if(!txt_optn2_S || !txt_optn2_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 2'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Texture du bouton jouer en multi*/
	SDL_Texture *txt_optn2_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn2_S);
	SDL_Texture *txt_optn2_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn2_Hover_S);
	if(!txt_optn2_T || !txt_optn2_Hover_T){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(txt_optn2_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_optn2_Hover_S); /* on a la texture, plus besoin du texte via surface */

	SDL_Rect txt_optn2_R;
	txt_optn2_R.x=420;
	txt_optn2_R.y=275;
	txt_optn2_R.w=265;
	txt_optn2_R.h=105;




	/*Surface du bouton 3*/
	SDL_Surface* txt_optn3_S = TTF_RenderUTF8_Blended(police, "OPTION 3", couleurNoire);
	SDL_Surface* txt_optn3_Hover_S = TTF_RenderUTF8_Blended(police, "OPTION 3", couleurGold);

	if(!txt_optn3_S || !txt_optn3_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 3'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Texture du bouton jouer en multi*/
	SDL_Texture *txt_optn3_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn3_S);
	SDL_Texture *txt_optn3_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn3_Hover_S);
	if(!txt_optn3_T || !txt_optn3_Hover_T){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(txt_optn3_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_optn3_Hover_S); /* on a la texture, plus besoin du texte via surface */

	SDL_Rect txt_optn3_R;
	txt_optn3_R.x=1015;
	txt_optn3_R.y=410;
	txt_optn3_R.w=265;
	txt_optn3_R.h=105;




	/*Surface du bouton quitter*/
	SDL_Surface* txt_optn4_S = TTF_RenderUTF8_Blended(police, "QUITTER ?", couleurNoire);
	SDL_Surface* txt_optn4_Hover_S = TTF_RenderUTF8_Blended(police, "NOOOOOO !", couleurGold);

	if(!txt_optn4_S || !txt_optn4_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 4'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/*Texture du bouton jouer en multi*/
	SDL_Texture *txt_optn4_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn4_S);
	SDL_Texture *txt_optn4_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn4_Hover_S);
	if(!txt_optn4_T || !txt_optn4_T){
		fprintf(stderr, "Erreur à la création du rendu du texte : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(txt_optn4_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_optn4_Hover_S); /* on a la texture, plus besoin du texte via surface */

	SDL_Rect txt_optn4_R;
	txt_optn4_R.x=420;
	txt_optn4_R.y=545;
	txt_optn4_R.w=265;
	txt_optn4_R.h=105;

//récupération des données de sauvegarde (quelles cartes possède le joueur / quelles sont toutes les cartes qui existent)-------------------------------------------
	
	carte_t * tab_cartes_total[N]; //tableau qui repertorie toutes les cartes qui existent
	carte_t * tab_sauvegarde[N]; //tableau qui repertorie les cartes que possède le joueur
	init_cartes(tab_cartes_total);
	recup_sauvegarde(tab_sauvegarde, tab_cartes_total);

//gestion des evenements---------------------------------------------------------------------------------------------------------------------------------------------

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
							SDL_RenderCopy(renderer_menu, txt_optn1_Hover_T, NULL, &txt_optn1_R);
							//OPTION 2
							SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
							SDL_RenderCopy(renderer_menu, txt_optn2_Hover_T, NULL, &txt_optn2_R);
							//OPTION 3
							SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
							SDL_RenderCopy(renderer_menu, txt_optn3_Hover_T, NULL, &txt_optn3_R);
							//OPTION 4
							SDL_RenderCopy(renderer_menu, txt_optn4_T, NULL, &txt_optn4_R);
							SDL_RenderCopy(renderer_menu, txt_optn4_Hover_T, NULL, &txt_optn4_R);




              /* On fait le rendu ! */
              SDL_RenderPresent(renderer_menu);

            break;
          }
        case SDL_MOUSEBUTTONDOWN:

					printf("x: %i\ny: %i\n",e.button.x,e.button.y);
          if(e.button.x>=	button1.x && e.button.x<=button1.x+button1.largeur && e.button.y>=button1.y && e.button.y<=button1.y+button1.hauteur){
            //SDL_DestroyTexture(img_Choix_Texture);
						printf("T BG\n");
          }
        break;
      }
    }
  }
} else {
  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
}

//Destruction de la fenetre
SDL_DestroyWindow(pWindow);

TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
TTF_Quit();
  SDL_Quit();
  return 0;
}
