from collections import deque
#deque 임포트에서 여기서 queue 사용할 꺼임

def bfs(graph, start, visited):
    queue = deque([start]) #일단 queue에 시작 노드 삽입
    #덱과 큐의 차이점은 큐는 선입선출에 인풋1개 아웃풋1개이지만 덱은 양쪽 top, tail에서 인풋아웃풋 전부 가능한 구조
    
    visited[start] = 1
    
    #큐가 빌때까지 계속 Traverse(순회)
    while queue: #이렇게 하면 queue가 empty일때까지 돌 수 있다.
        v = queue.popleft() #left가 top()매서드라고 생각.
        print(v, end=' ') #v를 출력하는데 end는 공백으로 채운다. 즉 ' ' 넣음
        
        #해당 원소와 연결된 아직 방문하지 않은 원소들을 큐에 삽입한다
        for i in gragh[v]:
            if not visited[i]:
                queue.append(i) #방문 안한것은 queue에 삽입
                visited[i] = True #방문처리

# gragh 2차원 리스트 (하나의 원소는 1번 노드 [2] 2번노드 [1,7] 이런식으로 연결되어 있는 노드 리스트(자신은 제외))
# 인덱스 0은 비운다
gragh = [
    [],
    [2,3,8],
    [1,7],
    [1,4,5],
    [3,5],
    [3,4],
    [7],
    [2,6,8],
    [1,7]
]

visited = [0 for _ in range(len(gragh))]

bfs(gragh,1,visited)