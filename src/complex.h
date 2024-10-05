#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

typedef struct complex {
    long double re;  // Real part
    long double im;  // Imaginary part
};

struct complex complexAdd(struct complex a, struct complex b);
struct complex complexSub(struct complex a, struct complex b);
struct complex complexMul(struct complex a, struct complex b);
struct complex complexDiv(struct complex a, struct complex b);
long double complexMag(struct complex a);
long double complexMagSq(struct complex a);

#endif