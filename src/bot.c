/**
 * @file bot.c
 * @author Jonathan Otto
 * @brief ici on gère les actions du bot qui est actif lorsque le joueur joue en solo
 * @version 1
 * @date 2022-03-28
 */

#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/carte.h"
#include "../header/window.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/affichage.h"
#include "../header/init_jeu_solo.h"
#include "../header/bot.h"
#include "../header/attaque.h"


//fonction qui parcours la formation du bot, s'il trouve un -2 (endroit où il peut placer une carte)
//il en place une, sinon il attaque une carte de l'adversaire
/**
 * @fn int poser_carte(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot)
 * @brief fonction qui permet au bot de poser une carte 
 * 
 * @param tab_formation_cartesADV tableau qui réportorie où le bot peut poser une carte
 * @param main_bot tableau qui contient toutes les cartes que le bot peut poser
 * @param taille_main_bot entier permettat de connaitre la taille de la main du bot
 * @return int si return 1 : permet de lancer une condition si le bot à réussi à poser une carte, son tour s'arrête donc là ; si return 0 : le bot n'a pas pu poser de carte, il attaque donc
 */
int poser_carte(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            if(tab_formation_cartesADV[i][j] == -2){
                //si le bot trouve un emplacement vide il place la premiere carte de sa main là
                tab_formation_cartesADV[i][j] = main_bot[0].id_carte;
                (*taille_main_bot)--;
                supprimer_carte_tab(main_bot, 0, taille_main_bot);
                return 1; //on retourne une valeur vraie pour lancer le if dans la fonction bot
            }
        }
    }
    return 0; //si on a rien trouvé de vide on retourne une valeur fausse et donc cela va lancer la fonction d'attaque
}


//fonction qui permet au bot d'attaquer une carte du joueur
void attaquer_carte_bot(int tab_formation_cartesADV[][3], int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur){
  int i = 0, j = 0, x = 0, y = 0, trouve = 0;
  //le bot choisit la première carte sur laquelle il tombe dans la formation du joueur pour attaquer
  trouve = 0; //variable permettant de pas avoir de problèmes avec les i++, j++ ci-dessous, on sortira de la boucle si on a trouvé en mettant à 1
  while(trouve == 0 && i < 5){
    j = 0;
    while(trouve == 0 && j < 3){
      if(tab_formation_cartesJ[i][j] >= 0){
        printf("j'ai trouve un leo : %i, i = %i, j = %i\n", tab_formation_cartesJ[i][j], i, j);
        trouve = 1;
      }
      if(trouve == 0){
        j++;
      }
    }
    if(trouve == 0){
      i++; 
    }
  }
  
  if(trouve == 0){ // si on a pas trouvé de carte
    printf("pas d'attaque J\n");
    printf("i = %i, j = %i\n", i, j);

    return;
  }
  //sinon le bot attaque avec la première carte qu'il trouve chez lui, on doit donc la trouver
  trouve = 0;
  while(trouve == 0 && x < 5){
    y = 0;
    while(trouve == 0 && y < 3){
      if(tab_formation_cartesADV[x][y] >= 0){
        printf("j'ai trouve un leo ADV : %i, x = %i, y = %i\n", tab_formation_cartesADV[x][y], x, y);
        trouve = 1;
      }
      if(trouve == 0){
        y++;
      }
    }
    if(trouve == 0){
      x++;
    }
  }

  if(trouve == 0){ // si aux coordonnées renvoyées on a pas trouvé de carte
    printf("pas d'attaque ADV\n");
    return;
  }

  //une fois trouvé la carte à attaquer et la carte qui va attaquer, on lance la fonction d'attaque
  printf("    phase d'attaque\n");
  printf("def = %i pour i = %i et j = %i\n",tab_formation_cartesJ[i][j],i,j);

  attaque(tab_formation_cartesADV[x][y], tab_formation_cartesJ[i][j], deck_bot, deck_joueur, tab_formation_cartesJ, taille_deck_joueur);
}




//fonction gerant le tour du bot
void bot(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot, int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur){
    //on regarde si le bot peut placer une carte, si la main est vide il reste plus rien a placer il attaque donc
    printf("On est dans la fonction bot\n");
    if((*taille_main_bot != 0) && (poser_carte(tab_formation_cartesADV, main_bot, taille_main_bot))){
        return;
    }
    //si la main est vide ou le plateau est rempli de cartes il attaque une carte du joeuer
    attaquer_carte_bot(tab_formation_cartesADV, tab_formation_cartesJ, deck_bot, deck_joueur, taille_deck_joueur);
}
