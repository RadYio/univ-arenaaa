void supprimer_carte_tab(int tab_main[], int indice_main, int* taille_main);


void suppression_carte_main(int tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main);


void choix_plateau(SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[], int tab_main[], int indice_main, int* taille_main);


void tour(int * running,SDL_Renderer* renderer_jeu, SDL_Window* pWindow, SDL_Rect tab_rect_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[], int tab_main[], int* taille_main);

void transfert_carte(SDL_Renderer* renderer_jeu, SDL_Rect rect_plateau, int tab_main[12], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[12], int colone, int ligne, int indice_main, int* taille_main);
