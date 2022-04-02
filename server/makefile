CC=gcc
CFLAGS_DEBUG	=	-g -Wextra

CLIENT=client_test
SERVER=server_test

all: clean ${SERVER} ${CLIENT}

${SERVER}: server.c
	${CC} ${CFLAGS_DEBUG} -o ${SERVER} server.c -lpthread 2>./log.txt

clean:
	rm -f ${SERVER}
	rm -f ${CLIENT}
	rm -f *.o
