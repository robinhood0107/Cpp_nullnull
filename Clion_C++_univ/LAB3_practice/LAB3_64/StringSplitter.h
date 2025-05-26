//이거는 그냥 보고 외우는 수 밖에 없음
#ifndef StringSplitter_H
#define StringSplitter_H

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class StringSplitter {
public:
    StringSplitter(const string& myString);
    StringSplitter& trim();
    StringSplitter& replaceSubstring(const string& old_str, const string& new_str);
    StringSplitter& removePunctuation();
    vector<string> split(char delim);
private:
    string str;
};

//메서드 체이닝 할때 StringSplitter& 이렇게 선언한다




#endif // StringSplitter_H
