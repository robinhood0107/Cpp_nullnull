#include "Student.hpp"
#include "my_make_unique.hpp"
#include <iostream>

int main() {
    std::string name = "Kim";
    int year = 4;
    auto s3 = my_make_unique<Student>(name, year);
    auto s4 = my_make_unique<Student>("Lee", 4);
    auto s5 = my_make_unique<Student>(std::string("Choi"));

    std::cout << *s3 << std::endl;
    std::cout << *s4 << std::endl;
    std::cout << *s5 << std::endl;

    return 0;
}