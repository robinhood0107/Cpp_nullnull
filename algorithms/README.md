# 알고리즘 풀이

각 실행 대상은 저장소 루트의 공통 CMake에서 빌드합니다. `archive`의 이전 구현은 빌드 대상에 넣지 않습니다.

| 실행 대상 | 연습한 내용 | 코드 | 설명·데이터 | 검증 상태 |
|---|---|---|---|---|
| `dog_01_fishbun` | 부호 있는 구간 반전 | [소스](dogorithm/01fishbun/fishbun.cpp) | [fishbun문제 풀때 아이디어 및 관련 내용 설명 총합](dogorithm/01fishbun/fishbun%EB%AC%B8%EC%A0%9C%20%ED%92%80%EB%95%8C%20%EC%95%84%EC%9D%B4%EB%94%94%EC%96%B4%20%EB%B0%8F%20%EA%B4%80%EB%A0%A8%20%EB%82%B4%EC%9A%A9%20%EC%84%A4%EB%AA%85%20%EC%B4%9D%ED%95%A9.md) · [java와 cpp 아키텍쳐 일부분 비교설명](dogorithm/01fishbun/java%EC%99%80%20cpp%20%EC%95%84%ED%82%A4%ED%85%8D%EC%B3%90%20%EC%9D%BC%EB%B6%80%EB%B6%84%20%EB%B9%84%EA%B5%90%EC%84%A4%EB%AA%85.md) · [샘플](dogorithm/01fishbun) | 샘플·경계값 확인 |
| `dog_02_Quaindrome` | 투 포인터 회문·유사회문 판별 | [소스](dogorithm/02Quaindrome/Quaindrome.cpp) | [샘플](dogorithm/02Quaindrome) | 샘플·경계값 확인 |
| `dog_02_Quaindrome_modern` | 투 포인터 회문·유사회문 판별 | [소스](dogorithm/02Quaindrome/Quaindrome_modern.cpp) | [샘플](dogorithm/02Quaindrome) | 샘플·경계값 확인 |
| `dog_03_Container` | 토너먼트와 두 번째 최댓값 | [소스](dogorithm/03Container/Container.cpp) | [샘플](dogorithm/03Container) | 샘플·경계값 확인 |
| `dog_05_oilwell` | 대화형 유정 범위 이분 탐색 | [소스](dogorithm/05Oil_Well/oilwell.cpp) | [샘플](dogorithm/05Oil_Well) | 샘플·경계값 확인 |
| `dog_06_Seminar` | 분량 분배와 매개 변수 탐색 | [소스](dogorithm/06Seminar/Seminar.cpp) | [샘플](dogorithm/06Seminar) | 샘플·경계값 확인 |
| `dog_07_Cleaning` | 가중 구간 선택 DP와 동점 처리 | [소스](dogorithm/07Cleaning/Cleaning.cpp) | [cpp입출력](dogorithm/07Cleaning/cpp%EC%9E%85%EC%B6%9C%EB%A0%A5.md) · [java입출력](dogorithm/07Cleaning/java%EC%9E%85%EC%B6%9C%EB%A0%A5.md) · [python입출력](dogorithm/07Cleaning/python%EC%9E%85%EC%B6%9C%EB%A0%A5.md) · [샘플](dogorithm/07Cleaning) | 샘플·경계값 확인 |
| `dog_08_test` | 역방향 DP·준문자열·사전순 비교 | [소스](dogorithm/08Quasi_String/test.cpp) | [샘플](dogorithm/08Quasi_String) | 샘플·경계값 확인 |
| `dog_08_test_____c11_` | 역방향 DP·준문자열·사전순 비교 | [소스](dogorithm/08Quasi_String/test_%EA%B0%84%EB%9E%B5%ED%99%94_c11_.cpp) | [샘플](dogorithm/08Quasi_String) | 샘플·경계값 확인 |
| `dog_08_final` | 역방향 DP·준문자열·사전순 비교 | [소스](dogorithm/08Quasi_String/%EC%B5%9C%EC%A2%85.cpp) | [샘플](dogorithm/08Quasi_String) | 샘플·경계값 확인 |
| `dog_11_K_Diet` | 정렬과 식단 선택 | [소스](dogorithm/11K-Diet/K-Diet.cpp) | [샘플](dogorithm/11K-Diet) | 샘플·경계값 확인 |
| `dog_13_pipe` | 다중 시작점 다익스트라 | [소스](dogorithm/13Pipecleaning/pipe.cpp) | [샘플](dogorithm/13Pipecleaning) | 샘플·경계값 확인 |
| `dog_14_spiral` | 각도·외적을 이용한 나선 정렬 | [소스](dogorithm/14Spiral_Sort/spiral.cpp) | 코드 내 설명 | 빌드 확인 |
| `dog_18_invert` | 접미사 배열과 역순 반복 구간 | [소스](dogorithm/18/invert.cpp) | [실행 계약·원본 불일치 설명](dogorithm/18/README.md) | 독립 완전 탐색과 비교 |
| `dog_19_station` | 원 교집합과 탐색 범위 제한 | [소스](dogorithm/19/station.cpp) | [샘플](dogorithm/19) | 샘플·경계값 확인 |
| `boj1926` | BFS 연결 요소와 넓이 | [소스](baekjoon/1926/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `boj7576` | 다중 시작점 BFS와 거리 | [소스](baekjoon/7576/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj15649` | 재귀와 백트래킹 | [소스](baekjoon/15649/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj1463` | 동적 계획법: 1로 만들기 | [소스](baekjoon/1463/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj9095` | 동적 계획법: 1·2·3 더하기 | [소스](baekjoon/9095/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj11047` | 그리디 동전 선택 | [소스](baekjoon/11047/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `boj2346` | deque 회전과 풍선 순서 | [소스](baekjoon/2346/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `boj18187` | 직선 분할과 조합 계산 | [소스](baekjoon/18187/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `boj2738` | 2차원 배열 덧셈 | [소스](baekjoon/2738/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj28278` | stack 명령 처리 | [소스](baekjoon/28278/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `boj4949` | stack으로 괄호 쌍 검사 | [소스](baekjoon/4949/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `boj9935` | 문자열을 스택으로 사용 | [소스](baekjoon/9935/main.cpp) | 코드 내 설명 | 샘플·경계값 확인 |
| `study_bfs` | 격자 BFS 탐색 | [소스](study/bfs/main.cpp) | 코드 내 설명 | 빌드 확인 |
| `pccp_string` | 문자열 파싱과 다중 정렬 기준 | [소스](programmers/pccp-string/main.cpp) | 코드 내 설명 | 빌드 확인 |

실행 파일은 `out/build/<preset>/bin`에 생성됩니다. 빌드 성공과 정답 검증은 다르므로 [검증 기록](../docs/verification.md)을 함께 확인하세요.
