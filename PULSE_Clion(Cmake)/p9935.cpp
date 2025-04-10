//
// Created by pjjpj on 25. 4. 4.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    //erase와 find를 반복적으로 사용할 경우 시간초과가 난다.
    //erase는 n find도 n이기 때문에 합쳐서 O(n^2)가 될 수 있다.
    /*
    auto lt = line.find(c4); //이게 문제다. 이게 최악의 경우 O(n^2)이 됨
    if (lt != string::npos) {
        while ((lt = line.find(c4)) != string::npos) {
            line.erase(lt, c4.length());
        }
        if (line.empty())
            cout << "FRULA" << "\n";
        else
            cout << line;
    }
    else {
        cout << "FRULA" << "\n";
    }

    return 0;
}
    */

    //그래서 위의 방식대로 접근하지 말고
    //- 스택을 활용하여 문자열을 순회하며 문자 하나씩 넣는다. (이렇게 되면 문자열 하나를 한번만 순회해서 시간복잡도가 O(n)이 된다.
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line, c4;
    cin >> line >> c4;
    string stack;//스택처럼 사용할 문자열
    int c4_length = c4.length(); //c4의 길이임
    for (char lt : line) {
        stack.push_back(lt);
        if (stack.size() >= c4_length && stack.substr(stack.size() - c4_length) == c4){
            stack.erase(stack.size() - c4_length, c4_length);
        }
    }
        //string 메소드 substr = 이거 용도는 "문자열 추출" 이다
        // (1) 첫 번째 문자부터 3글자 추출
        //cout << str.substr(0, 3) << endl;  // 출력: abc

        // (2) 세 번째 문자부터 끝까지 추출
        //cout << str.substr(2) << endl;     // 출력: cdef

        // (3) 끝에서 두 번째 문자 추출
        //cout << str.substr(str.size() - 2, 2) << endl;

        // 주의할 점!!!! 시작지점이 문자열 범위를 벗어나면 런타임 오류 발생함!!!!



    if (stack.empty()) {
        cout << "FRULA\n";
    } else {
        cout << stack << "\n";
    }

    return 0;

}

