#include "config.hh"
#include "helpers.hh"

#include <SDL2/SDL.h>

struct App {
    bool running = true;
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;

    void init() {
        init_sdl();
    }

    void init_sdl() {
        int rc = 0; // rc, result code

        rc = SDL_Init(SDL_INIT_VIDEO);
        if (rc != 0) {
            error_log(SDL_GetError());
        }

        window = SDL_CreateWindow(
            WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
            SCREEN_WIDTH, SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_RENDERER_ACCELERATED);
        if (window == nullptr) {
            error_log(SDL_GetError());
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
        if (renderer == nullptr) {
            error_log(SDL_GetError());
        }
    }

    void main_loop() {
        while (running) {
            /* process event */
            SDL_Event e;
            while (SDL_PollEvent(&e)) {
                switch (e.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                }
            }

            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }

    void cleanup() {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
};

int main(int argc, char *argv[]) {
    App app = {};

    app.init();
    app.main_loop();

    return 0;
}
