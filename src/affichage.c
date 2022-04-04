/**
 * @file affichage.c
 * @author Jonathan Otto et Arthur Boullier
 * @brief fichier contenant les fonctions d'affichage du jeu ainsi que certaines fonctions essentielles à la mise à jour de tableaux qui seront affichés ensuite
 * @version 1
 * @date 2022-03-28
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/affichage.h"
#include "../header/init_jeu_solo.h"


void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture){
  // Le fond de la fenêtre sera blanc
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);

  SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);
}


void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j){
  //creation de rectangle du joueur
  SDL_SetRenderDrawColor( renderer_jeu, 0, 213, 255, 255 ); //renderer passe en bleu pour le rectangle de la zone joueur
  SDL_RenderDrawRect(renderer_jeu, rect_joueur);

  //creation du rectangle de l'adversaire
  SDL_SetRenderDrawColor( renderer_jeu, 219, 0, 0, 255 ); //renderer passe en rouge pour le rectangle de la zone adversaire
  SDL_RenderDrawRect(renderer_jeu, rect_adv);

  SDL_SetRenderDrawColor( renderer_jeu, 0, 219, 0, 255 ); //renderer passe en vert pour le rectangle de la zone d'affichage d'une carte en particulier
  SDL_RenderDrawRect(renderer_jeu, rect_aff_carte_j);
}


void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]){
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255); //on passe en jaune
  for(int i = 0; i < *taille_main; i++){
    SDL_RenderDrawRect(renderer_jeu, &tab_rect_main[i]);
  }
}


 void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[]){
    int i;
    for(i = 0; i < *taille_main; i++){
      affichage_carte(renderer_jeu, tab_main,i, tab_rect_main[i]);
    }
}



void affichage_carte(SDL_Renderer* renderer_jeu, carte_t tab_carte[], int id_carte, SDL_Rect rect_afficher){
  SDL_Surface* carte_s = IMG_Load(tab_carte[id_carte].chemin_carte);
  SDL_Texture* cartes_T = SDL_CreateTextureFromSurface(renderer_jeu, carte_s);

  SDL_FreeSurface(carte_s);

  SDL_RenderCopy(renderer_jeu, cartes_T, NULL, &rect_afficher);
  SDL_DestroyTexture(cartes_T);
}


void afficher_rectangles_formation(SDL_Renderer* renderer_jeu,carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[][3], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[][3]){
  //creation des rectangles pour les lieux de placement des cartes
    SDL_SetRenderDrawColor(renderer_jeu, 255, 215, 0, 255); //renderer passe en jaune pour ces rectangles
    int x=0,y=0;

    //on va parcourir les 2 matrices de formation, et là où il y à un -2, on affichera un rectangle
    //à mettre dans une fonction séparé car long et moche :(
    //affichage colone 1 joueur
    for(int i=0; i < 15;i++){
      if(x == 4 && y < 2)y++;
      x =  i%5;
      if(tab_formation_cartesJ[x][y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationJ[x][y]);
      }
      else if(tab_formation_cartesJ[x][y] == -1) {
      }
      else {
        affichage_carte(renderer_jeu,tab_cartes_total,tab_formation_cartesJ[x][y],tab_rect_formationJ[x][y]) ;
      }
      if(tab_formation_cartesADV[x][2-y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[x][2-y]);
      }
      else if(tab_formation_cartesADV[x][2-y] == -1) {
      }
      else{
        affichage_carte(renderer_jeu,tab_cartes_total,tab_formation_cartesADV[x][2-y],tab_rect_formationAdv[x][2-y]) ;
      }
    }
}


void double_clique2(SDL_Renderer *renderer_jeu, int id_carte, carte_t tab_cartes_deck[], SDL_Rect *rect_aff_carte_j, SDL_Rect *rect_aff_att_j, SDL_Rect *rect_aff_hp_j, TTF_Font* police){
  SDL_Color couleurBlanche = {255, 255, 255};
  char attaque[4];
  char hp[4];
  snprintf(attaque,sizeof(attaque),"%i",tab_cartes_deck[id_carte].nb_degats);
  snprintf(hp,sizeof(hp),"%i",tab_cartes_deck[id_carte].hp_carte);
  printf("\n\n\nhp = %i\n\n\n",tab_cartes_deck[id_carte].hp_carte);




  carte_t tab_carte_temp[13];
  init_cartes(tab_carte_temp);


  SDL_Surface * att_carte_S = TTF_RenderUTF8_Blended(police, attaque, couleurBlanche);
  SDL_Surface * hp_carte_S = TTF_RenderUTF8_Blended(police, hp, couleurBlanche);

  SDL_Texture* att_carte_T = SDL_CreateTextureFromSurface(renderer_jeu, att_carte_S);
  SDL_Texture* hp_carte_T = SDL_CreateTextureFromSurface(renderer_jeu, hp_carte_S);

  //creation du rectangle pour le texte de deck de l'adversaire
  *rect_aff_att_j = creer_rectangle(700, 325, 30, sizeof(attaque)*8);

  //creation du rectangle pour le texte de deck de l'adversaire
  *rect_aff_hp_j = creer_rectangle(885, 325, 30, sizeof(hp)*8);

  SDL_FreeSurface(att_carte_S);
  SDL_FreeSurface(hp_carte_S);

  SDL_RenderCopy(renderer_jeu, att_carte_T, NULL, rect_aff_att_j);
  SDL_RenderCopy(renderer_jeu, hp_carte_T, NULL, rect_aff_hp_j);

  affichage_carte(renderer_jeu, tab_carte_temp, id_carte, *rect_aff_carte_j);
  SDL_RenderCopy(renderer_jeu, att_carte_T, NULL, rect_aff_att_j);
  SDL_RenderCopy(renderer_jeu, hp_carte_T, NULL, rect_aff_hp_j);
  SDL_RenderPresent(renderer_jeu);
  return;

}


void affichage_actions(SDL_Renderer *renderer_jeu,int * nb_actions){
  SDL_Surface* energie_S = IMG_Load("img/eclair.png");
  SDL_Texture* energie_T = SDL_CreateTextureFromSurface(renderer_jeu, energie_S);
  for(int i = 0 ; i < *nb_actions ; i++){
    printf("essai %i\n ",i);
    SDL_Rect image_action_R = creer_rectangle(50 + (70*i),830,60,60 );
    SDL_RenderCopy(renderer_jeu, energie_T, NULL, &image_action_R);
  }
  SDL_FreeSurface(energie_S);
}



void affichage_jeu2 (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,
SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,
int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[][3],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[][3] ,
int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[],SDL_Texture *menu_t,SDL_Rect menu_R
,SDL_Texture *txt_menu_Hover_T,
SDL_Rect txt_menu_R,SDL_Texture *txt_menu_T,SDL_Texture *passe_t,SDL_Rect passe_R,SDL_Texture *txt_passe_Hover_T
,SDL_Texture *txt_passe_T,SDL_Rect txt_passe_R,int * nb_actions){
    printf("on affiche \n\n");

    SDL_RenderClear(renderer_jeu);



    affichage_BG(renderer_jeu, img_jeu_Texture);



    affichage_gros_rectangles(renderer_jeu, rect_joueur, rect_adv,rect_aff_carte_j);

    afficher_rectangles_formation(renderer_jeu,tab_cartes_total,tab_formation_cartesJ, tab_rect_formationJ, tab_formation_cartesADV, tab_rect_formationAdv);


    afficher_rectangles_main(taille_main,renderer_jeu, tab_rect_main);

    affichage_main(taille_main,renderer_jeu, tab_main, tab_rect_main);


    SDL_RenderCopy(renderer_jeu, txt_titre_joueur_T, NULL, rect_txt_deck_j);
    SDL_RenderCopy(renderer_jeu, txt_titre_adv_T, NULL, rect_txt_deck_adv);

    SDL_RenderCopy(renderer_jeu, menu_t, NULL, &menu_R);
    SDL_RenderCopy(renderer_jeu, txt_menu_T, NULL, &txt_menu_R);
    SDL_RenderCopy(renderer_jeu, passe_t, NULL, &passe_R);
    SDL_RenderCopy(renderer_jeu, txt_passe_T, NULL, &txt_passe_R);
    affichage_actions(renderer_jeu,nb_actions);


    //On fait le rendu !
    SDL_RenderPresent(renderer_jeu);
}



 void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main){
  for(int i = indice_main ; i < *taille_main; i++){
    tab_main[i] = tab_main[i+1];
  }
}


void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main){
  //suppression de la carte dans tab_main
  (*taille_main)--;
  supprimer_carte_tab(tab_main, indice_main, taille_main);
  //mise à jour des rectangles
  creation_main(taille_main, tab_rect_main);
}



 void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main){
  //mises à jour des tableaux
  if(tab_formation_cartesJ[colone][ligne] == -2){ //si on peut placer une carte (-2 représente un endroit où on peut)
    //mise à jour de notre formation,on remplace le -2 par l'id de la carte
    tab_formation_cartesJ[colone][ligne] = tab_main[indice_main].id_carte;
    //mise à jour de notre main, on supprime la carte en question, et on arrete de l'afficher dans la main ainsi que son rectangle avec
    suppression_carte_main(tab_main, indice_main, tab_rect_main, taille_main);
  }
}


int victoire(SDL_Renderer* renderer_jeu,int* taille_deck_j,int* taille_deck_adv){
  //le joueur perd, on return 1
  if(*taille_deck_j <= 0 && *taille_deck_adv > 0){
    printf("defaite du joueur\n");
    affichage_victoire(renderer_jeu,1);

    return 1;
  }
  //le joueur gagne, on return 2
  if(*taille_deck_j > 0 && *taille_deck_adv <= 0){
    printf("victoire du joueur\n");
    affichage_victoire(renderer_jeu,2);
    return 2;
  }
  //si les 2 sont égal à 0 en meme temps alors il y a eu un bug, on return -1
  if(*taille_deck_j <= 0 && *taille_deck_adv <= 0){
    printf("bug dans la taille des deck, dans fonction victoire\n");
    affichage_victoire(renderer_jeu,-1);

    return -1;
  }
  //sinon personne gagne, on return 0
  return 0;
}


void affichage_victoire(SDL_Renderer* renderer_jeu,int victoire){
  SDL_SetRenderDrawBlendMode(renderer_jeu, SDL_BLENDMODE_BLEND);
  SDL_Color couleurBlanche = {255, 255, 255};
  char * texte_victoire = malloc(sizeof(texte_victoire));
  TTF_Font* police = TTF_OpenFont("font/ChowFun.ttf", 20);  
  if (police == NULL) {
    fprintf(stderr, "error: font not found\n");
    printf("\n%s\n",TTF_GetError());
    exit(EXIT_FAILURE);
  }
  SDL_Surface * texte_victoire_S ;
  switch(victoire){
    case 2:
      snprintf(texte_victoire, sizeof("Vous avez Gagné !"), "%s", "Vous avez Gagné !");
      break;
    case 1:
      snprintf(texte_victoire, sizeof("Vous avez Perdu !"), "%s", "Vous avez Perdu !");
      break;
    case -1:
      snprintf(texte_victoire, sizeof("Égalité !"), "%s", "Égalité !");
      break;
  }
  texte_victoire_S = TTF_RenderUTF8_Blended(police,texte_victoire , couleurBlanche);
  SDL_Rect texte_victoire_R = creer_rectangle(800-(sizeof(*texte_victoire)/2),500,50,sizeof(*texte_victoire)*200);
  SDL_Texture * texte_victoire_T = SDL_CreateTextureFromSurface(renderer_jeu,texte_victoire_S);
  SDL_FreeSurface(texte_victoire_S);
  free(texte_victoire);
  for(int i = 1;i < 5 ; i++){
    SDL_SetRenderDrawColor(renderer_jeu, 0, 0, 0, 62.5 * i);
    SDL_RenderFillRect(renderer_jeu, NULL);
    SDL_RenderCopy(renderer_jeu,texte_victoire_T,NULL,&texte_victoire_R);
    SDL_RenderPresent(renderer_jeu);
    sleep(1);
  }

}


int action(int * nb_actions){
  if(*nb_actions){
    *nb_actions = *nb_actions - 1;
    return 1;
  }
  printf("Pas d'actions disponnibles \n\n");
  return 0;
}


void nouveau_tour(int * nb_actions, int tab_formation[][3]){
  *nb_actions = 1;
  int j;
  int temp = 1;
  for(int i=0;i < 3;i++){
    for( j=0; j < 5 ; j++){
      if(tab_formation[j][i]==-2)temp = -1;
    }
    if(temp == 1)*nb_actions = *nb_actions + 1;
    temp = 1;
  }
}


void * calcul_temps(void * val){
  int * jeu =malloc(sizeof(int));
  jeu =  (int*)(val);


  time_t t1, t2;
  t1 = time(NULL);
 	t2 = time(NULL);
  while(1)
  {
      //un tour de 60 secondes
      if(difftime(t2, t1) >= 60){
        *jeu = 0;
        t1 = time(NULL);
      }
      if(*jeu == 0){
        printf ("reset temps\n");
        t1 = time(NULL);
      }
      t2 = time(NULL);
  }
}
