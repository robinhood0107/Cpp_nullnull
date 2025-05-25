#include <iostream>
#include "Range.hpp"

int main() {
    std::cout << "range(5): ";
    for (long long i : Range(5)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(2, 8): ";
    for (long long i : Range(2, 8)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(1, 10, 2): ";
    for (long long i : Range(1, 10, 2)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(10, 0, -1): ";
    for (long long i : Range(10, 0, -1)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(10, 0, -3): ";
    for (long long i : Range(10, 0, -3)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(5, 5): ";
    for (long long i : Range(5, 5)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(10, 0, 1): ";
    for (long long i : Range(10, 0, 1)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

     std::cout << "range(0, 10, -1): ";
    for (long long i : Range(0, 10, -1)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "range(1, 10, 0): ";
    for (long long i : Range(1, 10, 0)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}