#include "CMystring.h"
#include <iostream>
#include <algorithm>

// 강의 보면서 직접 짜기
using namespace std;

CMyString::CMyString() {
	cout << "CMyString()" << endl;
}

CMyString::CMyString(const CMyString& rhs)
{
	this->setData(rhs.getData());
}

CMyString::~CMyString() {
	cout << "~CMyString()" << endl;
	delete[] m_pszData;
}

void CMyString::setData(const char* pParam)
{
	if (m_pszData != nullptr)
		delete[] m_pszData;

	size_t length = strlen(pParam);
	m_pszData = new char[length + 1];

	strcpy_s(m_pszData, length + 1, pParam);
	this->length = length;
}