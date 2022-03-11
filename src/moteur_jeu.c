#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../header/jeu_solo.h"
#include "../header/moteur_jeu.h"
#include "../header/carte.h"


int aleat_gen(int max){
    srand(time(NULL));
    return rand() % max;
}

//vérifier tout les int tab main pour les transformés en carte_t 
void init_main_joueur(int * taille_main,carte_t tab_deck[],carte_t tab_main[]){
    *taille_main = 10;    
    int temp;
    //création de la main de base du joueur conteant 6 cartes prises au hasard dans son deck
    for(int i =0;i < 10;i++){
        tab_main[i] = tab_deck[i];
    } 
}

void tour_joueur(){
    time_t t1, t2;
    t1 = time(NULL);
 	t2 = time(NULL);
    //boucle de tour de 1 minute
    while(difftime(t2, t1) <= 60)
    {
        t2 = time(NULL);
        


    }
}

void moteur_jeu(int * taille_main,carte_t tab_deck[],carte_t tab_main[]){

    init_main_joueur(taille_main,tab_deck,tab_main);

        

}