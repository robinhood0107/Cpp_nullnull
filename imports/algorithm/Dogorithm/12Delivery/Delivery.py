import sys
myinput = sys.stdin.read().split()
n = int(myinput[0])
#딕셔너리에 좌표
pos = {}
pos['start'] = (int(myinput[1]), int(myinput[2]))
idx = 3
for i in range(1, n + 1):
    pos[f'+{i}'] = (int(myinput[idx]), int(myinput[idx+1]))
    pos[f'-{i}'] = (int(myinput[idx+2]), int(myinput[idx+3]))
    idx += 4
dic = {}
# 베달 완료인 상태는 2니까...
result = "2" * n
def get_dist(loc1, loc2):
    x1, y1 = pos[loc1]
    x2, y2 = pos[loc2]
    return abs(x1 - x2) + abs(y1 - y2)
def get_route(current, cnt):
    moves = []
    for i in range(n):
        num = i + 1
        if current[i] == '0' and cnt < 3:
            new_current = current[:i] + '1' + current[i+1:]
            moves.append((num, i, f"+{num}", new_current, cnt+1))
        #가방에 들고있을 때가 '1'임
        elif current[i] == '1':
            new_current = current[:i] + '2' + current[i+1:]
            moves.append((-num, i, f"-{num}", new_current, cnt-1))
    return moves
def dfs(my_node, current, cnt):
    if current == result:
        dic[(my_node, current)] = 0
        return 0
    # 이미 와본 상태면 딕셔너리 키 메모해둔거 바로 리턴(프로그래밍언어론에서 했던 메모리제이션 생각하기)
    current_key = (my_node, current)
    if current_key in dic:
        return dic[current_key]
    min_dist = float('inf')
    for _, _, resultnode, next_current, next_bag in get_route(current, cnt):
        dist = get_dist(my_node, resultnode)
        total_cost = dist + dfs(resultnode, next_current, next_bag)
        if total_cost < min_dist:
            min_dist = total_cost
    # 계산 끝났으면 해시에 박아둠
    dic[current_key] = min_dist
    return min_dist
#DP
init = "0"*n
dfs('start', init, 0)
my_node = 'start'
my_current = init
my_bag = 0
path = []
while my_current != result:
    best_choices = []
    for move in get_route(my_current, my_bag):
        resultnode = move[2]
        next_current = move[3]
        if get_dist(my_node, resultnode) + dic.get((resultnode, next_current), float('inf')) == dic[(my_node, my_current)]:
            best_choices.append(move)
    best_choices.sort() #정렬
    chosen = best_choices[0]
    # 결정된 노드 이름(+1, -2 등) 정답에 넣고 업데이트
    path.append(chosen[2])
    my_node = chosen[2]
    my_current = chosen[3]
    my_bag = chosen[4]
print('\n'.join(path))