CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}

CFLAGS_DEBUG    = -g -Wextra

PROG=test

all: test

test: test_jeu_solo.c affichages.c init_jeu_solo.c
	${CC} -o ${PROG} test_jeu_solo.c affichages.c init_jeu_solo.c ${LIBS} ${INCLUDES} ${CFLAGS_COMPIL}

clean:
	rm -f ${PROG}
	rm -f *.o
