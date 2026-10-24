#include "CMystring.h"
#include <cstring>

CMyString::CMyString(const CMyString& rhs) { setData(rhs.getData()); }
CMyString::~CMyString() { delete[] m_pszData; }

CMyString& CMyString::operator=(const CMyString& rhs) {
    if (this != &rhs) setData(rhs.getData());
    return *this;
}

void CMyString::setData(const char* text) {
    const std::size_t size = text ? std::strlen(text) : 0;
    char* replacement = new char[size + 1];
    // 기존 버퍼 안의 문자열을 인자로 받아도 복사 후에 해제한다.
    if (size != 0) std::memcpy(replacement, text, size);
    replacement[size] = '\0';
    delete[] m_pszData;
    m_pszData = replacement;
    length = size;
}
