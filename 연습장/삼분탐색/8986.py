import sys

n = int(sys.stdin.readline())
s = list(map(int, sys.stdin.readline().split()))

def howmuchyourcost(d):
    totalcost = 0
    for i in range(n):
        totalcost += abs(s[i] - i * d) # i번째 전봇대는 i * d 위치로 이동
    return totalcost #이걸로 최종 totalcost 구함(abs로 전부 절댓값화 되니까)

left = 0
right = int(10e+9)

while right - left > 3:
    a = (left*2 + right) // 3  #l과 r 사이의 1/3
    b = (left + right*2) // 3 #l과 r 사이의 1/2

    if howmuchyourcost(a) > howmuchyourcost(b):
        # 왼쪽 1/3 구간(left ~ a) 버림
        left = a
    else:
        # 오른쪽 1/3 구간(b ~ right) 버림
        right = b 
        
ans = float('inf')
for d in range(left, right + 1):
    ans = min(ans, howmuchyourcost(d))

print(ans)
# 참고로 print(type(float('inf')))  # <class 'float'>
# 이렇게도 쓸수 있다는거 기억(대략 10**18 정도 됨) 부동소수점 생각