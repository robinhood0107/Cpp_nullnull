#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<vector<int>> vec1;
    vector<vector<int>> vec2;

    int N(0);
    int M(0);

    cin >> N >> M;

    vec1.resize(N, vector<int>(M, 0));
    vec2.resize(N, vector<int>(M, 0));

    //참고 및 팁 백터 2차원배열 빠르게 선언할때는 이렇게 사용한다고 숙지하고 바로 써먹을 수 있어야 함
    /*
    vector<vector<int>> vec1;
    int N = 0;
    vec1.resize(N, vector<int>(M, 0));
    */

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp = 0;
            cin >> tmp;
            vec1[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int tmp = 0;
            cin >> tmp;
            vec2[i][j] = tmp;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << vec1[i][j] + vec2[i][j] << " ";
        }
        cout << "\n";
    }

}
