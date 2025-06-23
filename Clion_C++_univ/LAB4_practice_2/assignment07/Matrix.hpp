#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <initializer_list>

class Matrix {
private:
    int* data;
    size_t row;
    size_t col;

public:
    // Implement your code

    [[nodiscard]] Matrix inverse() const;
};

#endif // MATRIX_H