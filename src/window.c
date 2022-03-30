/**
 * @file window.c
 * @author Jonathan Otto
 * @brief deuxième étape dans le déroulement du programme : initialisation de SDL, creation d'une fenetre et appelle de la suite du programme
 * @version 1
 * @date 2022-03-28
 */

#include "../header/window.h"
#include "../header/menu.h"

#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

/**
 * @fn int initialiser_fenetre()
 * @brief fonction d'initialisation de SDL, creation d'une fenetre et appelle de la suite du programme, puis une fois le programme terminé quitte SDL
 * 
 * @return 1 si tout s'est bien déroulé
 */
int initialiser_fenetre(){
  //initialisation de SDL---------------------------------------------------------------
  if(SDL_Init(SDL_INIT_VIDEO) != 0){
      fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
      return -1;
  }

    //creation de la fenetre-------------------------------------------------------------
    SDL_Window* pWindow = NULL;
    pWindow = SDL_CreateWindow(
      "UnivArena", //nom fenetre
      SDL_WINDOWPOS_CENTERED, //x fenetre centré
      SDL_WINDOWPOS_CENTERED, //y fenetre centré
      1600, //largeur fenetre
      900, //hauteur fenetre, deux valeurs à modifier potentiellement, a voir avec redimensionnement de la fenetre
      SDL_WINDOW_SHOWN
    );

    if(pWindow){
      //lancement du jeu si fenetre bien crée-------------------------------------------------
      menu(pWindow); //on transmet le pointeur de la fenetre pour des utilisations antétieures
      printf("Attention il faut delete ca\n\n\n");
      SDL_DestroyWindow(pWindow);
    }
    else{
      printf("erreur de creation de fenetre\n");
      return -1;
    }

  SDL_Quit();
  return 1;
}
