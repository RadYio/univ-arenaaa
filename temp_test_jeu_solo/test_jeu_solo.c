#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"

//creation de la matrice où sera placé les cartes et qui servira pour savoir quoi afficher et ou. ici -1 correspond à une case
//vide, -2 représente une case où on peut mettre une carte mais où y'a rien dedans encore, ici on est en formation 3-2-1
int tab_formation_cartes[5][3] = {
    {-2, -1, -1},
    {-1, -2, -1},
    {-2, -1, -2},
    {-1, -2, -1},
    {-2, -1, -1}};
//à modifier : faire une fonction de choix de formation (si y'a le time) et passer ce tableau en parametre à jeu_solo



void main(){
    initialiser_fenetre();
}


//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//focntion de creation d'un rectangle prcq sinon ca va devenir le cancer a devoir déclarer 30 rectangles avec 150 lignes rien que pour ca
SDL_Rect create_rectangle(int x, int y, int w, int h){
    SDL_Rect rect_temp;
    rect_temp.x = x;
    rect_temp.y = y;
    rect_temp.w = w;
    rect_temp.h = h;
    return rect_temp;
}

//fonction de jeu en solo, a programmer : les méchaniques de jeu, le bot
void jeu_solo(SDL_Window * pWindow){ //a rajouter : deck de la main, TTF_FONT à passer en parametre pour etre utilisé ici
    //déclarations de variables, choses à utiliser plus tard dans le code---------------------------------------------------------------------------------------------------------------------

    SDL_Color couleurJaune = {255, 215, 0};

    TTF_Font* police = NULL;

    SDL_Renderer* renderer_jeu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //creation d'un nouveau renderer pour le jeu
    
    if(renderer_jeu == NULL){
		fprintf(stderr, "Erreur à la création du renderer de jeu\n");
		exit(EXIT_FAILURE);
	}

    //creation de rectangles pour les zones d'affichage-------------------------------------------------------------

    //creation du rectangle pour la zone joueur
    SDL_Rect rect_joueur = create_rectangle(100, 75, 600, 750);

    //creation du rectangle pour la zone adversaire
    SDL_Rect rect_adv = create_rectangle(900, 75, 600, 750);

    //creation du rectangle pour le texte de deck du joueur
    SDL_Rect rect_txt_deck_j = create_rectangle(300, 20, 200, 50);

    //creation du rectangle pour le texte de deck de l'adversaire
    SDL_Rect rect_txt_deck_adv = create_rectangle(1060, 20, 300, 50);

    //a rajouter: les rectangles pour les postitions des cartes


    //manipulations de renderer-------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    //SDL_RenderClear(renderer_menu); //on arrete d'afficher tout ce qu'il est en lien avec le menu
    
	/* DECLARATION BG_JEU*/
	SDL_Surface* img_jeu_Surface = IMG_Load("../img/BG_JEU.png");

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


    //manipulations de TTF-----------------------------------------------------------------------------------------------------------------------------------------------------

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

    SDL_Surface* txt_titre_joueur = TTF_RenderUTF8_Blended(police, "- - - TON  DECK  :) - - -", couleurJaune); //surface pour le texte du joueur
    SDL_Surface* txt_titre_adv = TTF_RenderUTF8_Blended(police, "- - -DECK  ADVERSAIRE  :( - - -", couleurJaune); //surface pour le texte adversaire

    if(!txt_titre_joueur|| !txt_titre_adv){
		fprintf(stderr, "Erreur à la création du texte '' titre de deck '': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

    /*Texture des titres de deck*/
	SDL_Texture *txt_titre_joueur_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_titre_joueur);
	SDL_Texture *txt_titre_adv_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_titre_adv);
	if(!txt_titre_joueur_T || !txt_titre_adv_T){
		fprintf(stderr, "Erreur à la création du rendu du texte de deck: %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_FreeSurface(txt_titre_joueur); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_titre_adv); /* on a la texture, plus besoin du texte via surface */



    //affichage de base : toutes les choses ici resteront constantes peu importe ce qu'il arrive sur le plateau------------------------------------------------------------

    // Le fond de la fenêtre sera blanc
    SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);
    SDL_RenderClear(renderer_jeu);

    SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);

    //creation texte de deck 
    SDL_RenderCopy(renderer_jeu, txt_titre_joueur_T, NULL, &rect_txt_deck_j);
    SDL_RenderCopy(renderer_jeu, txt_titre_adv_T, NULL, &rect_txt_deck_adv);
                            
    //creation de rectangle du joueur
    SDL_SetRenderDrawColor( renderer_jeu, 0, 213, 255, 255 ); //renderer passe en bleu pour le rectangle de la zone joueur
    SDL_RenderDrawRect(renderer_jeu, &rect_joueur);

    //creation du rectangle de l'adversaire
    SDL_SetRenderDrawColor( renderer_jeu, 219, 0, 0, 255 ); //renderer passe en rouge pour le rectangle de la zone adversaire
    SDL_RenderDrawRect(renderer_jeu, &rect_adv);
    //On fait le rendu !
    SDL_RenderPresent(renderer_jeu);

    


    //jeu lui meme, mettre gestion des evenements ici----------------------------------------------------------------------------------------------------------------------------
    
    if(pWindow){
        int running = 1;
        while(running) {
            SDL_Event e;
            while(SDL_PollEvent(&e)) {
                switch(e.type) {
                    case SDL_QUIT: running = 0;
                    break;

                }
            }
        }
    }





    //à la fin du jeu------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //Destruction de la fenetre
    SDL_DestroyWindow(pWindow);
    //A SUPPRIMER--------------------------------------------------------------------------------------------------------
    TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
    TTF_Quit();
}


//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//code a tester----------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int initialiser_fenetre(){
  //initialisation de SDL---------------------------------------------------------------
  if(SDL_Init(SDL_INIT_VIDEO) != 0){
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      return -1;
  }

    //creation de la fenetre-------------------------------------------------------------
    SDL_Window* pWindow = NULL;
    pWindow = SDL_CreateWindow(
      "UnivArena", //nom fenetre
      SDL_WINDOWPOS_CENTERED, //x fenetre centré
      SDL_WINDOWPOS_CENTERED, //y fenetre centré
      1600, //largeur fenetre
      900, //hauteur fenetre, deux valeurs à modifier potentiellement, a voir avec redimensionnement de la fenetre
      SDL_WINDOW_SHOWN
    );

    if(pWindow){
      //lancement du jeu si fenetre bien crée-------------------------------------------------
      jeu_solo(pWindow); //on transmet le pointeur de la fenetre pour des utilisations antétieures
      SDL_DestroyWindow(pWindow);
    }
    else{
      printf("erreur de creation de fenetre\n");
      return -1;
    }


    
  SDL_Quit();
}


