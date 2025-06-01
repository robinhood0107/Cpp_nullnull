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
    // 이렇게 이름만 선언하기
    Matrix() : data(nullptr), row(0), col(0) {}//생성자 소멸자는 헤더파일에서
    Matrix(size_t r, size_t c);
    Matrix(std::initializer_list<std::initializer_list<int>> lst);
    Matrix(const Matrix&);
    Matrix& operator=(const Matrix&);
    ~Matrix() { //생성자 소멸자는 헤더파일에서
        if (data) delete[] data;
    }
    Matrix operator+(const Matrix& m);
    Matrix operator-(const Matrix& m);
    Matrix operator*(const Matrix& m);
    bool operator==(const Matrix& m);
    bool operator!=(const Matrix& m);
    [[nodiscard]] Matrix inverse() const;
    friend std::ostream& operator<<(std::ostream& ss, const Matrix& m); //friend
};

#endif // MATRIX_H