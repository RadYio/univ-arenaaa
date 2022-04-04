/**
 * @file jeu_multi.h
 * @author ALLAN GONIN-SAGET (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief header de jeu_multi.c
 * @version 1.0
 * @date 2022-04-04
 * 
 */


/**
 * @brief (utilisation via un thread, sinon fonction bloquante) teste le delai de 60 secondes pour le tour du joueur et modifie la valeur si délai est dépassé
 *
 * @param pointeur générique (thread): cast en int
 * @return void* NULL
 */
void* calcul_temps2(void * val);

/**
 * @brief fonction lancé lorsque le joueur choisit de joueur en multijoueur : permet tout le jeu en multijoueur en lien avec client.c et la connexion au serveur ?/server/
 *
 * @param pWindow la fenetre où se déroule le jeu
 * @param renderer_jeu notre renderer lié à la fenetre
 * @param running variable: permettant de quitter le programme si le joueur decide de quitter le jeu
 * @param valSocket pointeur: permettant de garder la connexion établie entre le menu et l'instance du jeu multijoueur
 */
void jeu_multi(SDL_Window * pWindow, SDL_Renderer* renderer_jeu,int *running,int *valSocket);
