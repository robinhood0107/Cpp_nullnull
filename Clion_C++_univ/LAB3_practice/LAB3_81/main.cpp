#include <iostream>
#include <map>
#include "Complex.hpp"

int main() {
    Complex c1(3, 2);
    Complex c2(1, -1);
    Complex c3 = c1 + c2;
    Complex c4 = c1 - c2;

    std::cout << "c1 = " << c1 << std::endl;
    std::cout << "c2 = " << c2 << std::endl;
    std::cout << "c1 + c2 = " << c3 << std::endl;
    std::cout << "c1 - c2 = " << c4 << std::endl;

    if (c1 < c2)
        std::cout << "c1 is less than c2 (in magnitude)" << std::endl;
    else
        std::cout << "c1 is not less than c2 (in magnitude)" << std::endl;

    Complex c5(0, 4);
    Complex c6(5, 0);
    Complex c7(0, 0);

    std::cout << "c5 = " << c5 << std::endl;
    std::cout << "c6 = " << c6 << std::endl;
    std::cout << "c7 = " << c7 << std::endl;

    std::map<Complex, std::string> complexMap;

    Complex c11(1, 1);
    Complex c22(2, 0);
    Complex c33(0, 2);
    Complex c44(3, 4);
    Complex c55(1, 1);

    complexMap[c11] = "one plus i";
    complexMap[c22] = "two";
    complexMap[c33] = "two i";
    complexMap[c44] = "three plus four i";
    complexMap[c55] = "duplicate key - should overwrite c1";

    std::cout << "\n--- Map Contents (sorted by magnitude) ---" << std::endl;
    for (const auto& entry : complexMap) {
        std::cout << entry.first << " : " << entry.second << std::endl;
    }
    
    return 0;
}
