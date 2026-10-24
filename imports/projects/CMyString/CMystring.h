#pragma once
//#ifndef String_HPP
//#define String_HPP


//카멜 표기법

// //클래스 이름은 반드시 대문자로 한다//JAVA,C#도 마찬가지다!!! Mydata 이런방식으로 작명함
//근데 C++개발자들은 앞에 C를 붙여버림 (Mydata를 CMydata 이렇게)(C에선 구조체와 클래스를 확실하게 구분하고 싶어 하기 때문에 앞에 대문자 C를 붙이는 것이다)
//근데 이 관습이 옳다고는 못하겠음(애매함...)
//확실한 건 요즘은 C를 안적고 걍 Mydata 이렇게 적는게 맞음

//클래스의 멤버 데이터의 경우에는 int data;라면 int m_data라고 "m_"를 붙인다.
//private 멤버 데이터의 경우 앞에 언더바를 반드시 붙여준다. int data면 _data
//여기선 카멜 표기법을 준수할 생각임.


//그리고 vs의 클래스뷰와 같이 개발 방법을 숙지할 것!!!

//TIP
//바로 윗줄 복사 붙여넣기는 ctrl+D
class CMyString
{
public:
	CMyString();
	CMyString(const CMyString& rhs);
	~CMyString();

	const char* getData() const {
		return m_pszData;
	}

	size_t getLength() const {
		return this->length;
	}

	void operator=(const CMyString& rhs) {
		this->setData(rhs.getData());
	}

	void setData(const char* pParam);

private:
	char* m_pszData = nullptr;
	size_t length = 0;
};
	



//#endif

