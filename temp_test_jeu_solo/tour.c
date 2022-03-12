#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "../header/window.h"
#include "../header/tour.h"
#include "../header/carte.h"
#include "../header/affichages.h"
#include "../header/init_jeu_solo.h"

//a mettre dans fichier séparé
void supprimer_carte_tab(int tab_main[], int indice_main, int* taille_main){
  for(int i = indice_main - 1; i < *taille_main - 1; i++){
    tab_main[i] = tab_main[i+1];
  }
}

//a mettre dans fichier séparé
void suppression_carte_main(int tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main){
  //suppression de la carte dans tab_main
  (*taille_main)--;
  supprimer_carte_tab(tab_main, indice_main, taille_main);
  //mise à jour des rectangles
  creation_main(taille_main, tab_rect_main);
}



//fonction qui tranfère une carte de la main du joueur sur le plateau                       //MAJ               //MAJ                                                                                              
void transfert_carte(SDL_Renderer* renderer_jeu, SDL_Rect rect_plateau, int tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main){
  //mises à jour des tableaux
  if(tab_formation_cartesJ[colone][ligne] == -2){ //si on peut placer une carte (-2 représente un endroit où on peut)
    //mise à jour de notre formation,on remplace le -2 par l'id de la carte
    tab_formation_cartesJ[colone][ligne] = tab_main[indice_main]; 
    //mise à jour de notre main, on supprime la carte en question, et on arrete de l'afficher dans la main ainsi que son rectangle avec
    suppression_carte_main(tab_main, indice_main, tab_rect_main, taille_main); 
  }
  
  //affichages
  //affichage_main(taille_main, renderer_jeu, tab_main, tab_rect_main);
}





/*


//fonction de choix de l'emplacement sur le plateau
void choix_plateau(SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[], int tab_main[], int indice_main, int* taille_main){
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
                printf("colone 0, ligne 0\n");
                afficher_carte(renderer_jeu, 3, tab_rect_formationJ[0]);
                
              }else if(e.button.x >= tab_rect_formationJ[1].x && e.button.x <= tab_rect_formationJ[1].x+tab_rect_formationJ[1].w && e.button.y >= tab_rect_formationJ[1].y && e.button.y <= tab_rect_formationJ[1].y+tab_rect_formationJ[1].h){
                //case colone 0, ligne 1
                printf("colone 0, ligne 1\n");
              }else if(e.button.x >= tab_rect_formationJ[2].x && e.button.x <= tab_rect_formationJ[2].x+tab_rect_formationJ[2].w && e.button.y >= tab_rect_formationJ[2].y && e.button.y <= tab_rect_formationJ[2].y+tab_rect_formationJ[2].h){
                //case colone 0, ligne 2
                printf("colone 0, ligne 2\n");
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
              else{
                return;
              }
              SDL_RenderPresent(renderer_jeu);
              break;
              //---------------------------------rajouter cas si on clique qq part de random---------------
          }
        }
      }
    }
}

*/









