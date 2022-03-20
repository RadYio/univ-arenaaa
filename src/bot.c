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
  int i = -1, j = 0, x = -1, y = 0;
  //le bot choisit la première carte sur laquelle il tombe dans la formation du joueur pour attaquer
  while(tab_formation_cartesJ[i][j] < 0 && i < 5){ // un emplacement vide est -1 ou -2, s'il y a un nombre positif alors c'est une carte
    j = 0;
    i++; // i commence à -1 pour conserver le bon indice une fois qu'on à trouvé et qu'on sort de la boucle while dessous
    while(tab_formation_cartesJ[i][j] < 0 && j < 3){
      j++;
    }
  }
  if(i == 5 && j == 3){ // si i == 5 et j == 3 alors on à parcouru toute la formation sans trouver de carte, la formation du joueur est donc vide, le bot n'attaque donc pas
    return;
  }
  //sinon le bot attaque avec la première carte qu'il trouve chez lui, on doit donc la trouver
  while(tab_formation_cartesADV[x][y] < 0 && x < 5){
    y = 0;
    x++; // i commence à -1 pour conserver le bon indice une fois qu'on à trouvé et qu'on sort de la boucle while dessous
    while(tab_formation_cartesADV[x][y] < 0 && y < 3){
      y++;
    }
  }
  //une fois trouvé la carte à attaquer et la carte qui va attaquer, on lance la fonction d'attaque
  attaque(tab_formation_cartesADV[x][y], tab_formation_cartesJ[i][j], deck_bot, deck_joueur, tab_formation_cartesJ, taille_deck_joueur);
}




//fonction gerant le tour du bot
void bot(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot, int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur){
    //on regarde si le bot peut placer une carte, si la main est vide il reste plus rien a placer il attaque donc
    if((*taille_main_bot != 0) && (poser_carte(tab_formation_cartesADV, main_bot, taille_main_bot))){
        return;
    }
    //si la main est vide ou le plateau est rempli de cartes il attaque une carte du joeuer
    attaquer_carte_bot(tab_formation_cartesADV, tab_formation_cartesJ, deck_bot, deck_joueur, taille_deck_joueur);
}
