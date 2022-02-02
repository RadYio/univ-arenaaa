#include <stdio.h>
#include "carte.h"




carte_t * creer_carte(char * nom, int hp , int att , type_carte_t type , char * effet){
  carte_t * carte;
  carte = malloc(sizeof(carte_t));
  carte->nom_carte = nom;
  carte->hp_carte = hp;
  carte->att_carte = att;
  carte->type_carte = type;
  carte->effet_carte = effet;

  return carte;
}
