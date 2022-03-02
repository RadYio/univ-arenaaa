CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image
INCLUDES=-I${SDLINC_DIR}

CFLAGS_DEBUG    = -g -Wextra

PROG=univ-arenaaaa

all: univ-arenaaaa

univ-arenaaaa: main.c carte.c jeu_solo.c menu.c window.c collection.c
	${CC} -o ${PROG} main.c carte.c jeu_solo.c menu.c window.c collection.c ${LIBS} ${INCLUDES} ${CFLAGS_COMPIL}

clean:
	rm -f ${PROG}
	rm -f *.o
