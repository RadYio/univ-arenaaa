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
  //DEFINITION DU SERVEUR
  sockaddr_in_t server_Sin;
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  socklen_t s_Taille = sizeof(server_Sin);

  //DEFINITION DU CLIENT
  sockaddr_in_t client_Sin;
  int clientSocket;
  socklen_t c_Taille = sizeof(client_Sin);

  //On vérifie la création socket de notre serveur
  if(serverSocket==-1){
    printf("Sortie à cause d'un bug de création Socket\n");
    return 1;
  }
  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", serverSocket);

  //Configuration du serveur
  server_Sin.sin_addr.s_addr = htonl(INADDR_ANY);  //htonl donne une ip automatique
  server_Sin.sin_family = AF_INET;                 //Protocole ici (IP)
  server_Sin.sin_port = htons(PORT);               //Port

  int testBind = bind(serverSocket, (struct sockaddr *)&server_Sin, sizeof(server_Sin));
  if(testBind==SO_ERROR){
    printf("Sortie à cause d'un bug de bind Socket\n");
    return 1;
  }
  int testListen = listen(serverSocket, 50);
  if(testListen==SO_ERROR){
    printf("Sortie à cause d'un bug de listen Socket\n");
    return 1;
  }
  printf("Utilisation et écoute du port %d...\n", PORT);




  printf("On attente de la connexion d'un client ...\n");
  clientSocket = accept(serverSocket, (struct sockaddr*)&client_Sin, &c_Taille);
  printf("Un client se connecte avec la socket %d de %s:%d\n", clientSocket, inet_ntoa(client_Sin.sin_addr), htons(client_Sin.sin_port));
}
