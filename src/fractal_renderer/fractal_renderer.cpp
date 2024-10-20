#include <functional>
#include <thread>

#include "fractal_renderer.hpp"
#include "../utils/math.hpp"

const float MIN_REAL = -2.5;
const float MAX_REAL = 2.5;
const float MIN_IMAG = -2.5;
const float MAX_IMAG = 2.5;

const float MIN_ZOOM = 0.5;

FractalRenderer::FractalRenderer(int width, int height)
    : winWidth(width), winHeight(height)
{
    if (SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Could not initialise SDL: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    window = SDL_CreateWindow("Complex Fractal Renderer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create renderer: %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    fractalMap[SDLK_1] = processMandelbrot;
    fractalMap[SDLK_2] = processTricorn;
    fractalMap[SDLK_3] = processBurningShip;
    fractalMap[SDLK_4] = processNewtonFractal;

    curFractalFuncKey = SDLK_1;
    fractalFunc = fractalMap[curFractalFuncKey];
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
    SDL_Keycode eventKey;
    int mx, my;

    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            // Quit
            running = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON(SDL_BUTTON_LEFT)) {
                // Set centre of screen at the point clicked
                SDL_GetMouseState(&mx, &my);

                complex c = screenToFractal(mx, my, winWidth, winHeight, zoom, offsetX, offsetY);

                offsetX = fmin(fmax(c.re, MIN_REAL), MAX_REAL);
                offsetY = fmin(fmax(c.im, MIN_IMAG), MAX_IMAG);
                startAsyncRendering();
            }
            break;

        case SDL_MOUSEWHEEL:
            // Update zoom level based on direction of scroll
            zoom *= (event.wheel.y > 0) ? 2.0 : 0.5;
            zoom = fmax(zoom, MIN_ZOOM);
            startAsyncRendering();
            break;

        case SDL_KEYDOWN:
            eventKey = event.key.keysym.sym;

            if (eventKey == SDLK_ESCAPE) {
                // Quit
                running = false;
                break;
            }
            else if (fractalMap.find(eventKey) != fractalMap.end()) {
                if (eventKey == curFractalFuncKey)
                    break;

                // Set the fractal function
                fractalFunc = fractalMap[eventKey];
                curFractalFuncKey = eventKey;
                startAsyncRendering();
            }
            else if (eventKey == SDLK_r) {
                if (zoom == INITIAL_ZOOM && offsetX == INITIAL_OFFSET_X && offsetY == INITIAL_OFFSET_Y)
                    break;

                // Reset zoom and offset
                zoom = INITIAL_ZOOM;
                offsetX = INITIAL_OFFSET_X;
                offsetY = INITIAL_OFFSET_Y;
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
                    complex c = screenToFractal(x, y, winWidth, winHeight, zoom, offsetX, offsetY);
                    colour col = fractalFunc(c, MAX_ITERATIONS);
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
                    complex c = screenToFractal(x, y, winWidth, winHeight, zoom, offsetX, offsetY);
                    colour col = fractalFunc(c, MAX_ITERATIONS);
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

void FractalRenderer::run() {
    pixelBuffer.resize(winWidth, std::vector<colour>(winHeight));

    startAsyncRendering();

    while (running) {
        handleEvents();

        // Wait for the rendering thread to notify that recalculation is done
        {
            std::unique_lock<std::mutex> lock(bufferMutex);
            bufferCond.wait(lock, [this]() { return !recalculating; });
        }

        renderFrame();
    }
}