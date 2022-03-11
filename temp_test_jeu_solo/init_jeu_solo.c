#include "../header/window.h"
//#include "../header/tour.h"
#include "../header/affichages.h"
#include "../header/init_jeu_solo.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

void creation_main(int taille_main,SDL_Rect tab[]){
  int milieu = 800;
  if (taille_main == 0){
    return;
  }
  //si la main est impaire
  else if(taille_main%2==1){
    printf("impair");
    int x = milieu + 5 - (71 * (taille_main));
    for(int i=0;i<taille_main;i++){
      tab[i]=creer_rectangle(x,830,144,132);
      x += 142;
    }
  }
  else{
    printf("pair");
    int x = milieu - 5 - (71 * (taille_main));
    printf("%i\n\n",x);
    for(int i=0;i<taille_main;i++){
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
    rect_temp.w = w;
    rect_temp.h = h;
    return rect_temp;
}

//initialise les rectangles qu'il faut et les place dans des tableaux qui seront retournés
void init_jeu(int taille_main,SDL_Rect tab_rect_formationJ[15], SDL_Rect tab_rect_formationAdv[15], SDL_Rect tab_rect_main[12], SDL_Rect* rect_joueur, SDL_Rect* rect_adv, SDL_Rect* rect_txt_deck_j, SDL_Rect* rect_txt_deck_adv){
    
    
    //creation de rectangles pour les zones d'affichage-------------------------------------------------------------

    //creation du rectangle pour la zone joueur
    *rect_joueur = creer_rectangle(100, 75, 750, 600);

    //creation du rectangle pour la zone adversaire
    *rect_adv = creer_rectangle(900, 75, 750, 600);

    //creation du rectangle pour le texte de deck du joueur
    *rect_txt_deck_j = creer_rectangle(300, 20, 50, 200);

    //creation du rectangle pour le texte de deck de l'adversaire
    *rect_txt_deck_adv = creer_rectangle(1060, 20, 50, 300);

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
    tab_rect_formationJ[0] = rect_formationJ1;
    tab_rect_formationJ[1] = rect_formationJ2;
    tab_rect_formationJ[2] = rect_formationJ3;
    tab_rect_formationJ[3] = rect_formationJ4;
    tab_rect_formationJ[4] = rect_formationJ5;
    tab_rect_formationJ[5] = rect_formationJ6;
    tab_rect_formationJ[6] = rect_formationJ7;
    tab_rect_formationJ[7] = rect_formationJ8;
    tab_rect_formationJ[8] = rect_formationJ9;
    tab_rect_formationJ[9] = rect_formationJ10;
    tab_rect_formationJ[10] = rect_formationJ11;
    tab_rect_formationJ[11] = rect_formationJ12;
    tab_rect_formationJ[12] = rect_formationJ13;
    tab_rect_formationJ[13] = rect_formationJ14;
    tab_rect_formationJ[14] = rect_formationJ15;





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
    tab_rect_formationAdv[0] = rect_formationAdv1;
    tab_rect_formationAdv[1] = rect_formationAdv2;
    tab_rect_formationAdv[2] = rect_formationAdv3;
    tab_rect_formationAdv[3] = rect_formationAdv4;
    tab_rect_formationAdv[4] = rect_formationAdv5;
    tab_rect_formationAdv[5] = rect_formationAdv6;
    tab_rect_formationAdv[6] = rect_formationAdv7;
    tab_rect_formationAdv[7] = rect_formationAdv8;
    tab_rect_formationAdv[8] = rect_formationAdv9;
    tab_rect_formationAdv[9] = rect_formationAdv10;
    tab_rect_formationAdv[10] = rect_formationAdv11;
    tab_rect_formationAdv[11] = rect_formationAdv12;
    tab_rect_formationAdv[12] = rect_formationAdv13;
    tab_rect_formationAdv[13] = rect_formationAdv14;
    tab_rect_formationAdv[14] = rect_formationAdv15;

    /*
    //creation des rectangles pour l'affichage des cartes dans la main du joueur
    SDL_Rect rect_main1 = creer_rectangle(2, 830, 144, 132);
    SDL_Rect rect_main2 = creer_rectangle(135, 830, 144, 132);
    SDL_Rect rect_main3 = creer_rectangle(268, 830, 144, 132);
    SDL_Rect rect_main4 = creer_rectangle(401, 830, 144, 132);
    SDL_Rect rect_main5 = creer_rectangle(534, 830, 144, 132);
    SDL_Rect rect_main6 = creer_rectangle(667, 830, 144, 132);
    SDL_Rect rect_main7 = creer_rectangle(800, 830, 144, 132);
    SDL_Rect rect_main8 = creer_rectangle(933, 830, 144, 132);
    SDL_Rect rect_main9 = creer_rectangle(1066, 830, 144, 132);
    SDL_Rect rect_main10 = creer_rectangle(1199, 830, 144, 132);
    SDL_Rect rect_main11 = creer_rectangle(1332, 830, 144, 132);
    SDL_Rect rect_main12 = creer_rectangle(1465, 830, 144, 132);
    //tableau qui repertorie les rectangles liés a la main du joueur

    tab_rect_main[0] = rect_main1;
    tab_rect_main[1] = rect_main2;
    tab_rect_main[2] = rect_main3;
    tab_rect_main[3] = rect_main4;
    tab_rect_main[4] = rect_main5;
    tab_rect_main[5] = rect_main6;
    tab_rect_main[6] = rect_main7;
    tab_rect_main[7] = rect_main8;
    tab_rect_main[8] = rect_main9;
    tab_rect_main[9] = rect_main10;
    tab_rect_main[10] = rect_main11;
    tab_rect_main[11] = rect_main12;
    */
   
    creation_main(taille_main,tab_rect_main);


    


}