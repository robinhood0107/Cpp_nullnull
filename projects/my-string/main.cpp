#include "CMystring.h"
#include <iostream>

int main() {
    CMyString text;
    text.setData("Hello, C++");
    CMyString copy = text;
    std::cout << copy.getData() << " (" << copy.getLength() << ")\n";
}
