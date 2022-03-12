#include "../header/window.h"
#include "../header/carte.h"
#include "../header/tour.h"
#include "../header/affichages.h"
#include "../header/init_jeu_solo.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>

//---------------------------------------------NE PAS OUBLIER LES FREE APRES LES MALLOC !!!!!!!!!!!!!!!!!!!!!!!!!--------------------------------------------------------------




//tableau de la main du joueur, à passer en parametre au lieu de déclarer ici
int tab_main[12] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};



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



//fonction de jeu en solo, a programmer : les méchaniques de jeu, le bot
void jeu_solo(SDL_Window * pWindow, int tab_main[]){ //a rajouter : deck de la main, TTF_FONT à passer en parametre pour etre utilisé ici
    int* taille_main = malloc(sizeof(int));
    *taille_main = 6;
    //creation de la matrice où sera placé les cartes et qui servira pour savoir quoi afficher et ou. ici -1 correspond à une case
  //vide, -2 représente une case où on peut mettre une carte mais où y'a rien dedans encore, ici on est en formation 3-2-1, idem pour l'adversaire
  int tab_formation_cartesJ[5][3] = { //ceci est le tableau du joueur
    {-2, -1, -1},
    {-1, -2, -1},
    {-2, -1, -2},
    {-1, -2, -1},
    {-2, -1, -1}};

int tab_formation_cartesADV[5][3] = { //ceci est le tableau de l'adversaire
    {-1, -1, -2},
    {-1, -2, -1},
    {-2, -1, -2},
    {-1, -2, -1},
    {-1, -1, -2}};
//à modifier : faire une fonction de choix de formation (si y'a le time) et passer ce tableau en parametre à jeu_solo
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //déclarations--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    
    
    //declarations de variables, renderer etc-------------------------------------------------------------------------------------------
    SDL_Color couleurJaune = {255, 215, 0};

    TTF_Font* police = NULL;

    SDL_Renderer* renderer_jeu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //creation d'un nouveau renderer pour le jeu

    if(renderer_jeu == NULL){
		fprintf(stderr, "Erreur à la création du renderer de jeu\n");
		exit(EXIT_FAILURE);
	}


    //declarations des tableaux de rectangles-------------------------------------------------------------------------------------------
    SDL_Rect tab_rect_formationJ[15];
    SDL_Rect tab_rect_formationAdv[15];
    SDL_Rect tab_rect_main[*taille_main];

    
    //déclarations de rectangles individuels, des gros rectangles qui n'ont pas d'équivalents et donc pas besoin de tableau-------------------
    //creation du rectangle pour la zone joueur
    SDL_Rect* rect_joueur = malloc(sizeof(SDL_Rect));

    //creation du rectangle pour la zone adversaire
    SDL_Rect* rect_adv = malloc(sizeof(SDL_Rect));

    //creation du rectangle pour le texte de deck du joueur
    SDL_Rect* rect_txt_deck_j = malloc(sizeof(SDL_Rect));

    //creation du rectangle pour le texte de deck de l'adversaire
    SDL_Rect* rect_txt_deck_adv = malloc(sizeof(SDL_Rect));



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



  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //maniupulations----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    

  //manipulations de renderer-------------------------------------------------------------------------------------------------------------------------------------------------------------

  //SDL_RenderClear(renderer_menu); //on arrete d'afficher tout ce qu'il est en lien avec le menu

	


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



    //initialisation des rectangles--------------------------------------------------------------------------------------------------------------------------------------------------------
    init_jeu(taille_main,tab_rect_formationJ ,tab_rect_formationAdv, tab_rect_main, rect_joueur, rect_adv, rect_txt_deck_j, rect_txt_deck_adv);

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //affichage de base : le jeu apparaitra comme ceci au debut, s'en suivra les modifs nécessaires par la suite---------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);
    //affichage_texte(renderer_jeu, rect_txt_deck_j, txt_titre_joueur_T, rect_txt_deck_adv, txt_titre_adv_T);

    SDL_RenderCopy(renderer_jeu, txt_titre_joueur_T, NULL, rect_txt_deck_j);
    printf("test 3 \n");
    SDL_RenderCopy(renderer_jeu, txt_titre_adv_T, NULL, rect_txt_deck_adv);
    printf("test 2\n");


    //on joue un tour, si victoire joueur/adversaire tour renvoi 1 ou -1, 0 si on continue à jouer------------------------------------------------------------------------------------------------------------------------------------------------------------
    //tour(renderer_jeu, pWindow, tab_rect_main, tab_formation_cartesJ, tab_rect_formationJ, tab_main, taille_main);
    int etat = 0;
    if(pWindow){
      int *running ;
      *running = 1;
      while(*running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
          switch(e.type){
            case SDL_QUIT : running = 0;
            break;
            case SDL_MOUSEBUTTONDOWN:
              //tour(running,renderer_jeu, pWindow, tab_rect_main, tab_formation_cartesJ, tab_rect_formationJ, tab_main, taille_main);
              printf("\ntest nouvelle action\n\n");
              //affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);
              //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
              //gestion des cartes dans la main---------------------------------------------------------------------------------------------------------------------------------------------------------------
              //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
              printf("\netat avant = %i\n\n",etat);                     
              
              if(etat == 0){
                  int x = 0,y=0;
                  for(int i=0;i < 15;i++){
                    if(x == 4 && y < 2) y++;
                    x = i%5;
                    printf("[%i][%i] eme essai \n",x,y);
                    //cas ou on clique sur une des 10 cartes de la main
                    if(i <= 10 && e.button.x >= tab_rect_main[i].x && e.button.x <= tab_rect_main[i].x+tab_rect_main[i].w && e.button.y >= tab_rect_main[i].y && e.button.y <= tab_rect_main[i].y+tab_rect_main[i].h){
                      printf("carte %i de main\n",i);
                      etat = i + 1; 
                      printf(" etat +  = %i\n",etat);                     
                     
                      break;
                    }                 
                    //cas ou on clique sur une carte du plateau
                    else if(tab_formation_cartesJ[x][y] >= 0  && e.button.x >= tab_rect_formationJ[i].x && e.button.x <= tab_rect_formationJ[i].x+tab_rect_formationJ[i].w && e.button.y >= tab_rect_formationJ[i].y && e.button.y <= tab_rect_formationJ[i].y+tab_rect_formationJ[i].h){
                      printf("carte [%i][%i] du plateau\n",x,y);
                      etat = -(i + 1); 
                      printf(" etat - = %i\n",etat);                     
                      break;
                    }
                  }
                  break;
              }
              printf(" etat = %i\n",etat);                     
              /*
              if(e.button.x >= tab_rect_main[0].x && e.button.x <= tab_rect_main[0].x+tab_rect_main[0].w && e.button.y >= tab_rect_main[0].y && e.button.y <= tab_rect_main[0].y+tab_rect_main[0].h){
                //si on clique sur la case 0 (première à gauche) de la main
                //choix_plateau(renderer_jeu, pWindow, tab_rect_main, tab_formation_cartesJ, tab_rect_formationJ, tab_main, 0, taille_main);
                printf("carte 0\n");
                etat = 1;                      
                break;
              }else if(e.button.x >= tab_rect_main[1].x && e.button.x <= tab_rect_main[1].x+tab_rect_main[1].w && e.button.y >= tab_rect_main[1].y && e.button.y <= tab_rect_main[1].y+tab_rect_main[1].h){
                //si on clique sur la case 1 de la main
                printf("carte 1\n");
                etat = 2;                      
                break;
              }else if(e.button.x >= tab_rect_main[2].x && e.button.x <= tab_rect_main[2].x+tab_rect_main[2].w && e.button.y >= tab_rect_main[2].y && e.button.y <= tab_rect_main[2].y+tab_rect_main[2].h){
                //si on clique sur la case 2 de la main
                printf("carte 2\n");
                etat = 3;                      
                break;
              }else if(e.button.x >= tab_rect_main[3].x && e.button.x <= tab_rect_main[3].x+tab_rect_main[3].w && e.button.y >= tab_rect_main[3].y && e.button.y <= tab_rect_main[3].y+tab_rect_main[3].h){
                //si on clique sur la case 3 de la main
                printf("carte 3\n");
                etat = 4;                      
                break;
              }else if(e.button.x >= tab_rect_main[4].x && e.button.x <= tab_rect_main[4].x+tab_rect_main[4].w && e.button.y >= tab_rect_main[4].y && e.button.y <= tab_rect_main[4].y+tab_rect_main[4].h){
                //si on clique sur la case 4 de la main
                printf("carte 4\n");
                etat = 5;                      
                break;
              }else if(e.button.x >= tab_rect_main[5].x && e.button.x <= tab_rect_main[5].x+tab_rect_main[5].w && e.button.y >= tab_rect_main[5].y && e.button.y <= tab_rect_main[5].y+tab_rect_main[5].h){
                //si on clique sur la case 5 de la main
                printf("carte 5\n");
                etat = 6;                      
                break;
              }else if(e.button.x >= tab_rect_main[6].x && e.button.x <= tab_rect_main[6].x+tab_rect_main[6].w && e.button.y >= tab_rect_main[6].y && e.button.y <= tab_rect_main[6].y+tab_rect_main[6].h){
                //si on clique sur la case 6 de la main
                printf("carte 6\n");
                etat = 7;                      
                break;
              }else if(e.button.x >= tab_rect_main[7].x && e.button.x <= tab_rect_main[7].x+tab_rect_main[7].w && e.button.y >= tab_rect_main[7].y && e.button.y <= tab_rect_main[7].y+tab_rect_main[7].h){
                //si on clique sur la case 7 de la main
                printf("carte 7\n");
                etat = 8;                      
                break;
              }else if(e.button.x >= tab_rect_main[8].x && e.button.x <= tab_rect_main[8].x+tab_rect_main[8].w && e.button.y >= tab_rect_main[8].y && e.button.y <= tab_rect_main[8].y+tab_rect_main[8].h){
                //si on clique sur la case 8 de la main
                printf("carte 8\n");
                etat = 9;                      
                break;
              }else if(e.button.x >= tab_rect_main[9].x && e.button.x <= tab_rect_main[9].x+tab_rect_main[9].w && e.button.y >= tab_rect_main[9].y && e.button.y <= tab_rect_main[9].y+tab_rect_main[9].h){
                //si on clique sur la case 9 de la main
                printf("carte 9\n");
                etat = 10;                      
                break;
              }else if(e.button.x >= tab_rect_main[10].x && e.button.x <= tab_rect_main[10].x+tab_rect_main[10].w && e.button.y >= tab_rect_main[10].y && e.button.y <= tab_rect_main[10].y+tab_rect_main[10].h){
                //si on clique sur la case 10 de la main
              }else if(e.button.x >= tab_rect_main[11].x && e.button.x <= tab_rect_main[11].x+tab_rect_main[11].w && e.button.y >= tab_rect_main[11].y && e.button.y <= tab_rect_main[11].y+tab_rect_main[11].h){
                //si on clique sur la case 11 de la main
              }
              */

              if(etat > 0){
                ("la\n");
                etat -=1;
                int x = 0,y=0;
                for (int i = 0; i < 15;i++){
                  if(x == 4 && y < 2) y++;
                  x = i%5;
                  if(e.button.x >= tab_rect_formationJ[i].x && e.button.x <= tab_rect_formationJ[i].x+tab_rect_formationJ[i].w && e.button.y >= tab_rect_formationJ[i].y && e.button.y <= tab_rect_formationJ[i].y+tab_rect_formationJ[i].h){
                    printf("colone %i, ligne %i\n",x,y);               
                    transfert_carte(renderer_jeu,tab_rect_formationJ[0],tab_main,tab_formation_cartesJ,tab_rect_main,x,y,etat,taille_main);
                    affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);
                    printf("    je sors\n");
                    etat = 0;
                    break;

                  }
                }
                etat = 0;
                break;
              }

              else if(etat < 0){
                ("ou la \n");

                for (int i = 0; i < 15;i++){
                  if(e.button.x >= tab_rect_formationAdv[i].x+tab_rect_formationAdv[i].w && e.button.y >= tab_rect_formationAdv[i].y && e.button.y <= tab_rect_formationAdv[i].y+tab_rect_formationAdv[i].h){
                    printf("attaque sur la carte %i de l'adversaire \n\n",i);
                    etat = 0;
                    break;
                  }
                }
                etat = 0;
                break;
              }
              printf("allo ?\n");
              /*
              else{
                printf("reset etat 1\n");
                etat = 0;
              }
              */
              /*
              if(etat > 0 && e.button.x >= tab_rect_formationJ[0].x && e.button.x <= tab_rect_formationJ[0].x+tab_rect_formationJ[0].w && e.button.y >= tab_rect_formationJ[0].y && e.button.y <= tab_rect_formationJ[0].y+tab_rect_formationJ[0].h){
                //case colone 0, ligne 0
                printf("colone 0, ligne 0\n");               
                transfert_carte(renderer_jeu,tab_rect_formationJ[0],tab_main,tab_formation_cartesJ,tab_rect_main,0,0,etat,taille_main);
                affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);

                printf("je sors\n");
                break;

              }else if(etat > 0 && e.button.x >= tab_rect_formationJ[1].x && e.button.x <= tab_rect_formationJ[1].x+tab_rect_formationJ[1].w && e.button.y >= tab_rect_formationJ[1].y && e.button.y <= tab_rect_formationJ[1].y+tab_rect_formationJ[1].h){
                //case colone 0, ligne 1
                printf("colone 0, ligne 1\n");            
                transfert_carte(renderer_jeu,tab_rect_formationJ[1],tab_main,tab_formation_cartesJ,tab_rect_main,1,0,etat,taille_main);
                affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);

                printf("je sors\n");
                break;
              }else if(etat > 0 && e.button.x >= tab_rect_formationJ[2].x && e.button.x <= tab_rect_formationJ[2].x+tab_rect_formationJ[2].w && e.button.y >= tab_rect_formationJ[2].y && e.button.y <= tab_rect_formationJ[2].y+tab_rect_formationJ[2].h){
                //case colone 0, ligne 2
                printf("colone 0, ligne 2\n");               
                transfert_carte(renderer_jeu,tab_rect_formationJ[2],tab_main,tab_formation_cartesJ,tab_rect_main,2,0,etat,taille_main);
                affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);

                printf("je sors\n");
              }else if(etat > 0 && e.button.x >= tab_rect_formationJ[3].x && e.button.x <= tab_rect_formationJ[3].x+tab_rect_formationJ[3].w && e.button.y >= tab_rect_formationJ[3].y && e.button.y <= tab_rect_formationJ[3].y+tab_rect_formationJ[3].h){
                //case colone 0, ligne 3
              }else if(etat > 0 && e.button.x >= tab_rect_formationJ[4].x && e.button.x <= tab_rect_formationJ[4].x+tab_rect_formationJ[4].w && e.button.y >= tab_rect_formationJ[4].y && e.button.y <= tab_rect_formationJ[4].y+tab_rect_formationJ[4].h){
                //case colone 0 ligne 4
                transfert_carte(renderer_jeu,tab_rect_formationJ[1],tab_main,tab_formation_cartesJ,tab_rect_main,4,0,etat,taille_main);
                affichage_jeu (renderer_jeu,img_jeu_Texture, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main);

                printf("je sors\n");
              }else if(etat > 0 && e.button.x >= tab_rect_formationJ[5].x && e.button.x <= tab_rect_formationJ[5].x+tab_rect_formationJ[5].w && e.button.y >= tab_rect_formationJ[5].y && e.button.y <= tab_rect_formationJ[5].y+tab_rect_formationJ[5].h){
                //case colone 1, ligne 0
              }else if(e.button.x >= tab_rect_formationJ[6].x && e.button.x <= tab_rect_formationJ[6].x+tab_rect_formationJ[6].w && e.button.y >= tab_rect_formationJ[6].y && e.button.y <= tab_rect_formationJ[6].y+tab_rect_formationJ[6].h){
                //case colone 1, ligne 1
              }else if(e.button.x >= tab_rect_formationJ[7].x && e.button.x <= tab_rect_formationJ[7].x+tab_rect_formationJ[7].w && e.button.y >= tab_rect_formationJ[7].y && e.button.y <= tab_rect_formationJ[7].y+tab_rect_formationJ[7].h){
                //case colone 1, ligne 2
              }else if(e.button.x >= tab_rect_formationJ[8].x && e.button.x <= tab_rect_formationJ[8].x+tab_rect_formationJ[8].w && e.button.y >= tab_rect_formationJ[8].y && e.button.y <= tab_rect_formationJ[8].y+tab_rect_formationJ[8].h){
                //case colone 1, ligne 3
              }else if(e.button.x >= tab_rect_formationJ[9].x && e.button.x <= tab_rect_formationJ[9].x+tab_rect_formationJ[9].w && e.button.y >= tab_rect_formationJ[9].y && e.button.y <= tab_rect_formationJ[9].y+tab_rect_formationJ[9].h){
                //case colone 1, ligne 4
              }else if(e.button.x >= tab_rect_formationJ[10].x && e.button.x <= tab_rect_formationJ[10].x+tab_rect_formationJ[10].w && e.button.y >= tab_rect_formationJ[10].y && e.button.y <= tab_rect_formationJ[10].y+tab_rect_formationJ[10].h){
                //case colone 2, ligne 0
              }else if(e.button.x >= tab_rect_formationJ[11].x && e.button.x <= tab_rect_formationJ[11].x+tab_rect_formationJ[11].w && e.button.y >= tab_rect_formationJ[11].y && e.button.y <= tab_rect_formationJ[11].y+tab_rect_formationJ[11].h){
                //case colone 2, ligne 1
              }else if(e.button.x >= tab_rect_formationJ[12].x && e.button.x <= tab_rect_formationJ[12].x+tab_rect_formationJ[12].w && e.button.y >= tab_rect_formationJ[12].y && e.button.y <= tab_rect_formationJ[12].y+tab_rect_formationJ[12].h){
                //case colone 2, ligne 2
              }else if(e.button.x >= tab_rect_formationJ[13].x && e.button.x <= tab_rect_formationJ[13].x+tab_rect_formationJ[13].w && e.button.y >= tab_rect_formationJ[13].y && e.button.y <= tab_rect_formationJ[13].y+tab_rect_formationJ[13].h){
                //case colone 2, ligne 3
              }else if(e.button.x >= tab_rect_formationJ[14].x && e.button.x <= tab_rect_formationJ[14].x+tab_rect_formationJ[14].w && e.button.y >= tab_rect_formationJ[14].y && e.button.y <= tab_rect_formationJ[14].y+tab_rect_formationJ[14].h){
                //case colone 2, ligne 4
              }
              else{
                printf("reset etat 1\n");
                etat = 0;

              }
              */
            break;
          }

        }

      }
    }


    //à la fin du jeu------------------------------------------------------------------------------------------------------------------------------------------------------------------
    free(taille_main);
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
      jeu_solo(pWindow, tab_main); //on transmet le pointeur de la fenetre pour des utilisations antétieures
      SDL_DestroyWindow(pWindow);
    }
    else{
      printf("erreur de creation de fenetre\n");
      return -1;
    }



  SDL_Quit();
}

