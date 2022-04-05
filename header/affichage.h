/**
 * @file affichage.h
 * @author Jonathan Otto et Arthur Boullier
 * @brief header de affichage.c
 * @version 1
 * @date 2022-03-28
 */


/**
 * @fn void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[])
 * @brief fonction d'affichage des cartes de la main du joueur
 * @param taille_main variable qui repertorie la taille de la main, permet un affichage dynamique en fonction du nombre de cartes
 * @param renderer_jeu notre renderer
 * @param tab_main tableau qui repertorie quelles cartes possède le joueur dans sa main
 * @param tab_rect_main tableau qui repertorie les rectangles de la main pour savoir où afficher les cartes
 *
 * @return void
 */
void affichage_main(int * taille_main,SDL_Renderer* renderer_jeu, carte_t tab_main[], SDL_Rect tab_rect_main[12]);


/**
 * @fn void affichage_carte(SDL_Renderer* renderer_jeu,carte_t carte,SDL_Rect rect_afficher)
 * @brief fonction d'affichage d'une carte donnée dans un rectangle donnée
 * @param renderer_jeu notre renderer
 * @param carte la carte à afficher
 * @param rect_afficher le rectangle où afficher la carte en question
 *
 *
 */
void affichage_carte(SDL_Renderer* renderer_jeu,carte_t tab_carte[],int id_carte,SDL_Rect rect_afficher);


/**
 * @fn void afficher_rectangles_formation(SDL_Renderer* renderer_jeu,carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[][3], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[][3])
 * @brief fonction d'affichage des rectangles de la formationd du joueur en parcourant la matrice associé et en mettant un rectangle lorsqu'il y à un -2
 * @param renderer_jeu notre renderer
 * @param tab_cartes_total tableau qui repertorie toutes les cartes du jeu, permet de faire corresponndre une id de carte que possède le joueur aux reste des informations de la carte
 * @param tab_formation_cartesJ tableau correspondant à la formation du joueur, -2 correspond à un emplacement où l'on peut poser une carte, -1 est un emplacement où on à rien, et tout chiffre >= 0 est une carte
 * @param tab_rect_formationJ tableau correspondant aux rectangles de la formation du joueur, permet de connaitre où on pose les cartes
 * @param tab_formation_cartesADV tableau qui reprend le meme principe que tab_formation_cartesJ[][3] mais pour le coté adversaire
 * @param tab_rect_formationAdv tableau qui reprend le meme principe que tab_rect_formationJ[][3] mais pour le coté adversaire
 *
 */
void afficher_rectangles_formation(SDL_Renderer* renderer_jeu, carte_t tab_cartes_total[],int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_formationJ[][3], int tab_formation_cartesADV[5][3], SDL_Rect tab_rect_formationAdv[][3]);


/**
 * @fn void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture)
 * @brief fonction d'affichage du fond lors du jeu
 * @param renderer_jeu notre renderer
 * @param img_jeu_Texture la texture contenant l'image à afficher
 *
 *
 */
void affichage_BG(SDL_Renderer* renderer_jeu, SDL_Texture* img_jeu_Texture);


void affichage_texte(SDL_Renderer* renderer_jeu, SDL_Rect* rect_txt_deck_j, SDL_Texture* txt_titre_joueur_T, SDL_Rect* rect_txt_deck_adv, SDL_Texture* txt_titre_adv_T);

/**
 * @fn void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j)
 *
 * @brief fonction d'affichage des grands rectangles qui séparent le coté joueur du coté adversaire
 * @param renderer_jeu notre renderer
 * @param rect_joueur le grand rectangle du joueur
 * @param rect_adv le grand rectangle de l'adversaire
 * @param rect_aff_carte_j rectangle d'affichage pour la zone d'affichage en gros d'une carte
 *
 *
 */
void affichage_gros_rectangles(SDL_Renderer* renderer_jeu, SDL_Rect* rect_joueur,SDL_Rect* rect_adv,SDL_Rect * rect_aff_carte_j);


/**
 * @fn void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12])
 * @brief fonction d'affichage des rectangles autour des cartes dans la main du joueur
 * @param taille_main variable qui repertorie la taille de la main, permet un affichage dynamique en fonction du nombre de carte
 * @param renderer_jeu notre renderer
 * @param tab_rect_main repertorie les rectangles de la main du joueur
 *
 *
 */
void afficher_rectangles_main(int * taille_main,SDL_Renderer* renderer_jeu, SDL_Rect tab_rect_main[12]);


