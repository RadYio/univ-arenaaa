#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/collection.h"


int test_collec(){
  printf("test\n");
}

char * chemin_carte = "../img/Carte_Leo.png"; 
//char * nom_carte = "Leo Maître de la bagarre";


/*
*/
int collection(SDL_Window * pWindow, SDL_Texture* img_Collec_BG, SDL_Renderer* renderer_collec, int* running){

	carte_t * tab_cartes_total[13];

	carte_t * tab_sauvegarde[13];

	init_cartes(tab_cartes_total);

	recup_sauvegarde(tab_sauvegarde,tab_cartes_total);

	// Variable de couleur
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};
	SDL_Color couleurGold = {255, 215, 0};

	// Le pointeur vers notre police
	TTF_Font* police = NULL;


  /* DECLARATION BG_CHOIX*/
  SDL_Surface* img_Planche_Collec_S = IMG_Load("../img/planche_collec.png");

  if(!img_Planche_Collec_S){
		fprintf(stderr, "Erreur à la création du texte ''img_Planche_Collec_S'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

  if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Choix de la police */
	if((police = TTF_OpenFont("../font/ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
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
  SDL_Surface* img_Carte_Leo_S = IMG_Load(chemin_carte);

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
	nom_carte1.x=100;
	nom_carte1.y=80;
	nom_carte1.w=(strlen(tab_sauvegarde[0]->nom_collec)* 30 );
	nom_carte1.h=80;


  SDL_Rect nom_carte2;
	nom_carte2.x=420;
	nom_carte2.y=80;
	nom_carte2.w=(strlen(tab_sauvegarde[1]->nom_collec)* 30 );
	nom_carte2.h=80;

  SDL_Rect nom_carte3;
	nom_carte3.x=100;
	nom_carte3.y=160;
	nom_carte3.w=(strlen(tab_sauvegarde[2]->nom_collec)* 30 );
	nom_carte3.h=80;  
  
  SDL_Rect nom_carte4;
	nom_carte4.x=420;
	nom_carte4.y=160;
	nom_carte4.w=(strlen(tab_sauvegarde[3]->nom_collec)* 30 );
	nom_carte4.h=80;
  
  SDL_Rect nom_carte5;
	nom_carte5.x=100;
	nom_carte5.y=240;
	nom_carte5.w=(strlen(tab_sauvegarde[4]->nom_collec)* 30 );
	nom_carte5.h=80;  
  
  SDL_Rect nom_carte6;
	nom_carte6.x=420;
	nom_carte6.y=240;
	nom_carte6.w=(strlen(tab_sauvegarde[5]->nom_collec)* 30 );
	nom_carte6.h=80;

  SDL_Rect nom_carte7;
	nom_carte7.x=100;
	nom_carte7.y=320;
	nom_carte7.w=(strlen(tab_sauvegarde[6]->nom_collec)* 30 );
	nom_carte7.h=80;  
  
  SDL_Rect nom_carte8;
	nom_carte8.x=420;
	nom_carte8.y=320;
	nom_carte8.w=(strlen(tab_sauvegarde[7]->nom_collec)* 30 );
	nom_carte8.h=80;
  
  SDL_Rect nom_carte9;
	nom_carte9.x=100;
	nom_carte9.y=400;
	nom_carte9.w=(strlen(tab_sauvegarde[8]->nom_collec)* 30 );
	nom_carte9.h=80;

  SDL_Rect nom_carte10;
	nom_carte10.x=420;
	nom_carte10.y=400;
	nom_carte10.w=(strlen(tab_sauvegarde[9]->nom_collec)* 30 );
	nom_carte10.h=80;

  SDL_Rect nom_carte11;
	nom_carte9.x=100;
	nom_carte9.y=480;
	nom_carte9.w=(strlen(tab_sauvegarde[10]->nom_collec)* 30 );
	nom_carte9.h=80;

  SDL_Rect nom_carte12;
	nom_carte10.x=420;
	nom_carte10.y=480;
	nom_carte10.w=(strlen(tab_sauvegarde[11]->nom_collec)* 30 );
	nom_carte10.h=80;
  




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





	SDL_Surface* txt_carte1_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[0]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte1_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[0]->nom_collec, couleurGold);

	SDL_Texture *txt_optn1_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte1_S);
	SDL_Texture *txt_optn1_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte1_Hover_S);

	SDL_FreeSurface(txt_carte1_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte1_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 2e carte
  SDL_Surface* txt_carte2_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[1]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte2_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[1]->nom_collec, couleurGold);

	SDL_Texture *txt_optn2_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte2_S);
	SDL_Texture *txt_optn2_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte2_Hover_S);

	SDL_FreeSurface(txt_carte2_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte2_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 3e carte
  SDL_Surface* txt_carte3_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[2]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte3_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[2]->nom_collec, couleurGold);

	SDL_Texture *txt_optn3_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte3_S);
	SDL_Texture *txt_optn3_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte3_Hover_S);

	SDL_FreeSurface(txt_carte3_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte3_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 4e carte
  SDL_Surface* txt_carte4_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[3]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte4_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[3]->nom_collec, couleurGold);

	SDL_Texture *txt_optn4_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte4_S);
	SDL_Texture *txt_optn4_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte4_Hover_S);

	SDL_FreeSurface(txt_carte4_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte4_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 5e carte
  SDL_Surface* txt_carte5_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[4]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte5_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[4]->nom_collec, couleurGold);

	SDL_Texture *txt_optn5_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte4_S);
	SDL_Texture *txt_optn5_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte4_Hover_S);

	SDL_FreeSurface(txt_carte5_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte5_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 6e carte
  SDL_Surface* txt_carte6_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[5]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte6_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[5]->nom_collec, couleurGold);

	SDL_Texture *txt_optn6_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte6_S);
	SDL_Texture *txt_optn6_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte6_Hover_S);

	SDL_FreeSurface(txt_carte6_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte6_Hover_S); /* on a la texture, plus besoin du texte via surface */

	//7e carte
	SDL_Surface* txt_carte7_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[6]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte7_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[6]->nom_collec, couleurGold);

	SDL_Texture *txt_optn7_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte7_S);
	SDL_Texture *txt_optn7_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte7_Hover_S);

	SDL_FreeSurface(txt_carte7_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte7_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 8e carte
  SDL_Surface* txt_carte8_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[7]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte8_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[7]->nom_collec, couleurGold);

	SDL_Texture *txt_optn8_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte8_S);
	SDL_Texture *txt_optn8_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte8_Hover_S);

	SDL_FreeSurface(txt_carte8_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte8_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 9e carte
  SDL_Surface* txt_carte9_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[8]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte9_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[8]->nom_collec, couleurGold);

	SDL_Texture *txt_optn9_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte9_S);
	SDL_Texture *txt_optn9_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte9_Hover_S);

	SDL_FreeSurface(txt_carte9_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte9_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 10e carte
  SDL_Surface* txt_carte10_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[9]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte10_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[9]->nom_collec, couleurGold);

	SDL_Texture *txt_optn10_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte10_S);
	SDL_Texture *txt_optn10_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte10_Hover_S);

	SDL_FreeSurface(txt_carte10_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte10_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 11e carte
  SDL_Surface* txt_carte11_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[10]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte11_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[10]->nom_collec, couleurGold);

	SDL_Texture *txt_optn11_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte11_S);
	SDL_Texture *txt_optn11_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte11_Hover_S);

	SDL_FreeSurface(txt_carte11_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte11_Hover_S); /* on a la texture, plus besoin du texte via surface */

  // 12e carte
  SDL_Surface* txt_carte12_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[11]->nom_collec, couleurNoire);
	SDL_Surface* txt_carte12_Hover_S = TTF_RenderUTF8_Blended(police, tab_sauvegarde[11]->nom_collec, couleurGold);

	SDL_Texture *txt_optn12_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte12_S);
	SDL_Texture *txt_optn12_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte12_Hover_S);

	SDL_FreeSurface(txt_carte12_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(txt_carte12_Hover_S); /* on a la texture, plus besoin du texte via surface */


  SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
  SDL_RenderCopy(renderer_collec, img_Planche_Collec_T, NULL, &planche_R);
  SDL_RenderCopy(renderer_collec, img_Carte_Leo_T, NULL, &Carte_R);

  SDL_RenderCopy(renderer_collec, txt_optn1_T, NULL, &nom_carte1);
  SDL_RenderCopy(renderer_collec, txt_optn1_Hover_T, NULL, &nom_carte1);

  SDL_RenderCopy(renderer_collec, txt_optn2_T, NULL, &nom_carte2);
  SDL_RenderCopy(renderer_collec, txt_optn2_Hover_T, NULL, &nom_carte2);

  SDL_RenderCopy(renderer_collec, txt_optn3_T, NULL, &nom_carte3);
  SDL_RenderCopy(renderer_collec, txt_optn3_Hover_T, NULL, &nom_carte3);

  SDL_RenderCopy(renderer_collec, txt_optn4_T, NULL, &nom_carte4);
  SDL_RenderCopy(renderer_collec, txt_optn4_Hover_T, NULL, &nom_carte4);

  SDL_RenderCopy(renderer_collec, txt_optn5_T, NULL, &nom_carte5);
  SDL_RenderCopy(renderer_collec, txt_optn5_Hover_T, NULL, &nom_carte5);

  SDL_RenderCopy(renderer_collec, txt_optn6_T, NULL, &nom_carte6);
  SDL_RenderCopy(renderer_collec, txt_optn6_Hover_T, NULL, &nom_carte6);

  SDL_RenderCopy(renderer_collec, txt_optn7_T, NULL, &nom_carte7);
  SDL_RenderCopy(renderer_collec, txt_optn7_Hover_T, NULL, &nom_carte7);

  SDL_RenderCopy(renderer_collec, txt_optn8_T, NULL, &nom_carte8);
  SDL_RenderCopy(renderer_collec, txt_optn8_Hover_T, NULL, &nom_carte8);

  SDL_RenderCopy(renderer_collec, txt_optn9_T, NULL, &nom_carte9);
  SDL_RenderCopy(renderer_collec, txt_optn9_Hover_T, NULL, &nom_carte9);

  SDL_RenderCopy(renderer_collec, txt_optn10_T, NULL, &nom_carte10);
  SDL_RenderCopy(renderer_collec, txt_optn10_Hover_T, NULL, &nom_carte10);

  SDL_RenderCopy(renderer_collec, txt_optn11_T, NULL, &nom_carte11);
  SDL_RenderCopy(renderer_collec, txt_optn11_Hover_T, NULL, &nom_carte11);

  SDL_RenderCopy(renderer_collec, txt_optn12_T, NULL, &nom_carte12);
  SDL_RenderCopy(renderer_collec, txt_optn12_Hover_T, NULL, &nom_carte12);

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
/*			  case SDL_MOUSEBUTTONDOWN:
					printf("x: %i\ny: %i\n",e.button.x,e.button.y);
          if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
            //Si on clique sur le bouton 1

          }








					else if(e.button.x >= txt_optn3_R.x && e.button.x <= txt_optn3_R.x+txt_optn3_R.w && e.button.y >= txt_optn3_R.y && e.button.y <= txt_optn3_R.y+txt_optn3_R.h){
						  //Si on clique sur le bouton 3
							printf("Test on clique sur le bouton 3\n\n");
							SDL_RenderClear(renderer_menu);
							collection(pWindow ,img_Menu_Texture, renderer_menu, &running);

					}














					else if(e.button.x >= txt_optn4_R.x && e.button.x <= txt_optn4_R.x+txt_optn4_R.w && e.button.y >= txt_optn4_R.y && e.button.y <= txt_optn4_R.y+txt_optn4_R.h){
						  //Si on clique sur le bouton 4
							running=0; //Quitter le jeu

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
*/
    		}
          }
        }
      }
























}
