# Windows 10·VS2022 최초 설치

Windows 10 Pro 22H2 x64와 VS2022를 기준으로 합니다. 프로그램 설치에는 관리자 권한이 필요할 수 있으며, 설치 프로그램이 요구하면 재부팅한 뒤 진행합니다. 프로젝트 스크립트는 프로그램을 자동 설치하거나 시스템 설정을 영구 변경하지 않습니다.

## 필수 프로그램

| 프로그램 | 설치할 구성 | 공식 안내 |
|---|---|---|
| Visual Studio 2022 | **C++를 사용한 데스크톱 개발**, **MSVC v143 x64/x86**, **Windows 10/11 SDK**, **Windows용 C++ CMake 도구** | [VS2022 설치](https://learn.microsoft.com/visualstudio/install/install-visual-studio?view=vs-2022) |
| Git for Windows | 기본 설치 옵션 | [Git](https://git-scm.com/downloads/win) |
| CMake 3.28 이상 | 설치 시 **Add CMake to PATH** 선택 | [CMake](https://cmake.org/download/) |
| Ninja | ninja.exe가 PATH에 있어야 함 | [Ninja 릴리스](https://github.com/ninja-build/ninja/releases) |
| VS Code | C/C++, CMake Tools 확장 | [VS Code](https://code.visualstudio.com/download) |

VS2022에서 함께 설치한 CMake·Ninja가 Developer Command Prompt에 잡히면 별도로 중복 설치할 필요는 없습니다. Visual Studio Installer의 **수정 → 개별 구성 요소**에서 SDK·CMake 도구가 빠지지 않았는지 확인합니다. 다른 최신 Visual Studio 버전으로 대체하지 않고 VS2022와 v143을 선택합니다.

## CMake·Ninja를 별도로 설치해야 할 때

VS2022 Installer에서 **Windows용 C++ CMake 도구**를 선택한 경우 동봉 도구를 먼저 사용합니다. x64 개발자 명령 프롬프트의 `cmake --version`, `where ninja`가 동작하면 다음 별도 설치는 생략합니다.

- CMake가 없거나 3.28보다 낮다면 공식 다운로드의 Windows x64 설치 프로그램을 실행하고 **Add CMake to PATH**를 선택합니다.
- Ninja가 없다면 공식 릴리스에서 **ninja-win.zip**을 받아 `C:\Tools\ninja` 같은 폴더에 풉니다. 해당 폴더 바로 아래에 `ninja.exe`가 있어야 합니다.
- 시작 메뉴에서 **계정의 환경 변수 편집 → 사용자 변수 Path → 편집 → 새로 만들기**로 `C:\Tools\ninja`를 추가합니다. 기존 항목은 유지하며 실행 파일이 아닌 폴더 경로를 추가합니다.
- 터미널을 새로 열어 `where ninja`, `ninja --version`을 확인합니다. VS Code 설치 시에도 **Add to PATH**를 선택하고 새 터미널의 `code --version`으로 확인합니다.

## 저장소 받기

```powershell
git clone https://github.com/robinhood0107/Cpp_nullnull.git
cd Cpp_nullnull
```

GitHub의 **Code → Download ZIP**으로 받아 압축을 풀어도 됩니다. 다운로드한 파일이 차단돼 있다면 파일 속성에서 차단을 해제하거나 다음 명령을 사용합니다.

```powershell
Unblock-File .\scripts\setup.ps1
```

## 일반 PowerShell에서 한 번에 설정

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup.ps1
```

설치 스크립트는 VS2022 위치를 찾고 현재 프로세스의 x64 MSVC 환경을 준비합니다. 이어서 PDCurses 3.9를 SHA-256으로 확인해 받아 빌드하고 Debug·Release 전체 빌드와 CTest를 실행합니다. 경로에 공백이 있어도 사용할 수 있습니다. 재실행 시 기존 빌드 결과를 활용하며 실패한 명령을 성공으로 처리하지 않습니다.

실행 정책 변경은 해당 PowerShell 프로세스에만 적용합니다. 시스템 전체의 실행 정책이나 PATH를 바꿀 필요가 없습니다.

## 스크립트 없이 수동 설정

시작 메뉴에서 **x64 Native Tools Command Prompt for VS 2022**를 엽니다. 저장소 루트로 이동합니다.

```bat
cd /d C:\path\to\Cpp_nullnull
where cl
where rc
where mt
cmake --version
ninja --version
cmake --preset windows-debug
cmake --build --preset windows-debug --parallel 2
ctest --preset windows-debug
cmake --preset windows-release
cmake --build --preset windows-release --parallel 2
ctest --preset windows-release
```

최초 CMake 구성에서 PDCurses를 자동으로 준비하므로 MSYS2·MinGW를 별도로 설치할 필요가 없습니다. 오프라인 최초 구성은 지원하지 않습니다.

## 실행

```bat
out\build\windows-debug\bin\example_new_delete.exe
echo 2 9 | out\build\windows-debug\bin\example_swap.exe
out\build\windows-debug\bin\assignment05.exe
```

테트리스는 실제 콘솔에서 방향키·Space·`q`를 사용합니다. 파일 기반 예제는 [Ubuntu 안내의 파일을 읽는 예제](setup-ubuntu.md#파일을-읽는-예제)와 같은 작업 디렉터리를 사용합니다.

## 문제 해결

- `cl.exe` 없음: MSVC v143과 C++ 데스크톱 워크로드를 설치합니다.
- `rc.exe` 또는 `mt.exe` 없음: Windows SDK를 설치합니다. 일반 PowerShell 대신 x64 개발자 명령 프롬프트에서 확인합니다.
- Ninja 없음: CMake 도구 구성 요소를 설치하거나 공식 Ninja의 위치를 PATH에 등록한 뒤 터미널을 새로 엽니다.
- 다운로드 실패: 공식 다운로드 호스트에 접근 가능한지 확인하고 같은 명령을 재실행합니다. 해시가 맞지 않는 소스는 사용하지 않습니다.
- 일반 실행 파일 검색이 안 됨: `PATHEXT`에 `.EXE;.COM;.BAT;.CMD`가 있는지 확인합니다. 프로젝트 스크립트는 현재 프로세스에서만 보충합니다.

[VS2022·VS Code 디버깅 안내](editors.md)

개별 구성만 검증하려면 저장소 루트 PowerShell에서 아래 명령 중 하나를 사용합니다.

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup.ps1 -Configuration Debug
powershell -NoProfile -ExecutionPolicy Bypass -File .\scripts\setup.ps1 -Configuration Release
```

기본 Both에서는 한 구성의 테스트가 실패해도 다른 구성까지 확인한 뒤 실패로 종료합니다.
