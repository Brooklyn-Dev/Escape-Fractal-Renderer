#ifndef COLOUR_H
#define COLOUR_H

typedef struct colour {
    int r;
    int g;
    int b;
};

colour colourLerp(colour a, colour b, float t);
colour colourGradient(int iteration, int maxIterations);

const colour BLACK = colour{ 0, 0, 0 };

#endif