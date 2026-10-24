# C++ 학습과 구현

C++ 문법, 대학 실습과 과제, 알고리즘 풀이, 문자열 클래스 구현을 정리한 저장소입니다. 같은 소스를 Linux·VS2022·VS Code에서 빌드합니다.

## 대표 구현

| 구현 | 연습한 내용 | 바로가기 |
|---|---|---|
| 테트리스 과제 02→05 | 보드·충돌·회전·게임 상태·터미널 입출력 | [진행 단계](coursework/assignments/tetris) |
| 조직 구조 | 상속·다형성·unique_ptr 소유권 이동 | [소스·문제](coursework/assignments/organization) |
| 행렬과 제네릭 리스트 | 연산자 오버로딩·템플릿·범위 검사 | [행렬](coursework/assignments/matrix) · [리스트](coursework/assignments/generic-list) |
| 문자열 클래스 | 동적 메모리·깊은 복사·자기대입 | [CMyString](projects/my-string) |
| Cleaning / 토마토 | 가중 구간 DP·다중 시작점 BFS | [Cleaning](algorithms/dogorithm/07Cleaning) · [백준 7576](algorithms/baekjoon/7576) |

## 현재 검증 상태

Linux·Windows 호스트의 Debug/Release 전체 빌드와 각각 74개 CTest, 양쪽 운영체제 일반 CI와 Ubuntu 기본 이미지 설치 CI가 통과했습니다. 새 VM·IDE별 결과는 [검증 기록](docs/verification.md)에 구분합니다.

`invert`는 원본 정답 2개와 `S.txt`가 맞지 않아 원본을 보존하고 별도 `.verified.out`을 사용합니다. [명시한 실행 계약과 독립 완전 탐색](algorithms/dogorithm/18/README.md)으로 검산했으며, 확보하지 못한 공식 문제의 정답 확인과는 구분합니다.

## 처음 시작하기

- [Windows 10·VS2022: 필수 프로그램과 수동 설치](docs/setup-windows.md)
- [Ubuntu 24.04: 패키지와 수동 설치](docs/setup-ubuntu.md)
- [VS2022·VS Code: 실행과 디버깅](docs/editors.md)

필수 프로그램 설치 후 Windows PowerShell에서:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup.ps1
```

Ubuntu 터미널에서:

```bash
bash scripts/setup.sh
```

두 스크립트는 Debug·Release 전체 빌드와 CTest를 실행합니다. Ubuntu에서는 필요한 패키지도 설치합니다. 소스 파일이나 원본 저장소는 변경하지 않습니다. 인터넷 연결이 필요하며 Windows는 최초 PDCurses 다운로드가 있습니다.

## 분야별 목차

| 분야 | 연습한 내용 | 상세 목차 |
|---|---|---|
| C++ 문법 | 기본 자료형·입출력·포인터·참조·컨테이너·동적 메모리·format | [예제](examples/README.md) |
| 대학 실습·과제 | 클래스·상속·가상 함수·템플릿·반복자·예외·객체 소유권 | [실습 번호별 목차](coursework/README.md) |
| 알고리즘 | BFS·백트래킹·DP·그리디·이분 탐색·문자열·기하 | [문제별 목차](algorithms/README.md) |
| 작은 프로젝트 | 문자열의 값 복사와 메모리 관리 | [프로젝트](projects/README.md) |
| 개념 정리 | 예외·initializer_list·가변 인자·Concepts·알고리즘 메모 | [개념 목차](notes/README.md) |
| 원본·변형 | IDE별 다른 풀이와 구현 전 원본 | [보존 방식](archive/README.md) |

## 빌드·테스트·검증

지원 기준은 Windows 10 Pro 22H2 x64 + VS2022 MSVC v143, Ubuntu 24.04 LTS x64 + GCC 13입니다. CMake 3.28 이상과 C++20을 사용합니다.

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug --parallel 2
ctest --preset linux-debug
./out/build/linux-debug/bin/example_new_delete
```

Windows는 `x64 Native Tools Command Prompt for VS 2022`에서 `windows-debug` preset과 `.exe` 실행 파일을 사용합니다. Windows 도구가 없는 일반 PowerShell에서는 설치 스크립트가 MSVC 환경을 준비합니다.

**현재 확인된 결과와 미검증 항목은 [검증 기록](docs/verification.md)에 구분합니다.** 빌드만 통과한 예제를 정답 검증 완료로 표시하지 않습니다.

## 기존 자료 찾기

`Algorithm`과 `Cpp_Project_collection`의 과거 커밋을 함께 보존합니다. 독립적인 Python 학습 폴더는 현재 파일 배치에서 제외했으며, 같은 문제의 비교 풀이는 문제 폴더에 남겼습니다.

- [기존 경로 → 현재 경로](docs/migration.md)
- [원본 커밋·파일 해시](docs/migration-manifest.json)
- [실행 대상 목록](docs/targets.json)
