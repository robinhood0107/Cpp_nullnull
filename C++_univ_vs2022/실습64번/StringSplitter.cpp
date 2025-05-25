#include "StringSplitter.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

StringSplitter::StringSplitter(const string& in) : str{ in } {} // 디폴트 생성자로 초기화 리스트 이용



StringSplitter& StringSplitter::trim() {
    str.erase(str.find_last_not_of(" \t\n\r\f\v") + 1); // Rtrim (오른쪽 trim)
    // str.erase(find_last_not_of("0x20 | 0x09 | 0x0a | 0x0d | 0x0c | 0x0b")+1);
    // find_last_not_of()는 문자열이 모두 공백일 경우 string::npos를 반환하므로 +1을 해주면 0이 되는데,
    // str.erase(0)은 str.erase(0, string::npos)와 같고, 문자열을 모두 지운다

    str.erase(0, str.find_first_not_of(" \t\n\r\f\v")); // Ltrim
    // find_first_not_of()는 문자열이 모두 공백(whitespace character)일 경우 string::npos를 반환하므로
    // str.erase(0, string::npos)가 호출되어 문자열을 모두 지운다
    return *this;
}
// 메서드 체이닝을 위해 `*this`를 return


StringSplitter& StringSplitter::replaceSubstring(const string& old_str, const string& new_str) { // old_str를 new_str로 교체
    size_t from = 0, pos;
    // string의 .find() 메서드는 파라미터를 두 개 받을 경우, 첫번째 파라미터로 받은 문자열을 두번째 파라미터로 받은 인덱스에서부터 찾기 시작함 (그 이전 인덱스는 검사하지 않음)
    // 첫번째 파라미터로 받은 문자열을 더 이상 찾을 수 없다면 string::npos를 return
    while ((pos = str.find(old_str, from)) != string::npos) {
        str.replace(pos, old_str.size(), new_str); // pos 인덱스의 위치부터, old_str.size() 개수만큼의 문자를, new_str로 교체
        from += new_str.size(); // 교체된 문자열 이후의 character들만 다시 검사할 수 있도록 from 인덱스를 증가시켜줌
    }
    return *this;
}


StringSplitter& StringSplitter::removePunctuation() {
    str.erase(remove_if(str.begin(), str.end(), [](char c) { return ispunct(c); }), str.end());
    // remove_if() 함수와 `erase-remove idiom`을 통해 ispunct()를 true로 만드는 문자를 제거
    // std::remove(), std::remove_if() 모두 컨테이너에서 값을 실제로 없애주지는 않음!
    // 없애야 할 원소들을 모두 컨테이너 끝으로 밀어둔 뒤, 없애야 할 첫번째 원소를 가리키는 이터레이터를 return함
    // 따라서 remove()나 remove_if()의 리턴값인 이터레이터부터 .end() 이터레이터까지를 erase()해줘야 원소가 실제로 삭제됨!!!
    return *this;
}

vector<string> StringSplitter::split(char delim) {
    vector<string> ret; // return값을 담을 벡터
    stringstream ss(str); // str로 stringstream 객체 `ss`를 초기화
    string token; // split된 토큰을 담을 임시 문자열
    while (getline(ss, token, delim)) {
        // getline(stream, string, delim='\n') 함수는 세번째 파라미터로 char 타입의 구분자(delimiter)를 받을 수 있음! (기본값은 '\n'이라 줄바꿈 전까지 인식)
        ret.push_back(token);
    }
    return ret;
}