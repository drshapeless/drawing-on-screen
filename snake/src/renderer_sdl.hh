#ifndef RENDERER_SDL_HH
#define RENDERER_SDL_HH

#include <SDL2/SDL.h>

typedef SDL_Rect Rect;

struct RendererSDL {
    void init(SDL_Window *window);
    void destroy();

    void set_color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    void draw_rect(const Rect *rect);
    void draw_rects(const Rect *rects, int count);
    void clear();
    void present();

private:
    SDL_Renderer *renderer = nullptr;
};
typedef RendererSDL Renderer;

#endif // RENDERER_SDL_HH
