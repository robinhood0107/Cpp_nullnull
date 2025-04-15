//
// Created by pjjpj on 25. 4. 11.
//
#include <bits/stdc++.h>
using namespace std;
//flood fill 문제이다

//생각해야 하는 것
// 1.상하좌우로 연결된 그림의 크기를 알아내기
// 2.도화지에 있는 모든 그림을 찾아내기
// 모든 그림 찾아내기 = 모든 칸이 시작점이 될 수 있는지 확인
//(이중for문으로 각 칸이 BFS의 시작점이 될 수 있는지 체크)
int main() {
    int board[500][500] ={};
    bool vis[500][500] ={};
    int n,m;
    cin >> n >> m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> board[i][j];
        }
    }
    int max_pic=0;
    int num=0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (board[i][j] == 0 || vis[i][j]) continue; //이 조건일 경우 해당 i,j는 다음으로 건너뛴다는 것 //board에 그림 없거나, 이미 탐색해서 vis가 1인경우 건너뛰기
            vis[i][j] = 1; //시작점을 배열 요소 하나하나씩 전체 검사하기 위해
            queue<pair<int,int>> Q;
            Q.push({i,j});//시작점을 i,j로 설정 (vis랑 Q는 세트로 가야 한다.반드시 안그럼 시작점 2번 보는 참사 발생)
            num++; // 위에서 continue로 그림 아닌거나 했던거는 건너뛰기 했기 때문에 이건 그림의 개수가 된다.(그림의 개수 = 시작점의 개수)
            int area =0; //그림의 넓이
            while (!Q.empty()) {
                area++;
                pair<int,int> cur = Q.front();
                Q.pop();
                for (int i=0;i<4;i++) {
                    int nx = cur.first + dx[i];
                    int ny = cur.second + dy[i];
                if (nx < 0 || nx >= n || ny<0 || ny >= m) continue; // 이거 반드시 해야 한다, 길이 넘어갈 경우 dx,dy로 상하좌우 탐색 건너뛰기
                if (vis[nx][ny] || board[nx][ny] != 1) continue; //board가 0이거나 이미 vis가 1이면 넘어가기(이미 탐색 했거나 탐색 대상이 아니라는 거니까)
                vis[nx][ny] = 1; //그림이니까 "탐색했음"으로 1 넣기
                Q.push({nx,ny}); //그림이니까 큐에 넣기(상하좌우 탐색해서 borad가 1 = 그림이다)
                }
            }
        max_pic = max(max_pic,area); //반복문 통해서 가장 최댓값 찾음
        }
    }
cout << num << "\n" << max_pic;
}