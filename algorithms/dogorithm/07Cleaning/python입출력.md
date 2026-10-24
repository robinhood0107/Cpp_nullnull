# 파이썬 코테에서 자주 나오는 입력 유형별 템플릿 10개

코딩테스트에서는 보통 아래 한 줄을 먼저 써 두고 시작합니다.

```python
import sys
input = sys.stdin.readline
```

이렇게 해 두면 `input()`보다 빠르게 입력을 받을 수 있습니다.

---

## 0. 가장 기본 뼈대

```python
import sys
input = sys.stdin.readline
```

* 정수 입력: `int(input())`
* 여러 정수 입력: `map(int, input().split())`
* 리스트 입력: `list(map(int, input().split()))`
* 문자열 입력: `input().strip()`

---

## 1. 정수 1개 입력

### 입력 예시

```text
5
```

### 템플릿

```python
n = int(input())
```

### 설명

* 가장 기본적인 형태입니다.
* 보통 `n`: 개수, 길이, 노드 수 등에 많이 씁니다.

---

## 2. 한 줄에 정수 여러 개 입력

### 입력 예시

```text
3 7
```

### 템플릿

```python
n, m = map(int, input().split())
```

### 설명

* `N M`, `R C`, `A B` 같은 형태에 자주 나옵니다.
* 공백 기준으로 나눠서 정수로 바꿉니다.

---

## 3. 한 줄에 있는 수열을 리스트로 입력

### 입력 예시

```text
1 2 3 4 5
```

### 템플릿

```python
arr = list(map(int, input().split()))
```

### 설명

* 배열, 수열, 점수 목록 등을 받을 때 가장 자주 씁니다.

---

## 4. 여러 줄의 2차원 배열 입력

### 입력 예시

```text
3
1 2 3
4 5 6
7 8 9
```

### 템플릿

```python
n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
```

### 설명

* 행렬, 지도, 표 형태 입력에 사용합니다.
* `board[i][j]` 형태로 접근할 수 있습니다.

---

## 5. 문자열 한 줄 입력

### 입력 예시

```text
algorithm
```

### 템플릿

```python
s = input().strip()
```

### 설명

* 문자열 문제에서는 `strip()`을 붙이는 습관이 좋습니다.
* 줄 끝 개행문자 `\n` 제거용입니다.

---

## 6. 붙어 있는 숫자/문자를 한 글자씩 받기

### 입력 예시 1

```text
10101
```

### 템플릿 1

```python
arr = list(map(int, input().strip()))
```

### 결과

```python
[1, 0, 1, 0, 1]
```

### 입력 예시 2

```text
ABCDE
```

### 템플릿 2

```python
chars = list(input().strip())
```

### 결과

```python
['A', 'B', 'C', 'D', 'E']
```

### 설명

* 미로, 비트열, 문자열 탐색 문제에서 자주 나옵니다.

---

## 7. 테스트케이스가 여러 개인 경우

### 입력 예시

```text
3
5
10
20
```

### 템플릿

```python
t = int(input())

for _ in range(t):
    n = int(input())
    print(n)
```

### 설명

* 첫 줄이 테스트케이스 수 `T`인 경우입니다.
* 각 테스트마다 같은 로직을 반복하면 됩니다.

---

## 8. 간선 정보나 쌍 데이터 여러 줄 입력

### 입력 예시

```text
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14
```

### 템플릿

```python
n = int(input())
pairs = []

for _ in range(n):
    a, b = map(int, input().split())
    pairs.append((a, b))
```

### 설명

* 좌표, 간선, 구간, 두 값 묶음 입력에서 자주 사용합니다.
* 저장 결과는 예를 들면 `[(1, 4), (3, 5), ...]` 형태입니다.

---

## 9. 그래프 입력을 인접 리스트로 받기

### 입력 예시

```text
5 4
1 2
1 3
2 4
3 5
```

### 템플릿

```python
n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)   # 무방향 그래프일 때
```

### 설명

* DFS, BFS 문제에서 가장 많이 쓰는 그래프 저장 방식입니다.
* 방향 그래프면 `graph[a].append(b)`만 사용합니다.

---

## 10. 입력 전체를 한 번에 처리하는 방식

### 입력 예시

```text
5 3
1 2 3 4 5
```

### 템플릿

```python
import sys

data = sys.stdin.read().split()
data = list(map(int, data))

print(data)
```

### 설명

* 입력이 아주 많을 때 쓰는 방식입니다.
* 다만 초반에는 조금 헷갈릴 수 있으니, 보통은 `readline` 방식부터 익히는 것이 좋습니다.

---

# 자주 쓰는 실전형 템플릿 모음

## 1. `N`만 있는 경우

```python
n = int(input())
```

## 2. `N M` 형태

```python
n, m = map(int, input().split())
```

## 3. 수열 한 줄

```python
arr = list(map(int, input().split()))
```

## 4. `N`줄짜리 2차원 배열

```python
board = [list(map(int, input().split())) for _ in range(n)]
```

## 5. 문자열 한 줄

```python
s = input().strip()
```

## 6. 붙어 있는 숫자 문자열

```python
arr = list(map(int, input().strip()))
```

## 7. 테스트케이스 `T`

```python
t = int(input())
for _ in range(t):
    pass
```

## 8. 간선 `M개`

```python
for _ in range(m):
    a, b = map(int, input().split())
```

## 9. 좌표 `N개`

```python
points = [tuple(map(int, input().split())) for _ in range(n)]
```

## 10. 입력 전체 한 번에

```python
data = sys.stdin.read().split()
```

---

# 코테에서 특히 많이 쓰는 형태 5개

아래 5개는 거의 외워 두면 편합니다.

```python
import sys
input = sys.stdin.readline

n = int(input())
n, m = map(int, input().split())
arr = list(map(int, input().split()))
board = [list(map(int, input().split())) for _ in range(n)]
s = input().strip()
```

---

# 자주 헷갈리는 포인트

## `input().split()` 과 `input().strip()`

### 정수 입력

```python
a, b = map(int, input().split())
```

* 보통 `strip()` 없이 써도 괜찮습니다.

### 문자열 입력

```python
s = input().strip()
```

* 문자열은 `strip()`을 붙이는 것이 안전합니다.

---

## `list(map(int, input().split()))` 의미

```python
arr = list(map(int, input().split()))
```

순서는 다음과 같습니다.

1. `input()`으로 한 줄 입력
2. `split()`으로 공백 기준 분리
3. `map(int, ...)`으로 정수 변환
4. `list(...)`로 리스트로 만듦

---

# 추천하는 코테 시작 템플릿

```python
import sys
input = sys.stdin.readline

# 예시
n, m = map(int, input().split())
arr = list(map(int, input().split()))
```

---

# 한 줄 정리

파이썬 코테 입력은 결국 아래 4개가 핵심입니다.

```python
int(input())
map(int, input().split())
list(map(int, input().split()))
input().strip()
```

이 4개만 익숙해져도 대부분의 입력은 처리할 수 있습니다.