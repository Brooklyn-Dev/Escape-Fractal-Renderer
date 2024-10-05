#ifndef COLOUR_H
#define COLOUR_H

typedef struct colour {
    int r; // Red
    int g; // Green
    int b; // Blue
};

colour colourLerp(colour a, colour b, float t);
colour colourGradient(int iteration, int maxIterations) ;

#endif