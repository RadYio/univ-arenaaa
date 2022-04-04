/**
 * @file jeu_solo.h
 * @author Arthur Boullier et Jonathan Otto
 * @brief header de jeu_solo.h
 * @version 1
 * @date 2022-03-30
 * 
 */

/**
 * @fn jeu_solo(SDL_Window * pWindow, SDL_Renderer* renderer_jeu ,int * running)
 * @brief fonction lancé lorsque le joueur choisit de joueur en solo : permet tout le jeu en solo avec mise en place d'éléments, la détéctions d'eventements et la gestion des tours
 * 
 * @param pWindow la fenetre où se déroule le jeu
 * @param renderer_jeu notre renderer lié à la fenetre
 * @param running variable permettant de quitter le programme si le joueur arrête la fenetre
 */
void jeu_solo(SDL_Window * pWindow,SDL_Renderer* renderer_jeu,int * running);



