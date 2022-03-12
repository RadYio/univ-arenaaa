
void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, int tab_main[12], SDL_Rect tab_rect_main[12]);


void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher);


void afficher_rectangles_formation(SDL_Renderer* renderer_jeu, int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[15], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[15]);


void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture);


void affichage_texte(SDL_Renderer* renderer_jeu, SDL_Rect* rect_txt_deck_j, SDL_Texture* txt_titre_joueur_T, SDL_Rect* rect_txt_deck_adv, SDL_Texture* txt_titre_adv_T);


void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv);


void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]);

void affichage_jeu (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect *rect_txt_deck_j,SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[15],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[15] , int * taille_main, SDL_Rect tab_rect_main[12],int tab_main[]);
