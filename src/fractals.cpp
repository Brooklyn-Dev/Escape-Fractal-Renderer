#include "fractals.h"

colour processMandelbrot(complex c, int maxIterations) {
    struct complex z = { 0, 0 };

    for (int i = 0; i < maxIterations; i++) {
        z = complexAdd(complexMul(z, z), c);
        if (complexMagSq(z) > 4.0)
            return colourGradient(i, maxIterations);
    }

    return colour{ 0, 0, 0 };  // Return black for points in the Mandelbrot set
}
