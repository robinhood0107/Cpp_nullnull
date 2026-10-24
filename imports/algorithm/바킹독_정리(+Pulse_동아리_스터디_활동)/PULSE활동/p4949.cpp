//
// Created by pjjpj on 25. 4. 4.
//
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (true){
        stack<char> s;
        string line;
        getline(cin,line);
        if (line.length()== 1 && line[0] == '.')
            break;
        stringstream ss(line);
        bool wrong = false;
        char input;
        while (ss>>input){
            if ((input =='(') || (input =='[')) {
                s.push(input);
            }
            else if (input == ')') { //stack의 top함수 쓸때 조심할 것 = 스택이 비어있으면 런라임 오류남!!!!!
                //if ((s.top() == '(') && !s.empty()) {  //(매우매우 조심) 이렇게 쓰면 안됨
                //비교문은 왼쪽부터 오른쪽으로 글읽는거와 같이 순서대로 실행됨. 조심해라!!!!!!!!!!
                if (!s.empty() && (s.top() == '(')) { //나 이거 진짜 몰랐음. 항상 무조건 empty를 앞에 쓰고 stack.top()으로 비교문 작성해라
                    s.pop();
                }
                else{
                    wrong = true;
                    break;
                }
            }
            else if (input == ']') {
                if (!s.empty() && (s.top() == '[')) { //나 이거 진짜 몰랐음. 항상 무조건 empty를 앞에 쓰고 stack.top()으로 비교문 작성해라
                    s.pop();
                }
                else{
                    wrong = true;
                    break;
                }
            }
        }

        if (wrong == false && s.empty()) {
            cout << "yes" << endl;
        }
        else
            cout << "no" << endl;
    }
    return 0;
}
/*for (int i=0;i<line.length();i++) {
char input = line[i];

        }*/
