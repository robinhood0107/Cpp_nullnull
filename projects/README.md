# 작은 프로젝트

| 구현 | 연습한 내용 | 실행 대상 | 검증 |
|---|---|---|---|
| [CMyString](my-string) | 동적 버퍼·깊은 복사·대입·자기대입·부분 문자열 대입 | `my_string_demo` | `my_string_value_semantics` |

`getData()`는 빈 문자열도 안전하게 반환하고, `getLength()`는 바이트 길이입니다. 이동 연산이나 std::string 전체 인터페이스를 추가하지 않고 기존 클래스의 값 복사 동작을 검증합니다.
