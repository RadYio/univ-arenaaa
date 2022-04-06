/**
 * @file bot.h
 * @author Jonathan Otto
 * @brief header de bot.c
 * @version 1
 * @date 2022-03-28
 */


/**
 * @fn int poser_carte(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot)
 * @brief fonction qui permet au bot de poser une carte
 *
 * @param tab_formation_cartesADV tableau qui réportorie où le bot peut poser une carte
 * @param main_bot tableau qui contient toutes les cartes que le bot peut poser
 * @param taille_main_bot entier permettat de connaitre la taille de la main du bot
 * @return si return 1 : permet de lancer une condition si le bot à réussi à poser une carte, son tour s'arrête donc là ; si return 0 : le bot n'a pas pu poser de carte, il attaque donc
 */
int poser_carte(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot);


/**
 * @fn void attaquer_carte_bot(int tab_formation_cartesADV[][3], int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur)
 * @brief fonction permettant au bot d'attaquer une carte du joueur : parcourt la matrice du joueur, dès qu'il trouve une carte il l'attaque, s'il trouve rien il fait rien
 *
 * @param tab_formation_cartesADV la matrice de formation du bot, permet de trouver une carte avec laquelle attaquer
 * @param tab_formation_cartesJ  la matrice de formation du joueur, permet de trouver une carte à attaquer
 * @param deck_bot le deck du bot : la matrice de formation ne contient que les id des cartes, le deck fait donc correspondre ces id à des cartes pour retrouver les hp et le nombre de dégats
 * @param deck_joueur deck du joueur : reprend le même principe que deck_bot mais pour le joueur
 * @param taille_deck_joueur taille du deck du joueur, permet la mise à jour du deck lorsque le joueur perd une carte qui à été attaquée
 */
void attaquer_carte_bot(int tab_formation_cartesADV[][3], int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur);


/**
 * @fn bot(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot, int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur)
 * @brief fonction gérant le tour du bot : soit il pose une carte, soit il attaque, soit il ne fait rien
 *
 * @param tab_formation_cartesADV la matrice de formation du bot, permet de trouver un emplacement libre pour poser une carte ou de trouver une carte pour attaquer
 * @param main_bot la main du bot, repertorie toutes les cartes qu'il n'a pas encore posé sur le plateau
 * @param taille_main_bot taille de la main du bot, permet la mise à jour de main_bot lorsqu'il pose une carte
 * @param tab_formation_cartesJ la matrice de formation du joueur, permet de trouver une carte à attaquer
 * @param deck_bot le deck du bot, permet de faire correspondre un id de carte (présent sur le plateau) et ses attributs comme les hp ou le nombre de dégats
 * @param deck_joueur le deck du joueur, reprend le même principe que deck_bot mais pour le joueur
 * @param taille_deck_joueur la taille du deck du joueur, permet la mise à jour du deck du joueur lorsqu'il perd une carte suite à une attaque du bot
 */
void bot(int tab_formation_cartesADV[][3], carte_t main_bot[], int* taille_main_bot, int tab_formation_cartesJ[][3], carte_t deck_bot[], carte_t deck_joueur[], int* taille_deck_joueur);
