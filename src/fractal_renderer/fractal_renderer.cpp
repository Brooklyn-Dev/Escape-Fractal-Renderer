#include <functional>
#include <thread>

#include "fractal_renderer.hpp"
#include "../fractals/fractals.hpp"
#include "../utils/math.hpp"

FractalRenderer::FractalRenderer(int width, int height)
    : winWidth(width), winHeight(height) 
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
}

FractalRenderer::~FractalRenderer() {
    if (renderingTask.valid())
        renderingTask.wait();

    if (cachedFrame) {
        SDL_DestroyTexture(cachedFrame);
        cachedFrame = nullptr;
    }

    if (renderer) {
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window) {
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    pixelBuffer.clear();

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

                complex c = screenToFractal(mx, my, winWidth, winHeight, targetZoom, targetOffsetX, targetOffsetY);
                targetOffsetX = fmin(fmax(c.re, -2), 2);
                targetOffsetY = fmin(fmax(c.im, -2), 2);
            }
            break;

        case SDL_MOUSEWHEEL:
            targetZoom *= (event.wheel.y > 0) ? 2.0 : 0.5;
            targetZoom = fmax(targetZoom, 1.0);
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                running = false;
            }
            else if (event.key.keysym.sym == SDLK_r) {
                currentZoom = 1.0, targetZoom = 1.0;
                currentOffsetX = 0.0, targetOffsetX = 0.0;
                currentOffsetY = 0.0, targetOffsetY = 0.0;
                startAsyncRendering();
            }
            break;

        default:
            break;
        }
    }
}

void FractalRenderer::startAsyncRendering() {
    if (recalculating) return;
    recalculating = true;

    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threads;
    int sectionWidth = winWidth / numThreads;
    int sectionHeight = winHeight / 2;

    for (int i = 0; i < numThreads; ++i) {
        int startX = i * sectionWidth;
        int endX = (i + 1) * sectionWidth;

        // Each thread calculates and renders two vertical half-height tiles
        threads.push_back(std::thread([this, startX, endX, sectionHeight]() {
            // Render top tile (first half of height)
            for (int x = startX; x < endX; x++) {
                for (int y = 0; y < sectionHeight; y++) {
                    complex c = screenToFractal(x, y, winWidth, winHeight, targetZoom, targetOffsetX, targetOffsetY);
                    colour col = processMandelbrot(c, MAX_ITERATIONS);
                    pixelBuffer[x][y] = col;
                }
            }

            // Lock and update the rendering buffer for the top tile
            {
                std::lock_guard<std::mutex> lock(bufferMutex);
                for (int x = startX; x < endX; ++x) {
                    for (int y = 0; y < sectionHeight; ++y) {
                        const colour& col = pixelBuffer[x][y];
                        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
                        SDL_RenderDrawPoint(renderer, x, y);
                    }
                }
                SDL_RenderPresent(renderer);  // Present the top tile after it is done
            }

            // Render bottom tile (second half of height)
            for (int x = startX; x < endX; x++) {
                for (int y = sectionHeight; y < winHeight; y++) {
                    complex c = screenToFractal(x, y, winWidth, winHeight, targetZoom, targetOffsetX, targetOffsetY);
                    colour col = processMandelbrot(c, MAX_ITERATIONS);
                    pixelBuffer[x][y] = col;
                }
            }

            // Lock and update the rendering buffer for the bottom tile
            {
                std::lock_guard<std::mutex> lock(bufferMutex);
                for (int x = startX; x < endX; ++x) {
                    for (int y = sectionHeight; y < winHeight; ++y) {
                        const colour& col = pixelBuffer[x][y];
                        SDL_SetRenderDrawColor(renderer, col.r, col.g, col.b, 255);
                        SDL_RenderDrawPoint(renderer, x, y);
                    }
                }
                SDL_RenderPresent(renderer);  // Present the bottom tile after it is done
            }
        }));
    }

    // Wait for all threads to finish
    for (auto& t : threads)
        t.join();

    recalculating = false;
    updateCachedFrame = true;
}

void FractalRenderer::renderFrame() {
    if (!updateCachedFrame)
        return;
        
    SDL_RenderPresent(renderer);
    updateCachedFrame = false;
}

void FractalRenderer::updateFrame(double deltaTime) {
    double t = deltaTime * 0.5;

    currentZoom = lerp(currentZoom, targetZoom, t);
    currentOffsetX = lerp(currentOffsetX, targetOffsetX, t);
    currentOffsetY = lerp(currentOffsetY, targetOffsetY, t);

    bool zoomAtTarget = std::abs(currentZoom - targetZoom) < 0.0001;
    bool offsetXAtTarget = std::abs(currentOffsetX - targetOffsetX) < 0.0001;
    bool offsetYAtTarget = std::abs(currentOffsetY - targetOffsetY) < 0.0001;

    if (!zoomAtTarget || !offsetXAtTarget || !offsetYAtTarget)
        startAsyncRendering();
}

void FractalRenderer::run() {
    Uint32 lastFrameTime = SDL_GetTicks();

    pixelBuffer.resize(winWidth, std::vector<colour>(winHeight));

    startAsyncRendering();

    while (running) {
        Uint32 currentFrameTime = SDL_GetTicks();
        double deltaTime = (currentFrameTime - lastFrameTime) / 1000.0;
        lastFrameTime = currentFrameTime;

        handleEvents();

        updateFrame(deltaTime);

        // Wait for the rendering thread to notify that recalculation is done
        {
            std::unique_lock<std::mutex> lock(bufferMutex);
            bufferCond.wait(lock, [this]() { return !recalculating; });
        }

        renderFrame();
    }
}