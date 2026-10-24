#include <iostream>
#include <cassert>
#include <cstring>
#include "String.h"

void test_case1();
void test_case2();
void test_case3();
void test_case4();

int main(){
    std::cout <<  "\n\n" << "Testing the default constructor: " << "\n\n";
    test_case1();

    std::cout <<  "\n\n" <<  "Testing the constructor that takes a C-style string:" << "\n\n";
    test_case2();

    std::cout <<  "\n\n" << "Testing the copy constructor:" <<  "\n\n";
    test_case3();

    std::cout <<  "\n\n" << "Testing the append() function:" <<  "\n\n";
    test_case4();
}

void test_case4() {
    String s11("hello");
    String s12("world");
    s11.append(s12);
    assert(!s11.empty());
    assert(s11.size() == 10);
    assert(strcmp(s11.data(), "helloworld") == 0);

    String s13("");
    String s14("test");
    s13.append(s14);
    assert(!s13.empty());
    assert(s13.size() == 4);
    assert(strcmp(s13.data(), "test") == 0);
}

void test_case3() {
    String s3("hello");
    String s4(s3);
    assert(!s4.empty());
    assert(s4.size() == 5);
    assert(strcmp(s4.data(), "hello") == 0);

    String s5("");
    String s6(s5);
    assert(s6.empty());
    assert(s6.size() == 0);
    assert(s6.data()[0] == '\0');
}

void test_case2() {
    String s1("hello");
    assert(!s1.empty());
    assert(s1.size() == 5);
    assert(strcmp(s1.data(), "hello") == 0);

    String s2("");
    assert(s2.empty());
    assert(s2.size() == 0);
    assert(s2.data()[0] == '\0');
}

void test_case1() {
    String s;
    assert(s.empty());
    assert(s.size() == 0);
    assert(s.data()[0] == '\0');
}