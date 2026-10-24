import sys, math
#생각 과정(나중에 공부한 것 재복습할때를 위해서)
#문제를 보면 교수님이 P(t) = (1 - t) * A + t * B 이 함수를 활용해보라고 했는데 여기서 최소값만 찾으면 된다는 것
#2차함수이기도 하고 아래로 볼록한 함수만 만들기 때문에 이것만 찾아버리면 됨
#그러면 2차함수에다가 두개의 점을 찍은 다음에 둘이 대소 비교해서 높은 쪽 부분보다 큰부분 싹 버리고 나머지 2/3부분만 남기면 된다. 이걸 반복시키면 됨

#ABfinder에서 결정된 최단거리 점 P랑 선 CD랑의 거리
def CDfinder(P, C, D):
    left = C
    right = D
    for _ in range(91):
        m = [(left[i] * 2 + right[i]) / 3 for i in range(len(left))]
        n = [(left[i] + right[i] * 2) / 3 for i in range(len(left))]
        
        if math.dist(P, m) > math.dist(P, n): #그냥 P와 m, n 사이의 거리
            left = m
        else: 
            right = n
    return math.dist(P, left) # 결국 이걸 출력하게 됨

#선 AB 위를 움직이는 점 찾기
def ABfinder(A, B, C, D):
    left = A
    right = B
    for _ in range(91): #배정밀도 관련 공부랑 검색을 병행
        #while문을 사용하지 말고 그냥 부동소수점을 이용해서 부동소수점 한계까지만 반복시키면 된다는 아이디어를 검색해서 찾아서 적용시켰습니다.
        #원래는 while문으로 무한반복시켰는데 파이썬에서는 double 배정밀도를 실수float의 자료형객체로 사용함.
        #배정밀도 1 / 11 / 52으로 진수부가 2^52(52비트) 그리고 1.XX로 정규화때문에 실제 표현가능한 소수점이 2^53(53비트)임.
        #이걸 상용로그취해보면 15.955XX 이렇게 되므로 10^16정도가 되니까 소수점 16자리(사실 이래서 0.1 + 0.2 ≠ 0.3 이거 유명한것도 있음(무한소수))
        
        #배정밀도는 16자리까지 정밀도를 가진다는 것 알아두자
        #지금 내가 사용하려는 것이 그래프에 점 2개를 찍는 것인데 이러면 구간이 총 3개가 나오므로 삼분탐색이라고 할 수 있음
        #계속 2/3이 반복되서 곱해지니까 (2/3)^91에 상용로그 씌워보면 -16 정도가 나오기 때문에 91번 반복하면 배정밀도 끝까지 간다(이후는 어쩌피 표현 못해서 사용 못하니까 버려도 됨)
        m = [(left[i] * 2 + right[i]) / 3 for i in range(len(left))]
        n = [(left[i] + right[i] * 2) / 3 for i in range(len(left))]
        
        if CDfinder(m, C, D) > CDfinder(n, C, D): #1/3 버리기
            left = m 
        else: 
            right = n
    return CDfinder(left, C, D)


#입력은 최대한 빠르게(sys.stdin.readline()이 방식 꼭 외우자)
A, B, C, D = [list(map(int, sys.stdin.readline().split())) for _ in range(4)]
print(math.ceil(ABfinder(A, B, C, D) - 1e-9)) #이걸 빼야 정확하게 나온다... 배정밀도 이상으로 나오는 것인 epsilon(1e-9) 꼭 빼줘라
#항상 이렇게 1e-9 이하는 빼줘서 보정한다