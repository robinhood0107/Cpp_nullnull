#include <iostream>
#include <iomanip> // setw이나 setprecision 등을 쓰기 위해 필수
#include <format>  // C++20 필수
#include <string>

int main() {
    // ==========================================
    // 1. 최신 C++20 방식 (std::format) (중요)
    // ==========================================
    // 파이썬에서 f-string 사용하듯 사용하면 된다

    // [문법 해부도 (가장 중요)]
    // 중괄호 안의 구조는 다음과 같습니다. 순서가 중요합니다.
    // { [인덱스] : [채움][정렬][너비][.정밀도][타입] }

    // 인덱스: 몇 번째 변수를 넣을지 (생략하면 순서대로)
    // :     : "이제부터 포맷팅 옵션 시작이다"라는 신호
    // 채움/정렬: 빈 공간을 뭘로 채우고 어느 쪽으로 정렬할지
    // 너비   : 총 몇 칸을 차지할지
    // 정밀도 : 소수점 몇째 자리까지 보여줄지
    // 타입   : 10진수(d), 16진수(x), 실수(f) 등

    // (문자열 다룰때 포멧팅까지 해서 출력해서 시간단축)
    int age = 20;
    double height = 175.5;

    // Python의 f-string과 유사
    // {:>5} : 5칸 잡고 오른쪽 정렬
    // {:.2f} : 소수점 2자리 고정
    std::string s = std::format("나이: {:>5}, 키: {:.2f}cm", age, height);

    std::cout << s << std::endl;
    // 출력: 나이:    20, 키: 175.50cm


    // [소수점 관리 (실수)]
    // cout에서 fixed, setprecision 쓰던 악몽에서 해방입니다.
    // .nf: 소수점 n자리까지 표시 (반올림)
    double pi = 3.141592;
    
    // {:.2f} -> 소수점 2자리(f)까지
    std::string s2 = std::format("파이: {:.2f}", pi); 
    // 결과: "파이: 3.14"
    std::cout << s2 << std::endl;


    // [자릿수 맞추기 (정렬)]
    // 표를 만들거나 로그를 예쁘게 찍을 때 씁니다.
    // < : 왼쪽 정렬 (기본값)
    // > : 오른쪽 정렬 (숫자 기본값)
    // ^ : 가운데 정렬

    // {:>10} -> 10칸 잡고 오른쪽(>) 정렬
    std::cout << std::format("|{:>10}|", "Hello") << std::endl;
    // 결과: "|     Hello|"

    // {:*^10} -> 10칸 잡고 가운데(^) 정렬하되 빈칸은 *로 채움
    std::cout << std::format("|{:*^10}|", "Hello") << std::endl;
    // 결과: "|**Hello***|"


    // [숫자 0 채우기 (ID, 시간 등)]
    // 너비 앞에 0을 붙이면 빈칸 대신 0이 들어갑니다.
    int id = 7;
    
    // {:05} -> 5칸 잡고 빈 곳은 0으로 채움
    std::cout << std::format("ID: {:05}", id) << std::endl;
    // 결과: "ID: 00007"


    // [정수 (Integer)]
    // d: 10진수 (Decimal, 생략 가능)
    // x / X: 16진수 (Hex), X는 대문자
    // b / B: 2진수 (Binary) - C++20의 킬러 기능!
    // #: 접두사 붙이기 (0x, 0b 등)
    int n = 255;
    
    std::cout << std::format("{:d}", n) << std::endl;   // "255"
    std::cout << std::format("{:x}", n) << std::endl;   // "ff"
    std::cout << std::format("{:#X}", n) << std::endl;  // "0XFF" (0x 포함 대문자)
    std::cout << std::format("{:08b}", n) << std::endl; // "11111111" (2진수) -> 비트 연산 확인할 때 최고


    // [부호 (Sign)]
    // +: 양수도 무조건 + 기호 표시
    // (공백): 양수면 공백 한 칸, 음수면 - (줄 맞출 때 유용)
    std::cout << std::format("{:+}", 10) << std::endl;  // "+10"
    std::cout << std::format("{: }", 10) << std::endl;  // " 10" (양수라 앞에 공백 있음)
    std::cout << std::format("{: }", -10) << std::endl; // "-10"


    /* [cout vs std::format 비교]
    
       목표                       기존 cout 방식                          std::format 방식 (C++20)
       -----------------------------------------------------------------------------------------
       소수점 2자리         cout << fixed << setprecision(2) << 3.14;   format("{:.2f}", 3.14)
       폭 10, 우측정렬      cout << setw(10) << "Hi";                   format("{:>10}", "Hi")
       16진수 (0x포함)      cout << showbase << hex << 255;             format("{:#x}", 255)
       0 채우기 (007)       cout << setfill('0') << setw(3) << 7;       format("{:03}", 7)
    */


    // [진짜 사소한 팁: C++23을 쓸 수 있다면?]
    // C++20에서는 std::cout << std::format(...) 처럼 써야 하지만, 
    // C++23부터는 std::print가 추가되어 더 짧게 쓸 수 있음.
    
    // C++23 (현재 컴파일러 지원 여부에 따라 주석 처리함)
    // std::print("나이: {}, 키: {:.1f}\n", 20, 175.5); 
    // cout 없이 바로 출력됨 (속도도 더 빠름)


    std::cout << "\n==========================================" << std::endl;
    std::cout << "2. 기존 방식 (cout / iomanip)" << std::endl;
    std::cout << "==========================================" << std::endl;

    // [줄맞추기]
    // std::setw(n): 출력할 너비를 n칸으로 잡습니다. (주의: 이 설정은 딱 한 번의 출력에만 적용되고 바로 초기화됩니다.)
    // std::left / std::right: 왼쪽/오른쪽 정렬을 설정합니다. (영구 적용)
    // std::setfill(c): 빈 공간을 문자 c로 채웁니다. (영구 적용)

    std::cout << "===== 정렬 및 채우기 =====" << std::endl;
    // 기본: 오른쪽 정렬, 공백 채움
    std::cout << std::setw(10) << "Hello" << std::endl; 

    // 응용: 왼쪽 정렬, '*'로 채움
    std::cout << std::left;             // 왼쪽 정렬 고정
    std::cout << std::setfill('*');     // 빈칸은 *로 채움
    std::cout << std::setw(10) << "Hello" << std::endl; 
    std::cout << std::setw(10) << "C++" << std::endl;

    // 다음 예제를 위해 설정 초기화
    std::cout << std::right << std::setfill(' ');


    // [소수점 자릿수 고정, 과학적 표기법]
    double pi_val = 3.1415926535;
    std::cout << "===== 실수 포맷팅 =====" << std::endl;

    // std::setprecision(n): 유효 숫자를 n개로 설정합니다.
    // 1. 유효 숫자 5개 (전체 자릿수 기준)
    std::cout << std::setprecision(5) << pi_val << std::endl; // 3.1416

    // std::fixed: 소수점 아래 자릿수를 고정합니다. 
    // (이걸 쓰면 setprecision이 소수점 아래 자릿수가 됨)
    // 2. 소수점 아래 고정 (가장 많이 쓰는 방식)
    std::cout << std::fixed;
    std::cout.precision(3); // setprecision(3)과 동일 효과
    std::cout << pi_val << std::endl; // 3.142 (반올림 됨)

    // std::scientific: 과학적 표기법(e)으로 출력합니다.
    // 3. 과학적 표기법
    std::cout << std::scientific;
    std::cout << pi_val << std::endl; // 3.142e+00

    // 4. 원래대로 복구
    std::cout.unsetf(std::ios::scientific); // 플래그 해제
    std::cout.unsetf(std::ios::fixed);      // 플래그 해제
    std::cout.precision(6); // 기본값 복구


    // [진법 변환]
    // std::hex, std::oct, std::dec: 각각 16진수, 8진수, 10진수로 변경.
    // std::showbase: 앞에 0x(16진수)나 0(8진수)을 붙여줌.
    // std::uppercase: 16진수 출력 시 알파벳을 대문자로 출력.

    int num = 255;

    std::cout << "===== 진법 변환 =====" << std::endl;

    std::cout << std::dec << num << std::endl; // 255 (10진수)

    std::cout << std::hex << num << std::endl; // ff (16진수)

    std::cout << std::showbase << std::uppercase; // 0x 표시 + 대문자
    std::cout << std::hex << num << std::endl;    // 0XFF

    std::cout << std::dec << std::noshowbase; // 다시 10진수로 복구


    // [기타 포멧팅 (std::boolalpha, std::showpos)]
    // std::boolalpha: 1/0 대신 true/false 문자열로 출력.
    // Boolean 문자열 출력
    std::cout << std::boolalpha << true << std::endl; // true

    // std::showpos: 양수일 때도 앞에 + 기호를 강제로 붙임.
    // 양수 부호 표시
    std::cout << std::showpos << 100 << std::endl; // +100
    std::cout << std::noshowpos; // 해제

    return 0;
}