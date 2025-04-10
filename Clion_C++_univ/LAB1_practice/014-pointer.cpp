#include "pointer.h"

void update(int* a, int* b) {
    // implement your code
    const int tmp = *a;
    *a = *a - *b;
    *b = *b - tmp;
}
