import sys, math

#극한으로 아예 파라미터로 math.dist 함수를 받게해서 줄이고 람다 사용해서 main도 줄이기
def myfinder(g, l, h):
    for _ in range(91): 
        m = [(l[i] * 2 + h[i]) / 3 for i in range(len(l))]
        n = [(l[i] + h[i] * 2) / 3 for i in range(len(l))]
        if g(m) < g(n): h = n
        else: l = m
    return g(l)

A, B, C, D = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
print(math.ceil(myfinder(lambda x: myfinder(lambda y: math.dist(x, y), C, D), A, B)-1e-9))