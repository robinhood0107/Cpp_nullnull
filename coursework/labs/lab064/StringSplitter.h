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
    // 메서드 체이닝을 하려면 다음과 같이 선언해야 함
    /*
    StringSplitter&는 **StringSplitter 클래스의 참조형(Reference Type)**을 의미합니다.
    
    *	StringSplitter&는 "StringSplitter 객체 자신을 참조로 반환한다"는 뜻입니다.
    *	메서드 체이닝(method chaining)은 여러 메서드를 연속해서 호출할 수 있게 하는 패턴입니다.
    *	이를 위해 각 멤버 함수가 *this(자기 자신)를 참조로 반환해야 합니다.
    
    예시)
    class StringSplitter {
    public:
        StringSplitter& trim() {
            // ... 작업 ...
            return *this; // 자기 자신을 참조로 반환
        }
        StringSplitter& removePunctuation() {
            // ... 작업 ...
            return *this;
        }
        // ...
    };


    //이렇게 하면 메서드 채이닝을 사용할 수 있게 됨

    StringSplitter ss("hello, world!");
    ss.trim().removePunctuation(); // 이렇게 연속 호출 가능


    
    *	StringSplitter&는 자기 자신을 참조로 반환해서,
    *	여러 멤버 함수를 연속적으로 호출할 수 있게 해줍니다.
    *	메서드 체이닝을 지원하는 대표적인 반환 타입입니다.
    */

    StringSplitter& trim();
    StringSplitter& replaceSubstring(const string& old_str, const string& new_str);
    StringSplitter& removePunctuation();
    vector<string> split(char delim);
private:
    string str;
};


#endif // StringSplitter_H
