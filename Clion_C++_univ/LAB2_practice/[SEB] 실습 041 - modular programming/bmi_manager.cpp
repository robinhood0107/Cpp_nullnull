#include "bmi_manager.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
using namespace std;

static std::vector<int> bmis;

bool add_bmi(int weight, int height) {
    //Implement your code
    if (weight < 0 || height < 0){
        return false;
    }
    else {
        int bmi = static_cast<int>(100.0 * weight * 10000 / (height * height));
        bmis.push_back(bmi);
        return true;
    }
}

bool show_bmi() {
    //Implement your code
    vector<int> vec = bmis;
    sort(vec.begin(), vec.end());
    cout << vec.size() << "\n";
    for (const auto& lt : vec){
        double bmi = static_cast<double>(lt) / 100.0;
        cout << fixed << setprecision(2) << bmi << " ";
    }
    cout << endl;
    return true;
    
}

bool drop_value(int value) {
    //Implement your code
    auto size = bmis.size();
    bmis.erase(remove(bmis.begin(), bmis.end(), value), bmis.end());
    return bmis.size() < size;
}

int count_bmi() {
    //Implement your code
    auto size = bmis.size();
    return size;
    
}
