#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 8080
#define NB_TENTATIVE 5
#define DELAI 5

typedef struct sockaddr_in_s{
    short               sin_family;
    unsigned short      sin_port;
    struct in_addr      sin_addr;
    char                sin_zero[8];
}sockaddr_in_t;


int main(){
  sockaddr_in_t sin;
  socklen_t taille = sizeof(sin);

  //On crée notre socket
  int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(clientSocket==-1){
    printf("Sortie à cause d'un bug de création Socket\n");
    return 1;
  }
  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", clientSocket);


  //Configuration
  sin.sin_addr.s_addr = inet_addr("172.18.41.144");   //inet_addr("172.18.41.144") afin de connaitre l'adresse ip via ifconfig
  sin.sin_family = AF_INET;                           //Protocole ici (IP)
  sin.sin_port = htons(PORT);                         //Port

  int testConnect=-1;
  int i;
  testConnect = connect(clientSocket, (struct sockaddr*)&sin, sizeof(sin));
  for(i=1;i<=NB_TENTATIVE && testConnect==-1;i++){
    printf("Nouvelle tentative de connexion (%i)\n",i);
    sleep(DELAI);
    testConnect = connect(clientSocket, (struct sockaddr*)&sin, sizeof(sin));
  }
  if(i>=NB_TENTATIVE){
    printf("Nombre de tentative max atteinte (%i)\n\nEXIT\n",i);
    return 1;
  }
  printf("wtf: %i\n", testConnect);
  printf("Connexion à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));

  int choix = -1;
  do{
    printf("---MENU TEST ---\n");
    printf("1) QUITTER\n");
    printf("\n");
    scanf("%i",&choix);
  }while(choix==-1);
  switch (choix){
    case 1: //OPTN: QUITTER
      printf("1) %i\n",shutdown(clientSocket, 2));
      printf("2) %i\n",close(clientSocket));
      printf("3) On quitte le client\n");
      return 1;
  }
}
