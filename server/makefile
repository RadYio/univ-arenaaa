CC=gcc
CFLAGS_DEBUG	=	-g

SERVER=server_test

all: clean ${SERVER}

${SERVER}: server.c
	${CC} ${CFLAGS_DEBUG} -o ${SERVER} server.c -lpthread

clean:
	rm -f ${SERVER}
	rm -f *.o
