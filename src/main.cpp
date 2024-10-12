#include <stdlib.h>

#include "../include/fractal_renderer.h"

const int WIN_WIDTH = 1600;
const int WIN_HEIGHT = 900;

int main(int argc, char* argv[]) {
    FractalRenderer renderer(WIN_WIDTH, WIN_HEIGHT);
    renderer.run();

    return EXIT_SUCCESS;
}