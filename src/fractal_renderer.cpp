#include "../include/fractal_renderer.h"
#include "../include/fractals.h"

FractalRenderer::FractalRenderer(int width, int height) :
    winWidth(width), winHeight(height), zoom(1.0), offsetX(0.0), offsetY(0.0), running(true)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialise SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Fractal Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    cachedFrame = nullptr;
}

FractalRenderer::~FractalRenderer() {
    if (cachedFrame)
        SDL_DestroyTexture(cachedFrame);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void FractalRenderer::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_MOUSEWHEEL:
                zoom *= (event.wheel.y > 0) ? 1.25 : 0.75;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                else if (event.key.keysym.sym == SDLK_r) {
                    zoom = 1.0;
                    offsetX = 0.0;
                    offsetY = 0.0;
                }
                break;

            default:
                break;
        }
    }
}

void FractalRenderer::renderFrame() {
    if (!cachedFrame) {
        cachedFrame = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, winWidth, winHeight);
        SDL_SetRenderTarget(renderer, cachedFrame);
        renderSection(0, winWidth, 0, winHeight);
        SDL_SetRenderTarget(renderer, nullptr);
    }

    SDL_RenderCopy(renderer, cachedFrame, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void FractalRenderer::renderSection(int startX, int endX, int startY, int endY) {
    for (int x = startX; x < endX; x++) {
        for (int y = startY; y < endY; y++) {
            complex c = screenToFractal(x, y, winWidth, winHeight, zoom, offsetX, offsetY);
            colour colour = processMandelbrot(c, MAX_ITERATIONS);

            SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

void FractalRenderer::run() {
    while (running) {
        handleEvents();
        renderFrame();
    }
}