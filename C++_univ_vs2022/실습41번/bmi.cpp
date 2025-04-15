// Implement your code

#include "bmi.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

bool addBMI(std::vector<int>& bmis, int weight, int height) {
    if (weight < 0 || height < 0) {
        return false;
    }
    else {
        int bmi = static_cast<int>(100.0 * weight * 10000 / (height * height));
        bmis.push_back(bmi);
        return true;
    }
}

bool displayBMIs(const std::vector<int>& bmis) {
    vector<int> vec = bmis;
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (const auto& lt : vec) {
        double bmi = static_cast<double>(lt) / 100.0;
        std::cout << std::fixed << std::setprecision(2) << bmi << " ";
    }
    cout << endl;
    return true;
}

bool deleteByValue(std::vector<int>& bmis, int value) {
    auto size = bmis.size();
    bmis.erase(remove(bmis.begin(), bmis.end(), value), bmis.end());
    return bmis.size() < size;
}