include config.mk

SRC = main.cc helpers.cc app.cc game.cc
OBJ = $(SRC:.cc=.o) glad.o renderer.o

all: sample

sample: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

main.o: config.hh

glad.o:

helpers.o: helpers.hh

app.o: app.hh config.hh

game.o: game.hh

renderer.o: renderer.hh renderer_sdl.cc
	$(CXX) -o $@ $(CXXFLAGS) -c renderer_sdl.cc

clean:
	rm -f sample $(OBJ)

.PHONY: all clean
