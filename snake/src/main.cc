#include <SDL2/SDL.h>

#include "config.hh"
#include "helpers.hh"
#include "app.hh"

int main(int argc, char *argv[]) {
    App app = {};

    app.run();

    return 0;
}
