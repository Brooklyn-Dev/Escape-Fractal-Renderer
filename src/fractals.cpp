#include "../include/fractals.hpp"

complex screenToFractal(int px, int py, int width, int height, double zoom, double offsetX, double offsetY) {
    double minLength = fmin(width, height);
    return complex {
        (px - width / 2.0) / (0.5 * zoom * minLength) + offsetX,
        (py - height / 2.0) / (0.5 * zoom * minLength) + offsetY
    };
}

colour processMandelbrot(complex c, int maxIterations) {
    complex z = { 0, 0 };

    for (int i = 0; i < maxIterations; i++) {
        z = complexAdd(complexMul(z, z), c);
        if (complexMagSq(z) > 4.0)
            return colourGradient(i, maxIterations);
    }

    return colour{ 0, 0, 0 };  // Return black for points in the Mandelbrot set
}
