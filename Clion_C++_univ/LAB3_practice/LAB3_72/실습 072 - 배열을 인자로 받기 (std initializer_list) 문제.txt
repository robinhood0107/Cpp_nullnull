실습 072 - 배열을 인자로 받기 (std::initializer_list)
업로드 가능한 파일 수: 2
제출 방식: 개인

목적

이 실습은  class 의 생성자 정의와 std::initializer_list 타입을 연습을 합니다. 



설명

배열을 생성하는 과정을 생각해 봅시다.

int arr1[5] = {1, 2, 3, 4, 5};

int arr2[] = {1, 2, 3, 4, 5}; 

배열의 원소의 값들을 배열 선언과 동시에 초기화 해주고 있습니다.



C++에서는 initializer_list 타입을 이용해서 배열의 원소 초기화에 사용한 형식을 지원합니다.

예를 들어, 다음과 같이 initializer_list 타입을 사용할 수 있습니다.



#include <iostream>
#include <initializer_list>
#include <numeric>
using namespace std;


int sum(initializer_list<int> lst) {
    return accumulate(lst.begin(), lst.end(), 0);
}

 

int main() {
    cout  << sum ({1, 2, 3, 4, 5}) << '\n';
    return 0;
}



문제

Phonebook 클래스를 정의하시오.

<참조>
std::map 의 생성자 혹은 insert 함수의 설명을 참고하여, 적절한 생성자를 이용하시오.
https://en.cppreference.com/w/cpp/container/map/map
https://en.cppreference.com/w/cpp/container/map/insert




입력

없음



출력

주어진 main.cpp 파일의 표준 출력은 다음과 같다.


Kim 24
Lee 21


제출파일

main.cpp



참고


main.cpp -----------------------------


#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>
using namespace std;

class Phonebook {
    map<string, int> contacts;
public:
    Phonebook(initializer_list <pair<string, int>> lst) {
        //생성자를 구현하세요!
    }
    void print() const {
           //멤버 함수를 구현하세요!
    }
};



int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}

