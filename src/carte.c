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











//fonction de creation de cartes
carte_t * creer_carte(char * nom,char * nom_collec ,char * chemin_carte,int hp , int nb_degats , type_t type_attaque , type_t type_vulnerable, int id_image){
  carte_t * carte;
  carte = malloc(sizeof(carte_t));
  carte->nom = nom;
  carte->nom_collec= nom_collec;
  carte->chemin_carte=chemin_carte;
  carte->hp_carte = hp;
  carte->nb_degats = nb_degats;
  carte->type_attaque = type_attaque;
  carte->type_vulnerable = type_vulnerable;
  carte->id_image = id_image;
  return carte;
}

//fonction d'initialisation de toutes les cartes, 12 en brut car on à que 12 cartes, à modifier si on en rajoute plus

void init_cartes(carte_t * tab_cartes_total[]){
    tab_cartes_total[3] = creer_carte("Allan maître des l'esprit","Allan","../img/.png", 10, 4 , Psy,Poison,3);
    tab_cartes_total[4] = creer_carte("Charly maître du ratio","Charly", "../img/.png",10, 4 , Psy,Poison,4);
    tab_cartes_total[1] = creer_carte("Jonathan maître du temps","Jonathan","../img/Carte_Johno.png", 10, 4 , Physique,Psy,1);
    tab_cartes_total[0] = creer_carte("Léo maître de la bagarre","Léo","../img/Carte_Leo.png", 10, 4 , Physique,Psy,0);
    tab_cartes_total[2] = creer_carte("Alexis maître du sel","Alexis","../img/Carte_Alexis.png", 10, 4 , Poison,Physique,2);
    tab_cartes_total[5] = creer_carte("Arthur maître du silence","Arthur", "../img/.png",10, 4 , Poison,Physique,5);
    tab_cartes_total[6] = creer_carte("ChevaSlier","Chevalier", "../img/.png",5, 3 , Physique,Psy,6);
    tab_cartes_total[7] = creer_carte("Chevalier","Chevalier", "../img/.png",5, 3 , Physique,Psy,7);
    tab_cartes_total[8] = creer_carte("Mage","Mage A", "../img/.png",3, 5 , Psy,Poison,8);
    tab_cartes_total[9] = creer_carte("Mage","Mage B", "../img/.png",3, 5 , Psy,Poison,9);
    tab_cartes_total[10] = creer_carte("Voleur","Voleur A", "../img/.png",4, 4 , Poison,Physique,10);
    tab_cartes_total[11] = creer_carte("Voleur","Voleur B", "../img/.png",4, 4 , Poison,Physique,11);
    tab_cartes_total[12] = creer_carte("Roi Antoine Laurent","A.Laurent", "../img/.png",10, 10 , Psy,Psy,12); //a modifier
}


//si c'est la premiere fois que le joueur se connecte il n'a pas de sauvegarde, il faut la creer
void creer_sauvegarde(){
  FILE * fic1;
  int i;
  fic1 = fopen("../save/sauvegarde.txt", "w");
  for(i = 0; i < 12; i++){
    fprintf(fic1, "%i ", i);
  }
  fclose(fic1);
}

//fonction de mise à jour de la sauvergarde du joueur si il obtient une nouvelle carte
void maj_sauvergarde(carte_t * carte){
  FILE * fic1;
  fic1 = fopen("../save/sauvergarde.txt","a");
  fprintf(fic1,"%i",carte->id_image);
  fclose(fic1);
}

//fonction de récupération des cartes que possède le joueur selon son fichier de sauvegarde
void recup_sauvegarde(carte_t * tab_sauvegarde[], carte_t * tab_cartes_total[]){
    FILE * fic1;
    int id;
    int i = 0;
    if((fic1 = fopen("../save/sauvegarde.txt", "r")) == NULL){ //si c'est la premiere fois que le joueur se connecte il n'a pas de sauvegarde, il faut la creer
      creer_sauvegarde();
      return;
    }
    while(!feof(fic1)){
      fscanf(fic1, "%i", &id);
      tab_sauvegarde[i] = tab_cartes_total[id];
      i++;
    }
    fclose(fic1);
}



//fonction de creation du deck lors du lancement d'une game, 12 sera fixe obligatoirement car 12 cartes en main
void creation_tab_main(carte_t tab_main[],int taille){
  carte_t * tab_temp[13];
  init_cartes(tab_temp);
  for (int i =0;i < taille;i++){
    tab_main[i] = *tab_temp[i];
  }

}
