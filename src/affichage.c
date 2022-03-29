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



/**
 * @fn void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture)
 * @brief fonction d'affichage du fond lors du jeu
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param SDL_Texture* img_jeu_Texture la texture contenant l'image à afficher
 *
 * @return void
 */
void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture){
  // Le fond de la fenêtre sera blanc
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255);

  SDL_RenderCopy(renderer_jeu, img_jeu_Texture, NULL, NULL);
}

void affichage_energie(int * nb_actions){


}


/**
 * @fn void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j)
 *
 * @brief fonction d'affichage des grands rectangles qui séparent le coté joueur du coté adversaire
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param SDL_Rect* rect_joueur le grand rectangle du joueur
 * @param SDL_Rect* rect_adv le grand rectangle de l'adversaire
 * @param SDL_Rect* rect_aff_carte_j rectangle d'affichage pour la zone d'affichage en gros d'une carte
 *
 * @return void
 */
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


/**
 * @fn void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12])
 * @brief fonction d'affichage des rectangles autour des cartes dans la main du joueur
 * @param int* taille_main variable qui repertorie la taille de la main, permet un affichage dynamique en fonction du nombre de carte
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param SDL_Rect tab_rect_main[] repertorie les rectangles de la main du joueur
 *
 * @return void
 */
void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]){
  SDL_SetRenderDrawColor(renderer_jeu, 255, 255, 255, 255); //on passe en jaune
  for(int i = 0; i < *taille_main; i++){
    SDL_RenderDrawRect(renderer_jeu, &tab_rect_main[i]);
  }
}


//affichage du bouton retour menu et du bouton passage de tour
void afficher_boutton(SDL_Rect* rect_menu,SDL_Rect* rect_passe, SDL_Renderer* renderer_jeu){
  SDL_Surface* menu_s;
  SDL_Surface* passe_s;
  menu_s = IMG_Load("img/img_menu.png");
  passe_s = IMG_Load("img/retour_menu.png");
  SDL_Texture* menu_t;
  SDL_Texture* passe_t;
  menu_t = SDL_CreateTextureFromSurface(renderer_jeu, menu_s);
  passe_t = SDL_CreateTextureFromSurface(renderer_jeu, passe_s);

  SDL_FreeSurface(menu_s);
  SDL_FreeSurface(passe_s);
}



/**
 * @fn void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[])
 * @brief fonction d'affichage des cartes de la main du joueur
 * @param int* taille_main variable qui repertorie la taille de la main, permet un affichage dynamique en fonction du nombre de cartes
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param carte_t tab_main[] tableau qui repertorie quelles cartes possède le joueur dans sa main
 * @param SDL_Rect tab_rect_main[] tableau qui repertorie les rectangles de la main pour savoir où afficher les cartes
 *
 * @return void
 */
 void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[]){
    int i;
    for(i = 0; i < *taille_main; i++){
      affichage_carte(renderer_jeu, tab_main[i], tab_rect_main[i]);
    }
}


/**
 * @fn void affichage_carte(SDL_Renderer* renderer_jeu,carte_t carte,SDL_Rect rect_afficher)
 * @brief fonction d'affichage d'une carte donnée dans un rectangle donnée
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param carte_t carte la carte à afficher
 * @param SDL_Rect rect_afficher le rectangle où afficher la carte en question
 *
 * @return void
 */
void affichage_carte(SDL_Renderer* renderer_jeu,carte_t carte,SDL_Rect rect_afficher){
  SDL_Surface* carte_s;
  SDL_Texture* cartes_T;
  carte_s = IMG_Load(carte.chemin_carte);
  cartes_T = SDL_CreateTextureFromSurface(renderer_jeu, carte_s);
  SDL_FreeSurface(carte_s);
  SDL_RenderCopy(renderer_jeu, cartes_T, NULL, &rect_afficher);
  SDL_DestroyTexture(cartes_T);
}

