#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/affichage.h"
#include "../header/init_jeu_solo.h"

void creation_main(int * taille_main,SDL_Rect tab[]){
  int milieu = 800;
  if (*taille_main == 0){
    return;
  }
  //si la main est impaire
  else if(*taille_main%2==1){
    int x = milieu + 5 - (71 * (*taille_main));
    for(int i=0;i<*taille_main;i++){
      tab[i]=creer_rectangle(x,830,144,132);
      x += 142;
    }
  }

  else{
    int x = milieu - 5 - (71 * (*taille_main));
    for(int i=0;i<*taille_main;i++){
      tab[i]=creer_rectangle(x,830,144,132);
      x += 142;
    }
  }
}

//focntion de creation d'un rectangle prcq sinon ca va devenir le cancer a devoir déclarer 30 rectangles avec 150 lignes rien que pour ca
SDL_Rect creer_rectangle(int x, int y, int h, int w){
    SDL_Rect rect_temp;
    rect_temp.x = x;
    rect_temp.y = y;
    rect_temp.h = h;
    rect_temp.w = w;
    return rect_temp;
}

//initialise les rectangles qu'il faut et les place dans des tableaux qui seront retournés
void init_jeu(int  * taille_main,SDL_Rect tab_rect_formationJ[][3], SDL_Rect tab_rect_formationAdv[][3], SDL_Rect tab_rect_main[12],
 SDL_Rect* rect_joueur, SDL_Rect* rect_adv, SDL_Rect* rect_txt_deck_j, SDL_Rect* rect_txt_deck_adv,SDL_Rect* rect_aff_carte_j,
 SDL_Rect* rect_aff_att_j ,SDL_Rect* rect_aff_hp_j){


    //creation de rectangles pour les zones d'affichage-------------------------------------------------------------

    //creation du rectangle pour la zone joueur
    *rect_joueur = creer_rectangle(100, 75, 750, 600);

    //creation du rectangle pour la zone adversaire
    *rect_adv = creer_rectangle(900, 75, 750, 600);

    //creation du rectangle pour le texte de deck du joueur
    *rect_txt_deck_j = creer_rectangle(300, 20, 50, 200);

    //creation du rectangle pour le texte de deck de l'adversaire
    *rect_txt_deck_adv = creer_rectangle(1060, 20, 50, 200);

    //creation du rectangle pour le texte de deck de l'adversaire
    *rect_aff_carte_j = creer_rectangle(675, 20, 350, 250);





    //creation des rectangles pour l'affichage des cartes sur le plateau du joueur
    //à noter : pour les cartes, hauteur = 144, largeur = 132, 5 de marge en hauteur, 51 de marge en largeur entre les cartes
    //cartes de la colonne 1 (de gauche à droite)
    SDL_Rect rect_formationJ1 = creer_rectangle(151, 80, 144, 132);
    SDL_Rect rect_formationJ2 = creer_rectangle(151, 229, 144, 132);
    SDL_Rect rect_formationJ3 = creer_rectangle(151, 378, 144, 132);
    SDL_Rect rect_formationJ4 = creer_rectangle(151, 527, 144, 132);
    SDL_Rect rect_formationJ5 = creer_rectangle(151, 676, 144, 132);
    //cartes de la colonne 2
    SDL_Rect rect_formationJ6 = creer_rectangle(334, 80, 144, 132);
    SDL_Rect rect_formationJ7 = creer_rectangle(334, 229, 144, 132);
    SDL_Rect rect_formationJ8 = creer_rectangle(334, 378, 144, 132);
    SDL_Rect rect_formationJ9 = creer_rectangle(334, 527, 144, 132);
    SDL_Rect rect_formationJ10 = creer_rectangle(334, 676, 144, 132);
    //cartes de la colonne 3
    SDL_Rect rect_formationJ11 = creer_rectangle(517, 80, 144, 132);
    SDL_Rect rect_formationJ12 = creer_rectangle(517, 229, 144, 132);
    SDL_Rect rect_formationJ13 = creer_rectangle(517, 378, 144, 132);
    SDL_Rect rect_formationJ14 = creer_rectangle(517, 527, 144, 132);
    SDL_Rect rect_formationJ15 = creer_rectangle(517, 676, 144, 132);
    tab_rect_formationJ[0][0] = rect_formationJ1;
    tab_rect_formationJ[1][0] = rect_formationJ2;
    tab_rect_formationJ[2][0] = rect_formationJ3;
    tab_rect_formationJ[3][0] = rect_formationJ4;
    tab_rect_formationJ[4][0] = rect_formationJ5;
    tab_rect_formationJ[0][1] = rect_formationJ6;
    tab_rect_formationJ[1][1] = rect_formationJ7;
    tab_rect_formationJ[2][1] = rect_formationJ8;
    tab_rect_formationJ[3][1] = rect_formationJ9;
    tab_rect_formationJ[4][1] = rect_formationJ10;
    tab_rect_formationJ[0][2] = rect_formationJ11;
    tab_rect_formationJ[1][2] = rect_formationJ12;
    tab_rect_formationJ[2][2] = rect_formationJ13;
    tab_rect_formationJ[3][2] = rect_formationJ14;
    tab_rect_formationJ[4][2] = rect_formationJ15;





    //creation des rectangles pour l'affichage des cartes sur le plateau adversaire
    //cartes de la colonne 1 (de droite à gauche)
    SDL_Rect rect_formationAdv1 = creer_rectangle(1317, 80, 144, 132);
    SDL_Rect rect_formationAdv2 = creer_rectangle(1317, 229, 144, 132);
    SDL_Rect rect_formationAdv3 = creer_rectangle(1317, 378, 144, 132);
    SDL_Rect rect_formationAdv4 = creer_rectangle(1317, 527, 144, 132);
    SDL_Rect rect_formationAdv5 = creer_rectangle(1317, 676, 144, 132);
    //cartes de la colonne 2
    SDL_Rect rect_formationAdv6 = creer_rectangle(1134, 80, 144, 132);
    SDL_Rect rect_formationAdv7 = creer_rectangle(1134, 229, 144, 132);
    SDL_Rect rect_formationAdv8 = creer_rectangle(1134, 378, 144, 132);
    SDL_Rect rect_formationAdv9 = creer_rectangle(1134, 527, 144, 132);
    SDL_Rect rect_formationAdv10 = creer_rectangle(1134, 676, 144, 132);
    //cartes de la colonne 3
    SDL_Rect rect_formationAdv11 = creer_rectangle(951, 80, 144, 132);
    SDL_Rect rect_formationAdv12 = creer_rectangle(951, 229, 144, 132);
    SDL_Rect rect_formationAdv13 = creer_rectangle(951, 378, 144, 132);
    SDL_Rect rect_formationAdv14 = creer_rectangle(951, 527, 144, 132);
    SDL_Rect rect_formationAdv15 = creer_rectangle(951, 676, 144, 132);
    //à faire, tableau qui repertorie les cartes adversaire
    tab_rect_formationAdv[0][2] = rect_formationAdv1;
    tab_rect_formationAdv[1][2] = rect_formationAdv2;
    tab_rect_formationAdv[2][2] = rect_formationAdv3;
    tab_rect_formationAdv[3][2] = rect_formationAdv4;
    tab_rect_formationAdv[4][2] = rect_formationAdv5;
    tab_rect_formationAdv[0][1] = rect_formationAdv6;
    tab_rect_formationAdv[1][1] = rect_formationAdv7;
    tab_rect_formationAdv[2][1] = rect_formationAdv8;
    tab_rect_formationAdv[3][1] = rect_formationAdv9;
    tab_rect_formationAdv[4][1] = rect_formationAdv10;
    tab_rect_formationAdv[0][0] = rect_formationAdv11;
    tab_rect_formationAdv[1][0] = rect_formationAdv12;
    tab_rect_formationAdv[2][0] = rect_formationAdv13;
    tab_rect_formationAdv[3][0] = rect_formationAdv14;
    tab_rect_formationAdv[4][0] = rect_formationAdv15;

    creation_main(taille_main,tab_rect_main);





}
