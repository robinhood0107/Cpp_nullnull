#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>

class complex {
public:
    // Implement your code
    complex() = default; //private에 이미 값이 초기화 되어 있으면 그냥 이렇게 default로 한방에 디폴트 생성자 생성 가능

    complex(double real) : r{real}{}; //real만 r에 넣어줌

    complex(double real, double imag) : r{real}, i{imag}{}; //2개 들어올 경우 둘다 초기화 해줌

    complex add(const complex& c) const {
        return {r + c.r, i + c.i};
    }

    friend std::ostream& operator<<(std::ostream& os, const complex& c);

private:
    double r{0}, i{0};
};

std::ostream& operator<<(std::ostream& os, const complex& c) {
    os << c.r << " + " << c.i << "i";
    return os;
}

#endif // COMPLEX_COMPLEX_H
