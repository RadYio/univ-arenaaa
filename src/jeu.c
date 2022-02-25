#include <stdio.h>
#include "../header/jeu.h"
#include "../header/menu.h"
#include "../header/window.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

//fonction qui fait tourner le jeu lui meme : à rajouter, un message d'au revoir lorsque le joueur quitte le jeu (choix dans menu) ou eventuellement de crash lorsque 6 maitres invoqués
int jeu(SDL_Window * pWindow){

  int running = 1;
  while(running) {
    SDL_Event e;
    while(SDL_PollEvent(&e)) {
      switch(e.type) {
        case SDL_QUIT: running = 0;
        break;
        case SDL_WINDOWEVENT:
          switch(e.window.event){
            case SDL_WINDOWEVENT_EXPOSED:
            case SDL_WINDOWEVENT_SIZE_CHANGED:
            case SDL_WINDOWEVENT_RESIZED:
            case SDL_WINDOWEVENT_SHOWN:
              /* Le fond de la fenêtre sera blanc */
              SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
              SDL_RenderClear(renderer);

              SDL_RenderCopy(renderer, img_Menu_Texture, NULL, NULL);
              /* On fait le rendu ! */
              SDL_RenderPresent(renderer);

            break;
          }
        case SDL_MOUSEBUTTONDOWN:
          printf("x: %i\ny: %i\n",e.button.x,e.button.y);
          if(e.button.x>=button1.x && e.button.x<=button1.x+button1.largeur && e.button.y>=button1.y && e.button.y<=button1.y+button1.hauteur){
            printf("T BG\n");
          }
        break;
      }
    }
  }
} else {
  fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
}

//Destruction de la fenetre
SDL_DestroyWindow(pWindow);

TTF_CloseFont(police); /* Doit être avant TTF_Quit() */
TTF_Quit();
  SDL_Quit();
  return 0;
}







  //boucle du jeu lui meme-----------------------------------------------------------------------------------------------------
  while(1){ //à modifier : faire un évènement lié à la fermeture de fenetre/jeu
    if( menu(pWindow) < 0){ //on éxécute le menu et on récupère une valeur négative si erreur
      printf("echec du lancement du menu\n");
    };
  }
  return 1;
}
