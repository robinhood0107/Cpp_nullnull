#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>
#include <set>

//여기에서 배운 단절점(breakpoint)아이디어 꼭 제대로 외워두기

using namespace std;
void swapvector(int a, int b, vector<int>& vec);
int myreverse(int headidx, int tailidx, vector<int>& vec);

bool is_sorted(const vector<int>& A) {
    for (int i = 1; i < A.size(); i++) {
        if (A[i] - A[i-1] != 1) return false;
    }
    return true;
}

vector<pair<int, int>> get_candidates(const vector<int>& A, const vector<int>& P, const vector<int>& pos, int N) {
    set<pair<int, int>> cand_set;
    for (int idx : P) {
        // Case 1: idx를 시작점(L)으로
        int target1 = -(A[idx-1] + 1);
        if (target1 >= -(N+1) && target1 <= (N+1)) {
            int R = pos[target1 + N + 1];
            if (R >= idx && R <= N) cand_set.insert({idx, R});
        }
        // Case 2: idx를 끝점 다음(R+1)으로
        int target2 = -(A[idx] - 1);
        if (target2 >= -(N+1) && target2 <= (N+1)) {
            int L = pos[target2 + N + 1];
            if (L >= 1 && L <= idx - 1) cand_set.insert({L, idx - 1});
        }
    }
    return vector<pair<int, int>>(cand_set.begin(), cand_set.end());
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 0;
    cin >> t;

    cin.ignore();

    vector<vector<int>> vec1(5);

    for (int i = 0; i < 5; i++) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        int token = 0;
        while (ss >> token) {
            vec1[i].push_back(token);
        }
    }

    vector<int> result(5);

    for (int i = 0; i < 5; i++) {
        int N = vec1[i].size();
        
        //가상 패딩 추가 (양 끝 단절점 파악을 위해 0과 N+1 삽입)
        //배열 양 끝부분이 뒤집히는 경우를 감지하려면, 맨 앞에 0, 맨 뒤에 N+1을 가상으로 붙여주고 비교해야 양 끝점의 단절점을 놓치지 않음.
        vector<int> A(N + 2);
        A[0] = 0;
        A[N + 1] = N + 1;
        for (int j = 0; j < N; j++) {
            A[j + 1] = vec1[i][j];
        }

        if (is_sorted(A)) {
            result[i] = 0; // 이미 정렬된 경우
            continue;
        }

        // 2. 단절점(Breakpoint) 파악
        // 주의: 매 반복마다 새로 선언해야 정보가 안 섞입니다!
        vector<int> breakpointidx; 
        for (int j = 1; j <= N + 1; j++) {
            if (A[j] - A[j - 1] != 1) {
                breakpointidx.push_back(j);
            }
        }

        int breakpoint = breakpointidx.size();

        // 3. O(N) 처리를 위한 위치(pos) 배열 세팅
        //pos 배열을 이용해 '정확한 짝(target)'을 찾는 방식을 넣어야 완벽한 O(N)
        vector<int> pos(2 * N + 3, 0);
        for (int j = 0; j <= N + 1; j++) {
            pos[A[j] + N + 1] = j;
        }

        // --- 본격적인 조건 분기 ---
        if (breakpoint > 4) {
            result[i] = 3;
        } 
        else {
            // 단절점이 4개 이하라면 후보를 뽑아봄 (최대 8개)
            vector<pair<int, int>> candidates = get_candidates(A, breakpointidx, pos, N);
            bool found = false;

            // [1번 뒤집기 테스트]
            for (auto cand : candidates) {
                myreverse(cand.first, cand.second, A);
                if (is_sorted(A)) {
                    result[i] = 1;
                    found = true;
                    break;
                }
                myreverse(cand.first, cand.second, A); // 원상복구
            }

            // [2번 뒤집기 테스트] - 1번으로 안 끝났을 때만 실행
            if (!found && breakpoint <= 4) {
                for (auto cand1 : candidates) {
                    myreverse(cand1.first, cand1.second, A);
                    
                    // 첫 번째 뒤집기 후 새 단절점 계산
                    vector<int> new_P;
                    for (int j = 1; j <= N + 1; j++) {
                        if (A[j] - A[j - 1] != 1) new_P.push_back(j);
                    }
                    
                    // 새 위치 배열 세팅
                    vector<int> new_pos(2 * N + 3, 0);
                    for (int j = 0; j <= N + 1; j++) new_pos[A[j] + N + 1] = j;

                    if (new_P.size() <= 4) {
                        vector<pair<int, int>> candidates2 = get_candidates(A, new_P, new_pos, N);
                        for (auto cand2 : candidates2) {
                            myreverse(cand2.first, cand2.second, A);
                            if (is_sorted(A)) {
                                result[i] = 2;
                                found = true;
                                break;
                            }
                            myreverse(cand2.first, cand2.second, A); // 두 번째 원상복구
                        }
                    }
                    myreverse(cand1.first, cand1.second, A); // 첫 번째 원상복구
                    if(found) break;
                }
                if (!found) result[i] = 3;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if(result[i] == 1){
            cout << "one" << "\n";
        }
        else if(result[i] == 2){
            cout << "two" << "\n";
        }
        else{
            cout << "over" << "\n";
        }
    }

    //배열 잘 정렬되었는지 확인하는 출력코드
    // for (int i = 0; i < 5; i++) {
    //     for (int j = 0; j < vec1[i].size(); j++) {
    //         cout << vec1[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }

    return 0;
}

void swapvector(int a, int b, vector<int>& vec){
    int temp = vec[a];
    vec[a] = -vec[b];
    vec[b] = -temp;
}

int myreverse(int headidx, int tailidx, vector<int>& vec){
    if (headidx < 0 || tailidx >= vec.size() || headidx > tailidx) {
        return 0; 
    }

    //headidx와 tailidx에서 시작해서 하나하나 서로 만날때까지 좁혀들어오는
    //Two 포인터 방식을 사용하는게 더 효율적이고 안전함

    int left = headidx;
    int right = tailidx;

    while (left < right) {
        swapvector(left, right, vec);
        left++;
        right--;
    }
    
    // 만약 홀수 개라서 가운데 하나가 남는 경우, 그 값도 부호를 바꿔야 한다면:
    // 이거도 잊지말고 부호 바꿔야 하니까
    if (left == right) {
        vec[left] = -vec[left];
    }

    return 1;

    //맨처음 내가 시도한 방식

    // if((tailidx-headidx)%2==0){//head부터 tail까지 홀수개
    //     int gap = (tailidx-headidx)/2;
    //     int mididx = headidx+gap;
    //     for(int i=1; i<=gap; i++){
    //         swapvector(mididx+i,mididx-i,vec);
    //     }
    //     return 1;
    // }
    // else{
    //     int gap = (tailidx-headidx-1)/2;
    //     int mididx = headidx+gap;
    //     //이거 여기서 -1로 나오면 안되는 큰 오류 발생 가능성 있음.
    //     for(int i=0; i<=gap; i++){
    //         swapvector(mididx-i,mididx+1+i,vec);
    //     }
}