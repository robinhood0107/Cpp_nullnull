#include "word_manager.h"
#include <iostream>
#include <cctype>

using namespace std;

string change2low(string& s) {
    string tmp;
    for (auto a : s) {
        if (!isalnum(a)) continue;
        tmp += tolower(a);
    }
    return tmp;
}

void findWord(const map<string, size_t>& words, const string& rawWord) {
    string tmp = rawWord;
    auto find = words.find(change2low(tmp));
    if (find != words.end())
        std::cout << find->first << ": " << find->second << std::endl;
}

void updateWord(map<string, size_t>& words, const string& rawWord, size_t value) {
    string tmp = rawWord;
    auto find = words.find(change2low(tmp));
    if (find != words.end()) {
        find->second = static_cast<size_t>(value);
        cout << "Updated: " << find->first << " " << find->second << endl;
    }
    else {
        cout << "Error: '" << change2low(tmp) << "' not found. Cannot update." << endl;//그리고 이렇게 예외 처리 안해서 계속 틀렸던 것이었음 왜 그랬나 싶었다. 이렇게 예외처리 문제 잘 읽고 꼭 써라
    }
}

void deleteWord(map<string, size_t>& words, const string& rawWord) {
    string tmp = rawWord;
    auto find = words.find(change2low(tmp));
    if (find != words.end()) {
        cout << "Deleted: " << find->first << endl;
        words.erase(find); //cout << "Deleted: " << find->first << endl; 이걸 먼저 출력한 후에 words.erase(find);을 해야 한다
    }
    else {
        cout << "Error: '" << change2low(tmp) << "' not found. Cannot delete." << endl;
    }
}

void printWords(const map<string, size_t>& words) {
    int cnt(0);
    for (const auto& lt : words)
        cnt += static_cast<int>(lt.second);
    cout << "#Words: " << cnt << endl;
    cout << "Word List: ";
    for (const auto& lt : words)
        std::cout << lt.first << ": " << lt.second << " ";
    cout << endl;
}
