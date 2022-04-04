/**
 * @file carte.h
 * @author Jonathan Otto et Arthur Boullier
 * @brief header de carte.c ; ici on déclare la structure de carte
 * @version 1
 * @date 2022-04-04
 * 
 */


#ifndef _CARTE_H
#define _CARTE_H

#define N 13 //nombre de cartes dans le jeu au total

/**
 * @enum type
 * @brief représente le type d'attaque ou le type de vulnérabilité d'une carte, sert lors de la détermination des coups critiques
 */
typedef enum type{Poison, Psy, Physique}type_t;

/**
 * @struct carte_s
 * @brief la structure d'une carte
 */
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

/**
 * @fn carte_t creer_carte2(char* nom, char* nom_collec, char* chemin_carte, int hp, int nb_degats, type_t type_attaque, type_t type_vulnerable, int id_carte)
 * @brief fonction de creation d'une carte
 * 
 * @param nom nom de la carte
 * @param nom_collec nom qui sera affiché losrqu'on regarde la collection
 * @param chemin_carte chemin pour accéder à l'image de la carte
 * @param hp les points de vie de la carte
 * @param nb_degats le nombre dégats que fait la carte
 * @param type_attaque le type d'attaque de la carte
 * @param type_vulnerable le type d'attaque auquel la carte est vulnérable
 * @param id_carte l'id de la carte
 * @return carte_t la carte qui à été faite
 */
carte_t creer_carte2(char* nom, char* nom_collec, char* chemin_carte, int hp, int nb_degats, type_t type_attaque, type_t type_vulnerable, int id_carte); 


/**
 * @fn init_cartes(carte_t tab_cartes_total[])
 * @brief fonction qui remplit un tableau donné de cartes
 * 
 * @param tab_cartes_total le tableau à remplir
 */
void init_cartes(carte_t tab_cartes_total[]);

/**
 * @fn creer_sauvegarde()
 * @brief creation d'un fichier de sauvegarde (deprecated)
 * 
 */
void creer_sauvegarde();

/**
 * @fn void maj_sauvergarde(carte_t * carte)
 * @brief fonction qui met à jour le fichier de sauvegarde en lui rajoutant une carte (deprecated)
 * @param carte la carte à rajouter dans la sauvegarde
 */
void maj_sauvergarde(carte_t * carte);

/**
 * @fn recup_sauvegarde(carte_t *tab_sauvegarde[], carte_t tab_cartes_total[])
 * @brief fonction qui met les cartes sauvegardées dans un tableau (deprecated)
 * 
 * @param tab_sauvegarde tableau de la sauvegarde du joueur 
 * @param tab_cartes_total tableau contenant toutes les cartes du jeu
 */
void recup_sauvegarde(carte_t *tab_sauvegarde[], carte_t tab_cartes_total[]);

/**
 * @fn void creation_tab_main(carte_t tab_main[],int taille)
 * @brief fonction de creation de la main lors du lancement d'un jeu
 * 
 * @param tab_main le tableau de la main à créer
 * @param taille la taille de la main
 */
void creation_tab_main(carte_t tab_main[],int taille);

#endif
