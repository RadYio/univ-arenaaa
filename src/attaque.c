/**
 * @file attaque.c
 * @author Jonathan Otto
 * @brief ensemble des fonctions gérant le système d'attaque : l'attaque d'une carte, la mise a jour des hp et enlevement de cartes si nécessaire
 * @version 1
 * @date 2022-03-30 
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

/**
 * @fn attaque_critique(type_t attaque, type_t vulnerable)
 * @brief fonction qui vérifie si celui qui défend est vulnerable au type d'attaque
 * 
 * @param attaque le type d'attaque de la carte d'attaque
 * @param vulnerable le type de vulnérabilité de la carte de défense
 * @return renvoi 1 s'il s'agit d'une attaque critique, 0 sinon
 */
int attaque_critique(type_t attaque, type_t vulnerable){
    //Poison est vulnérable à Physique, Psy est vulnérable contre Poison et Physique est vulnérable à Psy
    return((attaque == Physique && vulnerable == Poison) || (attaque == Poison && vulnerable == Psy) || (attaque == Psy && vulnerable == Physique));
}

/**
 * @fn mort_carte(int id_carte_defense, carte_t deck_defense[], int tab_formation_defense[][3], int indice_deck, int* taille_deck_defense)
 * @brief fonction qui vérifie la mort d'un carte : si une carte n'a plus d'hp, on doit l'enlever de la formation et du deck
 * 
 * @param id_carte_defense id de la carte qui défend, pris depuis la matrice de formation de celui qui défend
 * @param deck_defense le deck de la défense, permet de faire correspondre l'id de la carte qui se fait attaquer à ses attributs (hp, nombre de dégats)
 * @param tab_formation_defense la matrice de formation de la défense, permet la mise à jour de cette dernière si une carte meurt
 * @param indice_deck l'indice dans le deck de défense de la carte qui est morte
 * @param taille_deck_defense taille du deck de la défense, permet la mise à jour du deck de défense
 */
void mort_carte(int id_carte_defense, carte_t deck_defense[], int tab_formation_defense[][3], int indice_deck, int* taille_deck_defense){
    int i = 0, j = 0, trouve = 0;
    printf("on rentre dans mort carte\n");
    //on parcourt la formation de la defense et on trouve l'emplacement de l'id de la carte mort pour la remplace
    trouve = 0;
    while(tab_formation_defense[i][j] != id_carte_defense && i < 5){ // un emplacement vide est -1 ou -2, s'il y a un nombre positif alors c'est une carte
        j = 0;
        while(tab_formation_defense[i][j] != id_carte_defense && j < 3){
            j++;
            if(tab_formation_defense[i][j] == id_carte_defense) trouve = 1; //on a trouvé l'emplacement, on met trouve = 1 pour eviter de faire le i++ après qui ferait tout bugger
        }
        if(!trouve) i++;
    } 
    
    //on a trouvé l'emplacement de l'id de la carte, on la remplace par -2
    tab_formation_defense[i][j] = -2;
    printf("tab formation defense apres mort carte : ");
    for(int p = 0; p < 5; p++){
        printf("\n");
        for(int l = 0; l < 3; l++){
            printf("%i ", tab_formation_defense[p][l]);
        }
    }

    //on supprime la carte du deck
    (*taille_deck_defense)--;
    supprimer_carte_tab(deck_defense, indice_deck, taille_deck_defense);
} 

/**
 * @fn attaque(int id_carte_attaque, int id_carte_defense, carte_t deck_attaque[], carte_t deck_defense[], int tab_formation_defense[][3], int* taille_deck_defense)
 * @brief fonction gérant le fait que quelqu'un attaque une carte
 * 
 * @param id_carte_attaque identifiant de la carte qui attaque, pris depuis la matrice de formation de celui qui attaque
 * @param id_carte_defense identifiant de la carte qui défend, pris depuis la matrice de formation de celui qui défend
 * @param deck_attaque deck de celui qui attaque, permet de faire correspondre l'id de la carte qui attaque à ses attributs
 * @param deck_defense deck de celui qui défend, même principe que deck_attaque mais pour celui qui défend
 * @param tab_formation_defense la matrice de formation de celui qui défend, permet de savoir où se trouve sur le plateau la carte qui défend
 * @param taille_deck_defense la taille du deck de celui qui défend, permet sa mise à jour si une carte meurt
 */
void attaque(int id_carte_attaque, int id_carte_defense, carte_t deck_attaque[], carte_t deck_defense[], int tab_formation_defense[][3], int* taille_deck_defense){
    int i = 0, j = 0, nb_degats, hp_carte;
    //parcours du deck de l'attaquant pour trouver la carte correspondante
    printf("test attaque %i\n",i);
    printf("id = %i",deck_attaque[i].id_carte );
    for(i = 0; deck_attaque[i].id_carte != id_carte_attaque && i < 13; i++){
      i++;
      //printf("id = %i et i = %i\n",deck_attaque[i].id_carte, i );
    }
    //on a trouvé la carte correspondante, on recupere donc la valeur d'attaque
    nb_degats = deck_attaque[i].nb_degats;
    printf("nb dégats : %i\n\n",nb_degats);


    //parcours du deck de l'adversaire pour trouver la carte correspondante
    j = 0;
    while(deck_defense[j].id_carte != id_carte_defense){
        j++;
        printf("id_carte_defense = %i, j = %i, deck.id_carte = %i\n", id_carte_defense, j, deck_defense[j].id_carte );
    }
    hp_carte = deck_defense[j].hp_carte;

    //on regarde si on fait une attaque critique : les degats sont multipliés par 2 si c'est le cas
    if(attaque_critique(deck_attaque[i].type_attaque, deck_defense[j].type_vulnerable)){
        nb_degats *= 2;
    }
    printf("hp : %i et nb dégats : %i\n\n",hp_carte,nb_degats);
    //on enleve les hp correspondant
    deck_defense[j].hp_carte = deck_defense[j].hp_carte  - nb_degats;
    printf("hp apres : %i et nb dégats : %i\n\n",deck_defense[j].hp_carte,nb_degats);

    //si la carte à plus de hp elle meurt, on l'enleve donc du jeu
   if(deck_defense[j].hp_carte <= 0){
        mort_carte(id_carte_defense, deck_defense, tab_formation_defense, j, taille_deck_defense);
    }

}
