#include <iostream>

void processInput(map<string, size_t>& words) {
    string s;
    getline(cin,s);
    stringstream ss(s);
    string token;
    while(ss >> token && token != "^^" ){
        string tmp;
        for (auto a : token){
            if(!isalnum(a)) continue;
            tmp += tolower(a);
        }
        auto lt = words.find(tmp);
        if(lt != words.end()) lt->second = static_cast<size_t>(static_cast<int>(lt->second) + 1);
        else {
            words.insert(make_pair(tmp,1));
        }
    }
}

// 여기에서 암기해야 할 것은 for (auto a : s) {
    // if (!isalnum(a)) continue;
    // tmp += tolower(a); <이거 해더파일 <cctype>
// } 이렇게 소문자로

string change2low(string& s) {
    string tmp;
    for (auto a : s) {
        if (!isalnum(a)) continue;
        tmp += tolower(a);
    }
    return tmp;
}
// 이렇게 하고 나면 밑에서부터는 string타입을 걍 map의 find메소드 words.find(찾고싶은 것) 이걸 반환하면 됨
// 그리고 그냥 쿨하게 find != word.end() 이거 쓰면 된다.

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
        cout << "Error: '" << change2low(tmp) << "' not found. Cannot update." << endl;
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