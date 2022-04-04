/**
 * @file menu.c
 * @author Allan GONIN-SAGET (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief  fichier qui s'occupe intégralement du menu
 * @version 1.0
 * @date 2022-04-03
 *
 */


#include "../header/menu.h"


int menu(SDL_Window* pWindow){

  //initialisations de base------------------------------------------------------------------------------------------------------
	int randomMenu = 0;
	// Variable de couleur
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurGold = {255, 215, 0};

	// Le pointeur vers notre police
	TTF_Font* police = NULL;
	/* renderer */
	SDL_Renderer* renderer_menu = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);

	if(renderer_menu == NULL){
		fprintf(stderr, "Erreur à la création du renderer 1\n");
		exit(EXIT_FAILURE);
	}

	SDL_Surface* img_Menu_Surface;

	/* Gestion aléatoire du background */
	srand(time(NULL));
	randomMenu = rand()%4+1;
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



  /* On init le background des boutons du menu  */
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

	/* Surface du bouton jouer en solo */
	SDL_Surface* txt_optn1_S = TTF_RenderUTF8_Blended(police, "Jouer en solo", couleurNoire);
	SDL_Surface* txt_optn1_Hover_S = TTF_RenderUTF8_Blended(police, "Jouer en solo", couleurGold);

	if(!txt_optn1_S || !txt_optn1_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 1 '': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Texture du bouton jouer en solo */
	SDL_Texture* txt_optn1_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn1_S);
	SDL_Texture* txt_optn1_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn1_Hover_S);
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






	/* Surface du bouton jouer en multi */
	SDL_Surface* txt_optn2_S = TTF_RenderUTF8_Blended(police, "Jouer en ligne", couleurNoire);
	SDL_Surface* txt_optn2_Hover_S = TTF_RenderUTF8_Blended(police, "Jouer en ligne", couleurGold);

	if(!txt_optn2_S || !txt_optn2_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 2'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Texture du bouton jouer en multi */
	SDL_Texture* txt_optn2_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn2_S);
	SDL_Texture* txt_optn2_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn2_Hover_S);

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


	/* Surface du bouton 3 */
	SDL_Surface* txt_optn3_S = TTF_RenderUTF8_Blended(police, "Collection", couleurNoire);
	SDL_Surface* txt_optn3_Hover_S = TTF_RenderUTF8_Blended(police, "Collection", couleurGold);

	if(!txt_optn3_S || !txt_optn3_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 3'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Texture du bouton jouer en multi */
	SDL_Texture* txt_optn3_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn3_S);
	SDL_Texture* txt_optn3_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn3_Hover_S);
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




	/* Surface du bouton quitter */
	SDL_Surface* txt_optn4_S = TTF_RenderUTF8_Blended(police, "QUITTER ?", couleurNoire);
	SDL_Surface* txt_optn4_Hover_S = TTF_RenderUTF8_Blended(police, "NOOOOOO !", couleurGold);

	if(!txt_optn4_S || !txt_optn4_Hover_S){
		fprintf(stderr, "Erreur à la création du texte ''option 4'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	/* Texture du bouton jouer en multi */
	SDL_Texture* txt_optn4_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn4_S);
	SDL_Texture* txt_optn4_Hover_T = SDL_CreateTextureFromSurface(renderer_menu, txt_optn4_Hover_S);
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


	hover_t etat_hover = PAS_HOVER;
	if(pWindow){
		int running=1;
		while(running){
			SDL_Event e;
			while(SDL_PollEvent(&e)){
				switch(e.type){
					case SDL_QUIT:
					running = 0;
					break;
					case SDL_WINDOWEVENT:
					switch(e.window.event){
						case SDL_WINDOWEVENT_EXPOSED:
						case SDL_WINDOWEVENT_SIZE_CHANGED:
						case SDL_WINDOWEVENT_RESIZED:
						case SDL_WINDOWEVENT_SHOWN:
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
					printf("x: %i\ny: %i\n",e.button.x,e.button.y); /* Detection // Affichage des coordonnées du clique de la souris */
					if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
						//Si on clique sur le bouton 1

						jeu_solo(pWindow,renderer_menu,&running);
						SDL_PollEvent(&e); /** on récupère la nouvelle position du curseur et on met à jour nos events*/
					}
					else if(e.button.x >= txt_optn2_R.x && e.button.x <= txt_optn2_R.x+txt_optn2_R.w && e.button.y >= txt_optn2_R.y && e.button.y <= txt_optn2_R.y+txt_optn2_R.h){
						//Si on clique sur le bouton 2

						pthread_t threadJoueur; /** \brief threadJoueur est un thread permettant de tester la connexion d'un joueur sans bloquer le programme */
						serverStruct_t infoServer;

						//affichage ecran noir + connexion au serveur...
						infoServer.joueurTrouve=0;
						infoServer.valSocket=connectC();
						printf("valSocket = %i\n",infoServer.valSocket);
						if(infoServer.valSocket==-1){
							//Tenta maximum atteinte
							//Afficher erreur
						}
						else{
							/* DECLARATION waiting*/
							SDL_Surface* img_Waiting_Surface = IMG_Load("img/waiting.png");
							SDL_Surface* img_Waiting_BG_Surface = IMG_Load("img/waitingBG.png");
							if(!img_Waiting_Surface || !img_Waiting_BG_Surface){
								fprintf(stderr, "Probleme chargement de la surface du waiting: %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}
							SDL_Texture* img_Waiting_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Waiting_Surface);
							SDL_FreeSurface(img_Waiting_Surface); /* on a la texture, plus besoin de la surface */
							SDL_Texture* img_Waiting_BG_Texture = SDL_CreateTextureFromSurface(renderer_menu, img_Waiting_BG_Surface);
							SDL_FreeSurface(img_Waiting_BG_Surface); /* on a la texture, plus besoin de la surface */

							if(!img_Waiting_Texture || !img_Waiting_BG_Texture){
								fprintf(stderr, "Erreur à la création de la texture ''waiting'' : %s\n", SDL_GetError());
								exit(EXIT_FAILURE);
							}

							/* On va creer les rectangles de positionnement */
							SDL_Rect rect_Waiting = creer_rectangle(670-64,800,64,64); /* -64 est du à la taille de l'image :) */
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
								delai1 = SDL_GetTicks() / 50; /* Taux de rafraichissement de notre sprite */
								delai2 = SDL_GetTicks() / 150; /* Taux de rafraichissement de notre sprite */


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

								SDL_PollEvent(&e); /* On recupere les actions du joueur sur la fenetre */

								if(e.type == SDL_QUIT){
									/* Si l'utilisateur decide de fermer le jeu */
									cancel = 1;
									running = 0;
									break;
								}

								if(e.type == SDL_MOUSEBUTTONDOWN && e.button.x >= rect_Waiting.x && e.button.x <= rect_Waiting.x+rect_Waiting.w && e.button.y >= rect_Waiting.y && e.button.y <= rect_Waiting.y+rect_Waiting.h){
									/* Si l'utilisateur decide de retourner au Menu */
									cancel = 1;
									break;
								}
							}
							/* On sort du while, quand on a trouvé un autre joueur, ou si le joueur effectue une action pour quitter cette recherche */
							pthread_cancel(threadJoueur); /* On bloque la recherche d'un joueur et on close le thread qui s'en occupe */

							if(cancel){
								/* Si le joueur effectue une action, pour terminer la recherche */
								connectF(&infoServer.valSocket); /* Coupe la connexion */
								break;
							}

							jeu_multi(pWindow, renderer_menu, &running, &infoServer.valSocket);

							if(infoServer.valSocket!=-1) connectF(&infoServer.valSocket); /* On verifie avant de retourner au menu, qu'on coupe la connexion, afin de liberer le serveur */
						}
						SDL_PollEvent(&e);
					}
					else if(e.button.x >= txt_optn3_R.x && e.button.x <= txt_optn3_R.x+txt_optn3_R.w && e.button.y >= txt_optn3_R.y && e.button.y <= txt_optn3_R.y+txt_optn3_R.h){
						/* Si on clique sur le bouton 3 [COLLECTION] */

						collection(pWindow ,img_Menu_Texture, renderer_menu, &running);
						SDL_PollEvent(&e); /* on récupère la nouvelle position du curseur et on met à jour nos events */
					}
					else if(e.button.x >= txt_optn4_R.x && e.button.x <= txt_optn4_R.x+txt_optn4_R.w && e.button.y >= txt_optn4_R.y && e.button.y <= txt_optn4_R.y+txt_optn4_R.h){
						/* Si on clique sur le bouton 4 [QUITTER] */

						running=0; //Quitter le jeu
					}
					case SDL_MOUSEMOTION:
					if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
						/* Si la souris HOVER sur le bouton 1 [SOLO] */

						SDL_RenderCopy(renderer_menu, txt_optn1_Hover_T, NULL, &txt_optn1_R);
						SDL_RenderPresent(renderer_menu);
						etat_hover=HOVER;
					}
					else if(e.button.x >= txt_optn2_R.x && e.button.x <= txt_optn2_R.x+txt_optn2_R.w && e.button.y >= txt_optn2_R.y && e.button.y <= txt_optn2_R.y+txt_optn2_R.h){
						/* Si la souris HOVER sur le bouton 2 [MULTIJOUEUR] */

						SDL_RenderCopy(renderer_menu, txt_optn2_Hover_T, NULL, &txt_optn2_R);
						SDL_RenderPresent(renderer_menu);
						etat_hover=HOVER;
					}
					else if(e.button.x >= txt_optn3_R.x && e.button.x <= txt_optn3_R.x+txt_optn3_R.w && e.button.y >= txt_optn3_R.y && e.button.y <= txt_optn3_R.y+txt_optn3_R.h){
						/* Si la souris HOVER sur le bouton 3 [COLLECTION] */

						SDL_RenderCopy(renderer_menu, txt_optn3_Hover_T, NULL, &txt_optn3_R);
						SDL_RenderPresent(renderer_menu);
						etat_hover=HOVER;
					}
					else if(e.button.x >= txt_optn4_R.x && e.button.x <= txt_optn4_R.x+txt_optn4_R.w && e.button.y >= txt_optn4_R.y && e.button.y <= txt_optn4_R.y+txt_optn4_R.h){
						/* Si la souris HOVER sur le bouton 4 [QUITTER] */

						/* On clear le render, et on raffiche tout ici, car on modifie le texte du quitter qui devient noooo, sinon même chose que les autres detections [1]/[2]/[3] */
						SDL_RenderClear(renderer_menu);
						SDL_RenderCopy(renderer_menu, img_Menu_Texture, NULL, NULL);
						SDL_RenderCopy(renderer_menu, img_Choix_Texture, NULL, NULL);
						SDL_RenderCopy(renderer_menu, txt_optn1_T, NULL, &txt_optn1_R);
						SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
						SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
						SDL_RenderCopy(renderer_menu, txt_optn4_Hover_T, NULL, &txt_optn4_R);

						SDL_RenderPresent(renderer_menu); /* On fait le rendu */
						etat_hover=HOVER;
					}
					else if(etat_hover==HOVER){
						/* Si on a deja effectué des hovers, mais qu'on arrete d'hover un bouton */

						SDL_RenderClear(renderer_menu);
						SDL_RenderCopy(renderer_menu, img_Menu_Texture, NULL, NULL);
						SDL_RenderCopy(renderer_menu, img_Choix_Texture, NULL, NULL);

						/* Render de toutes les options du menu principal */

						/* OPTION 1 */
						SDL_RenderCopy(renderer_menu, txt_optn1_T, NULL, &txt_optn1_R);
						/* OPTION 2 */
						SDL_RenderCopy(renderer_menu, txt_optn2_T, NULL, &txt_optn2_R);
						/* OPTION 3 */
						SDL_RenderCopy(renderer_menu, txt_optn3_T, NULL, &txt_optn3_R);
						/* OPTION 4 */
						SDL_RenderCopy(renderer_menu, txt_optn4_T, NULL, &txt_optn4_R);

						SDL_RenderPresent(renderer_menu); /* On fait le rendu */
						etat_hover=PAS_HOVER;
					}
					break;
				}
			}
		}
	}
	else{ /* Si la fenetre pWindow n'est pas init */
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
