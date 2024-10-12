#ifndef FRACTAL_RENDERER_H
#define FRACTAL_RENDERER_H

#include <SDL2/SDL.h>
#include "fractals.h"

class FractalRenderer {
    public:
        FractalRenderer(int width, int height);
        ~FractalRenderer();

        void run();

    private:
        void handleEvents();
        void renderFrame();
        void renderSection(int startX, int endX, int startY, int endY);

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* cachedFrame;

        int winWidth;
        int winHeight;
        double zoom;
        double offsetX;
        double offsetY;
        bool running;
};

#endif