/**
 * @fn void double_clique2(SDL_Renderer *renderer_jeu, int id_carte, carte_t tab_cartes_deck[], SDL_Rect *rect_aff_carte_j, SDL_Rect *rect_aff_att_j, SDL_Rect *rect_aff_hp_j, TTF_Font* police)
 * @brief fonction d'affichage des cartes en plus grand et des points de vie et d'attaque ce cette même carte
 * 
 * @param renderer_jeu notre renderer
 * @param id_carte identifiant d'une carte de type carte_t
 * @param tab_cartes_deck tableau de carte_t permettant de trouver la carte que l'on veut afficher à partir de son identifiant
 * @param rect_aff_carte_j rectangle où l'on affiche l'image de la carte
 * @param rect_aff_att_j rectangle où l'on affiche l'attaque de la carte
 * @param rect_aff_hp_j rectangle où l'on affiche les points de vie de la carte
 * @param police police SDL correspondant à la police utilisée ultérieurement
 */
void double_clique2(SDL_Renderer *renderer_jeu,int id_carte,carte_t tab_cartes_deck[],SDL_Rect *rect_aff_carte_j,SDL_Rect *rect_aff_att_j,SDL_Rect *rect_aff_hp_j,TTF_Font* police);


/**
 * @fn void affichage_jeu2 (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,
SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,
int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[][3],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[][3] ,
int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[],SDL_Texture *menu_t,SDL_Rect menu_R
,SDL_Texture *txt_menu_Hover_T,
SDL_Rect txt_menu_R,SDL_Texture *txt_menu_T,SDL_Texture *passe_t,SDL_Rect passe_R,SDL_Texture *txt_passe_Hover_T
,SDL_Texture *txt_passe_T,SDL_Rect txt_passe_R,int * nb_actions);
 * @brief fonction qui fait appel à toutes les fonctions d'affichages pour permettre un nouvel affichage à chaque action du joueur
 *
 * @param renderer_jeu notre renderer
 * @param img_jeu_Texture la texture contenant l'image à afficher en fond d'écran
 * @param rect_aff_carte_j rectangle où l'on affiche la carte en grand lors d'un double clique
 * @param rect_txt_deck_j  rectangle dans lequel le nom du joueur est affiché
 * @param txt_titre_joueur_T texture contenant le nom de joueur 
 * @param rect_txt_deck_adv rectangle dans lequel le nom de l'adversaire est affiché 
 * @param txt_titre_adv_T texture contenant le nom de l'adversaire
 * @param rect_joueur rectangle délimitant le plateau de joueur
 * @param rect_adv  recrangle délimitant le plateau de l'adversaire
 * @param tab_formation_cartesJ matrice représentant le plateau du joueur et contenant des entiers : -2 pour une case vide jouable, -1 pour une case injouable et >= 0 pour l'id de la carte posée dans cette case 
 * @param tab_rect_formationJ tableau de SDL_rect contenant les rectangles où les cartes peuvent être posées pour le joueur
 * @param tab_formation_cartesADV matrice représentant le plateau de l'adversaire et contenant des entiers : -2 pour une case vide jouable, -1 pour une case injouable et >= 0 pour l'id de la carte posée dans cette case 
 * @param tab_rect_formationAdv tableau de SDL_rect contenant les rectangles où les cartes peuvent être posées pour l'adversaire
 * @param taille_main pointeur sur un entier de valeur de la taille de la main
 * @param tab_rect_main tableau de SDL_rect contenant les rectangles où les cartes de la main du joueur vont apparaitre
 * @param tab_main tableau de carte_t contenant les cartes de la main du joueur
 * @param tab_cartes_total tableau de carte_t contenant toutes les cartes disponnibles dans le jeu
 * @param menu_t texture contenant l'image du bouton de retour menu
 * @param menu_R rectangle dans lequel va être affiché le bouton de retour menu
 * @param txt_menu_R rectangle dans lequel va être affiché le texte du bouton de retour menu
 * @param txt_menu_T texture contenant le texte du bouton de retour menu
 * @param passe_t texture contenant l'image du bouton de passage de tour
 * @param passe_R rectangle dans lequel va être affiché le bouton de passage de tour
 * @param txt_passe_T texture contenant le texte du bouton de passage de tour
 * @param txt_passe_R rectangle dans lequel va être affiché le texte du bouton de retour menu
 */
void affichage_jeu2 (SDL_Renderer* renderer_jeu,SDL_Texture* img_jeu_Texture,SDL_Rect * rect_aff_carte_j,SDL_Rect *rect_txt_deck_j,
SDL_Texture *txt_titre_joueur_T,SDL_Rect *rect_txt_deck_adv,SDL_Texture *txt_titre_adv_T,SDL_Rect *rect_joueur,SDL_Rect *rect_adv,
int tab_formation_cartesJ[5][3],SDL_Rect tab_rect_formationJ[][3],int tab_formation_cartesADV[5][3],SDL_Rect tab_rect_formationAdv[][3] ,
int * taille_main, SDL_Rect tab_rect_main[12],carte_t tab_main[],carte_t tab_cartes_total[],SDL_Texture *menu_t,SDL_Rect menu_R,
SDL_Rect txt_menu_R,SDL_Texture *txt_menu_T,SDL_Texture *passe_t,SDL_Rect passe_R
,SDL_Texture *txt_passe_T,SDL_Rect txt_passe_R,int * nb_actions);


