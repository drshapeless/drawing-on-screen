#include "app.hh"
#include "config.hh"
#include "helpers.hh"

#include <vector>

void App::run() {
    init();
    main_loop();
    cleanup();
}

void App::init() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        error_log(SDL_GetError());
    }

    window = SDL_CreateWindow(WINDOW_TITLE, SCREEN_WIDTH, SCREEN_HEIGHT,
                              SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        error_log(SDL_GetError());
    }

    renderer.init(window);

    game.init();
}

Rect snake_to_rect(uint32_t pos) {
    Rect rect = {};
    rect.w = SCREEN_WIDTH / GRID_WIDTH;
    rect.h = SCREEN_HEIGHT / GRID_HEIGHT;
    rect.x = pos % GRID_WIDTH * rect.w;
    rect.y = pos / GRID_WIDTH * rect.h;

    rect.w -= 2;
    rect.h -= 2;
    rect.x += 1;
    rect.y += 1;

    return rect;
}

void App::main_loop() {
    bool changed = false;
    bool pause = false;
    while (running) {
        /* process event */
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            switch (e.type) {
            case SDL_EVENT_QUIT:
                running = false;
                break;
            case SDL_EVENT_KEY_DOWN:
                switch (e.key.keysym.sym) {
                case SDLK_w:
                    if (!changed) {
                        game.change_direction(DIRECTION_UP);
                        changed = true;
                    }
                    break;
                case SDLK_d:
                    if (!changed) {
                        game.change_direction(DIRECTION_RIGHT);
                        changed = true;
                    }
                    break;
                case SDLK_s:
                    if (!changed) {
                        game.change_direction(DIRECTION_DOWN);
                        changed = true;
                    }
                    break;
                case SDLK_a:
                    if (!changed) {
                        game.change_direction(DIRECTION_LEFT);
                        changed = true;
                    }
                    break;
                case SDLK_SPACE:
                    if (game.dead) {
                        game.init();
                    } else {
                        pause = !pause;
                    }
                    break;
                case SDLK_ESCAPE:
                    running = false;
                    break;
                }
                break;
            }
        }

        if (pause) {
            continue;
        }

        if (game.dead) {
            continue;
        }

        int current = SDL_GetTicks();
        int delta = current - lastTick;
        if (delta < 1000 / FPS) {
            continue;
        }
        lastTick = current;

        game.tick();

        changed = false;

        renderer.set_color(0, 0, 0, 255);
        renderer.clear();

        // draw apple
        renderer.set_color(255, 0, 0, 255);
        Rect apple = snake_to_rect(game.apple);
        renderer.draw_rect(&apple);

        // draw head
        renderer.set_color(0, 255, 0, 255);
        Rect head = snake_to_rect(game.snake_head);
        renderer.draw_rect(&head);

        // draw body
        std::vector<Rect> body = {};
        for (auto b : game.snake_body) {
            body.push_back(snake_to_rect(b));
        }
        if (game.dead) {
            renderer.set_color(150, 150, 150, 255);
        } else {
            renderer.set_color(255, 255, 255, 255);
        }
        renderer.draw_rects(body.data(), body.size());

        renderer.present();
    }
}

void App::cleanup() {
    // no need to destroy game
    renderer.destroy();
    SDL_DestroyWindow(window);
    SDL_Quit();
}
