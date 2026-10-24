#include <algorithm>
#include <complex>
#include <iostream>
#include <string>
#include <vector>

#include "MyList.hpp"

using namespace std::complex_literals;

int main() {

    MyList<std::complex<double>, 5> complexList;

    std::complex<double> z1 = {0. + 0i}, z2 = {1. + 1i}, z3 = {2. + 2i};
    complexList.add(z1); complexList.add(z2); complexList.add(z3);

    std::vector<std::complex<double>> cTargets = {{0. + 0i}, {1. + 0i}};
    for(auto target : cTargets) {
        auto found = find(complexList.begin(), complexList.end(), target);
        if (found != complexList.end()) std::cout << "Found: " << *found << std::endl;
    }

    MyList<std::string, 5> stringList;
    std::string s1 = "abc", s2 = "def", s3 = "ghi";

    stringList.add(s1); stringList.add(s2); stringList.add(s3);

    std::vector<std::string> sTargets = {"ccc", "abc"};
    for(auto target : sTargets) {
        auto found = find(stringList.begin(), stringList.end(), target);
        if (found != stringList.end()) std::cout << "Found: " << *found << std::endl;
    }

    complexList.remove(z1);
    for (auto z : complexList) std::cout << z << std::endl;

    stringList.remove(s1);
    for (auto s : stringList) std::cout << s << std::endl;

    MyList<std::string, 5> stringList2(stringList);  // copy constructor
    stringList2.add(s1);
    for (auto s : stringList) std::cout << s << std::endl;
    for (auto s : stringList2) std::cout << s << std::endl;

    MyList<std::string, 5> stringList3;
    stringList3 = stringList2;              // copy assignment
    stringList3.remove(s2);

    for (auto s : stringList3) std::cout << s << std::endl;
    for (auto s : stringList2) std::cout << s << std::endl;
}