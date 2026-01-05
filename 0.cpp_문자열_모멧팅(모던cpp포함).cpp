#include <iostream>
#include <iomanip> //setw이나 setprecision 등을 쓰기 위해 필수

#include <format> // C++20 필수
#include <string>

void main(){
//최신 C++20 방식 (std::format) (중요)
//파이썬에서 f-string 사용하듯 사용하면 된다
//(문자열 다룰때 포멧팅까지 해서 출력해서 시간단축)
    int age = 20;
    double height = 175.5;

    // Python의 f-string과 유사
    // {:>10} : 10칸 잡고 오른쪽 정렬
    // {:.2f} : 소수점 2자리 고정
    std::string s = std::format("나이: {:>5}, 키: {:.2f}cm", age, height);
    
    std::cout << s << std::endl;
    // 출력: 나이:    20, 키: 175.50cm


//줄맞추기
//std::setw(n): 출력할 너비를 n칸으로 잡습니다. (주의: 이 설정은 딱 한 번의 출력에만 적용되고 바로 초기화됩니다.)
//std::left / std::right: 왼쪽/오른쪽 정렬을 설정합니다. (영구 적용)
//std::setfill(c): 빈 공간을 문자 c로 채웁니다. (영구 적용)

std::cout << "===== 정렬 및 채우기 =====" << std::endl;
// 기본: 오른쪽 정렬, 공백 채움
std::cout << std::setw(10) << "Hello" << std::endl; 

// 응용: 왼쪽 정렬, '*'로 채움
std::cout << std::left;             // 왼쪽 정렬 고정
std::cout << std::setfill('*');     // 빈칸은 *로 채움
std::cout << std::setw(10) << "Hello" << std::endl; 
std::cout << std::setw(10) << "C++" << std::endl;


//소수점 자릿수 고정, 과학적 표기법
double pi = 3.1415926535;
std::cout << "===== 실수 포맷팅 =====" << std::endl;


//std::setprecision(n): 유효 숫자를 n개로 설정합니다.
// 1. 유효 숫자 5개 (전체 자릿수 기준)
std::cout << std::setprecision(5) << pi << std::endl; // 3.1416

//std::fixed: 소수점 아래 자릿수를 고정합니다. 
//(이걸 쓰면 setprecision이 소수점 아래 자릿수가 됨)
// 2. 소수점 아래 고정 (가장 많이 쓰는 방식)
std::cout << std::fixed;
std::cout.precision(3); // setprecision(3)과 동일 효과
std::cout << pi << std::endl; // 3.142 (반올림 됨)

//std::scientific: 과학적 표기법(e)으로 출력합니다.
// 3. 과학적 표기법
std::cout << std::scientific;
std::cout << pi << std::endl; // 3.142e+00

// 4. 원래대로 복구
std::cout.unsetf(std::ios::scientific); // 플래그 해제
std::cout.unsetf(std::ios::fixed);      // 플래그 해제


//진법 변환
// std::hex, std::oct, std::dec: 각각 16진수, 8진수, 10진수로 변경.

// std::showbase: 앞에 0x(16진수)나 0(8진수)을 붙여줌.

// std::uppercase: 16진수 출력 시 알파벳을 대문자로 출력.

int num = 255;

std::cout << "===== 진법 변환 =====" << std::endl;

std::cout << std::dec << num << std::endl; // 255 (10진수)

std::cout << std::hex << num << std::endl; // ff (16진수)

std::cout << std::showbase << std::uppercase; // 0x 표시 + 대문자
std::cout << std::hex << num << std::endl;    // 0XFF

std::cout << std::dec; // 다시 10진수로 복구


//기타 포멧팅(std::boolalpha, std::showpos)
//std::boolalpha: 1/0 대신 true/false 문자열로 출력.
// Boolean 문자열 출력
std::cout << std::boolalpha << true << std::endl; // true

//std::showpos: 양수일 때도 앞에 + 기호를 강제로 붙임.
// 양수 부호 표시
std::cout << std::showpos << 100 << std::endl; // +100
std::cout << std::noshowpos; // 해제
}


