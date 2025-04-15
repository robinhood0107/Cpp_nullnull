//
// Created by pjjpj on 25. 4. 11.
//
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second

int borad[502][502] = {}; // 말그대로 borad, 판이라고 생각하면 됨 (1이면 파란칸, 0이면 빨간칸)
bool vis[502][502] ={}; // vis = 방문여부를 저장할 배열
int dx[4] = {1,0,-1,0}; //이 dx, dy는 상하좌우를 편하고 영리하게 처리하기 위한 방법(1,0)(0,1)(-1,0)(0,-1)의 좌표를 편하기 쓰기위한 배열
int dy[4] = {0,1,0,-1}; // 이거 주의해야 하는게 여기서 x는 세로(행개수)를 의미하고 y는 가로(열개수)를 의미한다 (절대 좌표생각하면 안됨)
int n=7, m=10; //각 행과 열의 수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    vis[0][0]= 1;//0,0에 방문 표시
    Q.push({0,0}); //0,0 Q에 추가
    while (Q.empty()) {
        pair<int,int> cur = Q.front();
        Q.pop();
        cout << '(' << cur.X << ',' << cur.Y << ") -> ";
            for (int dir=0;dir<4;dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir]; //변수 nx,ny에 깔끔하게 상하좌우 탐색한것 저장됨
                if (nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if (vis[nx][ny] || board[nx][ny] != 1) continue;
                vis[nx][ny] = 1;
                Q.push({nx,ny});
            }
        //구현할 때 조심할점 (이 BFS의 경우에는 코드를 아예 싸그리 외워버린다는 방식으로 접근해야만 함)
        //주로 실수하는 부분
        //1.시작점에 방문했다는 표시를 남기지 않음(0,0 체크 안할 경우) -> 이렇게 되면 시작점을 2번 방문하기 때문에 이러면 안된다.
        //2.큐에 넣을 때 방문했다는 표시를 하는 대신 큐에서 뺄 때 방문했다는 표시를 남긴 경우 -> 이렇게 되면 같은 칸이 큐에 여러번 들어가게 된다! -> 시간초과나 메모리 초과 발생 가능
        //3.nx,ny가 배열 바깥(범위)를 벗어난 경우
    }
}