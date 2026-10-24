# 검증 기록

실제로 실행한 범위와 자료의 한계를 구분합니다. Windows·Ubuntu의 수동·스크립트 경로 검증을 완료했습니다. 검증용 VM·설치 이미지는 삭제했으며, Windows가 잠근 임시 DLL 한 개는 다음 로그인 정리를 예약했습니다.

| 구분 | 현재 상태 |
|---|---|
| Linux GCC 13 Debug/Release 전체 빌드·CTest | 각각 74개 모두 통과 |
| Windows MSVC Debug/Release 전체 빌드·CTest | 각각 74개 모두 통과 |
| Ubuntu 24.04 새 VM의 수동 설치·빌드 | 패키지 설치·전체 빌드·두 구성 각각 74개 통과 |
| Ubuntu 24.04 새 VM의 스크립트 설치·빌드 | 다른 초기 VM에서 패키지 설치·전체 빌드·두 구성 각각 74개 통과 |
| Windows 10 22H2 새 VM | 스크립트 VM과 독립 수동 VM에서 Debug/Release 각각 74개 모두 통과 |
| 일반 CI 및 Ubuntu 기본 이미지 설치 CI | 5개 작업 모두 통과 |
| VS2022·VS Code 중단점·실행 | VS2022, Windows·Ubuntu VS Code에서 빌드·7행 중단점·길이 10 확인·8행 단계 실행 통과 |
| 검증 환경 정리 | VM 프로세스·이미지·임시 편집기·추가 패키지 제거. 잠긴 SDL2.dll 약 2.4MB는 다음 로그인 정리 예약 |
| 테트리스 실제 터미널 조작 | Linux PTY·Windows 콘솔에서 02~05 화면·키 입력·종료 확인 |

## 원본 샘플 확인이 필요한 항목

`algorithms/dogorithm/18/S.txt`는 177264개의 a/c/g/t로 구성돼 있습니다. 원본 `01.out`·`02.out`의 좌표 구간은 현재 문자열에서 역순으로 같지 않습니다. 원본 파일은 그대로 보존했습니다.

문제 원문을 확보하지 못해 기존 코드에서 복원한 실행 계약을 [별도 설명](../algorithms/dogorithm/18/README.md)에 명시했습니다. CTest 입출력 비교는 원본 정답과 구분한 `.verified.out`을 사용합니다. `invert_reference_comparison`은 작은 입력 전수와 긴 원본 문자열 두 범위에서 접미사 배열과 독립적인 부분 문자열 비교로 최대 길이·동점 순서를 검산합니다. 현재 74개 통과에는 이 계약 검증이 포함되며, 원래 문제의 공식 정답 확인을 의미하지 않습니다.

Seminar는 CRLF 입력에서 `cin.ignore()`가 한 문자만 소비해 빈 줄을 읽고 빈 vector에 접근했습니다. 문제에서 지정한 개수만큼 정수를 직접 읽도록 수정했으며 원본 입력은 변경하지 않았습니다. Container의 로컬 채점 헤더는 제공된 정답의 `READY CALLED`·`REPORTED` 출력을 재현하도록 연결했습니다.

## 구분 기준

- 전체 빌드 통과: 등록한 모든 실행 대상과 라이브러리를 컴파일·링크한 결과입니다.
- 입출력 검증: 명시된 샘플과 경계값을 실행해 비교한 결과입니다. 모든 입력의 정답을 증명한다는 의미는 아닙니다.
- 초기 환경 검증: 도구가 준비된 일반 CI와 달리 초기 OS 이미지에서 설치 절차를 실행한 결과입니다.
- archive와 설명용 코드 조각은 실행 대상이 아닙니다. 실행 대상은 targets.json에 명시합니다.

## 실행 증거

- [CI 결과](verification/ci.json), [테스트 집계](verification/test-matrix.json), [Ubuntu 초기 VM 기록](verification/ubuntu-vm.json), [Windows 초기 VM 기록](verification/windows-vm.json), [실행 로그](verification/logs).
- [원본 보존 확인](verification/source-preservation.json), [임시 환경 정리 상태](verification/cleanup.json).
- [Windows 초기 VM의 Git·VS Code·확장 설치](verification/windows-tools.json), [새 VS Code의 실제 디버깅](verification/vscode-windows-vm.json).
- [VS2022 빌드·디버거 결과](verification/vs2022.json): 공통 CMake에서 생성한 VS2022 솔루션을 IDE에서 빌드하고 중단점·변수·단계 실행·정상 종료를 확인했습니다.
- VS Code [Windows MSVC 결과](verification/vscode.json) · [Ubuntu GDB 결과](verification/vscode-linux.json): 각각 configure/build 종료 코드 0, 7행 중단점에서 길이 10 확인 후 8행으로 단계 실행. Linux는 Ubuntu 24.04 WSL2의 별도 VS Code·확장 프로필과 Xvfb 화면으로 실행했습니다.
- [Linux 테트리스 PTY 결과](verification/tetris-linux.json), [Windows 테트리스 콘솔 결과](verification/tetris-windows.json).
- Ubuntu VM 이미지 SHA-256: `04e8f2461a16a44e78a370284471f29616cdd9baf1893df25807b71f985b6c94`.
- Windows 10 22H2 English x64 ISO SHA-256: `a6f470ca6d331eb353b815c043e327a347f594f37ff525f17764738fe812852e`. Microsoft 다운로드 페이지의 값과 대조했습니다.
- 검증 시점: 2026-10-24. Windows 호스트는 10.0.19045, VS2022는 17.14.41, MSVC는 14.44.35207입니다.
- 일반 CI의 Windows runner는 Windows Server 2022이며 Windows 10 새 VM 검증을 대신하지 않습니다. Ubuntu 기본 컨테이너 설치 검증 역시 VM 검증과 구분합니다.

## 정리 후 확인이 남은 항목

Windows의 공유 잠금으로 `out/vm-runtime/qemu/SDL2.dll` 한 개(2412441바이트)는 즉시 삭제되지 않았습니다. 다음 로그인에서 파일의 생성 시각과 SHA-256이 검증 당시와 같은 경우에만 삭제하는 사용자별 일회성 정리를 등록했습니다. 원본 저장소 백업과 실행 증거는 보존합니다. 호스트 재시작과 WSL 종료는 실행하지 않았으며, 잠금 파일의 완전 삭제는 재시작 후 확인해야 합니다. WSL 내부의 임시 파일 삭제와 trim은 수행했지만 VHDX 물리 압축은 수행하지 않았습니다.
