export PKG_CONFIG_PATH=/usr/local/lib64/pkgconfig

# compiler
CC = clang
CXX = clang++

# includes and libs
INCS = $(shell pkg-config --cflags sdl3) -I../include
LIBS = $(shell pkg-config --libs sdl3)

# flags
CFLAGS = $(INCS) -O2 -std=c99
CXXFLAGS = $(INCS) -std=c++11
LDFLAGS = $(LIBS) -lpthread
# LDFLAGS = $(LIBS) -lGL -lpthread

UNAME := $(shell uname -s)
ifeq ($(UNAME), Darwin)
	LDFLAGS = $(LIBS) -ldl -lpthread
# LDFLAGS = $(LIBS) -ldl -lpthread -framework OpenGL
endif
