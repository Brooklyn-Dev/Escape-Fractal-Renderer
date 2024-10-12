#ifndef FRACTAL_RENDERER_H
#define FRACTAL_RENDERER_H

#include <vector>

#include <SDL2/SDL.h>

#include "fractals.hpp"

class FractalRenderer {
    public:
        FractalRenderer(int width, int height);
        ~FractalRenderer();

        void run();

    private:
        void handleEvents();
        void drawPixels(std::vector<std::vector<colour>> pixelBuffer);
        void startRendering();
        void renderFrame();

        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* cachedFrame;

        int winWidth;
        int winHeight;
        double zoom;
        double offsetX;
        double offsetY;
        bool recalculate;
        bool running;
};

#endif