import bisect #이진탐색용 라이브러리니까 꼭 기억
import sys

def mycompare(a, b):
    p1, c1 = a
    p2, c2 = b
    if p1 != p2:
        return a if p1 > p2 else b
    return a if c1 < c2 else b

n = int(input())
arr=[]
for _ in range(n):
    a, b, c = map(int, sys.stdin.readline().rstrip().split()) #rstrip()은 받은 string의 오른쪽제거
    arr.append((a, b, c))

arr.sort(key=lambda x: x[1]) #종료일인 b 기준으로 정렬시킴
endtime = [x[1] for x in arr]
dp = [(0, 0)] * (len(arr) + 1) #dp용 배열로 인덱스별로 최대이익이랑 해당일수 저장함

for i, (begin, end, cost) in enumerate(arr, 1): #enumerate 내장함수로 이렇게 쓰면 i는 1부터 시작한다는 것임
    j = bisect.bisect_left(endtime, begin) #파이썬 bisect으로 이진탐색하고 지금 시간에서 시간이 겹치지 않는 가장 마지막의 종료일 청소일정 잡음
    profitmoney, day = dp[j] #일단 이전 인덱스로 돌아가기
    latest = (profitmoney-10+cost, end-begin+1+ day) if j > 0 else (0, 0) #이전 작업이 있을 때만 10만원 차감하면 됨
    single = (cost, end - begin + 1)
    mybest = mycompare(latest, single) if j > 0 else single
    dp[i] = mycompare(dp[i-1], mybest) #점화식 이렇게 적음

result1, result2 = dp[-1]
print(f"{result1} {result2}")