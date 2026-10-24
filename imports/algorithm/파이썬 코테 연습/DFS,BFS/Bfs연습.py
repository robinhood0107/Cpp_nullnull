from collections import deque

#BFS는 그래프에서 가장 가까운 노드부터 먼저 방문하는 것
#(일단 방문처리(방문중, 방문해야할 곳)은 큐에 넣고 
# 방문완료(완료될 경우, 즉, 다른 노드로 이동할 경우)는 큐에서 빼는 방식)

#파이썬에서는 deque로 빠르게 구현한다(어쩌피 코테에서는 dfs쓰면 안됨 그냥 bfs로 끝내야 한다(dfs는 어쩌피 재귀 쓰는거임))
def bfs(graph, start, visited):
    queue = deque([start]) #일단 현재 노드는 현재 위치하고 있으므로 방문처리(방문중)
    #여기서 start는 시작할 노드(root)
    
    #그냥 현재 인접노드(방문중, 방문해야할 곳)는 큐에 넣고 이제 다시 안올 방문 완료인 경우만 큐에서 제거한다고 생각을 항상 해라
    #그리고 잊지말고 queue 반복 시작 전에 visited 방문 배열 넣어(여기선 인덱스=노드번호로 하긴 하네)
    visited[start] = True

    #항상 기억 : 큐가 빌때까지 돌려라
    while queue:
        v= queue.popleft() #가장 처음들어온, 상단 노드 출력(선입선출, deque에선 이걸 popleft라고 한다 기억해라)(queue로 쓰려면 걍 popleft쓴다고 생각하셈)

        for i in graph