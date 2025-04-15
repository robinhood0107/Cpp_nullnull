//
// Created by pjjpj on 25. 4. 11.
//
#include <bits/stdc++.h>
using namespace std;
// 미로의 좌측 상단에서 우측 하단으로 가는 최단경로를 찾는 문제

// 큐를 저장할 때 거리도 거리 배열에 저장해라!!
// 큐에 저장한 거리가 가장 작은 것을 따라서 나아가면 된다.
// 거리를 저장할 dist배열을 두고 상하좌우의 칸에 값을 넣기
// tip) dist 배열을 미리 -1로 초기화해두면 vis배열을 두지 않아도 방문 여부를 확인할 수 있다!
int main() {
    string board[102] = {};
    vector<vector<int>> dist ={};
    int n,m;
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    cin >> n >> m;
    for (int i=0;i<n;i++) {
            cin >> board[i]; // 이렇게 할경우 각 행에 띄워쓰기 없는 string이 1줄씩 string n개가 총 n행 들어감
                             //string은 문자열(즉, 배열)이라서 배열처럼 행동한다는 것을 이용하는 것(string이 1행이라서 다차원배열 됨)
    }
    dist.resize(n,vector<int>(m,-1));
    queue<pair<int,int>> Q;
    Q.push({0,0}); //시작점 초기화
    dist[0][0]= 0; // 시작점 값 0으로 초기화
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i=0;i<4;i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= n || ny<0 || ny >= m) continue; // 길이 넘어가면 건너뛰기
            if (dist[nx][ny] >=0 || board[nx][ny] != '1') continue; //이미 탐색한 것일 경우 건너뛰기 //board 값 string이라 '1' 조심
            //큐에 집어넣기
            dist[nx][ny] = dist[cur.first][cur.second] +1 ; //dist(거리)는 현재에서 1칸 더 간거니까 현재 거리+1을 해주면 된다
            Q.push({nx,ny}); //탐색한 좌표를 큐에 저장(여기서 탐색했는지 안했는지 판별을 위한 vis 역할을 dist가 대신해줌)
        }
    }
    cout << dist[n-1][m-1]+1; //n-1,m-1은 제일 우측 하단의 배열 주소(배열전체 크기)고 문제의 특성상 거리+1이 정답이 됨(시작점 자신을 포함해야 하니까)
}