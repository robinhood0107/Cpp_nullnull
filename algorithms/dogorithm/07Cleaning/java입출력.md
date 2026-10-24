# Java 코테에서 자주 나오는 입력 유형별 템플릿 10개

Java 코딩테스트에서는 보통 **`BufferedReader + StringTokenizer`** 조합을 가장 많이 씁니다.
`Scanner`도 가능하지만 대체로 더 느려서, 실전에서는 `BufferedReader` 쪽이 더 자주 쓰입니다.

---

## 0. 가장 기본 뼈대

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    }
}
```

### 설명

* `BufferedReader`: 빠른 입력
* `StringTokenizer`: 공백 기준 분리
* `throws Exception`: 예외 처리 간단화

---

## 1. 정수 1개 입력

### 입력 예시

```text
5
```

### 템플릿

```java
int n = Integer.parseInt(br.readLine());
```

### 설명

* 가장 기본적인 형태입니다.
* 개수, 길이, 노드 수 등에 자주 씁니다.

---

## 2. 한 줄에 정수 여러 개 입력

### 입력 예시

```text
3 7
```

### 템플릿

```java
StringTokenizer st = new StringTokenizer(br.readLine());
int n = Integer.parseInt(st.nextToken());
int m = Integer.parseInt(st.nextToken());
```

### 설명

* `N M`, `R C`, `A B` 같은 형태에 자주 나옵니다.
* Java 코테에서 가장 흔한 패턴 중 하나입니다.

---

## 3. 수열 한 줄을 배열로 입력

### 입력 예시

```text
5
1 2 3 4 5
```

### 템플릿

```java
int n = Integer.parseInt(br.readLine());
int[] arr = new int[n];

StringTokenizer st = new StringTokenizer(br.readLine());
for (int i = 0; i < n; i++) {
    arr[i] = Integer.parseInt(st.nextToken());
}
```

### 설명

* 배열, 점수 목록, 수열 입력에서 자주 씁니다.

---

## 4. 여러 줄의 2차원 배열 입력

### 입력 예시

```text
3 3
1 2 3
4 5 6
7 8 9
```

### 템플릿

```java
StringTokenizer st = new StringTokenizer(br.readLine());
int n = Integer.parseInt(st.nextToken());
int m = Integer.parseInt(st.nextToken());

int[][] board = new int[n][m];

for (int i = 0; i < n; i++) {
    st = new StringTokenizer(br.readLine());
    for (int j = 0; j < m; j++) {
        board[i][j] = Integer.parseInt(st.nextToken());
    }
}
```

### 설명

* 행렬, 지도, 표 문제에서 자주 나옵니다.

---

## 5. 문자열 한 줄 입력

### 입력 예시

```text
algorithm
```

### 템플릿

```java
String s = br.readLine();
```

### 설명

* 한 줄 문자열 입력입니다.
* 공백 없는 문자열도, 공백 포함 한 줄도 `readLine()`으로 받을 수 있습니다.

---

## 6. 붙어 있는 숫자나 문자를 한 글자씩 처리

### 입력 예시 1

```text
10101
```

### 템플릿 1

```java
String s = br.readLine();
int[] arr = new int[s.length()];

for (int i = 0; i < s.length(); i++) {
    arr[i] = s.charAt(i) - '0';
}
```

### 결과

```java
// [1, 0, 1, 0, 1]
```

### 입력 예시 2

```text
ABCDE
```

### 템플릿 2

```java
String s = br.readLine();

for (int i = 0; i < s.length(); i++) {
    char c = s.charAt(i);
    System.out.print(c + " ");
}
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

```java
int t = Integer.parseInt(br.readLine());

while (t-- > 0) {
    int n = Integer.parseInt(br.readLine());
    System.out.println(n);
}
```

### 설명

* 첫 줄이 테스트케이스 수 `T`인 경우입니다.
* `while (t-- > 0)` 또는 `for`문을 자주 씁니다.

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

```java
int n = Integer.parseInt(br.readLine());
List<int[]> pairs = new ArrayList<>();

for (int i = 0; i < n; i++) {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
    pairs.add(new int[]{a, b});
}
```

### 설명

* 좌표, 간선, 구간, 두 값 묶음 입력에 자주 씁니다.
* 필요하면 `int[]` 대신 `Point`, `Pair` 비슷한 클래스를 직접 만들어도 됩니다.

---

## 9. 그래프를 인접 리스트로 입력

### 입력 예시

```text
5 4
1 2
1 3
2 4
3 5
```

### 템플릿

```java
StringTokenizer st = new StringTokenizer(br.readLine());
int n = Integer.parseInt(st.nextToken());
int m = Integer.parseInt(st.nextToken());

List<Integer>[] graph = new ArrayList[n + 1];
for (int i = 0; i <= n; i++) {
    graph[i] = new ArrayList<>();
}

for (int i = 0; i < m; i++) {
    st = new StringTokenizer(br.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());

    graph[a].add(b);
    graph[b].add(a); // 무방향 그래프
}
```

### 설명

* DFS, BFS 문제에서 가장 많이 쓰는 그래프 저장 방식입니다.
* 방향 그래프면 `graph[a].add(b);`만 사용합니다.

---

## 10. 입력 끝까지 받기

