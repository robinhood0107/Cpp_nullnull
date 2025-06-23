#include <iostream>
#include <fstream>

// Implement your code

int main() {
    std::ifstream fin;
    fin.open("input.txt"); // This will not throw an exception even if file is missing

    if (!fin.is_open()) {
        std::cerr << "Error opening input.txt" << std::endl;
    }

    std::ofstream fout;
    fout.open("config/config.ini"); // Will fail silently

    if (!fout.is_open()) {
        std::cerr << "Error opening config/config.ini" << std::endl;
    } else {
        fout << "This is an example for the exception in C++!" << std::endl;
    }

    return 0;
}