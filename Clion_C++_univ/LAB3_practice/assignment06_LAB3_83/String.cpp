#include "String.h"
#include <cstring> 
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;



int String::count_ = 0; // static 변수 초기화 (꼭 하기)


// 일단 기본 생성자 (디폴트 생성자) 만들기
String::String() :len_{0} { // 문자열의 길이는 0이지만
	//빈 string (length 0, null로 끝나는 데이터)
	data_ = new char[len_ + 1]; // 공간은 1이고 (문자열 맨 마지막은 null문자 '\0'가 들어가야 하기 때문 << data_ = new char[len_ + 1]; 이랑 같다
	data_[0] = '\0'; // 할당받은 1의 공간에 '\0' null문자 넣기
	count_++; // static 변수인 count_ 1 증가시키고, 출력 처리
	cout << "Default Constructor\n# of String object: " << count_ << '\n';
}

//그리고 일단 소멸자
String::~String() noexcept { // 소멸자: 소멸자는 생성자 종류에 상관없이 공통으로 사용 가능하도록
	delete[] data_;
	cout << "Destructor\n# of String object: " << count_ << '\n';
	count_--; //!!!!!!!!!!!!!(주의)!!!!!!!!!!!!! 내가 이거 안해서 틀림
	//소멸자
}


// C 스타일 문자열을 입력으로 받았을 때 처리하는 생성자
// string 길이 구할때는 반드시 strlen 함수 사용하기!!!!!!!! size_t len = strlen(str);
String::String(const char* str) { 
	len_ = strlen(str); // 문자열의 길이는 입력받은 C-style string의 길이. 이때 strlen(str);을 이용
	data_ = new char[len_ + 1]; // data_ = new char[len_ + 1]; // 마지막에 null 문자 들어가야 되잖아
	copy(str, str + len_, data_); //std::copy(str, str + size(), data_); 난 이렇게 했었음
	data_[len_] = '\0'; // 반드시 추가! (이거 안하면 메모리 누수 발생)
	count_++;
	cout << "Constructor\n# of String object: " << count_ << '\n';
}
//explicit 키워드 때문에 묵시적 형변환을 하지 못한다.묵시적 형변환은 앞에 변환할 자료형을 붙여주지 않고 값을 변환하는 것을 의미한다
//그니깐 간단히 말하자면 형변환을 엄격하게 적용하겠다는 키워드가 explicit


String::String(const String& str) noexcept { 
	// 다른 String 객체를 복사해서 생성할 때 사용됨
	// String a(b) 이런식으로 String a = b;와 같으니까 b라는 객체를 복사해서 a는 복사생성자를 호출하게 된다.
	// (class가 있고 b라는 객체(인스턴스)가 선언되어 있는데, class에 미리 복사생성자가 만들어져 있으니까 b 객체도 복사생성자를 가짐, a는 그 b가 가지고 있는 복사 생성자를 호출함)
	
	////만약 자기 자신을 append 할 경우에는 임시 복사본 사용하도록 방어함
	//if (this == &str) {
	//	// 자기 자신을 append하는 경우, 임시 복사본 사용
	//	String temp(str);
	//	return append(temp.data_);
	//}

	len_ = str.len_; //매개변수로 받은 객체의 str길이가 저장된 변수 len_
	data_ = new char[len_ + 1]; //반드시 동적할당 해주고, len_+1로 null 자리 꼭 만들어주기
	copy(str.data_, str.data_ + len_, data_); //std::copy(str.data_, str.data_ + len_, data_); 난 이렇게 했음
	data_[len_] = '\0'; // 수동으로 널 문자 추가 (이거 꼭 해줘야 함) (null값은 자동으로 안들어가서 string의 제일 마지막(배열로 보면 len_인덱스가 문자열 끝 바로 뒤임)에 반드시 null값을 넣어줘야 함
	count_++;
	cout << "Copy Constructor\n# of String object: " << count_ << '\n';
}

const char* String::data() const {
	return data_;
}

bool String::empty() const {
	return !len_;
	//굳이 아래처럼 안해도 되고 bool 특성을 이용해서 길이가 0이면 true, 길이가 0이 아니면 false을 반환하도록 한다.]

	/*
	코드를 하나하나 쉽게 짜는 법))
	그리고 추가 팁인데 클래스 작성할 때 하나의 코드를 전부 완성한다고 생각하지 말고 
	일단 작동이라도 시켜봐야 되니까 (부분점수라도 당연히 따야 되잖아)
	len_==0 이렇게 임시로 데이터 주고 다른 클래스 멤버 함수 실험해도 됨
	*/

	/*
	auto lt = std::find(data_, data_ + size(), NULL);
	if (len_ == 0 && lt != 0) {
		return true;
	}
	else
		return false;
	*/
}
size_t String::size() const {
	return len_; //그냥 return len_;으로 반환하기
	/*return strlen(data_);*/
}
String& String::append(const String& str) { //이렇게 String&은 항상 return *this 이걸 해준다고 생각하면 된다(이건 걍 자동 반사적으로 암기)
	char* new_data = new char[len_ + str.len_ + 1]; //string+string에 해당하는 결과값 넣을 동적 변수 1개 생성
	// std::copy(복사 시작지점, 복사 끝 지점, 붙여넣기 시작할 지점)
	copy(this->data_, this->data_ + len_, new_data); // std::copy
	copy(str.data_, str.data_ + str.len_, new_data + len_); // std::copy
	// copy를 통해서 new_data에 0~len_까지 this->data_포인터(위치)를 넣고, len_~ str.data_+str.len_ 까지  str.data_포인터를 넣는다. 
	// (이게 this->data_의 마지막 문자가 null값이라서 인덱스가 len_이라 자동으로 거기가 str.data_의 시작이 되면서 자연스럽게 덮어쓰워져서 맨 뒤 str.data_ null값 1개만 남게 됨.)	
	new_data[len_ + str.len_] = '\0'; // 널 종료 문자 추가 (이거 잊지마 string의 끝은 항상 null 이다. 그리고 위의 copy 넣는 방식에서 보았듯이 null 값은 반드시 len_에 위치해야 한다는거도 이해 가능)

	delete[] data_;
	data_ = new_data;
	len_ += str.len_;
	//반드시 delete[]을 이용해서 메모리 해제 해주기(사용 끝났으면 반드시 해라. 스마트 포인터 사용 안할꺼면 메모리 누수 문제로 반드시 해줘야 함. 이거 명심해. 
	// 버그의 근원이라 반드시 잊지말고 해

	return *this;
}

String& String::append(const char* str) {
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