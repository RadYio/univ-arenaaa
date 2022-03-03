#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define PORT 8080

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
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if(serverSocket==-1){
    printf("Sortie à cause d'un bug de création Socket\n");
    return 1;
  }
  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", serverSocket);


  //Configuration
  //inet_addr("172.18.41.144");                //Oblige une certaine IP
  sin.sin_addr.s_addr = htonl(INADDR_ANY);  //htonl donne une ip automatique
  sin.sin_family = AF_INET;                 //Protocole ici (IP)
  sin.sin_port = htons(PORT);               //Port




  int testBind = bind(serverSocket, (struct sockaddr *)&sin, sizeof(sin));
  if(testBind==SO_ERROR){
    printf("Sortie à cause d'un bug de bind Socket\n");
    return 1;
  }



  int testListen = listen(serverSocket, 50);
  if(testListen==SO_ERROR){
    printf("Sortie à cause d'un bug de listen Socket\n");
    return 1;
  }
  printf("Utilisation du port %d...\n", PORT);




  printf("On attente de la connexion d'un client ...\n");
  int testAccept = accept(serverSocket, (struct sockaddr*)&sin, &taille);
  printf("Un client se connecte avec la socket %d de %s:%d\n", testAccept, inet_ntoa(sin.sin_addr), htons(sin.sin_port));
}
