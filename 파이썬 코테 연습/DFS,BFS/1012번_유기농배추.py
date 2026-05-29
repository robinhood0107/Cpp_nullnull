import sys
input = sys.stdin.readline #파이썬의 기본 input() 함수는 사용자의 입력을 받을 때마다 처리 과정을 거치기 때문에 속도가 매우 느립니다. 이를 sys.stdin.readline으로 덮어씌우면, 버퍼에서 한 번에 텍스트를 읽어오기 때문에 수만 줄의 데이터를 입력받아도 속도가 엄청나게 빠름
sys.setrecursionlimit(10**7) #파이썬은 기본적으로 재귀 함수(자기가 자기 자신을 다시 부르는 함수)가 1,000번까지만 호출되도록 제한이 걸려 있습니다. 이를 넘어가면 RecursionError가 발생하며 프로그램이 뻗어버립니다. 깊이 우선 탐색(DFS) 같은 알고리즘을 풀 때는 1,000번을 우습게 넘기기 때문에, 제한을 10,000,000(10**7)까지 넉넉하게 늘려주는 것    
#입력은 엄청 빠르게 받고, 재귀 제한은 넉넉하게 풀어서 에러 없이 T개의 테스트 케이스를 채점받겠다!
#백준 파이썬 기본 세팅이니까 이건 외워두자

#참고로 계속 파이썬으로 공부하려면 입출력 방식 이거 외워
# map(int, input().split())

from collections import deque

#시계방향으로 순회한다.
#상우하좌
dx = [0,1,0,-1]
dy = [1,0,-1,0]

def bfs(x, y):
    queue = deque([(x, y)])
    
    #여기에서는 한칸당 상하좌우 전부 검사하면 됨
    #바킹독 그 함수 전체 통채로 외우는 거 생각하셈
    visited[x][y] = True
    
    while queue:
        cx, cy = queue.popleft()
        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]
            
            #다음 위치가 배열 범위를 벗어나지 않는지 '먼저' 확인
            if 0 <= nx < row and 0 <= ny < col:
                #배추가 있고(graph == 1), 아직 방문하지 않았다면
                if graph[nx][ny] == 1 and not visited[nx][ny]:
                    visited[nx][ny] = True     # 방문 처리
                    queue.append((nx, ny))     # 큐에 '새로운' 좌표 삽입

    #인접한 배추들을 모두 탐색했다면 True를 반환해 묶음 개수를 1 증가
    return True



T = int(input()) #테스트 케이스의 개수를 입력받음 일단 T에 테스트할 개수 저장

for _ in range(T): #테스트케이스인 T만큼 반복한다
    row, col, K = map(int, input().split()) #K은 지렁이 개수

    res=0

    graph =  [[0] * (col) for _ in range(row)]
    visited =  [[0] * (col) for _ in range(row)]

    for _ in range(K):
        x, y = map(int, input().split())
        graph[x][y] = 1

    for i in range(row): 
        for j in range(col):
            #내가 틀린 부분
            #모든 칸에서 BFS를 돌리는 게 아니라, "배추가 있고 방문 안 한 곳"에서만 시작
            if graph[i][j] == 1 and not visited[i][j]:
                if bfs(i, j): # 여기서 bfs를 한 바퀴 쫙 돌고 지렁이 투입(res += 1)
                    res += 1  
    print(res)