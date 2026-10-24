# C++ 코테에서 자주 나오는 입력 유형별 템플릿 10개

코딩테스트에서 C++로 입력받을 때는 보통 아래 두 줄을 먼저 써 두고 시작합니다.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
```

이 설정을 해 두면 `cin`, `cout` 속도가 빨라져서 코테에서 거의 기본처럼 사용합니다.

---

## 0. 가장 기본 뼈대

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}
```

### 설명

* `#include <bits/stdc++.h>`: 자주 쓰는 헤더를 한 번에 포함
* `ios::sync_with_stdio(false);`
* `cin.tie(nullptr);`

이 2줄은 빠른 입출력을 위해 거의 항상 넣습니다.

---

## 1. 정수 1개 입력

### 입력 예시

```text
5
```

### 템플릿

```cpp
int n;
cin >> n;
```

### 설명

* 가장 기본적인 형태입니다.
* 보통 개수, 길이, 노드 수 등에 사용합니다.

---

## 2. 한 줄에 정수 여러 개 입력

### 입력 예시

```text
3 7
```

### 템플릿

```cpp
int n, m;
cin >> n >> m;
```

### 설명

* `N M`, `R C`, `A B` 같은 형태에서 자주 나옵니다.
* 공백과 줄바꿈은 `cin >>`이 자동으로 처리합니다.

---

## 3. 수열을 벡터로 입력

### 입력 예시

```text
5
1 2 3 4 5
```

### 템플릿

```cpp
int n;
cin >> n;

vector<int> arr(n);
for (int i = 0; i < n; i++) {
    cin >> arr[i];
}
```

### 설명

* 가장 흔한 배열 입력 방식입니다.
* `vector<int>`를 많이 씁니다.

---

## 4. 2차원 배열 입력

### 입력 예시

```text
3 3
1 2 3
4 5 6
7 8 9
```

### 템플릿

```cpp
int n, m;
cin >> n >> m;

vector<vector<int>> board(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> board[i][j];
    }
}
```

### 설명

* 행렬, 표, 지도 문제에서 자주 나옵니다.
* `board[i][j]`로 접근합니다.

---

## 5. 문자열 한 줄 입력

### 입력 예시

```text
algorithm
```

### 템플릿

```cpp
string s;
cin >> s;
```

### 설명

* 공백 없는 문자열일 때 사용합니다.
* 한 단어 입력이면 `cin >> s`로 충분합니다.

---

## 6. 공백이 포함된 한 줄 전체 입력

### 입력 예시

```text
hello world cpp
```

### 템플릿

```cpp
string s;
getline(cin >> ws, s);
```

### 설명

* 공백 포함 문자열을 통째로 읽을 때 사용합니다.
* `cin >> ws`를 붙이면 앞에 남아 있는 공백이나 개행을 정리해 줍니다.
* `getline`은 C++에서 꽤 자주 헷갈리는 부분이라 꼭 익혀 두는 것이 좋습니다.

---

## 7. 붙어 있는 숫자나 문자 한 글자씩 처리

### 입력 예시 1

```text
10101
```

### 템플릿 1

```cpp
string s;
cin >> s;

vector<int> arr;
for (char c : s) {
    arr.push_back(c - '0');
}
```

### 결과

```cpp
// [1, 0, 1, 0, 1]
```

### 입력 예시 2

```text
ABCDE
```

### 템플릿 2

```cpp
string s;
cin >> s;

for (char c : s) {
    cout << c << ' ';
}
```

### 설명

* 미로, 비트열, 문자열 탐색에서 자주 나옵니다.
* 숫자 문자 `'3'`을 정수 `3`으로 바꿀 때는 `c - '0'`을 씁니다.

---

## 8. 테스트케이스가 여러 개인 경우

### 입력 예시

```text
3
5
10
20
```

### 템플릿

```cpp
int t;
cin >> t;

while (t--) {
    int n;
    cin >> n;
    cout << n << '\n';
}
```

### 설명

* 첫 줄이 테스트케이스 수 `T`일 때 가장 흔한 형태입니다.
* `while (t--)`는 C++에서 매우 자주 씁니다.