/**
 * @fn void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main)
 * @brief fonction de suppression d'une carte dans un tableau
 * @param tab_main le tableau qui contient l'élément à supprimer
 * @param indice_main l'indice de l'élément à supprimer dans le tableau
 * @param taille_main taille du tableau
 *
 *
 */
void supprimer_carte_tab(carte_t tab_main[], int indice_main, int* taille_main);

/**
 * @fn void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main)
 * @brief fonction de suppression d'une carte dans la main du joueur
 * @param tab_main tableau de la main où il faut supprimer un élément
 * @param indice_main indice de l'élément à supprimer dans le tableau
 * @param tab_rect_main tableau de la main du joueur qui possède un élément à supprimer
 * @param taille_main la taille de la main qui devra être mis à jour après avoir supprimé un élément
 *
 *
 */
void suppression_carte_main(carte_t tab_main[], int indice_main, SDL_Rect tab_rect_main[], int* taille_main);


/**
 * @fn void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main)
 * @brief fonction qui transfère une carte de la main du joueur sur le plateau
 * @param tab_main tableau de la main dont il faut transférer une carte
 * @param tab_formation_cartesJ tableau qui répértorie où on peut poser une carte, sera mis à jour avec l'id de la carte nouvellement placé à l'endroit voulu
 * @param tab_rect_main tableau des rectangles de la main, sert à savoir sur quelle carte de la main on à cliqué
 * @param colone sert de coordonnée dans la formation
 * @param ligne sert de coordonnée dans la formation
 * @param taille_main taille de la main qui doit être mis à jour
 *
 *
 */
void transfert_carte(carte_t tab_main[], int tab_formation_cartesJ[5][3], SDL_Rect tab_rect_main[], int colone, int ligne, int indice_main, int* taille_main);

/**
 * @brief int action(int * nb_actions)

 * @fn fonction qui vérifie si le joueur a des points d'actions disponible et si oui lui en retire un
 * @param nb_actions nombre d'actions dont le joueur dispose dans un tour
 * @return int return 1 si le joueur avait une action disponnible et en a donc perdu une et 0 si il n'avait pas d'action disponnible
 */
int action(int * nb_actions);


/**
 * @brief void nouveau_tour(int * nb_actions, int tab_formation[][3])
 * @fn fonction qui calcul le nombre de d'action attribuées au joueur pour le tour à venir, au minimum 1 incrémenté pour toute colonne de son plateau remplie de carte
 * @param nb_actions nombre d'actions dont le joueur dispose dans un tour
 * @param tab_formation matrice d'entier correspondant au plateau du joueur nous permettant de connaître sa composition de carte présentes sur le plateau 
 */
void nouveau_tour(int * nb_actions, int tab_formation[][3]);

/**
 * @fn victoire(int* taille_deck_j,int* taille_deck_adv)
 * @brief fonction de vérification si quelqu'un à gagné la partie
 *
 * @param taille_deck_j taille du deck du joueur, si égal à 0 alors le joueur à perdu
 * @param taille_deck_adv taille du deck de l'adversaire, si égal à 0 alors l'adversaire à perdu
 * @return 1 si le joueur perd, 2 si le joueur gagne, 0 si on continue la partie
 */
int victoire(SDL_Renderer* renderer_jeu,int* taille_deck_j,int* taille_deck_adv);

/**
 * @brief void affichage_victoire(SDL_Renderer* renderer_jeu,int victoire)
 * @fn fonction d'affichage en fin de partie indiquant si le joueur a gagné , perdu ou si il y a eu match nul
 * @param renderer_jeu notre renderer
 * @param victoire entier qui vaut 1 si l'adversaire a gagné , 2 si le joueur a gagné et -1 si il y a match nul
 */
void affichage_victoire(SDL_Renderer* renderer_jeu,int victoire);

/**
 * @brief void affichage_actions(SDL_Renderer *renderer_jeu,int * nb_actions)
 * @fn fonction d'affichage du nombre d'action dont le joueur dispose dans son tour
 * 
 * @param renderer_jeu notre renderer
 * @param nb_actions le nombre d'actions dont le joueur dispose pendant un tour
 */
void affichage_actions(SDL_Renderer *renderer_jeu,int * nb_actions);

/**
 * @brief void * calcul_temps(void * val)

 * @fn thread changeant la valeur de jeu toute les 60 secondes pour limiter le temps de tour du joueur et ne bouclant pas quand jeu vaut 0
 * 
 * @param val pointeur sur la valeur de jeu qui vaut 1 quand c'est le tour du joueur et 0 pour le tour du bot
 * @return void* 
 */
void * calcul_temps(void * val);
