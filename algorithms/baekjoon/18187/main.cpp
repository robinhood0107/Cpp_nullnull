#include <iostream>

using namespace std;

int max_regions(int N) {
    // 기울기별 직선 수 계산 (최대한 균등하게 분배)
    int a = N / 3;                          // 기울기 -1인 직선의 수
    int b = N / 3 + (N % 3 >= 1 ? 1 : 0);   // 기울기 0인 직선의 수
    int c = N - a - b;                      // 기울기 1인 직선의 수

    // 최대 영역 수 계산 = 1 + N(직선 수) + 교점 수
    return 1 + N + a * b + a * c + b * c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;

    cout << max_regions(N);

    return 0;
}
