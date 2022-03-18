#include "../header/carte.h"
#include "../header/affichage.h"
#include "../header/bot.h"

//fonction qui vérifie si celui qui défend est vulnerable au type d'attaque, renvoi 1 si c'est le cas, 0 sinon
int attaque_critique(type_t attaque, type_t vulnerable){
    //Poison est vulnérable à Physique, Psy est vulnérable contre Poison et Physique est vulnérable à Psy
    return(attaque == Physique && defense == Poison) || (attaque == Poison && defense == Psy) || (attaque == Psy && defense == Physique));
}

//si une carte n'a plus d'hp, on doit l'enlever de la formation et du deck
void mort_carte(int id_carte_defense, carte_t deck_defense[], int tab_formation_defense[][3]){
    
} 


//foncton gérant le fait que qqn attaque une carte
void attaque(int id_carte_attaque, int id_carte_defense, carte_t deck_attaque[], carte_t deck_defense[], int tab_formation_defense[][3]){
    int i = 0, j = 0, nb_degats, hp;
    //parcours du deck du joueur pour trouver la carte correspondante
    while(deck_attaque[i] != id_carte_attaque) i++;
    //on a trouvé la carte correspondante, on recupere donc la valeur d'attaque
    nb_degats = deck_attaque[i].nb_degats;
    //parcours du deck de l'adversaire pour trouver la carte correspondante
    while(deck_defense[j] != id_carte_defense) j++;

    //on regarde si on fait une attaque critique : les degats sont multipliés par 2 si c'est le cas
    if(attaque_critique(deck_attaque[i].type_attaque, deck_defense[j].type_vulnerable)){
        nb_degats *= 2;
    }
    
    //on enleve les hp correspondant
    deck_defense[j].hp -= nb_degats;
    //si la carte à plus de hp elle meurt, on l'enleve donc du jeu
    if(deck_defense[j].hp <= 0){
        mort_carte(id_carte_defense, deck_defense, tab_formation_defense);
    }
    
}