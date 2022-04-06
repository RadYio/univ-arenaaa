/**
 * @file collection.h
 * @author Arthur (arthur.boullier.etu@univ-lemans.fr)
 * @brief header de collection.c
 * @version 1.0
 * @date 2022-04-06
 */



/**
 * @brief fonction d'affichage de la collection appelée dans le menu
 * @fn int collection(SDL_Window* pWindow, SDL_Texture* img_Collec_Texture, SDL_Renderer* test, int* running)

 * @param pWindow notre fenêtre précédemment créée
 * @param img_Collec_Texture la texture de fond d'écran initialisée dans le menu pour qu'elle soit le même dans la collection
 * @param renderer_collec notre renderer
 * @param running pointeur sur entier permettant de quitter la page de collection et la page de menu ensuite
 * @return int 
 */
int collection(SDL_Window* pWindow, SDL_Texture* img_Collec_Texture, SDL_Renderer* renderer_collec, int* running);

/**
 * @brief fonction de création des rectangles dans lesquels les noms des cartes vont apparaitres
 * @fn void creation_R_collec(int taille,SDL_Rect tab[],carte_t * tab_sauvegarde[])

 * @param taille entier donnant le nombre de rectangle à créer
 * @param tab tableau de SDL_Rect contenant tout les rectangles créés
 * @param tab_sauvegarde tableau de carte_t contenant les cartes devant apparaitre dans la collection
 */
void creation_R_collec(int taille,SDL_Rect tab[],carte_t * tab_sauvegarde[]);
