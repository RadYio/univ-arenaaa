#include <stdio.h>
#include "../header/jeu.h"
#include "../header/menu.h"
#include "../header/window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

//fonction qui fait tourner le jeu lui meme : à rajouter, un message d'au revoir lorsque le joueur quitte le jeu (choix dans menu) ou eventuellement de crash lorsque 6 maitres invoqués
int jeu(SDL_Window * pWindow){
  //boucle du jeu lui meme-----------------------------------------------------------------------------------------------------
  while(1){ //à modifier : faire un évènement lié à la fermeture de fenetre/jeu
    if( menu(pWindow) < 0){ //on éxécute le menu et on récupère une valeur négative si erreur
      printf("echec du lancement du menu\n");
    };
  }
  return 1;
}