---

## 9. 간선 정보나 쌍 데이터 여러 줄 입력

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

```cpp
int n;
cin >> n;

vector<pair<int, int>> edges;

for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges.push_back({a, b});
}
```

### 설명

* 좌표, 간선, 구간, 두 값 묶음 입력에 자주 씁니다.
* `pair<int, int>`는 C++ 코테에서 아주 많이 사용합니다.

---

## 10. 그래프를 인접 리스트로 입력

### 입력 예시

```text
5 4
1 2
1 3
2 4
3 5
```

### 템플릿

```cpp
int n, m;
cin >> n >> m;

vector<vector<int>> graph(n + 1);

for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a); // 무방향 그래프
}
```

### 설명

* DFS, BFS 문제에서 가장 많이 쓰는 그래프 저장 방식입니다.
* 방향 그래프면 `graph[a].push_back(b);`만 사용합니다.

---

# 자주 쓰는 실전형 템플릿 모음

## 1. `N`만 있는 경우

```cpp
int n;
cin >> n;
```

## 2. `N M` 형태

```cpp
int n, m;
cin >> n >> m;
```

## 3. 길이 `N`짜리 배열

```cpp
vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];
```

## 4. `N x M` 2차원 배열

```cpp
vector<vector<int>> board(n, vector<int>(m));
for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        cin >> board[i][j];
    }
}
```

## 5. 문자열 한 단어

```cpp
string s;
cin >> s;
```

## 6. 문자열 한 줄 전체

```cpp
string s;
getline(cin >> ws, s);
```

## 7. 테스트케이스 `T`

```cpp
int t;
cin >> t;
while (t--) {
    // solve
}
```

## 8. 간선 `M개`

```cpp
for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
}
```

## 9. 좌표 `N개`

```cpp
vector<pair<int, int>> points(n);
for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
}
```

## 10. 입력 끝까지 받기

```cpp
int x;
while (cin >> x) {
    cout << x << '\n';
}
```

---

# 코테에서 특히 많이 쓰는 형태 5개

아래 5개는 거의 외워 두면 편합니다.

```cpp
int n;
cin >> n;

int n, m;
cin >> n >> m;

vector<int> arr(n);
for (int i = 0; i < n; i++) cin >> arr[i];

string s;
cin >> s;

string line;
getline(cin >> ws, line);
```

---

# 자주 헷갈리는 포인트

## 1. `cin >> s` 와 `getline(cin, s)` 차이

### `cin >> s`

```cpp
string s;
cin >> s;
```

* 공백 전까지만 읽습니다.
* 예: `hello world` 입력 시 `hello`만 읽음

### `getline`

```cpp
string s;
getline(cin >> ws, s);
```

* 한 줄 전체를 읽습니다.
* 공백 포함 문자열에 사용합니다.

---

## 2. `cin` 다음에 바로 `getline` 쓰면 꼬일 수 있음

예를 들어

```cpp
int n;
cin >> n;

string s;
getline(cin, s);
```

이렇게 하면 `s`가 빈 문자열이 들어갈 수 있습니다.

그래서 보통 아래처럼 씁니다.

```cpp
getline(cin >> ws, s);
```

이 방식이 가장 안전합니다.

---

## 3. 출력은 `endl`보다 `'\n'`을 더 많이 씀

```cpp
cout << answer << '\n';
```

* `endl`은 줄바꿈 + 버퍼 비우기까지 해서 상대적으로 느릴 수 있습니다.
* 코테에서는 보통 `'\n'`을 더 많이 씁니다.

---

# 추천하는 C++ 코테 시작 템플릿

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    return 0;
}
```

---

# 한 줄 정리

C++ 코테 입력은 결국 아래 5개가 핵심입니다.

```cpp
cin >> n;
cin >> n >> m;
for (int i = 0; i < n; i++) cin >> arr[i];
cin >> s;
getline(cin >> ws, s);
```

이 다섯 개에 익숙해지면 대부분의 입력은 처리할 수 있습니다.
