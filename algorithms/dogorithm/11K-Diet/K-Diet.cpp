#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;
int mp, mf, ms, mv;
vector<vector<int>> vec;

int min_cost = 1e9;
int max_vec_sum = -1;
vector<int> best_result;

void dfs(int idx, int p, int f, int s, int v, int cost, vector<int>& result) {
    if (idx == n) {
        if (p >= mp && f >= mf && s >= ms && v >= mv) {
            int vec_sum = p + f + s + v;
            if (cost < min_cost) {
                min_cost = cost;
                max_vec_sum = vec_sum;
                best_result = result;
            } 
            else if (cost == min_cost) {
                if (vec_sum > max_vec_sum) {
                    max_vec_sum = vec_sum;
                    best_result = result;
                } 
                else if (vec_sum == max_vec_sum) {
                    if (result < best_result) {
                        best_result = result;
                    }
                }
            }
        }
        return;
    }

    //현재 재료를 선택하는 경우(push)
    result.push_back(idx + 1); // 1-based index 저장
    dfs(idx + 1, p + vec[idx][0], f + vec[idx][1], s + vec[idx][2], v + vec[idx][3], cost + vec[idx][4], result);
    result.pop_back(); //(pop)

    //현재 재료를 선택하지 않는 경우
    dfs(idx + 1, p, f, s, v, cost, result);
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    cin >> mp >> mf >> ms >> mv;

    vec.resize(n);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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

    vector<int> result;
    dfs(0, 0, 0, 0, 0, 0, result);

    if (best_result.empty()) {
        cout << 0 << "\n";
    } else {
        for (size_t i = 0; i < best_result.size(); i++) {
            cout << best_result[i] << (i == best_result.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    return 0;
}
