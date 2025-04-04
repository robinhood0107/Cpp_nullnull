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
        if (line == ".")
            break;
        stringstream ss(line);
        bool wrong = false;
        char input;
        while (ss>>input){
            if ((input =='(') || (input =='[')) {
                s.push(input);
            }
            else if (input == ')') {
                if ((s.top() == '(') && !s.empty()) {
                    s.pop();
                }
                else{
                    wrong = true;
                    break;
                }
            }
            else if (input == ']') {
                if ((s.top() == '[') && !s.empty()) {
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