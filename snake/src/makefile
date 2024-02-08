include config.mk

SRC := $(filter-out $(wildcard renderer*.cc), $(wildcard *.cc))
OBJ := $(SRC:.cc=.o)

all: sdl

sdl: $(OBJ) renderer_sdl.o
	$(CXX) -o snake $(OBJ) renderer_sdl.o $(LDFLAGS)

clean:
	rm -f sample $(OBJ) renderer*.o

.PHONY: all clean
