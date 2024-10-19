#ifndef FRACTAL_RENDERER_H
#define FRACTAL_RENDERER_H

#include <atomic>
#include <future>
#include <mutex>
#include <vector>

#include <SDL2/SDL.h>

#include "../fractals/fractals.hpp"

class FractalRenderer {
    public:
        FractalRenderer(int width, int height);
        ~FractalRenderer();

        void run();

    private:
        void handleEvents();
        void startAsyncRendering();
        void updateFrame(double deltatime);
        void renderFrame();

        int winWidth;
        int winHeight;

        SDL_Window* window = nullptr;
        SDL_Renderer* renderer = nullptr;
        SDL_Texture* cachedFrame = nullptr;

        double currentZoom = 1.0;
        double targetZoom = 1.0;

        double currentOffsetX = 0.0;
        double targetOffsetX = 0.0;

        double currentOffsetY = 0.0;
        double targetOffsetY = 0.0;

        bool running = true;
        bool recalculating = false;
        bool updateCachedFrame = false;

        std::future<void> renderingTask;
        std::atomic<int> completedThreads;
        std::vector<std::vector<colour>> pixelBuffer;
        std::mutex bufferMutex;
        std::condition_variable bufferCond;
};

#endif