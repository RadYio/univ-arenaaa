#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <string.h>



#define PORT 6666
#define CLIENT_MAX 32

typedef enum estLibre{OUI,NON}estLibre_t;

typedef struct sockaddr_in_s{
    short               sin_family;
    unsigned short      sin_port;
    struct in_addr      sin_addr;
    char                sin_zero[8];
}sockaddr_in_t;

typedef struct client_s{
  int num;
  estLibre_t libre;
  int numSock;
  sockaddr_in_t sin; //Socket address IN
  socklen_t taille;
}client_t;

typedef struct lien_s{
  client_t client1;
  client_t client2;
}lien_t;

//DEFINITION DU CLIENT
client_t listeClient[CLIENT_MAX];
int nb_client_attente=0;

//DEFINITION DES THREADS SAH QUEL PLAISIR
pthread_t th_attente[CLIENT_MAX];
pthread_t th_connectes[CLIENT_MAX];



struct tm* recupererTemps(){
  time_t temp;
  time(&temp);
  return localtime(&temp);
}

void tableauPropre(){
  int i;
  for(i=0;i<CLIENT_MAX;i++)
    listeClient[i].num=-1;
    listeClient[i].libre=NON;
    listeClient[i].numSock=-1;
}

void* connectes(void* oldJoueurs){
  lien_t* joueurs = (lien_t*) oldJoueurs; //On triche, le  thread forcant un param void*
  client_t joueur1 = joueurs->client1;
  client_t joueur2 = joueurs->client2;
  char buffer[64];
  send(joueur1.numSock, "CONNEXION", 64, 0);
  send(joueur2.numSock, "CONNEXION", 64, 0);
  sleep(2);
  send(joueur2.numSock, "FIN", 64, 0);
  ssize_t verif = -1;
  while(verif!=0){
    verif = read(joueur1.numSock,buffer,64);
  }
  struct tm* dateTh=recupererTemps();
  printf("2] %i:%i:%i || client[%i]: deconnexion\n", dateTh->tm_hour, dateTh->tm_min, dateTh->tm_sec, joueur1.num);


  //shutdown(joueur1.numSock, 2);
  //shutdown(joueur2.numSock, 2);

  //close(joueur1.numSock);
  //close(joueur2.numSock);

  free(joueurs);

  pthread_exit(NULL);
}

void* attente(void* informations){
  client_t* client = (client_t*) informations; //On triche, le  thread forcant un param void*
  ssize_t verif = -1;
  char buffer[64];

  while(verif!=0){
    printf("Client[%i]: j'attends des informations...\n",client->num);
    verif = read(client->numSock,buffer,64);
  }
  struct tm* dateTh=recupererTemps();
  printf("%i:%i:%i || client[%i]: deconnexion\n", dateTh->tm_hour, dateTh->tm_min, dateTh->tm_sec, client->num);client->num=-1;
  nb_client_attente--;
  pthread_exit(NULL);
}

int main(){
  //DEFINITION DU SERVEUR
  sockaddr_in_t server_Sin;                               //Socket address IN
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);     //serverSocket
  socklen_t s_Taille = sizeof(server_Sin);

  client_t client_temporaire;

  struct tm* date = recupererTemps(); //stucture date, contenant le temps actuel de l'ordinateur

  if(serverSocket==-1){ //On vérifie la création socket de notre serveur
    printf("Sortie à cause d'un bug de création Socket\n");
    return 1;
  }
  printf("La socket %d est maintenant ouverte en mode TCP/IP\n", serverSocket);

  //Configuration du serveur
  server_Sin.sin_addr.s_addr = htonl(INADDR_ANY);  //htonl donne une ip automatique
  server_Sin.sin_family = AF_INET;                 //Protocole ici (IP)
  server_Sin.sin_port = htons(PORT);               //Port


  //DECLARATION *test afin de se souvenir de la valeur des tests
  int* test = malloc(sizeof(int));

  *test = bind(serverSocket, (struct sockaddr *)&server_Sin, sizeof(server_Sin));
  if(*test==SO_ERROR){
    printf("Sortie à cause d'un bug de bind Socket\n");
    return 1;
  }



  *test= listen(serverSocket, 50);
  if(*test==SO_ERROR){
    printf("Sortie à cause d'un bug de listen Socket\n");
    return 1;
  }

  free(test);
  printf("Utilisation et écoute du port %d...\n\n", PORT);



  int i,j;
  tableauPropre();
  while(1){
    if(nb_client_attente!=0 && nb_client_attente%2==0){ //deux clients dispos pour jouer
      for(j=0;j<CLIENT_MAX;j++){
        if(listeClient[j].libre == OUI){
          listeClient[i].libre=NON;
          listeClient[j].libre=NON;
          lien_t* nouvelleConnexion = malloc(sizeof(lien_t));
          nouvelleConnexion->client1=listeClient[i];
          nouvelleConnexion->client2=listeClient[j];
          pthread_cancel(th_attente[i]);
          pthread_cancel(th_attente[j]);
          printf("Création de liens\n\n");
          pthread_create(&th_connectes[i], NULL, connectes, (void*)nouvelleConnexion);
          nb_client_attente-=2;
          break;
        }

      }
      if(j>=CLIENT_MAX) printf("Désolé, j'ai fait nimp\n");
    }


    printf("On attente de la connexion d'un client ...\n");
    client_temporaire.numSock = accept(serverSocket, (struct sockaddr*)&client_temporaire.sin, &client_temporaire.taille);
    for(i=0;i<CLIENT_MAX;i++){
      if(listeClient[i].num==-1){ //Si libre
        listeClient[i].sin = client_temporaire.sin;
        listeClient[i].taille= client_temporaire.taille;
        listeClient[i].numSock = client_temporaire.numSock;
        listeClient[i].num=i;
        break; //On break afin de garder l'indice de i;
      }
    }
    if(i<CLIENT_MAX){ //On a trouvé une place
      date=recupererTemps();
      printf("->%i:%i:%i || client[%i]: nouvelle connexion\n", date->tm_hour, date->tm_min, date->tm_sec, i);
      pthread_create(&th_attente[i], NULL, attente, (void*)&listeClient[i]);
      listeClient[i].libre=OUI;
      nb_client_attente++;
    }
    else{
    printf("Utilisateur à essayer de se connecter, mais on a plus de place\n\n");
    shutdown(client_temporaire.numSock, 2);
    }
  }
}
