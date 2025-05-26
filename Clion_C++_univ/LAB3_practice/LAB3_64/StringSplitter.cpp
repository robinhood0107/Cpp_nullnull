//이거는 그냥 보고 외우는 수 밖에 없음
#include "StringSplitter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

StringSplitter::StringSplitter(const string& in) : str{ in } {} //string str 초기화
//그리고 항상 string 입력 받을 때 const string& in 이렇게 포인터로 입력받으면 포인터 주소를 str에 넣어주어서 보안 챙길 수 있음

StringSplitter& StringSplitter::trim() {
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1);

    str.erase(0, str.find_first_not_of(" \t\n\r\f\v"));
    return *this;


    // string.erase() 함수는 총 3가지 방법이 있음
    // erase(시작주소, 길이) = 길이만큼 지움
    // erase(특정위치) str.begin()+5 이렇게 6번째 글자 지울수도 있음
    // erase(시작주소, 끝주소)
}

StringSplitter& StringSplitter::replaceSubstring(const string& old_str, const string& new_str) {
    size_t from = 0, pos;
    while ((pos = str.find(old_str, from)) != string::npos) {
        str.replace(pos, old_str.size(), new_str);
        from += new_str.size(); // 교체된 문자열 이후의 character들만 다시 검사할 수 있도록 from 인덱스를 증가시켜줌
    }
    return *this;
    // string의 .find() 메서드는 파라미터를 두 개 받을 경우, 첫번째 파라미터로 받은 문자열을 두번째 파라미터로 받은 인덱스에서부터 찾기 시작함 (그 이전 인덱스는 검사하지 않음)
    //원래는 find("찾을 문자") 못찾으면 string::npos 이거임 근데 위처럼 찾을 위치까지 지정 가능
    // replace 함수는 replace(시작 주소, 길이, 바꿀 문자열 주소)
    // pos 인덱스의 위치부터, old_str.size() 개수만큼의 문자를, new_str로 교체
}


StringSplitter& StringSplitter::removePunctuation() {
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return ispunct(c); }), str.end());
    return *this;

    // 항상 remove나 remove_if는 지우는 방식 때문에 배열 뒤로 쓰래기값을 보내는 방식이기 때문에 이 쓰래기 값을 지우기 위해서 무조건 erase 함수와 같이 쓰는 점 기억
    //remove_if는 다 찾은 다음 (뒤로 미룬 쓰래기값)없애야 할 원소 첫번째 이터레이터 반환, 쓰래기값 첫번째 주소부터 str 끝까지 삭제
    // erase(remove_if(시작,끝,람다함수),문자열의 최종 끝(str.end()))
}

vector<string> StringSplitter::split(char delim) {
    vector<string> ret; // return값을 담을 벡터
    stringstream ss(str); // str로 stringstream 객체 `ss`를 초기화
    string token;
    while (getline(ss, token, delim)) {
        // getline(stream, string, delim='\n') 함수는 세번째 파라미터로 char 타입의 구분자(delimiter)를 받을 수 있음! (기본값은 '\n'이라 줄바꿈 전까지 인식)
        ret.push_back(token);
    }
    return ret;
    //이건 걍 형태 자체를 암기
}