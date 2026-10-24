import sys, math

s = list(map(int, sys.stdin.readline().split()))
A, B, C, D = s[:2], s[2:4], s[4:6], s[6:8]

#내가 지금까지 풀던것과는 다르게 민호랑 강호는 반드시 같은 비율로 움직여야 됨(같은 속도 움직임)
#즉 그냥 삼분탐색을 진행하면 되는데 서로 동시에 계산해주면 됨

def finder(a, b, c, d):
    left_a, right_a = a, b #강호 좌표
    left_c, right_c = c, d #민호 좌표

    for _ in range(100):
        # 민호
        m_a = [(left_a[i] * 2 + right_a[i]) / 3 for i in range(2)]
        n_a = [(left_a[i] + right_a[i] * 2) / 3 for i in range(2)]

        # 강호
        m_c = [(left_c[i] * 2 + right_c[i]) / 3 for i in range(2)]
        n_c = [(left_c[i] + right_c[i] * 2) / 3 for i in range(2)]

        # 같은 속도는 같은 움직임. 즉, 둘이 같이 움직여야 함. 삼분탐색시에 x,y좌표(m,n)에 대한 a와 c값을 비교하고 이거로 어디의 1/3을 버릴지 판단하면 됨.
        if math.dist(m_a, m_c) > math.dist(n_a, n_c):
            left_a = m_a
            left_c = m_c
        else: 
            right_a = n_a
            right_c = n_c
            
    return math.dist(left_a, left_c)

print("{:.10f}".format(finder(A, B, C, D)))