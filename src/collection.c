
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
#include "../header/init_jeu.h"


void creation_R_collec(int taille,SDL_Rect tab[],carte_t * tab_sauvegarde[]){
	if (taille == 0){
    	return;
	}else{
		int y = 180;
		for(int i=0;i<taille;i++){
			tab[i] = creer_rectangle(110, y ,80,(strlen(tab_sauvegarde[i]->nom_collec)* 30));
			if(i+1 <taille){
				tab[i+1] = creer_rectangle(420, y ,80,(strlen(tab_sauvegarde[i+1]->nom_collec)* 30));
				y += 90;
				i++;
			}
		}
	}
}





int collection(SDL_Window * pWindow, SDL_Texture* img_Collec_BG, SDL_Renderer* renderer_collec, int * running){
	carte_t tab_cartes_total[13];
	int taille_tab_sauvegarde = 13;

	carte_t * tab_sauvegarde[taille_tab_sauvegarde];
	init_cartes(tab_cartes_total);


	recup_sauvegarde(tab_sauvegarde, tab_cartes_total);
	// Variable de couleur
	SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurGold = {255, 215, 0};

	// Le pointeur vers notre police
	TTF_Font* police = NULL;


	/* DECLARATION BG_CHOIX*/
	SDL_Surface* img_planche_bg1_S = IMG_Load("img/planche_bg1.png");

	if(!img_planche_bg1_S){
		fprintf(stderr, "Erreur à la création du texte ''img_planche_bg1_S'': %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	if(TTF_Init() == -1) {
		fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
		exit(EXIT_FAILURE);
	}

	/* Choix de la police */
	if((police = TTF_OpenFont("font/ChowFun.ttf", 20)) == NULL){
		fprintf(stderr, "erreur chargement font\n");
		exit(EXIT_FAILURE);
	}

	//Déclaration image planche
	SDL_Texture* img_planche_bg1_T = SDL_CreateTextureFromSurface(renderer_collec, img_planche_bg1_S);
	SDL_FreeSurface(img_planche_bg1_S); // on a la texture, plus besoin de l'image
	if(!img_planche_bg1_T){
		fprintf(stderr, "Erreur à la création du rendu ''img_planche_bg1_T'' : %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Surface* img_Planche_haut_S = IMG_Load("img/panneau_haut.png");
	SDL_Texture* img_Planche_haut_T = SDL_CreateTextureFromSurface(renderer_collec, img_Planche_haut_S);
	SDL_FreeSurface(img_Planche_haut_S); // on a la texture, plus besoin de l'image

	SDL_Surface* img_Planche_bas_S = IMG_Load("img/panneau_bas.png");
	SDL_Texture* img_Planche_bas_T = SDL_CreateTextureFromSurface(renderer_collec, img_Planche_bas_S);
	SDL_FreeSurface(img_Planche_bas_S); // on a la texture, plus besoin de l'image

	SDL_Surface* img_retour_menu_S = IMG_Load("img/retour_menu.png");
	SDL_Texture* img_retour_menu_T = SDL_CreateTextureFromSurface(renderer_collec, img_retour_menu_S);
	SDL_FreeSurface(img_retour_menu_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte1*/
	SDL_Surface* img_carte_1_S = IMG_Load(tab_sauvegarde[0]->chemin_carte);
	SDL_Texture* img_carte_1_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_1_S);
	SDL_FreeSurface(img_carte_1_S); // on a la texture, plus besoin de l'image


	/* DECLARATION carte2*/
	SDL_Surface* img_carte_2_S = IMG_Load(tab_sauvegarde[1]->chemin_carte);
	SDL_Texture* img_carte_2_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_2_S);
	SDL_FreeSurface(img_carte_2_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte3*/
	SDL_Surface* img_carte_3_S = IMG_Load(tab_sauvegarde[2]->chemin_carte);
	SDL_Texture* img_carte_3_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_3_S);
	SDL_FreeSurface(img_carte_3_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte4*/
	SDL_Surface* img_carte_4_S = IMG_Load(tab_sauvegarde[3]->chemin_carte);
	SDL_Texture* img_carte_4_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_4_S);
	SDL_FreeSurface(img_carte_4_S); // on a la texture, plus besoin de l'image


	/* DECLARATION carte5*/
	SDL_Surface* img_carte_5_S = IMG_Load(tab_sauvegarde[4]->chemin_carte);
	SDL_Texture* img_carte_5_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_5_S);
	SDL_FreeSurface(img_carte_5_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte6*/
	SDL_Surface* img_carte_6_S = IMG_Load(tab_sauvegarde[5]->chemin_carte);
	SDL_Texture* img_carte_6_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_6_S);
	SDL_FreeSurface(img_carte_6_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte7*/
	SDL_Surface* img_carte_7_S = IMG_Load(tab_sauvegarde[6]->chemin_carte);
	SDL_Texture* img_carte_7_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_7_S);
	SDL_FreeSurface(img_carte_7_S); // on a la texture, plus besoin de l'image


	/* DECLARATION carte8*/
	SDL_Surface* img_carte_8_S = IMG_Load(tab_sauvegarde[7]->chemin_carte);
	SDL_Texture* img_carte_8_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_8_S);
	SDL_FreeSurface(img_carte_8_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte9*/
	SDL_Surface* img_carte_9_S = IMG_Load(tab_sauvegarde[8]->chemin_carte);
	SDL_Texture* img_carte_9_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_9_S);
	SDL_FreeSurface(img_carte_9_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte10*/
	SDL_Surface* img_carte_10_S = IMG_Load(tab_sauvegarde[9]->chemin_carte);
	SDL_Texture* img_carte_10_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_10_S);
	SDL_FreeSurface(img_carte_10_S); // on a la texture, plus besoin de l'image


	/* DECLARATION carte11*/
	SDL_Surface* img_carte_11_S = IMG_Load(tab_sauvegarde[10]->chemin_carte);
	SDL_Texture* img_carte_11_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_11_S);
	SDL_FreeSurface(img_carte_11_S); // on a la texture, plus besoin de l'image

	/* DECLARATION carte12*/
	SDL_Surface* img_carte_12_S = IMG_Load(tab_sauvegarde[11]->chemin_carte);
	SDL_Texture* img_carte_12_T = SDL_CreateTextureFromSurface(renderer_collec, img_carte_12_S);
	SDL_FreeSurface(img_carte_12_S); // on a la texture, plus besoin de l'image

	//Déclaration de la zone dans laquelle vont être listées les cartes


	SDL_Rect planche_R;
		planche_R.x=75;
		planche_R.y=100;
		planche_R.w=650;
		planche_R.h=700;

	SDL_Rect planche_haut_R;
		planche_haut_R.x=10;
		planche_haut_R.y=700;
		planche_haut_R.w=800;
		planche_haut_R.h=200;

	SDL_Rect planche_bas_R;
		planche_bas_R.x=10;
		planche_bas_R.y=5;
		planche_bas_R.w=800;
		planche_bas_R.h=200;

	SDL_Rect retour_menu_R;
		retour_menu_R.x=800;
		retour_menu_R.y=750;
		retour_menu_R.w=300;
		retour_menu_R.h=120;


	SDL_Rect texte_retour_R;
		texte_retour_R.x=900;
		texte_retour_R.y=780;
		texte_retour_R.w=160;
		texte_retour_R.h=60;

	//Déclaration des rectangles dans lesquels vont être stockées les cartes

	SDL_Rect tab_nom_carte[taille_tab_sauvegarde];
	creation_R_collec(taille_tab_sauvegarde,tab_nom_carte,tab_sauvegarde);




	//Déclaration du rectangle dans lequel vont être listées les cartes
	SDL_Rect Carte_R;
		Carte_R.x=900;
		Carte_R.y=100;
		Carte_R.w=400;
		Carte_R.h=600;







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

	SDL_Texture *txt_optn5_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte5_S);
	SDL_Texture *txt_optn5_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, txt_carte5_Hover_S);

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

	//  retour au menu
	SDL_Surface* retour_menu_S = TTF_RenderUTF8_Blended(police, "Menu", couleurNoire);
	SDL_Surface* retour_menu_Hover_S = TTF_RenderUTF8_Blended(police, "Menu", couleurGold);

	SDL_Texture *retour_menu_T = SDL_CreateTextureFromSurface(renderer_collec, retour_menu_S);
	SDL_Texture *retour_menu_Hover_T = SDL_CreateTextureFromSurface(renderer_collec, retour_menu_Hover_S);

	SDL_FreeSurface(retour_menu_S); /* on a la texture, plus besoin du texte via surface */
	SDL_FreeSurface(retour_menu_Hover_S); /* on a la texture, plus besoin du texte via surface */


	SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
	SDL_RenderCopy(renderer_collec, img_planche_bg1_T, NULL, &planche_R);
	SDL_RenderCopy(renderer_collec, img_Planche_haut_T, NULL, &planche_haut_R);
	SDL_RenderCopy(renderer_collec, img_Planche_bas_T, NULL, &planche_bas_R);
	SDL_RenderCopy(renderer_collec, img_retour_menu_T, NULL, &retour_menu_R);




  SDL_RenderCopy(renderer_collec, txt_optn1_Hover_T, NULL, &tab_nom_carte[0]);
  SDL_RenderCopy(renderer_collec, txt_optn1_T, NULL, &tab_nom_carte[0]);

  SDL_RenderCopy(renderer_collec, txt_optn2_Hover_T, NULL, &tab_nom_carte[1]);
  SDL_RenderCopy(renderer_collec, txt_optn2_T, NULL, &tab_nom_carte[1]);

  SDL_RenderCopy(renderer_collec, txt_optn3_Hover_T, NULL, &tab_nom_carte[2]);
  SDL_RenderCopy(renderer_collec, txt_optn3_T, NULL, &tab_nom_carte[2]);

  SDL_RenderCopy(renderer_collec, txt_optn4_Hover_T, NULL, &tab_nom_carte[3]);
  SDL_RenderCopy(renderer_collec, txt_optn4_T, NULL, &tab_nom_carte[3]);

  SDL_RenderCopy(renderer_collec, txt_optn5_Hover_T, NULL, &tab_nom_carte[4]);
  SDL_RenderCopy(renderer_collec, txt_optn5_T, NULL, &tab_nom_carte[4]);

  SDL_RenderCopy(renderer_collec, txt_optn6_Hover_T, NULL, &tab_nom_carte[5]);
  SDL_RenderCopy(renderer_collec, txt_optn6_T, NULL, &tab_nom_carte[5]);

  SDL_RenderCopy(renderer_collec, txt_optn7_Hover_T, NULL, &tab_nom_carte[6]);
  SDL_RenderCopy(renderer_collec, txt_optn7_T, NULL, &tab_nom_carte[6]);

  SDL_RenderCopy(renderer_collec, txt_optn8_Hover_T, NULL, &tab_nom_carte[7]);
  SDL_RenderCopy(renderer_collec, txt_optn8_T, NULL, &tab_nom_carte[7]);

  SDL_RenderCopy(renderer_collec, txt_optn9_Hover_T, NULL, &tab_nom_carte[8]);
  SDL_RenderCopy(renderer_collec, txt_optn9_T, NULL, &tab_nom_carte[8]);

  SDL_RenderCopy(renderer_collec, txt_optn10_Hover_T, NULL, &tab_nom_carte[9]);
  SDL_RenderCopy(renderer_collec, txt_optn10_T, NULL, &tab_nom_carte[9]);

  SDL_RenderCopy(renderer_collec, txt_optn11_Hover_T, NULL, &tab_nom_carte[10]);
  SDL_RenderCopy(renderer_collec, txt_optn11_T, NULL, &tab_nom_carte[10]);

  SDL_RenderCopy(renderer_collec, txt_optn12_Hover_T, NULL, &tab_nom_carte[11]);
  SDL_RenderCopy(renderer_collec, txt_optn12_T, NULL, &tab_nom_carte[11]);

  SDL_RenderCopy(renderer_collec, retour_menu_Hover_T, NULL, &texte_retour_R);
  SDL_RenderCopy(renderer_collec, retour_menu_T, NULL, &texte_retour_R);

  SDL_RenderPresent(renderer_collec);


