
#flags de compilation---------------------------------------------------
CC=gcc
CFLAGS_DEBUG= -g -Wextra

#SDL---------------------------------------------------------------------
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread
INCLUDES=-I${SDLINC_DIR}

#notre projet-----------------------------------------------------------
PROG=univ-arenaaaa
PROG_DEBUG=univ-arenaaaa_debug

SRC=${wildcard *.c} #on récupère tous nos fichiers .c


#façons de make---------------------------------------------------------
all: ${PROG} #projet en mode normal
	./univ-arenaaaa

debug: ${PROG_DEBUG} #projet en mode debug
	./univ-arenaaaa_debug

clean: #supprimer fichiers
	rm -f ${PROG}
	rm -f ${PROG_DEBUG}
	rm -f *.o

doxygen: #générer le doxygen
	doxygen ./Doxyfile

#dependances-----------------------------------------------------------

${PROG}: ${SRC}
	${CC} -o $@ ${SRC} ${LIBS} ${INCLUDES}

${PROG_DEBUG}: ${SRC}
	${CC} -o $@ ${SRC} ${LIBS} ${INCLUDES} ${CFLAGS_DEBUG}
