#include <iostream>
#include <string>
#include <map>
#include <initializer_list>
#include <utility>
#include <algorithm>
using namespace std;

class Phonebook {
    map<string, int> contacts;
public:
    Phonebook(initializer_list <pair<string, int>> lst) {
        //생성자를 구현하세요!
        //map을 인자로 받아서 넣어주는 법
        //map은 insert 메서드함수를 쓰던가, 아님 구조적 바인딩 [k,v]를 통해서 넣어주던가.
        //!!!!!!!!!!(중요) 이거 진짜 나올 것 같음
        for (const auto& [k,v] : lst) contacts[k] =v; //구조적 바인딩으로
        for (const auto& p : lst) contacts.insert(p);
        //for (const auto& [k,v] : lst) contacts[k] =v;
        //for (const auto& p : lst) contacts.insert(p);

        // for_each는 for 함수 안쓸 수 있는 거다, 그리고 람다함수로 정해진 조건으로 넣어줄 수 있음.
        //std::for_each(lst.begin(),lst.end(),[this](auto p){ //this를 반드시 넣어서 클래스 멤버에 접근할 수 있어야 한다.
        //         contacts.insert(p);
        // });
    }
    void print() const {
        //멤버 함수를 구현하세요!
        //algorithm 헤더 필수
        for_each(contacts.begin(),contacts.end(),[](auto p) {
            std::cout << p.first << ": " << p.second << "\n";
        });

        //for (const auto& [k, v] : contacts) cout << k << " " << l << "\n";
        //for (const auto& p : lst) cout << p.first << " " << p.second << "\n";
        // for 루프로 이렇게도 돌 수 있다
    }
};



int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}

