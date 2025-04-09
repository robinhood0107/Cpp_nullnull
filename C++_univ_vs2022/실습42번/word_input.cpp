#include "word_input.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

void processInput(map<string, size_t>& words) {
    string s;
    getline(cin, s);
    stringstream ss(s);
    string token;
    while (ss >> token && token != "^^") {
        string tmp;
        for (auto a : token) {
            if (!isalnum(a)) continue;
            tmp += tolower(a);
        }
        auto lt = words.find(tmp);
        if (lt != words.end()) lt->second = static_cast<size_t>(static_cast<int>(lt->second) + 1);
        else {
            words.insert(make_pair(tmp, 1));
        }
    }
}