CC=gcc

SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread
INCLUDES=-I${SDLINC_DIR}

CFLAGS_DEBUG    = -g -Wextra

PROG=univ-arenaaaa

all: univ-arenaaaa
	./univ-arenaaaa



univ-arenaaaa: main.c carte.c menu.c jeu_solo.c jeu_multi.c  window.c collection.c affichage.c init_jeu_solo.c
	${CC} -o ${PROG} main.c carte.c menu.c jeu_solo.c jeu_multi.c  window.c collection.c affichage.c init_jeu_solo.c ${LIBS} ${INCLUDES} ${CFLAGS_COMPIL}

clean:
	rm -f ${PROG}
	rm -f *.o


