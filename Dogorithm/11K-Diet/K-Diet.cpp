#include <bits/stdc++.h>

using namespace std;

int n;
int mp, mf, ms, mv;
    //vector<int> limit; //이거로 교체한다.
vector<vector<int>> vec;

// 정답을 기록할 전역 변수
int min_cost = 1e9;
int max_nutrient_sum = -1;
vector<int> best_chosen;

// DFS 백트래킹 함수 (Call Stack 활용)
void dfs(int idx, int p, int f, int s, int v, int cost, vector<int>& chosen) {
    // 모든 재료를 다 탐색한 경우 (Base condition)
    if (idx == n) {
        // 4가지 영양소가 모두 최소 권장량 이상인지 확인
        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            int nutrient_sum = p + f + s + v;
            
            // 1. 최소 비용 갱신
            if (cost < min_cost) {
                min_cost = cost;
                max_nutrient_sum = nutrient_sum;
                best_chosen = chosen;
            } 
            // 2. 비용이 같다면 영양분 총합이 더 큰 조합 선택
            else if (cost == min_cost) {
                if (nutrient_sum > max_nutrient_sum) {
                    max_nutrient_sum = nutrient_sum;
                    best_chosen = chosen;
                } 
                // 3. 영양분 총합도 같다면 사전식 순서가 빠른 것 선택
                // C++의 vector '<' 연산자는 자동으로 사전식(Lexicographical) 비교를 수행함
                else if (nutrient_sum == max_nutrient_sum) {
                    if (chosen < best_chosen) {
                        best_chosen = chosen;
                    }
                }
            }
        }
        return;
    }

    // [분기 1] 현재 재료를 선택하는 경우 (Stack에 push하는 개념)
    chosen.push_back(idx + 1); // 1-based index 저장
    dfs(idx + 1, p + vec[idx][0], f + vec[idx][1], s + vec[idx][2], v + vec[idx][3], cost + vec[idx][4], chosen);
    chosen.pop_back(); // 탐색 후 원래 상태로 복구 (Stack에서 pop)

    // [분기 2] 현재 재료를 선택하지 않는 경우
    dfs(idx + 1, p, f, s, v, cost, chosen);
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n=0;
    cin >> n;

    cin >> mp >> mf >> ms >> mv;

    cin.ignore();

    for(int i=0; i<n; i++){
        string line;
        getline(cin, line);

        stringstream ss(line);
        int tempnum;

        while(ss >> tempnum){
            vec[i].push_back(tempnum);
        }
    }

    //입력 확인용
    // cout << "\n";
    // for(auto lt : vec){
    //     for(auto at : lt){
    //         cout << at << " ";
    //     }
    //     cout << "\n";
    // }

    

}


vec.resize(n, vector<int>(5));
    for(int i = 0; i < n; i++){
        cin >> vec[i][0] >> vec[i][1] >> vec[i][2] >> vec[i][3] >> vec[i][4];
    }

    vector<int> chosen;
    
    // 백트래킹 탐색 시작 (인덱스 0부터)
    dfs(0, 0, 0, 0, 0, 0, chosen);

    // 정답 출력
    if (best_chosen.empty()) {
        // 조건을 만족하는 조합이 없는 경우
        cout << 0 << "\n";
    } else {
        // 오름차순으로 인덱스 출력
        for (int i = 0; i < best_chosen.size(); i++) {
            cout << best_chosen[i] << (i == best_chosen.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}