/**
 * @fn void afficher_rectangles_formation(SDL_Renderer* renderer_jeu,carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[][3], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[][3])
 * @brief fonction d'affichage des rectangles de la formationd du joueur en parcourant la matrice associé et en mettant un rectangle lorsqu'il y à un -2
 * @param SDL_Renderer* renderer_jeu notre renderer
 * @param carte_t tab_cartes_total[] tableau qui repertorie toutes les cartes du jeu, permet de faire corresponndre une id de carte que possède le joueur aux reste des informations de la carte
 * @param int tab_formation_cartesJ[5][3] tableau correspondant à la formation du joueur, -2 correspond à un emplacement où l'on peut poser une carte, -1 est un emplacement où on à rien, et tout chiffre >= 0 est une carte
 * @param SDL_Rect tab_rect_formationJ[][3] tableau correspondant aux rectangles de la formation du joueur, permet de connaitre où on pose les cartes
 * @param int tab_formation_cartesADV[5][3] tableau qui reprend le meme principe que tab_formation_cartesJ[][3] mais pour le coté adversaire
 * @param SDL_Rect tab_rect_formationAdv[][3] tableau qui reprend le meme principe que tab_rect_formationJ[][3] mais pour le coté adversaire
 * @return void
 */
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
        affichage_carte(renderer_jeu,tab_cartes_total[ (tab_formation_cartesJ[x][y]) ],tab_rect_formationJ[x][y]) ;
      }
      if(tab_formation_cartesADV[x][2-y] == -2) {
        SDL_RenderDrawRect(renderer_jeu, &tab_rect_formationAdv[x][2-y]);
      }
      else if(tab_formation_cartesADV[x][2-y] == -1) {
      }
      else{
        affichage_carte(renderer_jeu,tab_cartes_total[(tab_formation_cartesADV[x][2-y])],tab_rect_formationAdv[x][2-y]) ;
      }
    }
}




void double_clique2(SDL_Renderer *renderer_jeu,int id_carte,carte_t tab_cartes_deck[],SDL_Rect *rect_aff_carte_j,SDL_Rect *rect_aff_att_j,SDL_Rect *rect_aff_hp_j,TTF_Font* police){
  SDL_Color couleurBlanche = {255, 255, 255};
  char attaque[4];
  char hp[4];
  snprintf(attaque,sizeof(attaque),"%i",tab_cartes_deck[id_carte].nb_degats);
  snprintf(hp,sizeof(hp),"%i",tab_cartes_deck[id_carte].hp_carte);


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

  affichage_carte(renderer_jeu,tab_cartes_deck[id_carte],*rect_aff_carte_j);
  SDL_RenderCopy(renderer_jeu, att_carte_T, NULL, rect_aff_att_j);
  SDL_RenderCopy(renderer_jeu, hp_carte_T, NULL, rect_aff_hp_j);
  SDL_RenderPresent(renderer_jeu);
  return;

}

// allo
/*void affichage_actions(SDL_Renderer *renderer_jeu,int * nb_actions,TTF_Font* police){
  SDL_Color couleurJaune = {255, 215, 0};
  char action[5];
  snprintf(action,sizeof(action),"%i",*nb_actions);
  SDL_Rect nb_action_R = creer_rectangle(100,800,80,160);
  SDL_Rect image_action_R = creer_rectangle(260,800,80,160);
  SDL_Surface* energie_S = IMG_Load("img/energie.png");
  SDL_Surface* nb_action_S = TTF_RenderUTF8_Blended(police, action, couleurJaune);
  SDL_Texture* energie_T = SDL_CreateTextureFromSurface(renderer_jeu, energie_S);
  SDL_Texture* nb_action_T = SDL_CreateTextureFromSurface(renderer_jeu, nb_action_S);

  SDL_FreeSurface(energie_S);
  SDL_FreeSurface(nb_action_S);

  SDL_RenderCopy(renderer_jeu, energie_T, NULL, &nb_action_R);
  SDL_RenderCopy(renderer_jeu, nb_action_T, NULL, &image_action_R);
}*/


