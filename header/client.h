

#define PORT 6666
#define NB_TENTATIVE 60
#define DELAI 1


typedef struct sockaddr_in_s{
    short               sin_family;
    unsigned short      sin_port;
    struct in_addr      sin_addr;
    char                sin_zero[8];
}sockaddr_in_t;



void* lecture(void* socket);
