#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/carte.h"
#include "../header/test_jeu_solo"
#include "../header/affichages.h"

//fonction d'un tour, à répéter jusqu'a victoire, fonction retourne 1 si victoire joueur, -1 si victoire adversaire et 0 si rien, on continue alors
int tour(SDL_Renderer* renderer_jeu, SDL_Window pWindow, SDL_Rect tab_rect_main[12]){
  if(pWindow){
      int running = 1;
      while(running) {
          SDL_Event e;
          while(SDL_PollEvent(&e)) {
              switch(e.type) {
                  case SDL_QUIT: running = 0;
                  break;
                  //tour du joueur-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                  case SDL_MOUSEBUTTONDOWN:
          					printf("x: %i\ny: %i\n",e.button.x,e.button.y);
                    //gestion des cartes dans la main---------------------------------------------------------------------------------------------------------------------------------------------------------------
                    if(e.button.x >= txt_optn1_R.x && e.button.x <= txt_optn1_R.x+txt_optn1_R.w && e.button.y >= txt_optn1_R.y && e.button.y <= txt_optn1_R.y+txt_optn1_R.h){
                      //Si on clique sur la case 1 de sa main------------------creer fonction tranfert_carte(int id_carte) qui servira de "tampon", il y aura un autre swtich avec les cases sur le plateau, efface carte
                      //dans main, et affiche carte sur le plateau
                      

                    }
                    break;















                //gestion des cartes sur le plateau
              }
          }
      }
   }
}
