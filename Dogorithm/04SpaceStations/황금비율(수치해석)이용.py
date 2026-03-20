import sys
import math

# 가장 빠른 입력 방식 적용
input = sys.stdin.readline

#황금비율 상수 (약 0.381966)
RHO = (3 - math.sqrt(5)) / 2 

def get_pt(p1, p2, t):
    """
    매개변수 t (0 <= t <= 1)를 이용해 선분 위의 3차원 점 P(t)를 반환합니다.
    교수님 힌트: P(t) = (1-t)*A + t*B 와 동일한 수식입니다.
    """
    return tuple(p1[i] + t * (p2[i] - p1[i]) for i in range(3))

def golden_section_search(f):
    """
    0.0 부터 1.0 사이의 구간에서 목적 함수 f(t)가 최솟값을 가지는 점을 찾습니다.
    단 1번의 초기 계산 후, 매 루프마다 1번만 추가 계산하여 극강의 효율을 냅니다.
    """
    a, b = 0.0, 1.0
    m1 = a + RHO * (b - a)
    m2 = b - RHO * (b - a)
    
    # 최초에만 2번 계산
    f1, f2 = f(m1), f(m2)
    
    # 80번 반복 (삼분 탐색의 100번보다 적게 돌아도 더 정밀하게 수렴함)
    for _ in range(80):
        if f1 < f2:
            b = m2
            m2, f2 = m1, f1           # [핵심] 기존 m1을 새로운 m2로 완벽히 재활용!
            m1 = a + RHO * (b - a)
            f1 = f(m1)                # 새 m1에 대해서만 1번 계산
        else:
            a = m1
            m1, f1 = m2, f2           # [핵심] 기존 m2를 새로운 m1으로 완벽히 재활용!
            m2 = b - RHO * (b - a)
            f2 = f(m2)                # 새 m2에 대해서만 1번 계산
            
    # 최종적으로 수렴한 두 값 중 더 작은 거리를 반환
    return min(f1, f2)

def solve(A, B, C, D):
    """두 선분 사이의 최단 거리를 중첩 황금분할 탐색으로 구합니다."""
    
    # 외부 탐색용 목적 함수: 선분 AB 위의 점 P(t1)을 고정했을 때의 최단 거리
    def outer_obj(t1):
        P = get_pt(A, B, t1)
        
        # 내부 탐색용 목적 함수: 점 P와 선분 CD 위의 점 Q(t2) 사이의 거리
        def inner_obj(t2):
            Q = get_pt(C, D, t2)
            return math.dist(P, Q)
            
        # P가 고정된 상태에서 선분 CD 위를 탐색(내부)하여 가장 짧은 거리를 반환
        return golden_section_search(inner_obj)
    
    # 선분 AB 위를 탐색(외부)하여 전체 최단 거리를 찾음
    min_distance = golden_section_search(outer_obj)
    
    # 문제의 조건에 따라 올림(Ceiling) 처리하여 정수 반환
    return math.ceil(min_distance)

# EOF까지 무한 루프 입력 처리
while True:
    try:
        line = input().strip()
        if not line:
            break
            
        # 예제에 포함된 주석(// A 좌표 등)을 무시하기 위해 [:3]으로 좌표 숫자만 파싱
        A = tuple(map(int, line.split()[:3]))
        B = tuple(map(int, input().split()[:3]))
        C = tuple(map(int, input().split()[:3]))
        D = tuple(map(int, input().split()[:3]))
        
        # 정답 출력
        print(solve(A, B, C, D))
        
    except EOFError:
        break