#include "String.h"
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

//Implement your code

//일단 맨 처음에 static 있는지 확인 꼭 하셈
int String::count_ = 0;


String::String() :len_{0} {
    // 일단 문자열 길이 0일 경우 null만 있는 경우 출력
    data_ = new char[len_+ 1]; //null 공간 확보
    data_[0] = '\0'; //길이 0이니까 null은 인덱스0
    count_++; //카운트 증가 무조건 해주기
}
String::String(const char* s){
    // len_의 길이는 무조건 strlen() 이 함수로 결정한다(c스타일은 strlen() 이 함수로 결정시키면 됨)
    len_ = strlen(s);
    data_ = new char[len_ + 1];
    copy(str, str + len_, data_); // copy(복사 시작, 복사 끝, 붙여넣기 시작)
    data_[len_] = '\0';
    count_++;
    cout << "Constructor\n# of String object: " << count_ << '\n';
}
String::~String(){
    delete[] data_; //소멸자 항상 무조건 소멸되게 delete 무조건 명령
    count_--; //이거 꼭 하기
    cout << "Destructor\n# of String object: " << count_ << '\n';
}
String::String(const String& s){
    len_ = str.len_;
    data_ = new char[len_ + 1];
    copy(str.data_, str.data_ + len_, data_);
    data_[len_] = '\0';
    count_++;
    cout << "Copy Constructor\n# of String object: " << count_ << '\n';
}
const char* String::data() const{
    return data_;
}
bool String::empty() const{
    return !len_;
    // 그냥 길이 0이면 true 아니면 false 나오게 !len_
}
size_t String::size() const{
    return len_;
}
String& String::append(const String& str){
//이거만 짜도 답 되긴 함 ㅇㅇ
    char* new_data = new char[len_ + str.len_ + 1]; //string+string에 해당하는 결과값 넣을 동적 변수 1개 생성
    copy(this->data_, this->data_ + len_, new_data); //0~len까지 첫번째 string
    copy(str.data_, str.data_ + str.len_, new_data + len_); //len(첫번째 string의 null)~len+str.len_까지 두번째 string
    new_data[len_ + str.len_] = '\0'; // 문장 마지막에 항상 null 값 넣어주는거 잊지말기
    delete[] data_;
    data_ = new_data;
    len_ += str.len_; //여기는 내기 임의로 new_data 선언시킨거라 무조건 동적할당 풀고 다시 지정하기
}
String& String::append(const char* str){
    if (!str || str[0] == '\0') return *this; // nullptr 또는 빈 문자열 방어

    size_t append_len = strlen(str);
    if (empty()) { // 현재 String 객체가 비어있으면 str만 복사
        delete[] data_; //기존 data_ 동적할당삭제 = 삭제
        data_ = new char[append_len + 1]; //str만 담을 동적할당
        copy(str, str + append_len, data_);
        data_[append_len] = '\0'; //null 넣어주기
        len_ = append_len; // 길이도 새로 저장(이거 꼭 해줘
        return *this;
    }

    // empty가 아니라면 기존 문자열과 str을 합쳐서 새로 할당
    char* new_data = new char[len_ + append_len + 1];
    copy(data_, data_ + len_, new_data);
    copy(str, str + append_len, new_data + len_);
    new_data[len_ + append_len] = '\0';

    delete[] data_;
    data_ = new_data;
    len_ += append_len;

    return *this;
}