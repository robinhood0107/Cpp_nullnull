//
// Created by pjjpj on 25. 4. 4.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string line, c4;
    cin >> line >> c4;

    auto lt = line.find(c4);
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