/**
 * @file init_jeu.h
 * @author Jonathan Otto et Arthur Boullier
 * @brief header de init_jeu.c
 * @version 1
 * @date 2022-03-30
 * 
 */

/**
 * @fn SDL_Rect creer_rectangle(int x, int y, int h, int w)
 * @brief fonction de creation d'un rectangle
 * 
 * @param x la coordonnée en abscisse du point supérieur gauche du rectangle
 * @param y la coordonnée en ordonnée du point supérieur gauche du rectangle
 * @param h la hauteur du rectangle
 * @param w la largeur du rectangle
 * @return le rectangle crée
 */
SDL_Rect creer_rectangle(int x, int y, int h, int w);


/**
 * @fn init_jeu(int  * taille_main,SDL_Rect tab_rect_formationJ[][3], SDL_Rect tab_rect_formationAdv[][3], SDL_Rect tab_rect_main[12],
      SDL_Rect* rect_joueur, SDL_Rect* rect_adv, SDL_Rect* rect_txt_deck_j, SDL_Rect* rect_txt_deck_adv,SDL_Rect* rect_aff_carte_j,
      SDL_Rect* rect_aff_att_j ,SDL_Rect* rect_aff_hp_j)
 * @brief initialise les rectangles nécessaires à l'affichage et la gestion des cliques et les place dans des tableaux et crée la main du joueur
 * 
 * @param taille_main la taille de la main du joueur à créer
 * @param tab_rect_formationJ la matrice des rectangles du plateau joueur, les rectangles initialisés pour le joueur seront mis dedans 
 * @param tab_rect_formationAdv la matrice des rectangles du plateau de l'adversaire, même principe que tab_rect_formationJ
 * @param tab_rect_main tableau qui contient les rectangles de la main du joueur
 * @param rect_joueur le grand rectangle pour le plateau du joueur
 * @param rect_adv le grand rectangle pour le plateau de l'adversaire
 * @param rect_txt_deck_j le rectangle où se place le texte au dessus du plateau du joueur
 * @param rect_txt_deck_adv le rectangle où se place le texte au dessus du plateau de l'adversaire
 * @param rect_aff_carte_j le rectangle où seront affichés les cartes losrqu'on double clique dessus
 * @param rect_aff_att_j le rectangle où seront affichés les points d'attaque d'une carte 
 * @param rect_aff_hp_j le rectangle où seront affichés les hp d'une carte
 */
void init_jeu(int  * taille_main,SDL_Rect tab_rect_formationJ[][3], SDL_Rect tab_rect_formationAdv[][3], SDL_Rect tab_rect_main[12],
 SDL_Rect* rect_joueur, SDL_Rect* rect_adv, SDL_Rect* rect_txt_deck_j, SDL_Rect* rect_txt_deck_adv,SDL_Rect* rect_aff_carte_j,
 SDL_Rect* rect_aff_att_j ,SDL_Rect* rect_aff_hp_j);
 
 
 void creation_main(int  *taille_main,SDL_Rect tab[]);
