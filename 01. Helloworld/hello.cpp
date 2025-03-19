#include <iostream>
using namespace std;


void my_swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}


int main() {

    int m, n;

    std::cin >> m >> n;

    my_swap(m, n);

    std::cout << m << " " << n;

}