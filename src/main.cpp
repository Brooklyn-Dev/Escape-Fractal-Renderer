#include <stdlib.h>

#include <SDL2/SDL.h>

#include "complex.h"
#include "colour.h"
#include "fractals.h"

const int WIN_WIDTH = 1600;
const int WIN_HEIGHT = 900;
const int MAX_ITERATIONS = 100;

int main(int argc, char* argv[]) {
    // Initialise SDL Video Subsystem - Returns 0 on success
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialise SDL: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window* window = SDL_CreateWindow("Fractal Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    bool running{ true };

    while (running) {
        // Polling for SDL Events
        SDL_Event event;

        // Loop until there are no more pending events to process
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Viewing window
        long double minRe = -2.0;
        long double maxRe = 1.0;
        long double minIm = -1.0;
        long double maxIm = minIm + (maxRe - minRe) * WIN_HEIGHT / WIN_WIDTH;

        // Pixel step sizes
        long double re_factor = (maxRe - minRe) / (WIN_WIDTH - 1);
        long double im_factor = (maxIm - minIm) / (WIN_HEIGHT - 1);

        // Render each pixel in the window
        for (int y = 0; y < WIN_HEIGHT; y++) {
            long double c_im = maxIm - y * im_factor;
            for (int x = 0; x < WIN_WIDTH; x++) {
                long double c_re = minRe + x * re_factor;

                struct complex c = { c_re, c_im };
                struct colour col = processMandelbrot(c, MAX_ITERATIONS);

                SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
    }

    // Cleanup SDL components and quit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;
}