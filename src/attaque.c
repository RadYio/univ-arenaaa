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

//fonction qui vérifie si celui qui défend est vulnerable au type d'attaque, renvoi 1 si c'est le cas, 0 sinon
int attaque_critique(type_t attaque, type_t vulnerable){
    //Poison est vulnérable à Physique, Psy est vulnérable contre Poison et Physique est vulnérable à Psy
    return((attaque == Physique && vulnerable == Poison) || (attaque == Poison && vulnerable == Psy) || (attaque == Psy && vulnerable == Physique));
}

//si une carte n'a plus d'hp, on doit l'enlever de la formation et du deck
void mort_carte(int id_carte_defense, carte_t deck_defense[], int tab_formation_defense[][3], int indice_deck, int* taille_deck_defense){
    int i = 0, j = 0;
    //on parcourt la formation de la defense et on trouve l'emplacement de l'id de la carte mort pour la remplacer
    //on utilise 2 while car cela permet de sortir des boucles une fois l'emplacement trouvé sans devoir faire de break
    for(i = 0; tab_formation_defense[i][j] != id_carte_defense || i < 5; i++){
      for(j = 0; tab_formation_defense[i][j] != id_carte_defense || j < 3; j++);
    //on a trouvé l'emplacement de l'id de la carte, on la remplace par -2
    tab_formation_defense[i][j] = -2;
    //on supprime la carte du deck
    (*taille_deck_defense)--;
    supprimer_carte_tab(deck_defense, indice_deck, taille_deck_defense);
}


//foncton gérant le fait que qqn attaque une carte
void attaque(int id_carte_attaque, int id_carte_defense, carte_t deck_attaque[], carte_t deck_defense[], int tab_formation_defense[][3], int* taille_deck_defense){
    int i = 0, j = 0, nb_degats, hp_carte;
    //parcours du deck de l'attaquant pour trouver la carte correspondante
    printf("test attaque %i\n",i);
    printf("id = %i",deck_attaque[i].id_carte );
    for(i = 0; deck_attaque[i].id_carte != id_carte_attaque && i < 13; i++){
      i++;
      printf("id = %i et i = %i\n",deck_attaque[i].id_carte, i );
    }
    //on a trouvé la carte correspondante, on recupere donc la valeur d'attaque
    nb_degats = deck_attaque[i].nb_degats;
    printf("nb dégats : %i\n\n",nb_degats);

    //parcours du deck de l'adversaire pour trouver la carte correspondante

    while(deck_defense[j].id_carte != id_carte_defense){
        j++;
        //printf("j = %i\n",j);
    }
    hp_carte = deck_defense[j].hp_carte;

    //on regarde si on fait une attaque critique : les degats sont multipliés par 2 si c'est le cas
 /*  if(attaque_critique(deck_attaque[i].type_attaque, deck_defense[j].type_vulnerable)){
        nb_degats *= 2;
    }
*/
    printf("hp : %i et nb dégats : %i\n\n",hp_carte,nb_degats);
    //on enleve les hp correspondant
    deck_defense[j].hp_carte = deck_defense[j].hp_carte  - nb_degats;
    printf("hp apres : %i et nb dégats : %i\n\n",deck_defense[j].hp_carte,nb_degats);

    //si la carte à plus de hp elle meurt, on l'enleve donc du jeu
   if(deck_defense[j].hp_carte <= 0){
        mort_carte(id_carte_defense, deck_defense, tab_formation_defense, j, taille_deck_defense);
    }

}
