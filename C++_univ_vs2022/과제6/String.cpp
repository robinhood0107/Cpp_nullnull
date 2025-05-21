#include "String.h"
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <string>

//private 변수 
//static int count_;
//char* data_;
//size_t len_;

static int count_ = 0;

String::String() :len_{0} {
	//빈 string (length 0, null로 끝나는 데이터)
	data_ = new char[len_ + 1];
	data_[0] = '\0';
	count_++;
	std::cout << "Constructor" << std::endl;
	std::cout << "# of String object: " << count_ << std::endl;
}

String::String(const char* s) {
	// If s == nullptr, treat it as empty string.
	if (s == nullptr) {
		String() ;
	}
	else {
		len_ = size();
		data_ = new char[len_ + 1];
		std::copy(s, s + size(), data_);
		std::cout << "Copy Constructor" << std::endl;
		std::cout << "# of String object: " << count_ << std::endl;
	}
}//explicit 키워드 때문에 묵시적 형변환을 하지 못한다.묵시적 형변환은 앞에 변환할 자료형을 붙여주지 않고 값을 변환하는 것을 의미한다
String::~String() noexcept {
	delete[] data_;
	std::cout << "Destructor" << std::endl;
	std::cout << "# of String object: " << --count_ << std::endl;
	//소멸자
}
String::String(const String& s) noexcept {
	//위 string(const char* s)의 복사 생성자
	len_ = size();
	data_ = new char[len_ + 1];
	std::copy(s.data_, s.data_ + size(), data_);
	std::cout << "Copy Constructor" << std::endl;
	std::cout << "# of String object: " << count_ << std::endl;
}
const char* String::data() const {
	return data_;
}
bool String::empty() const {
	auto lt = std::find(data_, data_ + size(), NULL);
	if (len_ == 0 && lt != 0) {
		return true;
	}
	else
		return false;
}
size_t String::size() const {
	return strlen(data_);
}
String& String::append(const String& str) {
	if (str.empty()) {
		String s1(data_);
		return s1;
	}
	else {
		char * = new char[]
		char  = data_+str.data_
		String s1(data_);

		return;
	}
}
String& String::append(const char* str) {
	if (str == '\0') {
		return ;
	}
	else {
		data_ + str;
	}
}