#include "renderer_sdl.hh"
#include "helpers.hh"

void RendererSDL::init(SDL_Window *window) {
    renderer = SDL_CreateRenderer(window, NULL, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        error_log(SDL_GetError());
    }
}

void RendererSDL::destroy() {
    SDL_DestroyRenderer(renderer);
}

void RendererSDL::set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    if (SDL_SetRenderDrawColor(renderer, r, g, b, a) != 0) {
        error_log(SDL_GetError());
    }
}

void RendererSDL::draw_rect(const Rect *rect) {
    if (SDL_RenderFillRect(renderer, rect) != 0) {
        error_log(SDL_GetError());
    }
}

void RendererSDL::draw_rects(const Rect *rects, int count) {
    if (SDL_RenderFillRects(renderer, rects, count) != 0) {
        error_log(SDL_GetError());
    }
}

void RendererSDL::clear() {
    if (SDL_RenderClear(renderer) != 0) {
        error_log(SDL_GetError());
    }
}

void RendererSDL::present() {
    if (SDL_RenderPresent(renderer) != 0) {
        error_log(SDL_GetError());
    }
}
