#include <functional>
#include <thread>

#include "../include/fractal_renderer.hpp"
#include "../include/fractals.hpp"

FractalRenderer::FractalRenderer(int width, int height) :
    winWidth(width), winHeight(height), zoom(1.0), offsetX(0.0), offsetY(0.0), recalculate(false), running(true)
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
    int mx, my;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON(SDL_BUTTON_LEFT)) {
                    SDL_GetMouseState(&mx, &my);

                    complex c = screenToFractal(mx, my, winWidth, winHeight, zoom, offsetX, offsetY);
                    offsetX = c.re;
                    offsetY = c.im;

                    recalculate = true;
                }
                break;

            case SDL_MOUSEWHEEL:
                zoom *= (event.wheel.y > 0) ? 2.0 : 0.5;
                recalculate = true;
                break;

            case SDL_KEYDOWN:
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    running = false;
                }
                else if (event.key.keysym.sym == SDLK_r) {
                    zoom = 1.0;
                    offsetX = 0.0;
                    offsetY = 0.0;
                    recalculate = true;
                }
                break;

            default:
                break;
        }
    }
}

void FractalRenderer::drawPixels(std::vector<std::vector<colour>> pixelBuffer) {
    for (int x = 0; x < winWidth; x++) {
        for (int y = 0; y < winHeight; y++) {
            colour col = pixelBuffer[x][y];

            SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
}

void FractalRenderer::startRendering() {
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;

    int sectionWidth = winWidth / numThreads;

    // Buffer to store the computed pixels (shared by threads)
    std::vector<std::vector<colour>> pixelBuffer(winWidth, std::vector<colour>(winHeight));

    for (int i = 0; i < numThreads; ++i) {
        int startX = i * sectionWidth;
        int endX = (i + 1) * sectionWidth;

        // Each thread calculates a section
        threads.push_back(std::thread([this, startX, endX, &pixelBuffer]() {
            for (int x = startX; x < endX; x++) {
                for (int y = 0; y < winHeight; y++) {
                    complex c = screenToFractal(x, y, winWidth, winHeight, zoom, offsetX, offsetY);
                     pixelBuffer[x][y] = processMandelbrot(c, MAX_ITERATIONS);
                }
            }
        }));
    }

    // Join threads (wait for all threads to finish)
    for (auto& t : threads) {
        t.join();
    }

    // Render the buffer (in the main thread)
    drawPixels(pixelBuffer);
}

void FractalRenderer::renderFrame() {
    if (recalculate || !cachedFrame) {
        if (cachedFrame)
            SDL_DestroyTexture(cachedFrame);

        cachedFrame = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, winWidth, winHeight);
        SDL_SetRenderTarget(renderer, cachedFrame);
        startRendering();
        SDL_SetRenderTarget(renderer, nullptr);

        recalculate = false;
    }

    // Draw cached frame
    SDL_RenderCopy(renderer, cachedFrame, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

void FractalRenderer::run() {
    while (running) {
        handleEvents();
        renderFrame();
    }
}