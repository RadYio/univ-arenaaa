
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

void init_cartes(carte_t * tab_cartes_total[N]);

void creer_sauvegarde();

void maj_sauvergarde(carte_t * carte);

void recup_sauvegarde(carte_t * tab_sauvegarde[N], carte_t * tab_cartes_total[N]);

void creation_deck(carte_t * deck[12]);