//fonction d'un tour, à répéter jusqu'a victoire, fonction retourne 1 si victoire joueur, -1 si victoire adversaire et 0 si rien, on continue alors
//a rajouter : cas si on clique sur un truc random qui ne correspond a rien
void tour(int * running,SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[], int tab_main[], int* taille_main){
  int etat = 0;
  if(pWindow){
      //int running  = 1;
      while(*running) {
          SDL_Event e;
          while(SDL_PollEvent(&e)) {
              switch(e.type) {
                  case SDL_QUIT: *running = 0;
                  break;
                  //tour du joueur-----------------------------------------------------------------------------------------------------------------------------------------------------------------------
                  case SDL_MOUSEBUTTONDOWN:
                    //-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    //gestion des cartes dans la main---------------------------------------------------------------------------------------------------------------------------------------------------------------
                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    if(e.button.x >= tab_rect_main[0].x && e.button.x <= tab_rect_main[0].x+tab_rect_main[0].w && e.button.y >= tab_rect_main[0].y && e.button.y <= tab_rect_main[0].y+tab_rect_main[0].h){
                      //si on clique sur la case 0 (première à gauche) de la main
                      //choix_plateau(renderer_jeu, pWindow, tab_rect_main, tab_formation_cartesJ, tab_rect_formationJ, tab_main, 0, taille_main);
                      printf("carte 0\n");
                      etat = 1;                      
                      break;
                    }else if(e.button.x >= tab_rect_main[1].x && e.button.x <= tab_rect_main[1].x+tab_rect_main[1].w && e.button.y >= tab_rect_main[1].y && e.button.y <= tab_rect_main[1].y+tab_rect_main[1].h){
                      //si on clique sur la case 1 de la main
                      printf("carte 1\n");
                      etat = 2;                      
                      break;
                    }else if(e.button.x >= tab_rect_main[2].x && e.button.x <= tab_rect_main[2].x+tab_rect_main[2].w && e.button.y >= tab_rect_main[2].y && e.button.y <= tab_rect_main[2].y+tab_rect_main[2].h){
                      //si on clique sur la case 2 de la main
                      printf("carte 2\n");
                      etat = 3;                      
                      break;
                    }else if(e.button.x >= tab_rect_main[3].x && e.button.x <= tab_rect_main[3].x+tab_rect_main[3].w && e.button.y >= tab_rect_main[3].y && e.button.y <= tab_rect_main[3].y+tab_rect_main[3].h){
                      //si on clique sur la case 3 de la main
                      printf("carte 3\n");
                      etat = 4;                      
                      break;
                    }else if(e.button.x >= tab_rect_main[4].x && e.button.x <= tab_rect_main[4].x+tab_rect_main[4].w && e.button.y >= tab_rect_main[4].y && e.button.y <= tab_rect_main[4].y+tab_rect_main[4].h){
                      //si on clique sur la case 4 de la main
                      printf("carte 4\n");
                      etat = 5;                      
                      break;
                    }else if(e.button.x >= tab_rect_main[5].x && e.button.x <= tab_rect_main[5].x+tab_rect_main[5].w && e.button.y >= tab_rect_main[5].y && e.button.y <= tab_rect_main[5].y+tab_rect_main[5].h){
                      //si on clique sur la case 5 de la main
                      printf("carte 5\n");
                    }else if(e.button.x >= tab_rect_main[6].x && e.button.x <= tab_rect_main[6].x+tab_rect_main[6].w && e.button.y >= tab_rect_main[6].y && e.button.y <= tab_rect_main[6].y+tab_rect_main[6].h){
                      //si on clique sur la case 6 de la main
                      printf("carte 6\n");
                    }else if(e.button.x >= tab_rect_main[7].x && e.button.x <= tab_rect_main[7].x+tab_rect_main[7].w && e.button.y >= tab_rect_main[7].y && e.button.y <= tab_rect_main[7].y+tab_rect_main[7].h){
                      //si on clique sur la case 7 de la main
                      printf("carte 7\n");
                    }else if(e.button.x >= tab_rect_main[8].x && e.button.x <= tab_rect_main[8].x+tab_rect_main[8].w && e.button.y >= tab_rect_main[8].y && e.button.y <= tab_rect_main[8].y+tab_rect_main[8].h){
                      //si on clique sur la case 8 de la main
                      printf("carte 8\n");
                    }else if(e.button.x >= tab_rect_main[9].x && e.button.x <= tab_rect_main[9].x+tab_rect_main[9].w && e.button.y >= tab_rect_main[9].y && e.button.y <= tab_rect_main[9].y+tab_rect_main[9].h){
                      //si on clique sur la case 9 de la main
                      printf("carte 9\n");
                    /*}else if(e.button.x >= tab_rect_main[10].x && e.button.x <= tab_rect_main[10].x+tab_rect_main[10].w && e.button.y >= tab_rect_main[10].y && e.button.y <= tab_rect_main[10].y+tab_rect_main[10].h){
                      //si on clique sur la case 10 de la main
                    }else if(e.button.x >= tab_rect_main[11].x && e.button.x <= tab_rect_main[11].x+tab_rect_main[11].w && e.button.y >= tab_rect_main[11].y && e.button.y <= tab_rect_main[11].y+tab_rect_main[11].h){
                      //si on clique sur la case 11 de la main*/
                    }
                    printf("aled\n");
                    if(etat == 10 && e.button.x >= tab_rect_formationJ[0].x && e.button.x <= tab_rect_formationJ[0].x+tab_rect_formationJ[0].w && e.button.y >= tab_rect_formationJ[0].y && e.button.y <= tab_rect_formationJ[0].y+tab_rect_formationJ[0].h){
                      //case colone 0, ligne 0
                      printf("colone 0, ligne 0\n");
                      afficher_carte(renderer_jeu, 3, tab_rect_formationJ[0]);
                      
                      transfert_carte(renderer_jeu,tab_rect_formationJ[0],tab_main,tab_formation_cartesJ,tab_rect_main,0,0,0,taille_main);
                      printf("je sors\n");
                      return;

                    }else if(e.button.x >= tab_rect_formationJ[1].x && e.button.x <= tab_rect_formationJ[1].x+tab_rect_formationJ[1].w && e.button.y >= tab_rect_formationJ[1].y && e.button.y <= tab_rect_formationJ[1].y+tab_rect_formationJ[1].h){
                      //case colone 0, ligne 1
                      printf("colone 0, ligne 1\n");
                    }else if(e.button.x >= tab_rect_formationJ[2].x && e.button.x <= tab_rect_formationJ[2].x+tab_rect_formationJ[2].w && e.button.y >= tab_rect_formationJ[2].y && e.button.y <= tab_rect_formationJ[2].y+tab_rect_formationJ[2].h){
                      //case colone 0, ligne 2
                      printf("colone 0, ligne 2\n");
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
                    else{
                      etat = 0;
                      printf("reset\n");
                    }
                //SDL_RenderPresent(renderer_jeu);
                break;
                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                    //gestion des cartes sur le plateau------------------------------------------------------------------------------------------------------------------------------------------------------
                    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                }
          }
      }
      return;
   }
}
