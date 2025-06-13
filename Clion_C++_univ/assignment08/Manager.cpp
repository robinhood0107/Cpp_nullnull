#include "Manager.hpp"
#include <cmath>

// Implement your code




Manager::Manager(std::string name, int salary): Employee{std::move(name),salary}{
}
double Manager::calculatePay() const{
    return std::floor(static_cast<double>(getSalary())*1.1/12);  //double은 cout으로 출력될 때 무조건 소수점 올림을 해버리기 때문에 버림이 필요함
    //버림 함수는 std::floor <cmath> 헤더 쓴다
    //부모가 private이면 이런식으로 접근하는거다!!!!
}