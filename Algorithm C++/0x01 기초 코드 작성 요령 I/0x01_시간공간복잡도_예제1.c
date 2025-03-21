#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int swap(int* x, int* y) {
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
    return 0;
}

int main() {
    int a, b, c = 0;
    scanf("%d %d %d", &a, &b, &c);

    int tmp;
    int arr[3] = { a, b, c };
    for (int j = 0; j < 2; j++) {
        for (int i = j + 1; i < 3; i++) {
            if (arr[j] > arr[i])
                swap(&arr[j], &arr[i]);
        }
    }
    printf("%d %d %d", arr[0], arr[1], arr[2]);

}