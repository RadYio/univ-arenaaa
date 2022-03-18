//#include "~/SDL2/include/SDL2/SDL.h"

void jeu_solo(SDL_Window * pWindow,SDL_Renderer* renderer_jeu,int * running);

void * calcul_temps(void * val);

int double_clique(SDL_Event e,SDL_Renderer *renderer_jeu,SDL_Rect tab_rect_main[],SDL_Rect tab_rect_formationJ[][3],SDL_Rect tab_rect_formationAdv[][3]
,SDL_Rect *rect_aff_carte_j,carte_t tab_cartes_total[13],carte_t tab_main[],int tab_formation_cartesJ[5][3],int tab_formation_cartesADV[5][3]);

