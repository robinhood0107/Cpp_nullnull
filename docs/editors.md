# VS2022·VS Code 실행과 디버깅

먼저 [Windows](setup-windows.md) 또는 [Ubuntu](setup-ubuntu.md)의 설치·빌드를 마치고 테스트 결과를 확인합니다. invert의 원본 자료 불일치와 별도 검산 범위는 [검증 기록](verification.md)을 참고합니다. 편집기 자체에는 컴파일러가 포함되지 않습니다.

## Visual Studio 2022

1. **파일 → 열기 → 폴더**로 저장소 루트를 엽니다. 과거 .sln 파일 대신 공통 CMake를 사용합니다.
2. CMake 구성에서 `windows-debug` preset을 선택합니다. preset이 보이지 않으면 **도구 → 옵션 → CMake → 일반**의 CMakePresets 사용을 확인합니다.
3. 구성 완료 후 **빌드 → 모두 빌드**를 실행합니다.
4. 시작 항목을 `example_new_delete.exe` 또는 `my_string_demo.exe`로 선택합니다.
5. 해당 main 함수 안에 중단점을 넣고 F5로 실행합니다. 변수 창에서 값을 확인하고 F10으로 한 줄씩 진행합니다.
6. 입력이 필요한 예제와 테트리스는 콘솔에서 입력합니다. 실행 파일은 preset별 bin 디렉터리에 있습니다.

Windows의 Linux 개발 워크로드를 설치하지 않아도 Windows 빌드는 가능합니다. Linux 빌드는 Ubuntu·WSL에서 같은 소스를 사용합니다.

## Visual Studio Code

최초 실행 때 계정 선택 화면이 나타나면 **Continue without Signing In**으로 편집기에 진입합니다. 로컬 C++ 빌드·디버깅은 계정 로그인 없이 사용할 수 있습니다.

1. **C/C++**(`ms-vscode.cpptools`), **CMake Tools**(`ms-vscode.cmake-tools`)를 설치합니다. 저장소에서 권장 확장으로 표시됩니다.
2. Windows에서는 x64 개발자 명령 프롬프트에서 `code .`로 엽니다. Ubuntu에서는 저장소 루트에서 `code .`를 실행합니다. WSL에서는 Windows용 VS Code에 Remote - WSL 확장을 설치하고 Ubuntu 쪽 폴더를 엽니다. C/C++·CMake Tools도 확장 창의 **WSL: Ubuntu에 설치**로 WSL 쪽에 설치합니다.
3. **CMake: Select Configure Preset**에서 OS에 맞는 Debug preset을 선택합니다.
4. **CMake: Configure**, **CMake: Build**를 실행합니다.
5. **CMake: Set Debug Target**에서 `example_new_delete` 또는 `my_string_demo`를 선택합니다.
6. main 내부에 중단점을 놓고 **CMake: Debug**를 실행합니다. Windows는 MSVC 디버거, Ubuntu는 GDB를 사용합니다.
7. CMake 사이드바 또는 **CMake: Run Tests**에서 CTest 결과를 확인합니다.

IntelliSense는 CMake Tools의 실제 컴파일 설정을 사용합니다. 개인 컴파일러 경로를 c_cpp_properties.json에 하드코딩하지 않습니다.

설치·빌드 성공과 실제 IDE 중단점 검증은 별개이며, 실행한 결과는 [검증 기록](verification.md)에 표시합니다.
