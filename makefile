# project name (generate executable with this name)
TARGETS  = univ-arenaaa #univ-arenaaa_test


CC       = gcc
# compiling flags here
CFLAGS   = -std=c99 -Wall -I. #-g


LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -I. -lm

#file directories
SRCDIR   = src
OBJDIR   = obj
BINDIR   = bin
HEADERDIR = header
TRGS	 := $(TARGETS:%=$(BINDIR)/%)


DIRS	 = $(OBJDIR) $(BINDIR)

#SDL---------------------------------------------------------------------
SDL_DIR=${HOME}/SDL2
SDLLIB_DIR=${SDL_DIR}/lib
SDLINC_DIR=${SDL_DIR}/include

LIBS=-L${SDLLIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -lpthread
INCLUDES_SDL=-I${SDLINC_DIR}


.PHONY: DIRS
all: $(DIRS) $(TRGS)

doxygen: #creation du doxygen
	doxygen ./doc/ProjetL2ConfigDoxygen
	firefox doc/html/index.html

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(HEADERDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
# Liste des fichiers .o sans ceux contenant un main
OBJS	 := $(filter-out $(MAINS),$(OBJECTS))
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
$(TRGS): $(OBJECTS)
	@$(LINKER) $(OBJS) $(LFLAGS) -o $@ ${LIBS} ${INCLUDES_SDL}
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ ${LIBS} ${INCLUDES_SDL}
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(BINDIR)/*
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGETS)
	@echo "Executable removed!"



