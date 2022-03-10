#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/tour.h"
#include "../header/carte.h"
#include "../header/affichages.h"

//fonction qui tranfère une carte de la main du joueur sur le plateau                       //MAJ               //MAJ                                                                                              
/*void transfert_carte(SDL_Renderer* renderer_jeu, SDL_Rect rect_main, SDL_Rect rect_plateau, int deck_main[12], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[12], int colone, int ligne, int indice_main){
  //mises à jour des tableaux
  tab_formation_cartesJ[colone][ligne] = deck_main[indice_main]; //mise à jour de notre formation, on place l'id de la carte au lieu d'un -2 signifiant qu'une carte peut aller là mais qu'il y a rien
  deck_main[indice_main] = -1; //mise à jour de notre main, on place -1 pour signifier qu'il n'y a plus de carte à cet emplacement
  //affichages
  afficher_main(renderer_jeu, deck_main, tab_rect_main);


  void affichage_main(SDL_Renderer* renderer_jeu, int deck_main[12], SDL_Rect tab_rect_main[12])






  carte_t = SDL_CreateTextureFromSurface(renderer_jeu, carte_s);
    SDL_FreeSurface(carte_s);
    SDL_RenderCopy(renderer_jeu, carte_t, NULL, &rect_afficher);
}*/







