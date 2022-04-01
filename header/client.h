/**
 * @file client.h
 * @author Allan (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief header du client.c
 * @version 0.1
 * @date 2022-04-01
 * 
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


typedef struct sockaddr_in_s{
    short               sin_family;
    unsigned short      sin_port;
    struct in_addr      sin_addr;
    char                sin_zero[8];
}sockaddr_in_t;

typedef struct serverStruct_s{
  int valSocket; /** \brief valSocket est un entier permettant de verifier et garder en memoire le socket du client */
  int joueurTrouve; /** \brief joueurTrouve est un entier permettant de verifier si on a trouve un joueur */
}serverStruct_t;

typedef struct gestion_s{
  int flag;
  int mat1[5][3];
  int mat2[5][3];
  carte_t tab1[10];
  carte_t tab2[10];
  int socket;
}gestion_t;

void* recupererInfo(void* structure);
void transfertInfo(gestion_t* futurInfos, int premiereMat[][3], int deuxiemeMat[][3], carte_t premierTab[], carte_t deuxiemeTab[], int flagC, int socket);
int gestionPartie(void* infos);
void connectF(int* socket);
void* rechercheJoueur(void* infos);
int connectC();
