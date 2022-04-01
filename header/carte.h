#ifndef _CARTE_H
#define _CARTE_H

#define N 13 //nombre de cartes dans le jeu au total

typedef enum type{Poison, Psy, Physique}type_t;

typedef struct carte_s{
  char * nom;
  char * nom_collec;
  char * chemin_carte;
  int hp_carte;
  int nb_degats;
  type_t  type_attaque;
  type_t  type_vulnerable;
  int id_carte;
}carte_t;


carte_t * creer_carte(char* nom, char * nom_collec,char * chemin_carte,int hp , int attaque , type_t type_attaque , type_t type_vulnerable, int id);
carte_t creer_carte2(char* nom, char* nom_collec, char* chemin_carte, int hp, int nb_degats, type_t type_attaque, type_t type_vulnerable, int id_carte); //aled
void init_cartes(carte_t tab_cartes_total[]);

void creer_sauvegarde();

void maj_sauvergarde(carte_t * carte);

void recup_sauvegarde(carte_t * tab_sauvegarde[], carte_t * tab_cartes_total[]);

void creation_deck(carte_t * deck[12]);

void creation_tab_main(carte_t tab_main[],int taille);

#endif