### 입력 예시

```text
1
2
3
4
```

### 템플릿

```java
String line;
while ((line = br.readLine()) != null) {
    int x = Integer.parseInt(line);
    System.out.println(x);
}
```

### 설명

* EOF까지 입력받는 문제에서 사용합니다.
* 백준 일부 문제에서 자주 보입니다.

---

# 자주 쓰는 실전형 템플릿 모음

## 1. `N`만 있는 경우

```java
int n = Integer.parseInt(br.readLine());
```

## 2. `N M` 형태

```java
StringTokenizer st = new StringTokenizer(br.readLine());
int n = Integer.parseInt(st.nextToken());
int m = Integer.parseInt(st.nextToken());
```

## 3. 수열 한 줄

```java
int[] arr = new int[n];
StringTokenizer st = new StringTokenizer(br.readLine());
for (int i = 0; i < n; i++) {
    arr[i] = Integer.parseInt(st.nextToken());
}
```

## 4. `N x M` 2차원 배열

```java
int[][] board = new int[n][m];
for (int i = 0; i < n; i++) {
    StringTokenizer st = new StringTokenizer(br.readLine());
    for (int j = 0; j < m; j++) {
        board[i][j] = Integer.parseInt(st.nextToken());
    }
}
```

## 5. 문자열 한 줄

```java
String s = br.readLine();
```

## 6. 테스트케이스 `T`

```java
int t = Integer.parseInt(br.readLine());
while (t-- > 0) {
    // solve
}
```

## 7. 간선 `M개`

```java
for (int i = 0; i < m; i++) {
    StringTokenizer st = new StringTokenizer(br.readLine());
    int a = Integer.parseInt(st.nextToken());
    int b = Integer.parseInt(st.nextToken());
}
```

## 8. 좌표 `N개`

```java
int[][] points = new int[n][2];
for (int i = 0; i < n; i++) {
    StringTokenizer st = new StringTokenizer(br.readLine());
    points[i][0] = Integer.parseInt(st.nextToken());
    points[i][1] = Integer.parseInt(st.nextToken());
}
```

## 9. 붙어 있는 숫자 문자열

```java
String s = br.readLine();
for (int i = 0; i < s.length(); i++) {
    int num = s.charAt(i) - '0';
}
```

## 10. EOF까지 입력

```java
String line;
while ((line = br.readLine()) != null) {
    // 처리
}
```

---

# 코테에서 특히 많이 쓰는 형태 5개

아래 5개는 거의 외워 두면 편합니다.

```java
int n = Integer.parseInt(br.readLine());

StringTokenizer st = new StringTokenizer(br.readLine());
int n = Integer.parseInt(st.nextToken());
int m = Integer.parseInt(st.nextToken());

int[] arr = new int[n];
st = new StringTokenizer(br.readLine());
for (int i = 0; i < n; i++) {
    arr[i] = Integer.parseInt(st.nextToken());
}

String s = br.readLine();

List<Integer>[] graph = new ArrayList[n + 1];
```

---

# 자주 헷갈리는 포인트

## 1. `BufferedReader`와 `Scanner` 차이

### `Scanner`

```java
Scanner sc = new Scanner(System.in);
int n = sc.nextInt();
```

* 문법은 쉽습니다.
* 다만 코테에서는 상대적으로 느릴 수 있습니다.

### `BufferedReader`

```java
BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
int n = Integer.parseInt(br.readLine());
```

* 더 빠릅니다.
* 그래서 실전에서는 더 많이 씁니다.

---

## 2. `readLine()`은 문자열로 읽는다

```java
String s = br.readLine();
```

* `readLine()`은 항상 문자열입니다.
* 숫자로 쓰려면 직접 바꿔야 합니다.

```java
int n = Integer.parseInt(br.readLine());
long x = Long.parseLong(br.readLine());
```

---

## 3. 공백으로 나뉜 입력은 `StringTokenizer`

```java
StringTokenizer st = new StringTokenizer(br.readLine());
int a = Integer.parseInt(st.nextToken());
int b = Integer.parseInt(st.nextToken());
```

* Java 코테에서 거의 기본 패턴입니다.

---

## 4. 출력이 많으면 `StringBuilder`를 자주 쓴다

출력이 많을 때는 `System.out.println()`을 반복하기보다 `StringBuilder`를 자주 씁니다.

```java
StringBuilder sb = new StringBuilder();
sb.append("Hello").append('\n');
sb.append("World").append('\n');

System.out.print(sb);
```

### 설명

* 출력 횟수가 많을수록 더 유리한 경우가 많습니다.
* 백준 같은 환경에서 특히 자주 씁니다.

---

# 추천하는 Java 코테 시작 템플릿

```java
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(st.nextToken());
        }

        StringBuilder sb = new StringBuilder();
        sb.append(n).append(' ').append(m).append('\n');

        System.out.print(sb);
    }
}
```

---

# 한 줄 정리

Java 코테 입력은 결국 아래 4개가 핵심입니다.

```java
Integer.parseInt(br.readLine())
StringTokenizer st = new StringTokenizer(br.readLine())
st.nextToken()
StringBuilder sb = new StringBuilder()
```

이 네 가지에 익숙해지면 대부분의 입력과 출력은 처리할 수 있습니다.