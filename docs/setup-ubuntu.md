# Ubuntu 24.04 최초 설치

Ubuntu 24.04 LTS x64의 기본 설치 상태에서 시작합니다. WSL2의 Ubuntu 24.04도 같은 명령을 사용합니다. 관리자 권한을 가진 사용자와 인터넷 연결이 필요합니다. `/etc/os-release`에서 버전을 확인합니다.

## 저장소 받기

Git이 없다면 GitHub 페이지의 **Code → Download ZIP**으로 받아 압축을 풀어도 됩니다. Git을 쓰려면 다음과 같이 설치하고 복제합니다.

```bash
sudo apt-get update
sudo apt-get install -y git
git clone https://github.com/robinhood0107/Cpp_nullnull.git
cd Cpp_nullnull
```

작업 브랜치를 검토할 때는 해당 브랜치를 checkout합니다. ZIP의 디렉터리 이름에는 브랜치 이름이 붙을 수 있습니다.

## 자동 설정

```bash
bash scripts/setup.sh
```

GCC 13·CMake·Ninja·GDB·ncurses 개발 패키지를 확인하고 없는 패키지만 설치합니다. 이어서 Debug·Release를 빌드하고 테스트합니다. 실패하면 종료 코드가 0이 아니며, 출력된 실패를 해결한 뒤 같은 명령으로 재실행합니다.

## 스크립트 없이 수동 설치

```bash
sudo apt-get update
sudo apt-get install -y build-essential g++-13 cmake ninja-build gdb git pkg-config libncurses-dev
cmake --version
ninja --version
g++-13 --version
gdb --version
```

CMake는 3.28 이상이어야 합니다. Ubuntu 24.04 패키지를 사용하면 별도 패키지 저장소가 필요하지 않습니다.

저장소 루트에서 다음 명령을 순서대로 실행합니다.

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug --parallel 2
ctest --preset linux-debug
cmake --preset linux-release
cmake --build --preset linux-release --parallel 2
ctest --preset linux-release
```

## VS Code 최초 설치

일반 Ubuntu 데스크톱에서는 [VS Code 공식 다운로드](https://code.visualstudio.com/download)의 Linux **.deb / x64** 파일을 받습니다. 다운로드 폴더에서 실제 받은 파일명으로 설치하고 버전을 확인합니다.

```bash
(
cd ~/Downloads
sudo apt install ./code_*_amd64.deb
code --version
)
```

WSL2에서는 Linux용 VS Code를 별도 설치하지 않습니다. Windows에 VS Code를 설치하고 **Remote - WSL** 확장을 추가한 뒤 Ubuntu 터미널의 저장소 루트에서 `code .`를 실행합니다. 확장 창에서 C/C++와 CMake Tools를 **WSL: Ubuntu에 설치**합니다. 일반 Ubuntu에서도 두 확장을 설치해야 합니다.

## 실행과 디버깅

```bash
./out/build/linux-debug/bin/example_new_delete
printf '2 9\n' | ./out/build/linux-debug/bin/example_swap
gdb ./out/build/linux-debug/bin/example_new_delete
```

GDB에서 `break main`, `run`, `next`, `quit`를 사용합니다. VS Code 사용법은 [IDE 안내](editors.md)를 참고합니다.

## 테트리스

```bash
./out/build/linux-debug/bin/assignment05
```

실제 터미널에서 실행합니다. 방향키는 이동·회전, Space는 내리기, `q`는 종료입니다. 최소 80×30 터미널을 권장합니다. 최초 단계인 assignment02는 고정 보드 표시와 `q` 종료만 구현합니다.

## 파일을 읽는 예제

`dog_18_invert`는 실행하는 디렉터리의 `S.txt`를 사용합니다.

```bash
cd algorithms/dogorithm/18
../../../out/build/linux-debug/bin/dog_18_invert < 01.inp
```

원본 정답 파일과의 불일치는 [검증 기록](verification.md)을 확인합니다. `lab038`은 비교할 파일 경로 두 개를 인자로 받습니다. `lab112`는 의도적으로 파일 열기 오류를 관찰하는 실습입니다.

## 문제 해결

- `Curses`를 찾지 못함: `libncurses-dev` 설치 여부를 확인합니다.
- 다른 컴파일러로 만든 캐시 충돌: 별도 preset 디렉터리를 사용합니다. 필요한 경우 `cmake --fresh --preset linux-debug`로 캐시만 다시 구성합니다.
- 입력 대기: 해당 예제의 문제 설명이나 테스트 입력을 확인합니다. 모든 예제가 자동으로 종료되는 데모는 아닙니다.

개별 구성만 검증하려면 `bash scripts/setup.sh Debug` 또는 `bash scripts/setup.sh Release`를 사용합니다. 기본 Both에서는 한 구성의 테스트가 실패해도 다른 구성까지 확인한 뒤 실패로 종료합니다.
