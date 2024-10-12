#include "../include/complex.hpp"

// Add two complex numbers
complex complexAdd(complex a, complex b) {
    return complex{ a.re + b.re, a.im + b.im };
}

// Subtract two complex numbers
complex complexSub(complex a, complex b) {
    return complex{ a.re - b.re, a.im - b.im };
}

// Multiply two complex numbers
complex complexMul(complex a, complex b) {
    return complex{ a.re * b.re - a.im * b.im, a.re * b.im + a.im * b.re };
}

// Divide two complex numbers
complex complexDiv(complex a, complex b) {
    long double denominator = b.re * b.re + b.im * b.im;
    return complex{
        (a.re * b.re + a.im * b.im) / denominator,
        (a.im * b.re - a.re * b.im) / denominator
    };
}

// Calculate the magnitude of a complex number
long double complexMag(complex a) {
    return sqrtl(a.re * a.re + a.im * a.im);
}

// Calculate the squared magnitude of a complex number
long double complexMagSq(complex a) {
    return a.re * a.re + a.im * a.im;
}