#include <iostream>
#include "Array.hpp"
#include <stdexcept>

// Implement your code

int main() {
    Array<int> arr(5);
    try {
        arr.at(0) = 1;
        arr.at(1) = 2;
        arr.at(2) = 3;
        arr.at(3) = 4;
        arr.at(4) = 5;
        arr.at(5) = 6;
    }catch (const std::exception &e) { //rvalue 받을때는 항상 참조자로 받으세요!!!!! (주소가 없잖아!!!)
        std::cout << e.what() << std::endl;
    }
    return 0;
}