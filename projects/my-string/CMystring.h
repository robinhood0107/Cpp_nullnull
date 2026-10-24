#pragma once
#include <cstddef>

class CMyString {
public:
    CMyString() = default;
    CMyString(const CMyString& rhs);
    ~CMyString();
    CMyString& operator=(const CMyString& rhs);
    const char* getData() const { return m_pszData ? m_pszData : ""; }
    std::size_t getLength() const { return length; }
    void setData(const char* text);

private:
    char* m_pszData = nullptr;
    std::size_t length = 0;
};
