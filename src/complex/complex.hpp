#ifndef COMPLEX_H
#define COMPLEX_H

#include <math.h>

typedef struct complex {
    long double re;
    long double im;
};

complex complexAdd(complex a, complex b);
complex complexSub(complex a, complex b);
complex complexMul(complex a, complex b);
complex complexDiv(complex a, complex b);

long double complexMag(complex a);
long double complexMagSq(complex a);

#endif