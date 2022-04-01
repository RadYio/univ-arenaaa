/**
 * @file client.c
 * @author Allan GONIN-SAGET (allan.gonin-saget.etu@univ-lemans.fr)
 * @brief  Fichier regroupant les fonctions princpales permettant le lien et le contact avec un serveur
 * @version 1.0
 * @date 2022-03-28
 *
 */
#include "../header/client.h"


void* recupererInfo(void* structure){
  gestion_t* informations = (gestion_t*)structure; //On triche
  int saveSocket = informations->socket;
  int taille = read(saveSocket, informations, sizeof(gestion_t));
  printf("Socket[%i] // taille[%i]\n", saveSocket, taille);
  while(taille>0){
    taille = read(saveSocket, informations, sizeof(gestion_t));
  }
  printf("A VERIFIER ATTENTION\n\n");
  return NULL;
}
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
void transfertInfo(gestion_t* futurInfos, int premiereMat[][3], int deuxiemeMat[][3], carte_t premierTab[], carte_t deuxiemeTab[], int flagC, int socket){
  for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
      futurInfos->mat1[i][j] = premiereMat[i][j];
      futurInfos->mat2[i][j] = deuxiemeMat[i][j];
    }
  }
  for(int i=0;i<10;i++){
    futurInfos->tab1[i].hp_carte = premierTab[i].hp_carte;
    futurInfos->tab2[i].hp_carte = deuxiemeTab[i].hp_carte;
  }
  futurInfos->flag = flagC;
  send(socket, futurInfos, sizeof(*futurInfos), 0);
  printf("Le flag est de %i\n\n",futurInfos->flag);
  futurInfos->flag = 0;
}
/**
 * @brief termine la connexion avec le serveur
 *
 * @param socket pointeur vers le socket du serveur
 */
void connectF(int* socket){
  send(*socket,"FIN",64,0);
  shutdown(*socket,2);
  close(*socket);
  *socket=-1;
}
/**
 * @brief fonction qui repere l'information du serveur, pour connaitre qui commence
 *
 * @param infos pointeur générique, qu'on cast en int, afin d'avoir le socket du serveur
 * @return int [1] si tour du joueur, [2] si pas le tour du joueur, [-1] si on recoit une deconnexion, [0], si aucun cas
 */
int gestionPartie(void* infos){
  int* socket = (int*)infos;
  char buffer[64];
  recv(*socket, buffer, 64, 0);
  printf("J'ai recu [%s]\n",buffer);

  if(strcmp(buffer,"TOUR_TOI") == 0){
    return 1;
  }
  else if(strcmp(buffer,"TOUR_PASTOI") == 0){
    return 2;
  }
  else if(strcmp(buffer,"FIN") == 0){
    printf("J'ai recu une dinguerie\n\n");
    shutdown(*socket,2);
    close(*socket);
    *socket=-1;
    return -1;
  }
  return 0;
}
/**
 * @brief
 *
 * @param infos
 * @return void*
 */
void* rechercheJoueur(void* infos){
  serverStruct_t* infoServer = (serverStruct_t*)infos;
  char buffer[64];
  recv(infoServer->valSocket, buffer, 64, 0);
  if(strcmp(buffer,"CONNEXION") == 0){
    infoServer->joueurTrouve=1;
  }
  else{
    printf("la fonction recv, n'est pas bloquante: [%s]\n",buffer);
    infoServer->joueurTrouve=0;
  }
  pthread_exit(NULL);
  return NULL;
}
/**
 * @brief genere une connexion avec le serveur
 *
 * @return int renvoie le socket, apres la connexion avec le serveur
 */
int connectC(){
  sockaddr_in_t sin;

  //On crée notre socket
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(clientSocket==-1){
    printf("Sortie à cause d'un bug de création Socket\n");
    return 1;
  }
  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", clientSocket);


  //Configuration
  sin.sin_addr.s_addr = inet_addr("193.52.29.245");    //inet_addr("172.18.41.172") afin de connaitre l'adresse ip via ifconfig
  sin.sin_family = AF_INET;                           //Protocole ici (IP)
  sin.sin_port = htons(PORT);                         //Port

  int testConnect = -1;
  int i;
  testConnect = connect(clientSocket, (struct sockaddr*)&sin, sizeof(sin));
  for(i=1;i<=NB_TENTATIVE && testConnect==-1;i++){
    printf("Nouvelle tentative de connexion (%i)\n",i);
    sleep(DELAI);
    testConnect = connect(clientSocket, (struct sockaddr*)&sin, sizeof(sin));
  }
  if(i>=NB_TENTATIVE){
    printf("Nombre de tentative max atteinte (%i)\n\nEXIT\n",i);
    return -1;
  }

  printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

  printf("Tentative de free\n");
  printf("Sortie\n");
  return (clientSocket);
}
