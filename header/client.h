/**
 * @file client.h
 * @author Allan (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief header du client.c
 * @version 1.0
 * @date 2022-04-04
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>

#include "carte.h"

#define PORT 6666 
#define NB_TENTATIVE 60
#define DELAI 1

/** @struct sockaddr_in_s
  *
  * @brief cf. <sys/socket.h>
  */
typedef struct sockaddr_in_s{
  /** @brief Le protocole */
  short               sin_family;

  /** @brief numéro du port */
  unsigned short      sin_port;

  /** @brief adresse ip; 4 octets sous forme de 155.101.23.66 */
  struct in_addr      sin_addr;

  /** @brief on utilise ici 16 octets */
  char                sin_zero[8];
}sockaddr_in_t;

/**
 * @struct serverStruct_s
 * @brief structure contenant le socket de connexion et un entier(utilisé comme bool), qui permet de connaitre si un joueur est trouvé
 */
typedef struct serverStruct_s{
  /** @brief valSocket est un entier permettant de verifier et garder en memoire le socket du client */
  int valSocket; 
  /** @brief joueurTrouve est un entier permettant de verifier si on a trouve un joueur */
  int joueurTrouve; 
}serverStruct_t;

/**
 * @struct gestion_s
 * @brief structure qui contient les informations du plateau qu'on envoie à travers le serveur d'un client à un autre
 */
typedef struct gestion_s{
  int flag;
  int mat1[5][3];
  int mat2[5][3];
  carte_t tab1[10];
  carte_t tab2[10];
  int socket;
}gestion_t;

void* recupererInfo(void* structure);

/**
 * @brief Fonction permettant de prendre les données des joueurs et les transferer au joueur qui attend son tour
 *
 * @param futurInfos structure gestion_t
 * @param premiereMat matrice contenant l'etat du plateau du joueur actuel
 * @param deuxiemeMat matrice contenant l'etat du plateau du joueur adverse
 * @param premierTab tableau de carte_t, contenant l'état des cartes du joueur
 * @param deuxiemeTab tableau de carte_t, contenant l'état des cartes de l'adversaire
 * @param socket entier contenant le socket du serveur
 */
void transfertInfo(gestion_t* futurInfos, int premiereMat[][3], int deuxiemeMat[][3], carte_t premierTab[], carte_t deuxiemeTab[], int flagC, int socket);

/**
 * @brief fonction qui repere l'information du serveur, pour connaitre qui commence
 *
 * @param infos pointeur générique, qu'on cast en int, afin d'avoir le socket du serveur
 * @return int [1] si tour du joueur, [2] si pas le tour du joueur, [-1] si on recoit une deconnexion, [0], si aucun cas
 */
int gestionPartie(void* infos);

/**
 * @brief termine la connexion avec le serveur
 *
 * @param socket pointeur vers le socket du serveur
 */
void connectF(int* socket);

/**
 * @brief (utilisation via un thread, sinon fonction bloquante) reste en attente de la réponse du serveur annoncant une connexion établie avec un autre joueur
 *
 * @param pointeur générique (thread): cast en serverStruct_t
 * @return void* NULL
 */
void* rechercheJoueur(void* infos);

/**
 * @brief genere une connexion avec le serveur
 *
 * @return int renvoie le socket, apres la connexion avec le serveur
 */
int connectC();
