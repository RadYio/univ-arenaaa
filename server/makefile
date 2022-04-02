CC=gcc
CFLAGS_DEBUG	=	-g -Wextra

SERVER=server_test

all: clean ${SERVER}

${SERVER}: server.c
	${CC} ${CFLAGS_DEBUG} -o ${SERVER} server.c -lpthread 2>./log.txt

clean:
	rm -f ${SERVER}
	rm -f *.o
