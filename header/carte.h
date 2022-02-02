


typedef enum type{Feu , Eau , Air , Terre , Poison , Electrique }type_carte_t;


typedef struct carte{
  char * nom_carte;
  int hp_carte;
  int att_carte;
  type_carte_t  type_carte;
  char * effet_carte;

}carte_t;




typedef struct deck_carte{

  carte_t deck[12];

}deck_t;

typedef struct main_joueur{

  carte_t main[6];

}main_t;
