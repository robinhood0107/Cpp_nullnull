#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

// 최대 길이는 1000이므로 넉넉하게 1005로 잡습니다.
// 전역 변수로 선언하여 0으로 자동 초기화합니다.
int dp[1005][1005]; 

// 각 열(Column)마다 행(Row) 방향의 슬라이딩 윈도우를 관리할 덱 배열
deque<int> col_dq[1005]; 

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    if (!(cin >> k)) return 0;
    string S, T;
    cin >> S >> T;

    int N = S.length();
    int M = T.length();

    // =========================================================================
    // [방법 2 적용] 2D 슬라이딩 윈도우 (Monotonic Queue) - O(N * M)
    // =========================================================================
    
    // 뒤에서부터 역방향 탐색
    for (int i = N - 1; i >= 0; i--) {
        
        // 1. 세로 방향 (행 단위) 슬라이딩 윈도우 갱신
        // 현재 행 i를 처리하기 전, i+1 행의 데이터를 각 열의 덱에 업데이트합니다.
        for (int j = 0; j < M; j++) {
            // 새로 들어올 값(dp[i+1][j])보다 작거나 같은 기존 값들은 덱에서 제거 (단조 감소 유지)
            while (!col_dq[j].empty() && dp[col_dq[j].back()][j] <= dp[i + 1][j]) {
                col_dq[j].pop_back();
            }
            col_dq[j].push_back(i + 1);
            
            // 점프 가능 범위(k+1)를 벗어난 이전 행 인덱스는 제거
            while (!col_dq[j].empty() && col_dq[j].front() > i + k + 1) {
                col_dq[j].pop_front();
            }
        }

        // 2. 가로 방향 (열 단위) 슬라이딩 윈도우를 위한 덱
        deque<int> row_dq; 
        
        for (int j = M - 1; j >= 0; j--) {
            // j+1 열이 탐색 범위 내에 있다면 가로 덱에 추가
            if (j + 1 < M) {
                int c_idx = j + 1;
                // 해당 열(c_idx)의 세로 윈도우 최댓값
                int val_to_add = dp[col_dq[c_idx].front()][c_idx]; 
                
                // 단조 감소 큐 유지
                while (!row_dq.empty()) {
                    int back_idx = row_dq.back();
                    int back_val = dp[col_dq[back_idx].front()][back_idx];
                    if (back_val <= val_to_add) {
                        row_dq.pop_back();
                    } else {
                        break;
                    }
                }
                row_dq.push_back(c_idx);
            }

            // 가로 점프 가능 범위(j + k + 1)를 벗어난 열 인덱스는 제거
            while (!row_dq.empty() && row_dq.front() > j + k + 1) {
                row_dq.pop_front();
            }

            // DP 테이블 채우기
            if (S[i] == T[j]) {
                int max_next_len = 0;
                if (!row_dq.empty()) {
                    int best_c = row_dq.front(); // 가로 범위 내 최댓값을 가진 열 인덱스
                    max_next_len = dp[col_dq[best_c].front()][best_c]; // 그 열의 세로 최댓값
                }
                dp[i][j] = 1 + max_next_len;
            } else {
                dp[i][j] = 0;
            }
        }
    }

    // =========================================================================
    // [방법 3 적용] BFS 추적 & STL erase-unique 중복 제거 방어
    // =========================================================================
    
    // 1. 전체 DP 테이블에서 최장 길이(MAX_L) 찾기
    int max_len = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j] > max_len) {
                max_len = dp[i][j];
            }
        }
    }

    // 2. 시작 후보군 중 사전식으로 가장 빠른 문자 찾기
    char min_start_char = 127; // 아스키코드 한계값으로 초기화
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j] == max_len) {
                if (S[i] < min_start_char) {
                    min_start_char = S[i];
                }
            }
        }
    }

    // 최적의 시작 좌표들만 후보군(candidates)에 담기
    vector<pair<int, int>> candidates;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[i][j] == max_len && S[i] == min_start_char) {
                candidates.push_back({i, j});
            }
        }
    }

    // 3. 남은 문자열 추적
    string ans = "";
    int current_len = max_len;

    while (current_len > 0) {
        // 현재 후보군에 있는 위치의 문자는 모두 동일하므로 하나만 뽑아서 정답에 추가
        ans += S[candidates[0].first];
        current_len--;
        
        if (current_len == 0) break;

        vector<pair<int, int>> next_candidates;
        char min_next_char = 127;

        // 추적 시에는 유효한 좌표들에서만 탐색하므로 4중 루프의 연산량이 극히 적음
        for (auto p : candidates) {
            int r = p.first;
            int c = p.second;
            
            int max_dr = min(k + 1, N - r - 1);
            int max_dc = min(k + 1, M - c - 1);

            for (int dr = 1; dr <= max_dr; dr++) {
                for (int dc = 1; dc <= max_dc; dc++) {
                    int nr = r + dr;
                    int nc = c + dc;

                    // 다음 길이가 성립하는 경우
                    if (dp[nr][nc] == current_len) {
                        if (S[nr] < min_next_char) {
                            min_next_char = S[nr];
                            next_candidates.clear();
                            next_candidates.push_back({nr, nc});
                        } else if (S[nr] == min_next_char) {
                            next_candidates.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        // 핵심 최적화: std::set 대신 vector + sort + unique로 중복 좌표 날리기
        sort(next_candidates.begin(), next_candidates.end());
        next_candidates.erase(
            unique(next_candidates.begin(), next_candidates.end()), 
            next_candidates.end()
        );

        candidates = next_candidates;
    }

    // 결과 출력
    cout << ans << "\n";

    return 0;
}