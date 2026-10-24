# C++ 문법별 연습

각 실행 대상은 저장소 루트의 공통 CMake에서 빌드합니다. `archive`의 이전 구현은 빌드 대상에 넣지 않습니다.

| 실행 대상 | 연습한 내용 | 코드 | 설명·데이터 | 검증 상태 |
|---|---|---|---|---|
| `example_format` | std::format 출력 형식 | [소스](modern-cpp/format/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic011` | 형 변환·실수 평균·출력 정밀도 | [소스](basics/lab011/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `basic012` | 학생 점수 입력·평균·정렬 | [소스](basics/lab012/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic013` | 실수 사칙연산과 iomanip | [소스](basics/lab013/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic014` | 포인터 매개변수와 값 변경 | [소스](basics/lab014/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `basic015` | 동적 배열과 간접 인덱싱 | [소스](basics/lab015/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic017` | unique_ptr 소유권과 get | [소스](basics/lab017/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic018` | 참조 매개변수와 swap | [소스](basics/lab018/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic021` | 동적 배열 역순 출력 | [소스](basics/lab021/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic022` | 2차원 vector 초기화 | [소스](basics/lab022/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic023` | std::array 정렬과 최솟값·최댓값 | [소스](basics/lab023/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic024` | 구조체 배열·비교 함수·정렬 | [소스](basics/lab024/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic025` | 가변 길이 2차원 vector와 조회 | [소스](basics/lab025/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic026` | 문자열 파싱과 erase-remove | [소스](basics/lab026/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic027` | vector 원소 삭제와 값 제거 | [소스](basics/lab027/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic028` | 문자 수 세기·대문자 변환·접두사 | [소스](basics/lab028/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic029` | enum class·map·별점 집계 | [소스](basics/lab029/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic031` | 조건문과 성적 분류 | [소스](basics/lab031/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic032` | 열거형과 switch 분기 | [소스](basics/lab032/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `basic033` | vector 입력·짝수/홀수 합·pair | [소스](basics/lab033/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `basic034` | enum class와 가위바위보 | [소스](basics/lab034/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic035` | 줄 단위 정수 파싱·최솟값·최댓값 | [소스](basics/lab035/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic036` | map 전화번호부 조회 | [소스](basics/lab036/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `basic037` | 입출력 반복자·copy·sort | [소스](basics/lab037/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `example_swap` | 참조 매개변수와 swap | [소스](basics/swap/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `example_new_delete` | new·delete와 동적 배열 | [소스](memory/new-delete/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `example_rvalue` | rvalue 참조와 임시 객체 | [소스](memory/rvalue/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `example_project_intro` | 문자열과 콘솔 출력 | [소스](basics/project-intro/main.cpp) | 코드 내 설명 | 빌드 확인 |

실행 파일은 `out/build/<preset>/bin`에 생성됩니다. 빌드 성공과 정답 검증은 다르므로 [검증 기록](../docs/verification.md)을 함께 확인하세요.
