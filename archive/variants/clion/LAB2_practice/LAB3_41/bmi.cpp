// Implement your code

#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

bool addBMI(std::vector<int>& bmis, int weight, int height);
bool displayBMIs(const std::vector<int>& bmis);
bool deleteByValue(std::vector<int>& bmis, int value);

bool addBMI(std::vector<int>& bmis, int weight, int height){

 // 100을 곱해서 int 상태로 보관
    if (weight<0 ||height <0) {
        return false;
    }
    else {
        int bmi = static_cast<int>(100.0 * (weight * 10000) / (height * height));
        bmis.push_back(bmi);
        return true;
    }
}

bool displayBMIs(const std::vector<int>& bmis) {
    vector <int> vec = bmis;
    sort(vec.begin(),vec.end(),[](auto x, auto y){return x<y;}); // 람다함수 sort 오름차순은 [](auto x, auto y){return a<b} 이거다 a<b 이거 명심하셈
    for(const auto& lt : bmis){
        double bmi = static_cast<double>(lt)/100.0; //static_cast쓸 때 무조건 괄호 해줘라
        cout << fixed << setprecision(2) << bmi << " "; //iomanip에서 setprecision이다 set 꼭 붙여
    }
}

bool deleteByValue(std::vector<int>& bmis, int value) {
    auto size = bmis.size(); // 이렇게 size메소드로 vector 크기 구할 수 있음
    bmis.erase(remove(bmis.begin(), bmis.end(),value), bmis.end());
    return bmis.size() < size;// 이거보다 크거나 같다는 이야기는 지워지지 않았다는 것, 이렇게 쓴거 기억
}
