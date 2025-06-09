#include "word_manager.h"
#include <map>
#include <string>
#include <iostream>
#include <cctype>
using namespace std;

static std::map<std::string, size_t> word_map;

std::string normalize_word(const std::string& word) {
    //Implement your code
    string s;
    for (auto a: word){
        if (!isalnum(a)) continue;
        s += tolower(a);
    }
    return s;
}

void add_word(const std::string& word) {
    //Implement your code
    auto p = word_map.find(word);
    if (p != word_map.end()){
        p->second = static_cast<size_t>(static_cast<int>(p->second)+1);
    }
    else {
        word_map.insert(make_pair(word,1));
    }
}

int find_word(const std::string& word) {
    //Implement your code
    auto p = word_map.find(word);
    if (p != word_map.end()){
        cout << p->first <<": " << p->second << '\n'; //a->b는 (*a)->b와 같음
        return p->second;
        
    }
    else
        return -1;
}

bool update_word(const std::string& word, size_t value) {
    //Implement your code
    string wd = normalize_word(word);
    auto p = word_map.find(word);
    if (p != word_map.end()){
        p->second = static_cast<size_t>(value);
        cout << "Updated: " << p->first << " " << p->second << endl;
        return true;
    }
    else {
        cout << "Error: '" << normalize_word(wd) << "' not found. Cannot update." << endl;
        return false;
    }
}

bool delete_word(const std::string& word) {
    //Implement your code
    string wd = normalize_word(word);
    auto p = word_map.find(wd);
    if (p != word_map.end()){
        cout << "Deleted: " << p->first << endl;
        word_map.erase(wd);
        return true;
    }
    else{
        cout << "Error: '" << normalize_word(wd) << "' not found. Cannot delete." << endl;
        return false;
    }
}

void print_words() {
    //Implement your code
    int cnt = 0;
    for (const auto& lt : word_map)
        cnt += static_cast<int>(lt.second);
    cout << "#Words: " << cnt << endl;
    cout << "Word List: ";
    for (const auto& lt : word_map)
        cout << lt.first << ": " << lt.second << " ";
    cout << endl;
    //시간복잡도가 중요한 과목이 아니면 for문 2번 돌려도 된다
    /*
    int cnt = 0;
    for (auto [k,v] : words) cnt += v;
        cout << "#words: " << cnt << "\nword List: ";
    for (auto [k,v] :words) cout << k << ": " << v << ' ';
    cout << '\n';
    */
}

void reset_words() {
    //Implement your code
    
    
}
