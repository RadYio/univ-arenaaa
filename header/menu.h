/**
 * @file menu.h
 * @author ALLAN GONIN-SAGET (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief header de menu.c
 * @version 1.0
 * @date 2022-04-04
 * 
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include <time.h>

#include "../header/carte.h"
#include "../header/collection.h"
#include "../header/jeu_solo.h"
#include "../header/jeu_multi.h"
#include "../header/window.h"
#include "../header/affichage.h"
#include "../header/client.h"
#include "../header/init_jeu.h"


/**
 * @enum hover 
 * @brief contient l'état du menu, si on a deja effectué un HOVER ou PAS_HOVER
 */
typedef enum hover{HOVER,PAS_HOVER}hover_t;


/**
 * @brief fonction qui gere l'intégralité de la gestion et affichage du menu
 *
 * @param pWindow pointeur de (SDL_Window*), permettant de garder la fênetre afficher pour le joueur.
 * @return int [0] si tout c'est bien passé
 */
int menu(SDL_Window * pWindow);
