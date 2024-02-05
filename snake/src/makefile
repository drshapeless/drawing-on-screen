include config.mk

SRC = main.cc helpers.cc
OBJ = $(SRC:.cc=.o) glad.o

all: sample

sample: $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LDFLAGS)

main.o: config.hh

glad.o:

helpers.o:

clean:
	rm -f sample $(OBJ)

.PHONY: all clean
