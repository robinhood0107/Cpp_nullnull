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
        // for_each(lst.begin(),lst.end(),[this](auto p){ 
        //         contacts.insert(p);
        // });
        //this를 반드시 넣어서 클래스 멤버에 접근할 수 있어야 한다.
        for (const auto& [k,v] : lst) contacts[k] =v; 
        //구조적 바인딩으로 이렇게 map을 초기화 할 수 있다.
        // for (const auto& p : lst) contacts.insert(p);
        
    }
    void print() const {
           //멤버 함수를 구현하세요!
           for_each(contacts.begin(), contacts.end(), [](auto p){
               cout << p.first << ": " << p.second << "\n";
           });
        //   for (const auto& [k, v] : contacts) cout << k << " " << l << "\n";
        //   for (const auto& p : lst) cout << p.first << " " << p.second << "\n";
    }
};



int main() {
    Phonebook p = {{"Kim", 24}, {"Lee", 21}};
    p.print();
    return 0;
}