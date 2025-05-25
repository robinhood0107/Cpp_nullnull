#include "Complex.hpp"
#include <cmath>

Complex::Complex(double real, double imag) : real(real), imag(imag) {}

Complex Complex::operator+(const Complex& other) const {
    return Complex(this->real + other.real, this->imag + other.imag);
}

Complex Complex::operator-(const Complex& other) const {
    return Complex(this->real - other.real, this->imag - other.imag);
}

bool Complex::operator<(const Complex& other) const {
    double mag1 = std::sqrt(this->real * this->real + this->imag * this->imag);
    double mag2 = std::sqrt(other.real * other.real + other.imag * other.imag);
    return mag1 < mag2;
}

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    if (c.real == 0 && c.imag == 0) {
        os << "0";
    } else if (c.imag == 0) {
        os << c.real;
    } else if (c.real == 0) {
        os << c.imag << "i";
    } else {
        os << c.real;
        if (c.imag > 0)
            os << "+" << c.imag << "i";
        else
            os << c.imag << "i";  // c.imag already has '-' sign
    }
    return os;
}
