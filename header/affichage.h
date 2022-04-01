
void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[12]);


void afficher_carte(SDL_Renderer* renderer_jeu, int carte, SDL_Rect rect_afficher);

void affichage_carte(SDL_Renderer* renderer_jeu,carte_t tab_carte[],int id_carte,SDL_Rect rect_afficher);

void afficher_rectangles_formation(SDL_Renderer* renderer_jeu, carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[][3], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[][3]);


void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture);


void affichage_texte(SDL_Renderer* renderer_jeu, SDL_Rect* rect_txt_deck_j, SDL_Texture* txt_titre_joueur_T, SDL_Rect* rect_txt_deck_adv, SDL_Texture* txt_titre_adv_T);


void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j);


void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]);

void double_clique2(SDL_Renderer *renderer_jeu,int id_carte,carte_t tab_cartes_deck[],SDL_Rect *rect_aff_carte_j,SDL_Rect *rect_aff_att_j,SDL_Rect *rect_aff_hp_j,TTF_Font* police);



void affichage_jeu2 (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,
SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,
int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[][3],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[][3] , 
int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[],SDL_Texture *menu_t,SDL_Rect menu_R
,SDL_Texture *txt_menu_Hover_T,
SDL_Rect txt_menu_R,SDL_Texture *txt_menu_T,SDL_Texture *passe_t,SDL_Rect passe_R,SDL_Texture *txt_passe_Hover_T
,SDL_Texture *txt_passe_T,SDL_Rect txt_passe_R,int * nb_actions);

void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main);


void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main);

void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main);

int action(int * nb_actions);

void nouveau_tour(int * nb_actions, int tab_formation[][3]);

int victoire(int* taille_deck_j,int* taille_deck_adv);

void * calcul_temps(void * val);
