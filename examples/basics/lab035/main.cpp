//
// Created by pjjpj on 25. 4. 1.
//


//반드시 알아야 하는 사항 = (cin >> ) 연산의 경우 EOF(\0)나 유효하지 않은 입력을 만나면 false 반환
//이래서 while 조건문 안에 쓸 수 있는거임(while 동안 EOF나 유효한거만나면 false이니까)
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream input(line);
        vector<int> values;
        int value;
        while (input >> value) values.push_back(value);
        if (values.empty()) continue;
        const auto [lowest, highest] = minmax_element(values.begin(), values.end());
        cout << values.size() << " " << *lowest << " " << *highest << "\n";
    }
}
