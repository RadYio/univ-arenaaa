#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include "../header/carte.h"
#include "../header/affichage.h"
#include "../header/bot.h"


//fonction qui parcours la formation du bot, s'il trouve un -2 (endroit où il peut placer une carte)
//il en place une, sinon il attaque une carte de l'adversaire
int parcours_formation(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot){
    int i, j;
    for(i = 0; i < 5; i++){
        for(j = 0; j < 3; j++){
            if(tab_formation_cartesADV[i][j] == -2){
                //si le bot trouve un emplacement vide il place la premiere carte de sa main là
                tab_formation_cartesADV[i][j] = main_bot[0].id_image;
                (*taille_main_bot)--;
                supprimer_carte_tab(main_bot, 0, taille_main_bot);
                return 1; //on retourne une valeur vraie pour lancer le if dans la fonction bot
            }
        }
    }
    return 0; //si on a rien trouvé de vide on retourne une valeur fausse et donc cela va lancer la fonction d'attaque
}



void attaquer_carte_bot(){

}




//fonction gerant le tour du bot
void bot(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot){
    //on regarde si le bot peut placer une carte, si la main est vide il reste plus rien a placer il attaque donc
    if((*taille_main_bot != 0) && (parcours_formation(tab_formation_cartesADV, main_bot, taille_main_bot))){
        return;
    }
    //si la main est vide ou le plateau est rempli de cartes il attaque une carte du joeuer
    attaquer_carte_bot();
}