CC=gcc
CFLAGS_DEBUG	=	-g -Wextra

CLIENT=client_test
SERVER=server_test

all: clean ${SERVER} ${CLIENT}

${SERVER}: server.c
	${CC} -g -o ${SERVER} server.c -lpthread

${CLIENT}: client.c
	${CC} -g -o ${CLIENT} client.c -lpthread

clean:
	rm -f ${SERVER}
	rm -f ${CLIENT}
	rm -f *.o
