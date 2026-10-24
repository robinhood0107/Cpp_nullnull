#include "CMystring.h"
#include <cstring>
#include <iostream>

int main() {
    auto check = [](bool condition) {
        if (!condition) std::cerr << "문자열 값 검증 실패\n";
        return condition;
    };
    CMyString empty;
    CMyString empty_copy(empty);
    if (!check(empty_copy.getLength() == 0 && std::strcmp(empty_copy.getData(), "") == 0)) return 1;
    CMyString value;
    value.setData("abcdef");
    CMyString copy(value);
    value.setData("other");
    if (!check(std::strcmp(copy.getData(), "abcdef") == 0)) return 1;
    value = copy;
    value = value;
    if (!check(value.getLength() == 6 && std::strcmp(value.getData(), "abcdef") == 0)) return 1;
    value.setData(value.getData() + 2);
    if (!check(std::strcmp(value.getData(), "cdef") == 0 && value.getLength() == 4)) return 1;
    value.setData(nullptr);
    return check(value.getLength() == 0 && std::strcmp(value.getData(), "") == 0) ? 0 : 1;
}
