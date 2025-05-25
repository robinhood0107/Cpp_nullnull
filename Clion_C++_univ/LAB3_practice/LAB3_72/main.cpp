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

