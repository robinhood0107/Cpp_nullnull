#ifndef COMPLEX_COMPLEX_H
#define COMPLEX_COMPLEX_H

#include <iostream>
#include <algorithm>

class complex {
public:
    // Implement your code
    complex() = default; //Default 생성자로 r{0} i{0} 아래에 선언되 있음
    
    complex(double real) : r{real}{}; //생성자 생성할때 반드시 초기화 //Default 생성자로 r{0} i{0} 아래에 선언되 있음
    
    complex(double real, double imag) : r{real}, i{imag}{};
   

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