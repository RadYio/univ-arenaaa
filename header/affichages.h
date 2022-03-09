

void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher);

void affichage_de_base(
    SDL_Window* pWindow, 
    SDL_Renderer* renderer_jeu, 
    SDL_Texture img_jeu_Texture,
    SDL_Texture txt_titre_joueur_T,
    SDL_Texture txt_titre_adv_T,
    SDL_Rect rect_txt_deck_j,
    SDL_Rect rect_txt_deck_adv,
    SDL_Rect rect_joueur,
    SDL_Rect rect_adv,
    int tab_formation_cartesJ[5][3],
    int tab_formation_cartesADV[5][3]
    );