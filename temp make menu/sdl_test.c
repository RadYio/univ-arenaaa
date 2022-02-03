#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


typedef struct button_s{
	int x;
	int y;
	int hauteur;
	int largeur;
}button_t;




int main(int argc, char** argv)
{
	button_t button1;
	button1.x=20;
	button1.y=100;
	button1.hauteur=20;
	button1.largeur=100;

	// Variable de couleur
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};

	// Le pointeur vers notre police
	TTF_Font *police = NULL;


	//Le pointeur vers la fenetre
	SDL_Window* pWindow = NULL;


	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("univ-arenaaa",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1600, 900, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

	/* renderer */
	SDL_Renderer* renderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}


	/* DECLARATION IMG*/
	SDL_Surface* img_Menu_Surface = IMG_Load("./menu.png");

	if(!img_Menu_Surface){
		fprintf(stderr, "WOLA C CHO : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture* img_Menu_Texture = SDL_CreateTextureFromSurface(renderer, img_Menu_Surface);

	if(!img_Menu_Texture){
		fprintf(stderr, "Erreur à la création du rendu de l'image : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}



	SDL_FreeSurface(img_Menu_Surface); /* on a la texture, plus besoin de l'image */


	/* Initialisation simple */
	if (SDL_Init(SDL_INIT_VIDEO) != 0 ) {
			fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
			return -1;
	}

	/* Initialisation TTF - POLICE */
	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Choix de la police */
	if((police = TTF_OpenFont("ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}







	if(renderer == NULL){
		fprintf(stderr, "Erreur à la création du renderer\n");
		exit(EXIT_FAILURE);
	}

	if(!pWindow){
		fprintf(stderr, "Erreur à la création de la fenetre : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}





























	if( pWindow )
	{
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
								/* Le fond de la fenêtre sera blanc */
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
								SDL_RenderClear(renderer);

								SDL_RenderCopy(renderer, img_Menu_Texture, NULL, NULL);




                /* On fait le rendu ! */
                SDL_RenderPresent(renderer);

							break;
						}
					case SDL_MOUSEBUTTONDOWN:
						printf("x: %i\ny: %i\n",e.button.x,e.button.y);
						if(e.button.x>=button1.x && e.button.x<=button1.x+button1.largeur && e.button.y>=button1.y && e.button.y<=button1.y+button1.hauteur){
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
