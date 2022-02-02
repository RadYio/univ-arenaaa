# nom du projet, a creer sous ce nom
TARGETS  = Univ-arena

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
LIBS=-L${SDL_LIB_DIR} -lSDL2 -lSDL2 image -lSDL2 ttf

INCS=-I${SDL_INC_DIR}

PROG=univ-arena

all: test #à changer

test: ${TARGETS}.c
	${CC} -o ${PROG} ${TARGETS}.c ${LIBS} ${INCS} ${CFLAGS_COMPIL}


clean:
	rm -f ${PROG}
	rm -f *.o