void affichage_jeu2 (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,
SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,
int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[][3],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[][3] ,
int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[],SDL_Texture *menu_t,SDL_Rect menu_R
,SDL_Texture *txt_menu_Hover_T,
SDL_Rect txt_menu_R,SDL_Texture *txt_menu_T,SDL_Texture *passe_t,SDL_Rect passe_R,SDL_Texture *txt_passe_Hover_T
,SDL_Texture *txt_passe_T,SDL_Rect txt_passe_R){
    printf("on affiche \n\n");
    TTF_Font* police = NULL;
    SDL_RenderClear(renderer_jeu);



    affichage_BG(renderer_jeu, img_jeu_Texture);



    affichage_gros_rectangles(renderer_jeu, rect_joueur, rect_adv,rect_aff_carte_j);

    afficher_rectangles_formation(renderer_jeu,tab_cartes_total,tab_formation_cartesJ, tab_rect_formationJ, tab_formation_cartesADV, tab_rect_formationAdv);


    afficher_rectangles_main(taille_main,renderer_jeu, tab_rect_main);

    affichage_main(taille_main,renderer_jeu, tab_main, tab_rect_main);

    //affichage_actions(renderer_jeu,nb_actions,police);

    SDL_RenderCopy(renderer_jeu, txt_titre_joueur_T, NULL, rect_txt_deck_j);
    SDL_RenderCopy(renderer_jeu, txt_titre_adv_T, NULL, rect_txt_deck_adv);

    SDL_RenderCopy(renderer_jeu, menu_t, NULL, &menu_R);
    SDL_RenderCopy(renderer_jeu, txt_menu_T, NULL, &txt_menu_R);
    SDL_RenderCopy(renderer_jeu, passe_t, NULL, &passe_R);
    SDL_RenderCopy(renderer_jeu, txt_passe_T, NULL, &txt_passe_R);

    //On fait le rendu !
    SDL_RenderPresent(renderer_jeu);
}


/**
 * @fn void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main)
 * @brief fonction de suppression d'une carte dans un tableau
 * @param carte_t tab_main[] le tableau qui contient l'élément à supprimer
 * @param int indice_main l'indice de l'élément à supprimer dans le tableau
 * @param int* taille_main taille du tableau
 *
 * @return void
 */
 void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main){
  for(int i = indice_main ; i < *taille_main; i++){
    tab_main[i] = tab_main[i+1];
  }
}

/**
 * @fn void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main)
 * @brief fonction de suppression d'une carte dans la main du joueur
 * @param carte_t tab_main[] tableau de la main où il faut supprimer un élément
 * @param int indice_main indice de l'élément à supprimer dans le tableau
 * @param SDL_Rect tab_rect_main[] tableau de la main du joueur qui possède un élément à supprimer
 * @param int* taille_main la taille de la main qui devra être mis à jour après avoir supprimé un élément
 *
 * @return void
 */
void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main){
  //suppression de la carte dans tab_main
  (*taille_main)--;
  supprimer_carte_tab(tab_main, indice_main, taille_main);
  //mise à jour des rectangles
  creation_main(taille_main, tab_rect_main);
}


/**
 * @fn void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main)
 * @brief fonction qui transfère une carte de la main du joueur sur le plateau
 * @param carte_t tab_main[] tableau de la main dont il faut transférer une carte
 * @param int tab_formation_cartesJ[5][3] tableau qui répértorie où on peut poser une carte, sera mis à jour avec l'id de la carte nouvellement placé à l'endroit voulu
 * @param SDL_Rect tab_rect_main[] tableau des rectangles de la main, sert à savoir sur quelle carte de la main on à cliqué
 * @param int colone sert de coordonnée dans la formation
 * @param int ligne sert de coordonnée dans la formation
 * @param int* taille_main taille de la main qui doit être mis à jour
 *
 * @return void
 */
 void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main){
  //mises à jour des tableaux
  if(tab_formation_cartesJ[colone][ligne] == -2){ //si on peut placer une carte (-2 représente un endroit où on peut)
    //mise à jour de notre formation,on remplace le -2 par l'id de la carte
    tab_formation_cartesJ[colone][ligne] = tab_main[indice_main].id_carte;
    //mise à jour de notre main, on supprime la carte en question, et on arrete de l'afficher dans la main ainsi que son rectangle avec
    suppression_carte_main(tab_main, indice_main, tab_rect_main, taille_main);
  }
}

/*
int victoire(carte_t tab_cartes_deck[],carte_t tab_cartes_deck_bot[]){
  //return 1 si le joueur n'as plus de cartes
  if(tab_cartes_deck[0].id_carte == NULL)return 1;
  //return 2 si le bot n'as plus de cartes
  if(tab_cartes_deck_bot[0].id_carte== NULL)return 2;
  //return 0 si les 2 joueurs ont encore des cartes
  return 0;
}
*/

int action(int * nb_actions){
  SDL_Color couleurRouge = {255, 0, 0};
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
      if(difftime(t2, t1) >= 10){
        *jeu = 0;
        t1 = time(NULL);
      }
      if(*jeu == 0){
        printf ("reset temps\n");
        t1 = time(NULL);
      }
      t2 = time(NULL);
      sleep(1);
      if(*jeu == 1){
      }
  }
}
