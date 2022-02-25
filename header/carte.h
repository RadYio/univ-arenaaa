
typedef enum type{Poison, Psy, Physique}type_t;

typedef struct carte{
  char * nom;
  int hp_carte;
  int nb_degats;
  type_t  type_attaque;
  type_t  type_vulnerable;
  int id_image;
}carte_t;


carte_t * creer_carte(char * nom, int hp , int attaque , type_t type_attaque , type_t type_vulnerable, int id);



/*
typedef struct deck_carte{

  carte_t deck[12];

}deck_t;

typedef struct main_joueur{

  carte_t main[6];

}main_t;
*/
