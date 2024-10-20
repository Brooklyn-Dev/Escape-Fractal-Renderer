#include "complex.hpp"

// Add two complex numbers
complex complex::operator+(const complex& w) const {
    return complex{ re + w.re, im + w.im };
}

// Subtract two complex numbers
complex complex::operator-(const complex& w) const {
    return complex{ re - w.re, im - w.im };
}

// Multiply two complex numbers
complex complex::operator*(const complex& w) const {
    return complex{ re * w.re - im * w.im, re * w.im + im * w.re };
}

// Divide two complex numbers
complex complex::operator/(const complex& w) const {
    long double denominator = w.re * w.re + w.im * w.im;
    return complex{
        (re * w.re + im * w.im) / denominator,
        (im * w.re - re * w.im) / denominator
    };
}

// Add a scalar to a complex number
complex complex::operator+(long double scalar) const {
    return complex{ re + scalar, im };
}

// Subtract a scalar from a complex number
complex complex::operator-(long double scalar) const {
    return complex{ re - scalar, im };
}

// Multiply a complex number by a scalar
complex complex::operator*(long double scalar) const {
    return complex{ re * scalar, im * scalar };
}

// Divide a complex number by a scalar
complex complex::operator/(long double scalar) const {
    return complex{ re / scalar, im / scalar };
}

// Get the complex conjugate
complex complexConj(const complex& z) {
    return complex{ z.re, -z.im };
}

// Calculate the magnitude of a complex number
long double complexMag(const complex& z) {
    return sqrtl(z.re * z.re + z.im * z.im);
}

// Calculate the squared magnitude of a complex number
long double complexMagSq(const complex& z) {
    return z.re * z.re + z.im * z.im;
}