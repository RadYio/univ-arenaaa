CC=gcc
CFLAGS_DEBUG	=	-g -Wextra

CLIENT=client_test
SERVER=server_test

all: clean ${SERVER} ${CLIENT}

${SERVER}: server.c
	${CC} -o ${SERVER} server.c ${CFLAGS_COMPIL} -lpthread

${CLIENT}: client.c
	${CC} -o ${CLIENT} client.c ${CFLAGS_COMPIL} -lpthread

clean:
	rm -f ${SERVER}
	rm -f ${CLIENT}
	rm -f *.o
