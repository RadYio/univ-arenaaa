#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <unistd.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/carte.h"
#include "../header/window.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/affichage.h"
#include "../header/init_jeu_solo.h"




//---------------------------------------------NE PAS OUBLIER LES FREE APRES LES MALLOC !!!!!!!!!!!!!!!!!!!!!!!!!--------------------------------------------------------------

void * calcul_temps(void * val){
  int * jeu = (int*)(val);


  time_t t1, t2;
  t1 = time(NULL);
 	t2 = time(NULL);
  while(1)        
  {
      //un tour de 60 secondes
      if(difftime(t2, t1) >= 5){
        *jeu = 0;
        t1 = time(NULL);
      }
      if(*jeu == 0){
        t1 = time(NULL);
      }
      t2 = time(NULL);
      sleep(1);
      if(*jeu){
      printf ("temps %i\n", t2-t1);
      }
  }
}

int double_clique(SDL_Event e,SDL_Renderer *renderer_jeu,SDL_Rect tab_rect_main[],SDL_Rect tab_rect_formationJ[][3],SDL_Rect tab_rect_formationAdv[][3]
,SDL_Rect *rect_aff_carte_j,carte_t tab_cartes_total[13],carte_t tab_main[],int tab_formation_cartesJ[5][3],int tab_formation_cartesADV[5][3]){
  int x = 0,y=0,i=0;

  while(i < 15){
    if(x == 4 && y < 2) y++;
    x = i%5;
    //cas ou on clique sur une des 10 cartes de la main
    if(i <= 10 && e.button.x >= tab_rect_main[i].x && e.button.x <= tab_rect_main[i].x+tab_rect_main[i].w && e.button.y >= tab_rect_main[i].y && e.button.y <= tab_rect_main[i].y+tab_rect_main[i].h){
      printf("main %i\n",i);
      affichage_carte(renderer_jeu,tab_main[i],*rect_aff_carte_j);
      SDL_RenderPresent(renderer_jeu);
      return 0;

    }
    printf("%i \n",tab_formation_cartesJ[x][y])   ;
    //cas ou on clique sur une carte du plateau
    if(tab_formation_cartesJ[x][y] >= 0  && e.button.x >= tab_rect_formationJ[x][y].x && e.button.x <= tab_rect_formationJ[x][y].x+tab_rect_formationJ[x][y].w && e.button.y >= tab_rect_formationJ[x][y].y && e.button.y <= tab_rect_formationJ[x][y].y+tab_rect_formationJ[x][y].h){
      printf("plateau [%i][%i] \n",x,y);
      affichage_carte(renderer_jeu,tab_cartes_total[tab_formation_cartesJ[x][y]],*rect_aff_carte_j);
      SDL_RenderPresent(renderer_jeu);
      return 0;
    }
    if(tab_formation_cartesADV[x][2-y] >= 0  && e.button.x >= tab_rect_formationAdv[x][2-y].x && e.button.x <= tab_rect_formationAdv[x][2-y].x+tab_rect_formationAdv[x][2-y].w && e.button.y >= tab_rect_formationAdv[x][2-y].y && e.button.y <= tab_rect_formationAdv[x][2-y].y+tab_rect_formationAdv[x][2-y].h){
      printf("plateau [%i][%i] \n",x,y);
      affichage_carte(renderer_jeu,tab_cartes_total[tab_formation_cartesADV[x][2-y]],*rect_aff_carte_j);
      SDL_RenderPresent(renderer_jeu);
      return 0;
    }

    i++;
  }
  return 1;

}
//tableau de la main du joueur, à passer en parametre au lieu de déclarer ici



