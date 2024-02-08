include config.mk

SRC = main.cc helpers.cc app.cc game.cc
OBJ = $(SRC:.cc=.o)

all: sdl_renderer

sdl_renderer: $(OBJ) renderer_sdl.o
	$(CXX) -o sample $(OBJ) renderer_sdl.o $(LDFLAGS)

webgpu: $(OBJ) renderer_wgpu.o
	$(CXX) $(CXXFLAGS) -o sample $(OBJ) renderer_wgpu.o $(LDFLAGS) ../lib/libwgpu_native.a

main.o: config.hh

glad.o:

helpers.o: helpers.hh

app.o: app.hh config.hh

game.o: game.hh

renderer_sdl.o: renderer.hh renderer_sdl.hh

renderer_wgpu.o: renderer.hh renderer_wgpu.hh

clean:
	rm -f sample $(OBJ) renderer*.o

.PHONY: all clean
