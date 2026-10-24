#include <iostream>
#include "Matrix.hpp"

using namespace std;

void print_matrix(const string& name, const Matrix& m) {
    cout << name << endl;
    cout << m;
}

int main() {
    // ======= 2x2 Matrix Tests =======
    cout << "===== 2x2 Matrix Tests =====" << endl;
    Matrix m2a = {{4, 1},
                  {-7, -3}};
    Matrix m2b = {{1, 1},
                  {0, 0}};

    Matrix m2c = m2a + m2b;
    print_matrix("m2a", m2a);
    print_matrix("m2b", m2b);
    print_matrix("m2c = m2a + m2b", m2c);
    print_matrix("m2c.inverse", m2c.inverse());

    // ======= 3x3 Matrix Tests =======
    cout << "\n===== 3x3 Matrix Tests =====" << endl;
    Matrix m3a = {{2, 3, 0},
                  {1, -2, -1},
                  {2, 0, -1}};
    Matrix m3b = {{-1, -1, 3},
                  {-1, 2, 5},
                  {3, 6, 1}};

    Matrix m3c = m3a + m3b;
    print_matrix("m3a", m3a);
    print_matrix("m3b", m3b);
    print_matrix("m3c = m3a + m3b", m3c);
    print_matrix("m3c.inverse", m3c.inverse());

    // Combine inverses
    Matrix inv_m3a = m3a.inverse();
    Matrix m3d = inv_m3a + Matrix({{0, 0, 0}, {0, 0, 0}, {0, 0, 1}});
    print_matrix("m3d = m3a.inverse + [[0,0,0],[0,0,0],[0,0,1]]", m3d);

    // ======= Additional Operator Tests =======
    cout << "\n===== Additional Operator Tests =====" << endl;

    Matrix a = {{1, 2}, {3, 4}};
    Matrix b = {{5, 6}, {7, 8}};
    Matrix c = a * b;
    Matrix d = a - Matrix({{1, 1}, {1, 1}});
    bool isEqual = (a == a);
    bool isNotEqual = (a != d);

    print_matrix("a", a);
    print_matrix("b", b);
    print_matrix("a * b", c);
    print_matrix("a - [[1,1],[1,1]]", d);

    cout << "a == a: " << std::boolalpha << isEqual << endl;
    cout << "a != d: " << std::boolalpha << isNotEqual << endl;

    return 0;
}
