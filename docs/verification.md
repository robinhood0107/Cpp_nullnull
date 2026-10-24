# 검증 기록

검증은 진행 중입니다. 실제 완료하지 않은 항목을 통과로 표시하지 않습니다.

| 구분 | 현재 상태 |
|---|---|
| Linux GCC 13 Debug 전체 빌드 | 통과 |
| Linux Debug·Release CTest | 각각 73개 중 71개 통과, invert 원본 샘플 2개 불일치 |
| Windows MSVC Debug/Release | 전체 빌드 통과, 원본 invert 샘플 2개 실패 재현 |
| Ubuntu 24.04 새 VM의 수동 설치·빌드 | Debug 전체 빌드 통과, 동일 샘플 2개 실패 |
| Ubuntu 24.04 새 VM의 스크립트 설치·빌드 | 패키지 설치·Debug 전체 빌드 통과, 동일 샘플 2개에서 실패 종료 |
| Windows 10 22H2 새 VM | 공식 ISO 해시 확인, OS 설치 진행 중 |
| VS2022·VS Code 중단점·실행 | VS Code는 구성·빌드·중단점·변수 확인·단계 실행 통과. VS2022는 확인 중 |
| 테트리스 실제 터미널 조작 | Linux PTY·Windows 콘솔에서 02~05 화면·키 입력·종료 확인 |

## 원본 샘플 확인이 필요한 항목

`algorithms/dogorithm/18/S.txt`는 177264개의 a/c/g/t로 구성돼 있습니다. 01.out의 좌표를 1부터 시작하는 구간으로 해석하면 첫 구간은 `ccagagcgca`, 두 번째 구간은 `taacagacac`로 역순 일치하지 않습니다. 현재 알고리즘의 출력도 원본 정답과 다릅니다. 문제 정의와 샘플의 대응 확인 전에는 해당 풀이를 정답 검증 완료로 표시하지 않습니다. 원본 정답은 변경하지 않았습니다.

Seminar는 CRLF 입력에서 `cin.ignore()`가 한 문자만 소비해 빈 줄을 읽고 빈 vector에 접근했습니다. 문제에서 지정한 개수만큼 정수를 직접 읽도록 수정했으며 원본 입력은 변경하지 않았습니다. Container의 로컬 채점 헤더는 제공된 정답의 `READY CALLED`·`REPORTED` 출력을 재현하도록 연결했습니다.

## 구분 기준

- 전체 빌드 통과: 등록한 모든 실행 대상과 라이브러리를 컴파일·링크한 결과입니다.
- 입출력 검증: 명시된 샘플과 경계값을 실행해 비교한 결과입니다. 모든 입력의 정답을 증명한다는 의미는 아닙니다.
- 초기 환경 검증: 도구가 준비된 일반 CI와 달리 초기 OS 이미지에서 설치 절차를 실행한 결과입니다.
- archive와 설명용 코드 조각은 실행 대상이 아닙니다. 실행 대상은 targets.json에 명시합니다.

## 실행 증거

- [VS Code CMake·디버거 결과](verification/vscode.json): configure/build 종료 코드 0, 7행 중단점에서 길이 10 확인 후 8행으로 단계 실행.
- [Linux 테트리스 PTY 결과](verification/tetris-linux.json), [Windows 테트리스 콘솔 결과](verification/tetris-windows.json).
- Ubuntu VM 이미지 SHA-256: `04e8f2461a16a44e78a370284471f29616cdd9baf1893df25807b71f985b6c94`.
- Windows 10 22H2 English x64 ISO SHA-256: `a6f470ca6d331eb353b815c043e327a347f594f37ff525f17764738fe812852e`. Microsoft 다운로드 페이지의 값과 대조했습니다.
- 검증 시점: 2026-10-24. Windows 호스트는 10.0.19045, VS2022는 17.14.41, MSVC는 14.44.35207입니다.
- 일반 CI의 Windows runner는 Windows Server 2022이며 Windows 10 새 VM 검증을 대신하지 않습니다. Ubuntu 기본 컨테이너 설치 검증 역시 VM 검증과 구분합니다.
