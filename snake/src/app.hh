#ifndef APP_HH
#define APP_HH

#include <SDL2/SDL.h>

#include "renderer.hh"
#include "game.hh"

struct App {
public:
    void run();

private:
    bool running = true;
    SDL_Window *window = nullptr;
    Renderer renderer = {};
    int lastTick = 0;
    Game game = {};

    void init();
    void main_loop();
    void cleanup();
};

#endif // APP_HH
