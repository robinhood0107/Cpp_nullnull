#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dp[1000][1000];
//스택 메모리 문제 때문에 전역변수로 잡음

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie();

    //직접 테이블도 그리긴 그려봤는데
    //DP를 거꾸로 간다는 사실이 좋다는 것을 알게 됨(검색 및 찾아봄)
    //앞에서부터 찾으면 서로 같을 경우에는 사전식으로 비교하기 어렵기 때문에 문장 끝에서 앞으로 dp를 해서 찾는 방식이 맞음
    int k;
    if (!(cin >> k)) return 0;
    string str1, str2; 
    cin >> str1 >> str2;
    int n = str1.length();
    int m = str2.length();
    int max_len = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (str1[i] == str2[j]) {
                int next_len = 0; 
                for (int r = i + 1; r <= min(i+k+1,n-1); r++) {
                    for (int c = j + 1; c <= min(j+k+1,m-1); c++) {
                        if (dp[r][c] > next_len) next_len = dp[r][c];}
                }
                dp[i][j] = next_len + 1;
                if (dp[i][j] > max_len) max_len = dp[i][j];
            }
        }
    }


    //가장 긴거 가진 시작좌표 찾기
    char min_ch = 'z'+1; 
    vector<pair<int, int>> q; //탐색 시작좌표 배열
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i][j] == max_len && str1[i] <= min_ch) {
                if (str1[i] < min_ch) { 
                    min_ch = str1[i]; 
                    q.clear();    
                }
                q.push_back({i, j});
            }
        }
    }

    //BFS로 백트래킹한다
    string result = ""; 
    
    while (max_len > 0) {
        result += str1[q[0].first];
        
        max_len--; //글자 하나 찾았으니까 1줄만 찾으면 됨
        if (max_len == 0) break; //남은길이 0이면 종료

        vector<pair<int, int>> vec; 
        char nextchar = 'z'+1;  //일종의 char용 무한? 정도로 생각      

        for (const auto& p : q) {
            int r = p.first, c = p.second;
            for (int nr = r + 1; nr <= min(r+k+1,n-1); nr++) {
                for (int nc = c + 1; nc <= min(c+k+1,m-1); nc++) {
                    if (dp[nr][nc] == max_len && str1[nr] <= nextchar) {
                        if (str1[nr] < nextchar) { 
                            nextchar = str1[nr]; 
                            vec.clear();}
                        vec.push_back({nr, nc});
                    }
                }
            }
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        q.swap(vec); }
    cout << result;
    return 0;
}