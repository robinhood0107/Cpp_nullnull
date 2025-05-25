실습 064 this 포인터 (revised)
업로드 가능한 파일 수: 3
제출 방식: 개인


목적


이 실습은 class 내부에서 this 키워드를 사용하는 연습을 합니다.



설명


객체 지향 프로그래밍에서 메서드 체이닝 (method chaining) 은 단일 문(statement) 에서 객체의 여러 메서드를 이어서 호출하는 방법입니다. 



예를 들어, 문자열을 변형하는 코드를 메서드 체이닝으로 다음과 같이 작성할 수 있습니다.




std::string myString = "  Hello, World!   ";

std::string result = StringSplitter(myString)
                                                   .trim()
                                                   .removeNonAlnum()
                                                   .split(' ') ;



문제


주어진 프로그램이 동작하는데 필요한 StringSplitter 클래스를 구현하시오.

this 키워드를 이용하여 메서드 체이닝 (method chaining) 방법을 활용하시오.
a punctuation character


<참고>



// main.cpp



#include <iostream>
#include "StringSplitter.h"

int main() {
    std::string myString;
    std::getline(std::cin, myString);
    auto tokens =
            StringSplitter(myString)
                    .trim()
                    .replaceSubstring("World", "Edward")
                    .removePunctuation()
                    .split(' ');

    for (auto& token : tokens)
        std::cout << token << std::endl;

    return 0;
}




입력 예


  Hello, World!  



(주의: 앞뒤에 공백이 있습니다!)



출력 예


Hello

Edward





제출파일 


StringSplitter.h

StringSplitter.cpp

