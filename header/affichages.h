
void affichage_main(SDL_Renderer* renderer_jeu, int deck_main[12], SDL_Rect tab_rect_main[12]);


void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher);


void afficher_rectangles_formation(SDL_Renderer* renderer_jeu, int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[15]);


void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture img_jeu_Texture);