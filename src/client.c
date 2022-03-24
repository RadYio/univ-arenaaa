#include "../header/client.h"

void connectF(int* socket){
  send(*socket,"FIN",64,0);
  shutdown(*socket,2);
  close(*socket);
  *socket=-1;
}

int gestionPartie(void* infos){
  int* socket = (int*)infos;
  char buffer[64];
  ssize_t taille = recv(*socket, buffer, 64, 0);

  if(strcmp(buffer,"TOUR_TOI") == 0){
    return 1;
  }
  else if(strcmp(buffer,"TOUR_PASTOI") == 0){
    return 2;
  }
  else if(strcmp(buffer,"FIN") == 0){
    shutdown(*socket,2);
    close(*socket);
    *socket=-1;
    return -1;
  }
}

void* rechercheJoueur(void* infos){
  serverStruct_t* infoServer = (serverStruct_t*)infos;
  char buffer[64];
  ssize_t taille = recv(infoServer->valSocket, buffer, 64, 0);
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

int connectC(){
  sockaddr_in_t sin;
  socklen_t taille = sizeof(sin);
  pthread_t thread;

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