//fonction de choix de l'emplacement sur le plateau
void choix_plateau(SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main, int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15], int deck_main[12], int indice_main){
    if(pWindow){
      int running = 1;
      while(running){
        SDL_Event e;
        while(SDL_PollEvent(&e)){
          switch(e.type){
            case SDL_QUIT : running = 0;
            break;
            case SDL_MOUSEBUTTONDOWN:
              printf("x: %i\ny: %i\n",e.button.x,e.button.y);
              //-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
              //choix de la case sur le plateau----------------------------------------------------------------------------------------------------------------------------------------------------
              //------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
              if(e.button.x >= tab_rect_formationJ[0].x && e.button.x <= tab_rect_formationJ[0].x+tab_rect_formationJ[0].w && e.button.y >= tab_rect_formationJ[0].y && e.button.y <= tab_rect_formationJ[0].y+tab_rect_formationJ[0].h){
                //case colone 0, ligne 0
              }else if(e.button.x >= tab_rect_formationJ[1].x && e.button.x <= tab_rect_formationJ[1].x+tab_rect_formationJ[1].w && e.button.y >= tab_rect_formationJ[1].y && e.button.y <= tab_rect_formationJ[1].y+tab_rect_formationJ[1].h){
                //case colone 0, ligne 1
              }else if(e.button.x >= tab_rect_formationJ[2].x && e.button.x <= tab_rect_formationJ[2].x+tab_rect_formationJ[2].w && e.button.y >= tab_rect_formationJ[2].y && e.button.y <= tab_rect_formationJ[2].y+tab_rect_formationJ[2].h){
                //case colone 0, ligne 2
              }else if(e.button.x >= tab_rect_formationJ[3].x && e.button.x <= tab_rect_formationJ[3].x+tab_rect_formationJ[3].w && e.button.y >= tab_rect_formationJ[3].y && e.button.y <= tab_rect_formationJ[3].y+tab_rect_formationJ[3].h){
                //case colone 0, ligne 3
              }else if(e.button.x >= tab_rect_formationJ[4].x && e.button.x <= tab_rect_formationJ[4].x+tab_rect_formationJ[4].w && e.button.y >= tab_rect_formationJ[4].y && e.button.y <= tab_rect_formationJ[4].y+tab_rect_formationJ[4].h){
                //case colone 0 ligne 4
              }else if(e.button.x >= tab_rect_formationJ[5].x && e.button.x <= tab_rect_formationJ[5].x+tab_rect_formationJ[5].w && e.button.y >= tab_rect_formationJ[5].y && e.button.y <= tab_rect_formationJ[5].y+tab_rect_formationJ[5].h){
                //case colone 1, ligne 0
              }else if(e.button.x >= tab_rect_formationJ[6].x && e.button.x <= tab_rect_formationJ[6].x+tab_rect_formationJ[6].w && e.button.y >= tab_rect_formationJ[6].y && e.button.y <= tab_rect_formationJ[6].y+tab_rect_formationJ[6].h){
                //case colone 1, ligne 1
              }else if(e.button.x >= tab_rect_formationJ[7].x && e.button.x <= tab_rect_formationJ[7].x+tab_rect_formationJ[7].w && e.button.y >= tab_rect_formationJ[7].y && e.button.y <= tab_rect_formationJ[7].y+tab_rect_formationJ[7].h){
                //case colone 1, ligne 2
              }else if(e.button.x >= tab_rect_formationJ[8].x && e.button.x <= tab_rect_formationJ[8].x+tab_rect_formationJ[8].w && e.button.y >= tab_rect_formationJ[8].y && e.button.y <= tab_rect_formationJ[8].y+tab_rect_formationJ[8].h){
                //case colone 1, ligne 3
              }else if(e.button.x >= tab_rect_formationJ[9].x && e.button.x <= tab_rect_formationJ[9].x+tab_rect_formationJ[9].w && e.button.y >= tab_rect_formationJ[9].y && e.button.y <= tab_rect_formationJ[9].y+tab_rect_formationJ[9].h){
                //case colone 1, ligne 4
              }else if(e.button.x >= tab_rect_formationJ[10].x && e.button.x <= tab_rect_formationJ[10].x+tab_rect_formationJ[10].w && e.button.y >= tab_rect_formationJ[10].y && e.button.y <= tab_rect_formationJ[10].y+tab_rect_formationJ[10].h){
                //case colone 2, ligne 0
              }else if(e.button.x >= tab_rect_formationJ[11].x && e.button.x <= tab_rect_formationJ[11].x+tab_rect_formationJ[11].w && e.button.y >= tab_rect_formationJ[11].y && e.button.y <= tab_rect_formationJ[11].y+tab_rect_formationJ[11].h){
                //case colone 2, ligne 1
              }else if(e.button.x >= tab_rect_formationJ[12].x && e.button.x <= tab_rect_formationJ[12].x+tab_rect_formationJ[12].w && e.button.y >= tab_rect_formationJ[12].y && e.button.y <= tab_rect_formationJ[12].y+tab_rect_formationJ[12].h){
                //case colone 2, ligne 2
              }else if(e.button.x >= tab_rect_formationJ[13].x && e.button.x <= tab_rect_formationJ[13].x+tab_rect_formationJ[13].w && e.button.y >= tab_rect_formationJ[13].y && e.button.y <= tab_rect_formationJ[13].y+tab_rect_formationJ[13].h){
                //case colone 2, ligne 3
              }else if(e.button.x >= tab_rect_formationJ[14].x && e.button.x <= tab_rect_formationJ[14].x+tab_rect_formationJ[14].w && e.button.y >= tab_rect_formationJ[14].y && e.button.y <= tab_rect_formationJ[14].y+tab_rect_formationJ[14].h){
                //case colone 2, ligne 4
              }
              break;
              //---------------------------------rajouter cas si on clique qq part de random---------------
          }
        }
      }
    }
}











