# nom du projet, a creer sous ce nom
TARGETS  = Univ' arena

CC       = gcc


# compiling flags here
CFLAGS_COMPIL   =  -c -Wall
CFLAGS_DEBUG    = -g -Wextra


#repertoires
SRCDIR   = src #fichiers sources
OBJDIR   = obj #.o
BINDIR   = bin #executables
TRGS	 := $(TARGETS:%=$(BINDIR)/%)

#---------------------------------------SDL------------------------------------------------------
SDL_DIR=${HOME}/SDL2
SDL_LIB_DIR=${SDL_DIR}/lib
SDL_INC_DIR=${SDL_DIR}/include
LIBS=-L${SDL_LIB_DIR} -lSDL2

INCS=-I${SDL_INC_DIR}

PROG=sdl_test

all: sdl_text
sdl_text: sdl_test.c
	${CC} -o ${PROG} sdl_test.c ${LIBS} ${INCS} ${FLAGS}

clean:
	rm -f ${PROG}
	rm -f *.o
