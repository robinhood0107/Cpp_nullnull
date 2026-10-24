#include <iostream>

void update(int* a, int* b) {
    // implement your code
    const int tmp = *a;
    *a = *a - *b;
    *b = *b - tmp;
}

int main() {
    int a, b;
    if (!(std::cin >> a >> b)) return 0;
    update(&a, &b);
    std::cout << a << " " << b << "\n";
}
