/**
 * @file attaque.h
 * @author Jonathan Otto
 * @brief header de attaque.c
 * @version 1
 * @date 2022-03-30 
 */


/**
 * @fn attaque_critique(type_t attaque, type_t vulnerable)
 * @brief fonction qui vérifie si celui qui défend est vulnerable au type d'attaque
 * 
 * @param attaque le type d'attaque de la carte d'attaque
 * @param vulnerable le type de vulnérabilité de la carte de défense
 * @return renvoi 1 s'il s'agit d'une attaque critique, 0 sinon
 */
int attaque_critique(type_t attaque, type_t vulnerable);

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
void mort_carte(int id_carte_defense, carte_t deck_defense[], int tab_formation_defense[][3], int indice_deck, int* taille_deck_defense);

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
void attaque(int id_carte_attaque, int id_carte_defense, carte_t deck_attaque[], carte_t deck_defense[], int tab_formation_defense[][3], int* taille_deck_defense);
