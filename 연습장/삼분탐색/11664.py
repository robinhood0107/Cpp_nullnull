import sys, math

s = list(map(int, sys.stdin.readline().split()))
A, B, C = s[:3], s[3:6], s[6:]

def finder(c, a, b):
    left = a;
    right = b;

    for _ in range(91):
        m = [(left[i] * 2 + right[i]) / 3 for i in range(len(left))] #l과 r의 1/3지점을 x,y,z 좌표별로 나열한 리스트
        n = [(left[i] + right[i] * 2) / 3 for i in range(len(left))] #l과 r의 2/3지점을 x,y,z 좌표별로 나열한 리스트

        if math.dist(c, m) > math.dist(c, n): #그냥 c와 m, n 사이의 거리
            left = m
        else: 
            right = n
    return math.dist(c, left)


print("{:.10f}".format(finder(C,A,B)))