//gestion des evenements---------------------------------------------------------------------------------------------------------------------------------------------
	//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
	int oldHover=0;

    if(pWindow){
      while(*running){


        SDL_Event e;
        while(SDL_PollEvent(&e)){

          switch(e.type){
            case SDL_QUIT: *running = 0;
            break;
			case SDL_MOUSEBUTTONDOWN:
			if(e.button.x >= texte_retour_R.x && e.button.x <= texte_retour_R.x+texte_retour_R.w && e.button.y >= texte_retour_R.y && e.button.y <= texte_retour_R.y+texte_retour_R.h){
				//Si on clique sur le bouton 1
				SDL_RenderClear(renderer_collec);
				return 1;
			}
			case SDL_MOUSEMOTION:
				//SOURIS QUI HOVER SUR LA CARTE 1
				if(e.button.x >= tab_nom_carte[0].x && e.button.x <= tab_nom_carte[0].x+tab_nom_carte[0].w && e.button.y >= tab_nom_carte[0].y && e.button.y <= tab_nom_carte[0].y+tab_nom_carte[0].h){
					SDL_RenderCopy(renderer_collec, txt_optn1_Hover_T, NULL, &tab_nom_carte[0]);
					SDL_RenderCopy(renderer_collec, img_carte_1_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 2
				else if(e.button.x >= tab_nom_carte[1].x && e.button.x <= tab_nom_carte[1].x+tab_nom_carte[1].w && e.button.y >= tab_nom_carte[1].y && e.button.y <= tab_nom_carte[1].y+tab_nom_carte[1].h){
					SDL_RenderCopy(renderer_collec, txt_optn2_Hover_T, NULL, &tab_nom_carte[1]);
					SDL_RenderCopy(renderer_collec, img_carte_2_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 3
				else if(e.button.x >= tab_nom_carte[2].x && e.button.x <= tab_nom_carte[2].x+tab_nom_carte[2].w && e.button.y >= tab_nom_carte[2].y && e.button.y <= tab_nom_carte[2].y+tab_nom_carte[2].h){
					SDL_RenderCopy(renderer_collec, txt_optn3_Hover_T, NULL, &tab_nom_carte[2]);
					SDL_RenderCopy(renderer_collec, img_carte_3_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=3;
				}
				//SOURIS QUI HOVER SUR LA CARTE 4
				else if(e.button.x >= tab_nom_carte[3].x && e.button.x <= tab_nom_carte[3].x+tab_nom_carte[3].w && e.button.y >= tab_nom_carte[3].y && e.button.y <= tab_nom_carte[3].y+tab_nom_carte[3].h){
					SDL_RenderCopy(renderer_collec, txt_optn4_Hover_T, NULL, &tab_nom_carte[3]);
					SDL_RenderCopy(renderer_collec, img_carte_4_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 5
				else if(e.button.x >= tab_nom_carte[4].x && e.button.x <= tab_nom_carte[4].x+tab_nom_carte[4].w && e.button.y >= tab_nom_carte[4].y && e.button.y <= tab_nom_carte[4].y+tab_nom_carte[4].h){
					SDL_RenderCopy(renderer_collec, txt_optn5_Hover_T, NULL, &tab_nom_carte[4]);
					SDL_RenderCopy(renderer_collec, img_carte_5_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 6
				else if(e.button.x >= tab_nom_carte[5].x && e.button.x <= tab_nom_carte[5].x+tab_nom_carte[5].w && e.button.y >= tab_nom_carte[5].y && e.button.y <= tab_nom_carte[5].y+tab_nom_carte[5].h){
					SDL_RenderCopy(renderer_collec, txt_optn6_Hover_T, NULL, &tab_nom_carte[5]);
					SDL_RenderCopy(renderer_collec, img_carte_6_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}



				//SOURIS QUI HOVER SUR LA CARTE 7
				else if(e.button.x >= tab_nom_carte[6].x && e.button.x <= tab_nom_carte[6].x+tab_nom_carte[6].w && e.button.y >= tab_nom_carte[6].y && e.button.y <= tab_nom_carte[6].y+tab_nom_carte[6].h){
					SDL_RenderCopy(renderer_collec, txt_optn7_Hover_T, NULL, &tab_nom_carte[6]);
					SDL_RenderCopy(renderer_collec, img_carte_7_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 8
				else if(e.button.x >= tab_nom_carte[7].x && e.button.x <= tab_nom_carte[7].x+tab_nom_carte[7].w && e.button.y >= tab_nom_carte[7].y && e.button.y <= tab_nom_carte[7].y+tab_nom_carte[7].h){
					SDL_RenderCopy(renderer_collec, txt_optn8_Hover_T, NULL, &tab_nom_carte[7]);
					SDL_RenderCopy(renderer_collec, img_carte_8_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 9
				else if(e.button.x >= tab_nom_carte[8].x && e.button.x <= tab_nom_carte[8].x+tab_nom_carte[8].w && e.button.y >= tab_nom_carte[8].y && e.button.y <= tab_nom_carte[8].y+tab_nom_carte[8].h){
					SDL_RenderCopy(renderer_collec, txt_optn9_Hover_T, NULL, &tab_nom_carte[8]);
					SDL_RenderCopy(renderer_collec, img_carte_9_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 10
				else if(e.button.x >= tab_nom_carte[9].x && e.button.x <= tab_nom_carte[9].x+tab_nom_carte[9].w && e.button.y >= tab_nom_carte[9].y && e.button.y <= tab_nom_carte[9].y+tab_nom_carte[9].h){
					SDL_RenderCopy(renderer_collec, txt_optn10_Hover_T, NULL, &tab_nom_carte[9]);
					SDL_RenderCopy(renderer_collec, img_carte_10_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 11
				else if(e.button.x >= tab_nom_carte[10].x && e.button.x <= tab_nom_carte[10].x+tab_nom_carte[10].w && e.button.y >= tab_nom_carte[10].y && e.button.y <= tab_nom_carte[10].y+tab_nom_carte[10].h){
					SDL_RenderCopy(renderer_collec, txt_optn11_Hover_T, NULL, &tab_nom_carte[10]);
					SDL_RenderCopy(renderer_collec, img_carte_11_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LA CARTE 12
				else if(e.button.x >= tab_nom_carte[11].x && e.button.x <= tab_nom_carte[11].x+tab_nom_carte[11].w && e.button.y >= tab_nom_carte[11].y && e.button.y <= tab_nom_carte[11].y+tab_nom_carte[11].h){
					SDL_RenderCopy(renderer_collec, txt_optn12_Hover_T, NULL, &tab_nom_carte[11]);
					SDL_RenderCopy(renderer_collec, img_carte_12_T, NULL, &Carte_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//SOURIS QUI HOVER SUR LE BOUTON RETOUR MENU
				else if(e.button.x >= texte_retour_R.x && e.button.x <= texte_retour_R.x+texte_retour_R.w && e.button.y >= texte_retour_R.y && e.button.y <= texte_retour_R.y+texte_retour_R.h){
					SDL_RenderCopy(renderer_collec, retour_menu_Hover_T, NULL, &texte_retour_R);
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=1;
				}
				//Si on a deja effectué des hovers
				else if(oldHover){
					SDL_RenderClear(renderer_collec);
					SDL_RenderCopy(renderer_collec, img_Collec_BG, NULL, NULL);
					SDL_RenderCopy(renderer_collec, img_planche_bg1_T, NULL, &planche_R);
					SDL_RenderCopy(renderer_collec, img_Planche_haut_T, NULL, &planche_haut_R);
					SDL_RenderCopy(renderer_collec, img_Planche_bas_T, NULL, &planche_bas_R);
					SDL_RenderCopy(renderer_collec, img_retour_menu_T, NULL, &retour_menu_R);

					//Render de toutes les options du menu principal
					//OPTION 1
					SDL_RenderCopy(renderer_collec, txt_optn1_T, NULL, &tab_nom_carte[0]);
					SDL_RenderCopy(renderer_collec, txt_optn2_T, NULL, &tab_nom_carte[1]);
					SDL_RenderCopy(renderer_collec, txt_optn3_T, NULL, &tab_nom_carte[2]);
					SDL_RenderCopy(renderer_collec, txt_optn4_T, NULL, &tab_nom_carte[3]);
					SDL_RenderCopy(renderer_collec, txt_optn5_T, NULL, &tab_nom_carte[4]);
					SDL_RenderCopy(renderer_collec, txt_optn6_T, NULL, &tab_nom_carte[5]);
					SDL_RenderCopy(renderer_collec, txt_optn7_T, NULL, &tab_nom_carte[6]);
					SDL_RenderCopy(renderer_collec, txt_optn8_T, NULL, &tab_nom_carte[7]);
					SDL_RenderCopy(renderer_collec, txt_optn9_T, NULL, &tab_nom_carte[8]);
					SDL_RenderCopy(renderer_collec, txt_optn10_T, NULL, &tab_nom_carte[9]);
					SDL_RenderCopy(renderer_collec, txt_optn11_T, NULL, &tab_nom_carte[10]);
					SDL_RenderCopy(renderer_collec, txt_optn12_T, NULL, &tab_nom_carte[11]);
					SDL_RenderCopy(renderer_collec, retour_menu_Hover_T, NULL, &texte_retour_R);
					SDL_RenderCopy(renderer_collec, retour_menu_T, NULL, &texte_retour_R);

					//On fait le rendu !
					SDL_RenderPresent(renderer_collec);
					//oldHover: Variable qui permet d'éviter de render toutes les frames, si pas besoin
					oldHover=0;
				}

			break;
    		}
          }
        }
      }
	return 1;
	}
