#p142에 나오는 그래프를 DFS로 전체 노드를 방문해라
#stack을 이용해서


def dfs(gragh, v, visited): #방문처리하는 dfs 함수
    #일단 현재 노드를 방문 처리한다
    visited[v] = True
    print(v, end=' ')

    #재귀 방문을 통해서 DFS를 구현한다
    #근데 앵간하면 DFS문제의 경우 BFS로 해결 될 것
    #애초에 재귀를 피하는 방식으로 코딩을 해야 함

    for i in gragh[v]: #gragh에 있는 특정 인덱스 i의 경우
        if not visited[i]: #visited 배열에서 방문하지 안았다고 할 경우
            dfs(gragh, i, visited) #dfs를 호출해서 현재 노드를 방문처리한다

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

dfs(gragh,1,visited)