//fonction de jeu en solo, a programmer : les méchaniques de jeu, le bot
void jeu_solo(SDL_Window * pWindow, SDL_Renderer* renderer_jeu ,int * running){ //a rajouter : deck de la main, TTF_FONT à passer en parametre pour etre utilisé ici
    printf("test 2");

    int* taille_main = malloc(sizeof(int));
    *taille_main = 6;
    carte_t tab_main[*taille_main];
    //carte_t tab_total[13];
    creation_tab_main(tab_main,*taille_main);
    carte_t tab_cartes_total[13];

    creation_tab_main(tab_cartes_total,13);
    int * jeu;

    jeu = malloc(sizeof(int));
    *jeu = 1;
    pthread_t thread_tps;




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
    {-1, 1, -1},
    {0, -1, -2},
    {-1, -2, -1},
    {-1, -1, -2}};
//à modifier : faire une fonction de choix de formation (si y'a le time) et passer ce tableau en parametre à jeu_solo
    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //déclarations--------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


    //declarations de variables, renderer etc-------------------------------------------------------------------------------------------
    SDL_Color couleurJaune = {255, 215, 0};
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurBlanche = {255, 255, 255};

    TTF_Font* police = NULL;

    //SDL_Renderer* renderer_jeu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED); //creation d'un nouveau renderer pour le jeu

    if(renderer_jeu == NULL){
		fprintf(stderr, "Erreur à la création du renderer de jeu\n");
		exit(EXIT_FAILURE);
	}


    //declarations des tableaux de rectangles-------------------------------------------------------------------------------------------
    SDL_Rect tab_rect_formationJ[5][3];
    SDL_Rect tab_rect_formationAdv[5][3];
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

    //creation du rectangle pour le texte de deck de l'adversaire
    SDL_Rect* rect_aff_carte_j = malloc(sizeof(SDL_Rect));



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
  //cration des boutons de passage de tour et de retour menu 
  SDL_Surface* menu_s;
  SDL_Surface* passe_s;
  menu_s = IMG_Load("../img/img_menu.png");
  passe_s = IMG_Load("../img/retour_menu.png");
  SDL_Texture* menu_t;
  SDL_Texture* passe_t;
  menu_t = SDL_CreateTextureFromSurface(renderer_jeu, menu_s);
  passe_t = SDL_CreateTextureFromSurface(renderer_jeu, passe_s);

  SDL_FreeSurface(menu_s);
  SDL_FreeSurface(passe_s);

  //création du texte pour le bouton retour menu
  SDL_Surface * txt_menu_S = TTF_RenderUTF8_Blended(police, "Menu", couleurNoire);
	SDL_Surface* txt_menu_Hover_S = TTF_RenderUTF8_Blended(police, "Menu", couleurJaune);

  if(!txt_menu_S|| !txt_menu_Hover_S){
		fprintf(stderr, "Erreur à la création du texte '' titre de deck '': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture* txt_menu_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_menu_S);
	SDL_Texture* txt_menu_Hover_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_menu_Hover_S);

	SDL_FreeSurface(txt_menu_S); // on a la texture, plus besoin du texte via surface 
	SDL_FreeSurface(txt_menu_Hover_S);

  SDL_Rect menu_R = creer_rectangle(1400,0,90,190);
  SDL_Rect txt_menu_R = creer_rectangle(1440,20,50,(strlen("Menu")*25));
  
  

  //création du texte du bouton de passe tour
  SDL_Surface * txt_passe_S = TTF_RenderUTF8_Blended(police, "Passe", couleurNoire);
	SDL_Surface* txt_passe_Hover_S = TTF_RenderUTF8_Blended(police, "Passe", couleurJaune);

  if(!txt_passe_S|| !txt_passe_Hover_S){
		fprintf(stderr, "Erreur à la création du texte '' titre de deck '': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	SDL_Texture* txt_passe_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_passe_S);
	SDL_Texture* txt_passe_Hover_T = SDL_CreateTextureFromSurface(renderer_jeu, txt_passe_Hover_S);

	SDL_FreeSurface(txt_passe_S); // on a la texture, plus besoin du texte via surface 
	SDL_FreeSurface(txt_passe_Hover_S);

  SDL_Rect passe_R = creer_rectangle(1400,820,80,180);
  SDL_Rect txt_passe_R = creer_rectangle(1440,835,45,(strlen("Passe")*20));
  
  

  //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //maniupulations----------------------------------------------------------------------------------------------------------------------------------------------------------------------
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


  //manipulations de renderer-------------------------------------------------------------------------------------------------------------------------------------------------------------

  //SDL_RenderClear(renderer_menu); //on arrete d'afficher tout ce qu'il est en lien avec le menu







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
    init_jeu(taille_main,tab_rect_formationJ ,tab_rect_formationAdv, tab_rect_main, rect_joueur, rect_adv, rect_txt_deck_j, rect_txt_deck_adv,rect_aff_carte_j);

    //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //affichage de base : le jeu apparaitra comme ceci au debut, s'en suivra les modifs nécessaires par la suite---------------------------------------------------------------------------------------------
    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

    affichage_jeu2 (renderer_jeu,img_jeu_Texture,rect_aff_carte_j, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,
    rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main,tab_cartes_total,
    menu_t,menu_R,txt_menu_Hover_T,txt_menu_R,txt_menu_T,passe_t,passe_R,txt_passe_Hover_T,txt_passe_T,txt_passe_R);










    //affichage_texte(renderer_jeu, rect_txt_deck_j, txt_titre_joueur_T, rect_txt_deck_adv, txt_titre_adv_T);

    
    

    //on joue un tour, si victoire joueur/adversaire tour renvoi 1 ou -1, 0 si on continue à jouer------------------------------------------------------------------------------------------------------------------------------------------------------------
    int etat = 0;
    int oldHover = 0;
    int coord_x = 0,coord_y = 0;





    pthread_create(&thread_tps,NULL,calcul_temps,(void*)(jeu));
    if(pWindow){

      *running = 1;
      while(*running){
          SDL_Event e;
          while(*jeu == 0 && SDL_PollEvent(&e)){
              etat = 0;
              if(e.type == SDL_QUIT){

                *running = 0;
                printf("on sort mtn 1\n");
              } 
              printf("tour bot début\n");
              sleep(5);            
              printf("fin\n");
              *jeu = 1;
            }
            while(*jeu == 1 && SDL_PollEvent(&e)){


            switch(e.type){
              case SDL_QUIT : 
                printf("je suis ici %i\n",e.type);

                *running = 0 ;
                printf("on sort mtn\n");

              break;

              case SDL_MOUSEBUTTONDOWN :
                //tour(running,renderer_jeu, pWindow, tab_rect_main, tab_formation_cartesJ, tab_rect_formationJ, tab_main, taille_main);
                printf("\ntest nouvelle action\n\n");
                //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                //gestion des cartes dans la main---------------------------------------------------------------------------------------------------------------------------------------------------------------
                //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                /*
                printf("\netat avant = %i\n\n",etat);
                if(e.button.x >= texte_retour_R.x && e.button.x <= texte_retour_R.x+texte_retour_R.w && e.button.y >= texte_retour_R.y && e.button.y <= texte_retour_R.y+texte_retour_R.h){
                  //Si on clique sur le bouton 1
                  SDL_RenderClear(renderer_jeu);
                  return;
                }
                */
                if(e.button.x >= menu_R.x && e.button.x <= menu_R.x+menu_R.w && e.button.y >= menu_R.y && e.button.y <= menu_R.y+menu_R.h){
                  pthread_cancel(thread_tps);
                  return;
                }
                if(e.button.x >= passe_R.x && e.button.x <= passe_R.x+passe_R.w && e.button.y >= passe_R.y && e.button.y <= passe_R.y+passe_R.h){
                  printf("on passe le tour\n");
                  *jeu = 0;
                  break;
                }
                if(etat == 0){
                    affichage_jeu2 (renderer_jeu,img_jeu_Texture,rect_aff_carte_j, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,
                    rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main,tab_cartes_total,
                    menu_t,menu_R,txt_menu_Hover_T,txt_menu_R,txt_menu_T,passe_t,passe_R,txt_passe_Hover_T,txt_passe_T,txt_passe_R);
                    int x = 0,y=0;
                    for(int i=0;i < 15;i++){
                      if(x == 4 && y < 2) y++;
                      x = i%5;
                      printf("[%i][%i] eme essai \n",x,y);
                      if(i <= 10 && e.button.x >= tab_rect_main[i].x && e.button.x <= tab_rect_main[i].x+tab_rect_main[i].w && e.button.y >= tab_rect_main[i].y && e.button.y <= tab_rect_main[i].y+tab_rect_main[i].h){
                        etat = i + 1;
                        break;
                      }
                      else if(tab_formation_cartesJ[x][y] >= 0  && e.button.x >= tab_rect_formationJ[x][y].x && e.button.x <= tab_rect_formationJ[x][y].x+tab_rect_formationJ[x][y].w && e.button.y >= tab_rect_formationJ[x][y].y && e.button.y <= tab_rect_formationJ[x][y].y+tab_rect_formationJ[x][y].h){
                        printf("carte [%i][%i] du plateau allié\n",x,y);
                        etat = -(i + 1);
                        coord_x = x;
                        coord_y = y;
                        break;
                      }
                      else if(tab_formation_cartesADV[x][2-y] >= 0  && e.button.x >= tab_rect_formationAdv[x][2-y].x && e.button.x <= tab_rect_formationAdv[x][2-y].x+tab_rect_formationAdv[x][2-y].w && e.button.y >= tab_rect_formationAdv[x][2-y].y && e.button.y <= tab_rect_formationAdv[x][2-y].y+tab_rect_formationAdv[x][2-y].h){
                        printf("carte [%i][%i] du plateau ennemie\n",x,2-y);
                        etat = i + 11;
                        coord_x = x;
                        coord_y = 2-y;
                        break;
                      }
                    }
                    break;
                }
                printf(" etat = %i\n",etat);

                if(etat > 0 && etat < 11){
                  etat -=1;
                  int x = 0,y=0;
                  for (int i = 0; i < 15;i++){
                    if(x == 4 && y < 2) y++;
                    x = i%5;
                    //vérifie qu'on reclique sur la même carte
                    if(i == etat && e.button.x >= tab_rect_main[i].x && e.button.x <= tab_rect_main[i].x+tab_rect_main[i].w && e.button.y >= tab_rect_main[i].y && e.button.y <= tab_rect_main[i].y+tab_rect_main[i].h){
                        etat = 0;
                        double_clique(e,renderer_jeu,tab_rect_main,tab_rect_formationJ,tab_rect_formationAdv,rect_aff_carte_j,tab_cartes_total,tab_main,tab_formation_cartesJ,tab_formation_cartesADV);
                        break;
                    }
                    if(e.button.x >= tab_rect_formationJ[x][y].x && e.button.x <= tab_rect_formationJ[x][y].x+tab_rect_formationJ[x][y].w && e.button.y >= tab_rect_formationJ[x][y].y && e.button.y <= tab_rect_formationJ[x][y].y+tab_rect_formationJ[x][y].h){
                      transfert_carte(tab_main,tab_formation_cartesJ,tab_rect_main,x,y,etat,taille_main);
                      affichage_jeu2 (renderer_jeu,img_jeu_Texture,rect_aff_carte_j, rect_txt_deck_j,txt_titre_joueur_T,rect_txt_deck_adv,txt_titre_adv_T,rect_joueur,
                      rect_adv, tab_formation_cartesJ, tab_rect_formationJ,tab_formation_cartesADV,tab_rect_formationAdv ,taille_main, tab_rect_main, tab_main,tab_cartes_total,
                      menu_t,menu_R,txt_menu_Hover_T,txt_menu_R,txt_menu_T,passe_t,passe_R,txt_passe_Hover_T,txt_passe_T,txt_passe_R);
                      printf("la carte a été posée\n");
                      etat = 0;
                      break;

                    }
                  }
                  etat = 0;
                  break;
                }

                else if(etat < 0){

                  for (int i = 0; i < 5;i++){
                    for(int j = 0; j < 3; j++){
                      if(i == coord_x && j == coord_y && tab_formation_cartesJ[i][j] >= 0  && e.button.x >= tab_rect_formationJ[i][j].x && e.button.x <= tab_rect_formationJ[i][j].x+tab_rect_formationJ[i][j].w && e.button.y >= tab_rect_formationJ[i][j].y && e.button.y <= tab_rect_formationJ[i][j].y+tab_rect_formationJ[i][j].h){
                        double_clique(e,renderer_jeu,tab_rect_main,tab_rect_formationJ,tab_rect_formationAdv,rect_aff_carte_j,tab_cartes_total,tab_main,tab_formation_cartesJ,tab_formation_cartesADV);
                        coord_x = 0;
                        coord_y = 0;
                        etat = 0;
                        break;
                      }
                      if(e.button.x >= tab_rect_formationAdv[i][j].x && e.button.x <= tab_rect_formationAdv[i][j].x+tab_rect_formationAdv[i][j].w && e.button.y >= tab_rect_formationAdv[i][j].y && e.button.y <= tab_rect_formationAdv[i][j].y+tab_rect_formationAdv[i][j].h){
                        printf("attaque sur la carte %i de l'adversaire \n\n",i);
                        double_clique(e,renderer_jeu,tab_rect_main,tab_rect_formationJ,tab_rect_formationAdv,rect_aff_carte_j,tab_cartes_total,tab_main,tab_formation_cartesJ,tab_formation_cartesADV);

                        etat = 0;
                        break;
                      }
                    }
                  }
                  etat = 0;
                  break;
                }
                else if(etat > 10){

                  for (int x = 0; x < 5;x++){
                    for(int y = 0; y < 3; y++){
                      if(x == coord_x && 2-y == coord_y && tab_formation_cartesADV[x][2-y] >= 0  && e.button.x >= tab_rect_formationAdv[x][2-y].x && e.button.x <= tab_rect_formationAdv[x][2-y].x+tab_rect_formationAdv[x][2-y].w && e.button.y >= tab_rect_formationAdv[x][2-y].y && e.button.y <= tab_rect_formationAdv[x][2-y].y+tab_rect_formationAdv[x][2-y].h){
                        double_clique(e,renderer_jeu,tab_rect_main,tab_rect_formationJ,tab_rect_formationAdv,rect_aff_carte_j,tab_cartes_total,tab_main,tab_formation_cartesJ,tab_formation_cartesADV);
                        etat = 0;
                        coord_x = 0;
                        coord_y = 0;
                        break;
                      }
                    }
                  }
                }
              break;
              case SDL_MOUSEMOTION:
                if(e.button.x >= menu_R.x && e.button.x <= menu_R.x+menu_R.w && e.button.y >= menu_R.y && e.button.y <= menu_R.y+menu_R.h){
                      SDL_RenderCopy(renderer_jeu, txt_menu_Hover_T, NULL, &txt_menu_R);
                      SDL_RenderPresent(renderer_jeu);
                      oldHover = 1;
                }
                else if(e.button.x >= passe_R.x && e.button.x <= passe_R.x+passe_R.w && e.button.y >= passe_R.y && e.button.y <= passe_R.y+passe_R.h){
                      SDL_RenderCopy(renderer_jeu, txt_passe_Hover_T, NULL, &txt_passe_R);
                      SDL_RenderPresent(renderer_jeu);
                      oldHover = 1;

                }
                else if(oldHover){
                  SDL_RenderCopy(renderer_jeu, txt_passe_T, NULL, &txt_passe_R);
                  SDL_RenderCopy(renderer_jeu, txt_menu_T, NULL, &txt_menu_R);
                  SDL_RenderPresent(renderer_jeu);
                  oldHover = 0;
                }

              break;

            }
            break;
          }

  }

//}

  //à la fin du jeu------------------------------------------------------------------------------------------------------------------------------------------------------------------
  free(taille_main);
  pthread_cancel(thread_tps);
  //A SUPPRIMER--------------------------------------------------------------------------------------------------------
  TTF_CloseFont(police); /* Doit être avant TTF_Quit() */

  TTF_Quit();
  return;
  }
}
