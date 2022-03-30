#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <time.h>
//pas tout seul

#include "../header/carte.h"
#include "../header/collection.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/window.h"
#include "../header/affichage.h"
#include "../header/client.h"
#include "../header/init_jeu_solo.h"



int menu(SDL_Window * pWindow){

  //initialisations de base------------------------------------------------------------------------------------------------------
	int randomMenu = 0;
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
		fprintf(stderr, "Erreur à la création du renderer 1\n");
		exit(EXIT_FAILURE);
	}

	SDL_Surface* img_Menu_Surface;
	// DECLARATION BG_MENU aléatoire
	srand(time(NULL));
	randomMenu = rand()%4+1;
	printf("Choix random du menu Version:%i\n\n",randomMenu);
	switch(randomMenu){
		case 1:
			img_Menu_Surface = IMG_Load("img/BG_MENU1.png");
			break;
		case 2:
			img_Menu_Surface = IMG_Load("img/BG_MENU2.png");
			break;
		case 3:
			img_Menu_Surface = IMG_Load("img/BG_MENU3.png");
			break;
		case 4:
			img_Menu_Surface = IMG_Load("img/BG_MENU4.png");
			break;
		default:
			img_Menu_Surface = IMG_Load("img/BG_DEFAULT.png");
	}

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
	SDL_Surface* img_Choix_Surface = IMG_Load("img/BG_CHOIX.png");

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
	if((police = TTF_OpenFont("font/ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}

	/*Surface du bouton jouer en solo*/
	SDL_Surface* txt_optn1_S = TTF_RenderUTF8_Blended(police, "Jouer en solo", couleurNoire);
	SDL_Surface* txt_optn1_Hover_S = TTF_RenderUTF8_Blended(police, "Jouer en solo", couleurGold);

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
	txt_optn1_R.x=950;
	txt_optn1_R.y=140;
	txt_optn1_R.w=strlen("jouer en solo")*30;
	txt_optn1_R.h=105;






	/*Surface du bouton jouer en multi*/
	SDL_Surface* txt_optn2_S = TTF_RenderUTF8_Blended(police, "Jouer en ligne", couleurNoire);
	SDL_Surface* txt_optn2_Hover_S = TTF_RenderUTF8_Blended(police, "Jouer en ligne", couleurGold);

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
	txt_optn2_R.x=320;
	txt_optn2_R.y=275;
	txt_optn2_R.w=strlen("jouer en ligne")*30;
	txt_optn2_R.h=105;




	/*Surface du bouton 3*/
	SDL_Surface* txt_optn3_S = TTF_RenderUTF8_Blended(police, "Collection", couleurNoire);
	SDL_Surface* txt_optn3_Hover_S = TTF_RenderUTF8_Blended(police, "Collection", couleurGold);

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
	txt_optn3_R.w=strlen("Collection")*30;
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
	txt_optn4_R.w=strlen("QUITTER ?")*30;
	txt_optn4_R.h=105;



//récupération des données de sauvegarde (quelles cartes possède le joueur / quelles sont toutes les cartes qui existent)-------------------------------------------

	/*carte_t * tab_cartes_total[N]; //tableau qui repertorie toutes les cartes qui existent
	carte_t * tab_sauvegarde[N]; //tableau qui repertorie les cartes que possède le joueur
	init_cartes(tab_cartes_total);
	recup_sauvegarde(tab_sauvegarde, tab_cartes_total);*/

//gestion des evenements---------------------------------------------------------------------------------------------------------------------------------------------
		//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
		int oldHover=0;

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
				printf("Test clique sur le bouton 1\n\n");
				jeu_solo(pWindow,renderer_menu,&running);
				//SDL_RenderPresent(renderer_menu);

				SDL_PollEvent(&e);
				SDL_RenderPresent(renderer_menu);


			}
			else if(e.button.x >= txt_optn2_R.x && e.button.x <= txt_optn2_R.x+txt_optn2_R.w && e.button.y >= txt_optn2_R.y && e.button.y <= txt_optn2_R.y+txt_optn2_R.h){
				//Si on clique sur le bouton 2
				printf("Test clique sur le bouton 2\n\n");

				pthread_t threadJoueur; /** \brief threadJoueur est un thread permettant de tester la connexion d'un joueur sans bloquer le programme */
				serverStruct_t infoServer;

				//affichage ecran noir + loading...
				printf("Je vais dans le truc\n");
				infoServer.joueurTrouve=0;
				printf("Je sors du truc\n");
				infoServer.valSocket=connectC();



				printf("valSocket = %i\n",infoServer.valSocket);
				if(infoServer.valSocket==-1){
					//Tenta maximum atteinte
					//Afficher erreur
				}
				else{
					printf("Je boucle tant que pas de joueur\n");



					/* DECLARATION waiting*/
					SDL_Surface* img_Waiting_Surface = IMG_Load("img/waiting.png");
					SDL_Surface* img_Waiting_BG_Surface = IMG_Load("img/waitingBG.png");
					if(!img_Waiting_Surface || !img_Waiting_BG_Surface){
						fprintf(stderr, "Probleme chargement de la surface du waiting: %s\n", SDL_GetError());
						exit(EXIT_FAILURE);
					}


				  SDL_Texture* img_Waiting_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Waiting_Surface);
					SDL_Texture* img_Waiting_BG_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Waiting_BG_Surface);
				  SDL_FreeSurface(img_Waiting_Surface); /* on a la texture, plus besoin de la surface */

					if(!img_Waiting_Texture || !img_Waiting_BG_Texture){
						fprintf(stderr, "Erreur à la création de la texture ''waiting'' : %s\n", SDL_GetError());
						exit(EXIT_FAILURE);
					}



					printf("Affichage\n\n");
					SDL_Rect rect_Waiting = creer_rectangle(670-64,800,64,64);
					SDL_Rect rect_Waiting_Evolution = creer_rectangle(0,0,64,64);
					SDL_Rect rect_Waiting_BG_Evolution = creer_rectangle(0,0,368,768);

					




					printf("Je cree le thread\n");
					pthread_create(&threadJoueur, NULL, rechercheJoueur, (void*)&infoServer);
					int animation1 = 0;
					int animation2 = 0;
					int cancel = 0;
					Uint32 delai1 = SDL_GetTicks();
					Uint32 delai2 = SDL_GetTicks();
					Uint32 diffDelai1 = -1;
					Uint32 diffDelai2 = -1;
					while(infoServer.joueurTrouve!=1){
						delai1 = SDL_GetTicks() / 50;
						delai2 = SDL_GetTicks() / 150;
						if(delai1!=diffDelai1){
						rect_Waiting_Evolution.x=rect_Waiting_Evolution.w*animation1;
						animation1=(animation1+1)%27;
						}
						if(delai2!=diffDelai2){
						rect_Waiting_BG_Evolution.x=rect_Waiting_BG_Evolution.w*animation2;
						animation2=(animation2+1)%7;
						}
						SDL_RenderClear(renderer_menu);
						SDL_RenderCopy(renderer_menu,img_Waiting_BG_Texture, &rect_Waiting_BG_Evolution, NULL);
						SDL_RenderCopy(renderer_menu, img_Waiting_Texture, &rect_Waiting_Evolution, &rect_Waiting);
						SDL_RenderPresent(renderer_menu);
						diffDelai1 = delai1;
						diffDelai2 = delai2;

						SDL_PollEvent(&e);
					
						if(e.type == SDL_QUIT){
							printf("on quitte pas cool\n");
							cancel = 1;
							running = 0;
							break;
						}
						if(e.type == SDL_MOUSEBUTTONDOWN && e.button.x >= rect_Waiting.x && e.button.x <= rect_Waiting.x+rect_Waiting.w && e.button.y >= rect_Waiting.y && e.button.y <= rect_Waiting.y+rect_Waiting.h){
							printf("fin de recherche retour menu\n");
							cancel = 1;
							break;
						}
					}
						
					
					//trouve
					pthread_cancel(threadJoueur); //On bloque la recherche d'un joueur
					if(cancel){
						printf("je veux quitter \n\n");
						connectF(&infoServer.valSocket);
						break;
					}
					jeu_multi(pWindow, renderer_menu, &running, &infoServer.valSocket);
					printf("YOOOOOOOOOO: %i\n\n",infoServer.valSocket);
					if(infoServer.valSocket!=-1)
						connectF(&infoServer.valSocket);

				}
				SDL_PollEvent(&e);



			}

			else if(e.button.x >= txt_optn3_R.x && e.button.x <= txt_optn3_R.x+txt_optn3_R.w && e.button.y >= txt_optn3_R.y && e.button.y <= txt_optn3_R.y+txt_optn3_R.h){
				//Si on clique sur le bouton 3
				printf("Test on clique sur le bouton 3\n\n");

				collection(pWindow ,img_Menu_Texture, renderer_menu, &running);
				//on récupère la nouvelle position du curseur
				SDL_PollEvent(&e);
				//SDL_RenderClear(renderer_menu);
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
    	}
    }
  }
} else {
  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
}

//Destruction de la fenetre
SDL_DestroyTexture(img_Menu_Texture);
SDL_DestroyTexture(img_Choix_Texture);
SDL_DestroyTexture(txt_optn1_T);
SDL_DestroyTexture(txt_optn1_Hover_T);
SDL_DestroyTexture(txt_optn2_T);
SDL_DestroyTexture(txt_optn2_Hover_T);
SDL_DestroyTexture(txt_optn3_T);
SDL_DestroyTexture(txt_optn3_Hover_T);
SDL_DestroyTexture(txt_optn4_T);
SDL_DestroyTexture(txt_optn4_Hover_T);
SDL_DestroyRenderer(renderer_menu);
TTF_CloseFont(police); //Doit être avant TTF_Quit()

TTF_Quit();
  return 0;
}
