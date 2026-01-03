#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

//일단 bfs 기본 틀

//백준 1926 그림문제 예시
//어떤 큰 도화지에 그림이 그려져 있을 때, 그 그림의 개수와, 그 그림 중 넓이가 가장 넓은 것의 넓이를 출력하여라. 
//단, 그림이라는 것은 1로 연결된 것을 한 그림이라고 정의하자. 
//가로나 세로로 연결된 것은 연결이 된 것이고 대각선으로 연결이 된 것은 떨어진 그림이다. 그림의 넓이란 그림에 포함된 1의 개수이다.

using namespace std;

//초기 설정
vector<vector<int>> board = {502,vector<int>(502,0)}; //기본 공간 //이렇게 하면 502,502 배열 선언됨  //처음 502가 행 다음이 502 열
vector<vector<int>> vis(502,vector<int>(502,0)); //방문표시+

// int n = 7;
// int m = 8;
//실제 문제의 행과 열
int n;
int m;


int dx[4] = {1,0,-1,0}; //우 상 좌 하 순으로 반시계로 가자 //솔직히 이 순서는 아무 상관이 없음 그냥 전부 순회만 하면 됨
int dy[4] = {0,1,0,-1};
//헷깔리면 중앙을 x,y라고 할 때 좌(-1,0) 우(1,0) 상(0,1) 하(0,-1) 로 먼저 생각을 한 후 전부 들어가게만 적으면 된다.

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> board[i][j]; //일단 이렇게 필요한 지도 받아오기 //입력은 달라질 수 있음
        }
    }

    int pmax = 0; //그림의 최대수
    int pnum = 0; //그림의 수

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(board[i][j] == 0 || vis[i][j]) continue; //board가 막혀있거나(벽같이 유효X한 곳), 이미 방문한 vis의 경우 넘어간다
            pnum++; //1로 연결된 것 전부를 그림으로 하기 때문에 지금 1 덩어리 하나 찾으려고 하므로 그림 1개 카운트
            
            queue<pair<int,int>> Q; //이 그림 덩어리 1개에서만 사용하는 queue이다. 그러므로 여기서 생성

            vis[i][j] = 1; //지금 있는 i,j 좌표의 경우 방문했다고 처리
            Q.push({i,j});
            int area = 0;

            while(!Q.empty()){
                area++;
                pair<int, int> cur = Q.front(); //Q에서 front를 꺼냄 //이걸 계속 반복하면서 Queue가 비워질 때까지 계속한다
                Q.pop(); //꺼낸 것은 지운다
                for(int dir=0; dir<4; dir++){
                    int nx = cur.first + dx[dir];
                    int ny = cur.second + dy[dir];
                
                    if(nx < 0 || ny < 0 || nx > n || ny > m) continue; //nx,ny가 board에서 board의 벽을 넘어갈 경우 다음 dir로 넘어감 
                    if(vis[nx][ny] || board[nx][ny] != 1) continue; //board가 막혀있거나(벽같이 유효X한 곳), 이미 방문한 vis의 경우 넘어간다
                    
                    //모든 if에서 안걸렸으면 그건 유효한 값이란 것
                    vis[nx][ny] = 1;
                    Q.push({nx,ny});
                }
            }

            pmax = max(pmax,area); //새로운 area 값과 pmax를 비교해서 더 큰 값을 pmax로 한다
        }
    }
    cout << pnum << "\n" << pmax;
}
