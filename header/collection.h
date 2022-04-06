//#include "~/SDL2/include/SDL2/SDL.h"

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
