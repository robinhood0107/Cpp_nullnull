
# C++ 예외 처리 및 템플릿 기초 정리 🧠💻

---

## ✅ 핵심 예외 처리 원칙

### 항상 기억할 것!
- **throw** 할 때는 반드시 `r-value`(주소 없는 값)로 던져라.
- **catch**로 받을 때는 **reference(참조자)** 형태로 받아라. (`자료형&`)
  - 예시: `catch(const std::exception& e)`

---

## 🧩 템플릿 사용 팁

- 템플릿을 만들기 전에 **항상 원본 함수(int 등)** 로 먼저 작성해볼 것.
- 그 후 **template** 으로 일반화하면 쉬워진다.
- 예시:
  ```cpp
  throw std::out_of_range("string");
  ```

---

## 🛠️ 팁: 클래스 예외 출력 문제 대비!

### 예외 발생 코드 예시
```cpp
throw AAA("하고싶은 말");
```

> **문제**: 이 예외 클래스를 작성하라고 하면?

### ✅ 정답 예시
```cpp
class AAA {
public:
    std::string str;
    AAA(std::string s) : str(s) {}
    std::string what() { return str; }
};

try {
    throw AAA("하고싶은 말");
} catch (AAA& e) { // ❗ const 붙이면 안됨!!
    std::cout << e.what() << std::endl;
}
```

---

## 📂 파일 입출력 예외 처리 방법

- `ifstream` 이 자체적으로 예외를 throw 해주는 구조임!
- 우리는 그 예외를 **catch**만 하면 됨.

### 파일 예외 활성화 방법
```cpp
std::ifstream fin;
fin.exceptions(std::ios_base::failbit | std::ios_base::badbit);
```

---

## 🔁 예외는 어디서 catch 해야 하나?

> **항상 main()에서 try-catch 하자.**

예시:
```cpp
void print2() {
    throw std::ios_base::failure("AAAA");
}

void print() {
    print2();
}

int main() {
    try {
        print();
    } catch (std::ios_base::failure& e) {
        std::cerr << e.what() << std::endl;
    }
}
```

- **print2**에서 throw 해도,
- **print**를 통해 호출되면,
- **main**에서 try-catch로 처리 가능!
- 따라서 항상 **main**에 try-catch 걸자!!

---

## ✨ 기타 참고 사항

- 모든 예외를 다 받고 싶을 때:
  ```cpp
  try {
      // ...
  } catch (...) {
      std::cerr << "모든 예외를 잡음!" << std::endl;
  }
  ```

---

## 📝 언어 공부 꿀팁

- **시험 기간엔 동영상 보지 마라!**
  - 제대로 이해 못하고 시간만 낭비함.
- **직접 코딩하며 어려운 개념 위주로 연습하라.**

---

## 📱 안드로이드에서의 preload와 예외

- **프리로딩 구현 팁**
  - 예외를 **제일 마지막 실행 함수에 throw**로 걸어두자.
  - throw가 발생할 때까지 preload() 함수들이 미리 실행됨.
  - throw가 발생하면 main의 catch에서 받아서 **run()만 실행**.

```cpp
void preload1();
void preload2();
void preloadFinal() { throw std::runtime_error("preloaded"); }

int main() {
    try {
        preload1();
        preload2();
        preloadFinal(); // 이 시점에서 throw 발생
    } catch (...) {
        run(); // 이제 run()은 바로 실행됨!
    }
}
```

> ❗ 유지보수 편하고 실행속도도 빠른 구조!

---

### `std::ios::failure`란?

- 파일 읽기/쓰기 중 에러가 생기면 발생하는 예외
- **파일 자체가 없음** → 이 경우는 `std::ios::failure` 아님!

### 예외 받을 땐 왜 `const&`?
- 복사 비용 줄이고 정보 손실 막기 위해 `const&` 사용!

### 예외 전파란? (try catch 문은 무조건 main에 적어주자)
- throw가 상위 함수로 계속 전달됨 → 결국 `main()`까지!
- 즉  
- throw 하고 나서는 무조건 try catch문으로 받아야 한다. 
- **throw 하고나서 try catch문 안쓰면 terminate 된다. os에서 강제로 프로그램을 죽여버림** 
- → 프로그램이 죽어버려서 자원들(메모리) 회수도 못하고 아무것도 못해짐. 
- (즉, 컴퓨터와 코딩 입에서는 정말로 최악의 상황이므로 반드시 피하기)

### 예외 강제 발생: `exceptions()` 사용법

```cpp
#include <fstream>
#include <iostream>
#include <stdexcept>

int main() {
    std::ifstream myFile;
    myFile.exceptions(std::ios_base::badbit | std::ios_base::failbit);

    try {
        myFile.open("정말없는파일.txt");
        std::cout << "파일 열기 성공!" << std::endl;
    } catch (const std::ios_base::failure& e) {
        std::cerr << "파일 열기 실패! 에러 메시지: " << e.what() << std::endl;
    }

    return 0;
}
```

---

## 🎯 마무리 핵심 정리

- **예외는 항상 main에서 처리해라.**
- **파일 열기 실패 감지에는 exceptions() 사용하라.**
- **예외 클래스 출력 문제 대비 연습해라.**
- **예외 받을 땐 const& (단, 커스텀 클래스는 const 없이도 연습 필요)**
- **시험기간엔 동영상 X, 직접 코딩 O**
- **템플릿 사용 전 일반 버전 먼저!**
