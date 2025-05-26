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

    if (!(mag1 < mag2) && !(mag2 < mag1)){
        if(this->real == other.real){
            return this->imag < other.imag;
        }
        else
            return this->real < other.real;
    }
    else
        return mag1 < mag2;
    //이거 그냥 보고 따라 치면 됨 가장 먼저 mag를 비교함(mag2==mag1 인 경우를 찾음)
    //그리고 real 파트도 마찬가지로 같은지 확인
}
//필승 법 이 아래 operator는 내가 직접 다시 작성해본다 아래는 무조건 나온다고 했음
// << 이거 먼저 작성한 다음에 다른거 작성하는 거라고 했음

std::ostream& operator<<(std::ostream& os, const Complex& c) {
    //std::ostream& operator<<(std::ostream os, const Complex& c) 이건 확실하게 외워가기
    if (c.real == 0 && c.imag == 0) {
        os << "0"; //이런식으로 os에 출력시키는 것
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




// std::ostream& operator<<(std::ostream& os, const Complex& c) {
//     if (c.real == 0 && c.imag == 0) {
//         os << "0";
//     } else if (c.imag == 0) {
//         os << c.real;
//     } else if (c.real == 0) {
//         os << c.imag << "i";
//     } else {
//         os << c.real;
//         if (c.imag > 0)
//             os << "+" << c.imag << "i";
//         else
//             os << c.imag << "i";  // c.imag already has '-' sign
//     }
//     return os;
// }
