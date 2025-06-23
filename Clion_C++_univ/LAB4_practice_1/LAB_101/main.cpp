#include "my_accumulate.hpp"
#include <numeric>
#include <iostream>
#include <vector>
#include <string>
#include <list>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    for (const auto& it : vec)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << my_accumulate(vec.cbegin(), vec.cend(), 0) << std::endl;

    std::list<double> numbers = {1., 2., 3., 4., 5.};
    for (const auto& it : numbers)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << my_accumulate(numbers.cbegin(), numbers.cend(), 0.) << std::endl;

    std::list<std::string> strs = {"hello", ",", "world!"};
    for (const auto& it : strs)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << my_accumulate(strs.cbegin(), strs.cend(), std::string("")) << std::endl;

    return 0;
}
