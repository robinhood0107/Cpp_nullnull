//토마토 문제
//유명하다 BFS로 빠르게 풀 줄 알아야 됨

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m,n = 0;
    cin >> m >> n;

    vector<vector<int>> board(n);
    vector<vector<int>> vis(n,vector<int>(m,0));

    cin.ignore(); //cin 다음에 getline 쓸때는 이거 필수
    
    string line;
    getline(cin, line);
    stringstream ss(line);
    int token;

    for(int i=0; i<n; i++){
        while(ss >> token){
            board[i].push_back(token);
            }
    }

    int count=0;

    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    //상우하좌로 한다

    //여기 외워서 칠 정도로 이중for문 숙달하기
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(board[i][j] == 0 || vis[i][j]) continue;




            
        }
    }



}


//나중에는 응용으로 여기에 썩은 토마토 처리도 할 줄 알아야 함