//fonction d'un tour, à répéter jusqu'a victoire, fonction retourne 1 si victoire joueur, -1 si victoire adversaire et 0 si rien, on continue alors
//a rajouter : cas si on clique sur un truc random qui ne correspond a rien
int tour(SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main[12], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15]){
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
                    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    //gestion des cartes dans la main---------------------------------------------------------------------------------------------------------------------------------------------------------------
                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    if(e.button.x >= tab_rect_main[0].x && e.button.x <= tab_rect_main[0].x+tab_rect_main[0].w && e.button.y >= tab_rect_main[0].y && e.button.y <= tab_rect_main[0].y+tab_rect_main[0].h){
                      //si on clique sur la case 0 (première à gauche) de la main
                      //Si on clique sur la case 1 de sa main------------------creer fonction tranfert_carte(int id_carte) qui servira de "tampon", il y aura un autre swtich avec les cases sur le plateau, efface carte
                      //dans main, et affiche carte sur le plateau
                    }else if(e.button.x >= tab_rect_main[1].x && e.button.x <= tab_rect_main[1].x+tab_rect_main[1].w && e.button.y >= tab_rect_main[1].y && e.button.y <= tab_rect_main[1].y+tab_rect_main[1].h){
                      //si on clique sur la case 1 de la main
                    }else if(e.button.x >= tab_rect_main[2].x && e.button.x <= tab_rect_main[2].x+tab_rect_main[2].w && e.button.y >= tab_rect_main[2].y && e.button.y <= tab_rect_main[2].y+tab_rect_main[2].h){
                      //si on clique sur la case 2 de la main
                    }else if(e.button.x >= tab_rect_main[3].x && e.button.x <= tab_rect_main[3].x+tab_rect_main[3].w && e.button.y >= tab_rect_main[3].y && e.button.y <= tab_rect_main[3].y+tab_rect_main[3].h){
                      //si on clique sur la case 3 de la main
                    }else if(e.button.x >= tab_rect_main[4].x && e.button.x <= tab_rect_main[4].x+tab_rect_main[4].w && e.button.y >= tab_rect_main[4].y && e.button.y <= tab_rect_main[4].y+tab_rect_main[4].h){
                      //si on clique sur la case 4 de la main
                    }else if(e.button.x >= tab_rect_main[5].x && e.button.x <= tab_rect_main[5].x+tab_rect_main[5].w && e.button.y >= tab_rect_main[5].y && e.button.y <= tab_rect_main[5].y+tab_rect_main[5].h){
                      //si on clique sur la case 5 de la main
                    }else if(e.button.x >= tab_rect_main[6].x && e.button.x <= tab_rect_main[6].x+tab_rect_main[6].w && e.button.y >= tab_rect_main[6].y && e.button.y <= tab_rect_main[6].y+tab_rect_main[6].h){
                      //si on clique sur la case 6 de la main
                    }else if(e.button.x >= tab_rect_main[7].x && e.button.x <= tab_rect_main[7].x+tab_rect_main[7].w && e.button.y >= tab_rect_main[7].y && e.button.y <= tab_rect_main[7].y+tab_rect_main[7].h){
                      //si on clique sur la case 7 de la main
                    }else if(e.button.x >= tab_rect_main[8].x && e.button.x <= tab_rect_main[8].x+tab_rect_main[8].w && e.button.y >= tab_rect_main[8].y && e.button.y <= tab_rect_main[8].y+tab_rect_main[8].h){
                      //si on clique sur la case 8 de la main
                    }else if(e.button.x >= tab_rect_main[9].x && e.button.x <= tab_rect_main[9].x+tab_rect_main[9].w && e.button.y >= tab_rect_main[9].y && e.button.y <= tab_rect_main[9].y+tab_rect_main[9].h){
                      //si on clique sur la case 9 de la main
                    }else if(e.button.x >= tab_rect_main[10].x && e.button.x <= tab_rect_main[10].x+tab_rect_main[10].w && e.button.y >= tab_rect_main[10].y && e.button.y <= tab_rect_main[10].y+tab_rect_main[10].h){
                      //si on clique sur la case 10 de la main
                    }else if(e.button.x >= tab_rect_main[11].x && e.button.x <= tab_rect_main[11].x+tab_rect_main[11].w && e.button.y >= tab_rect_main[11].y && e.button.y <= tab_rect_main[11].y+tab_rect_main[11].h){
                      //si on clique sur la case 11 de la main
                    }
                  break;
                //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                //gestion des cartes sur le plateau------------------------------------------------------------------------------------------------------------------------------------------------------
                //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
              }
          }
      }
   }
}
