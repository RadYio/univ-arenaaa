#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>



#define PORT 6666
#define CLIENT_MAX 32

typedef struct sockaddr_in_s{
    short               sin_family;
    unsigned short      sin_port;
    struct in_addr      sin_addr;
    char                sin_zero[8];
}sockaddr_in_t;

typedef struct client_s{
  int num;
  int numSock;
  sockaddr_in_t sin; //Socket address IN
  socklen_t taille;
}client_t;


//HORLOGE
time_t horloge;
int oldSecondes;

//DEFINITION DU CLIENT
client_t listeClient[CLIENT_MAX];
int nb_client_total=0;

//DEFINITION DES THREADS SAH QUEL PLAISIR
pthread_t thread[CLIENT_MAX];

//DEFINITION GLOBALE DU serveur
int serverSocket;

/*void* connecting(void* v){
  client_t new;
  new.taille=sizeof(new.sin);
  new.numSock=accept(serverSocket, (struct sockaddr*)&new.sin, &new.taille);
  printf("Un client se connecte avec la socket %d de %s:%d\n", new.numSock, inet_ntoa(new.sin.sin_addr), htons(new.sin.sin_port));

  listeClient[nb_client_total++]=new;
  return NULL;
}*/

void* attente(void* informations){
  client_t* client = (client_t*) informations; //On triche, le  thread forcant un param void*

  ssize_t verif = -1;
  char* buffer = malloc(sizeof(char)*32+1);
  while(verif!=0){
    printf("Client[%i]: j'attends des informations...\n",client->num);
    verif = read(client->numSock,buffer,32);
    if(verif==0){
      printf("Client[%i] s'est deconnecté (pas cool)\n",client->num);
      return NULL;
    }
    else{
      printf("chaine: %s\n",buffer);
    }
  }
}

int main(){
  //DEFINITION DU SERVEUR
  sockaddr_in_t server_Sin;                               //Socket address IN
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);     //serverSocket
  socklen_t s_Taille = sizeof(server_Sin);


  srand(time(NULL));

  if(serverSocket==-1){ //On vérifie la création socket de notre serveur
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
  printf("Utilisation et écoute du port %d...\n\n", PORT);

  //pthread_create(&thread[0], NULL, connecting, NULL);
  //pthread_create(&thread[1], NULL, connecting, NULL);


  time(&horloge);
  while(1){
    if(oldSecondes!=horloge)
      printf("temps:(%li)\n\n",horloge);
    else
      oldSecondes = horloge;


    printf("On attente de la connexion d'un client ...\n");
    listeClient[nb_client_total].numSock = accept(serverSocket, (struct sockaddr*)&listeClient[nb_client_total].sin, &listeClient[nb_client_total].taille);
    listeClient[nb_client_total].num=nb_client_total;

    pthread_create(&thread[nb_client_total], NULL, attente, (void*)&listeClient[nb_client_total]);


    time(&horloge);
    nb_client_total++;
  }



}
