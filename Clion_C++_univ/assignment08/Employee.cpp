#include "Employee.hpp"
#include <utility>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;
int Employee::nextId_ = 1; //이렇게 static 변수 선언해주기

// Implement your code

Employee::Employee(std::string name, int salary): name_{std::move(name)},salary_{salary},id_{nextId_++}{ //내가 틀린 부분: 이렇게 nextId_++를 아예 초깃값으로 넣어버리는 거다!!!!!
}

string Employee::getName() const{
    return name_;
}
int Employee::getId() const{//id{} 이런 멤버 이니셜라이저 목록은 오직 생성자에서만 사용할 수 있습니다. 함수에서 쓰면 컴파일 에러
    return id_;
}
int Employee::getSalary() const{
    return salary_;
}
double Employee::calculatePay() const{
    return std::floor(static_cast<double>(salary_) / 12); //내가 틀린 부분: static_cast<double>(salary_) 이렇게 double로 변환할 부분만 변환하기
}
//추가적으로 또 틀린 부분
//double은 cout으로 출력될 때 무조건 소수점 올림을 해버리기 때문에 버림이 필요함
//버림 함수는 std::floor <cmath> 헤더 쓴다
void Employee::printDetails(std::ostream& os) const{
    os << getName() << " " << getId() << " (Annual: " << getSalary() << ", Monthly Pay: " << calculatePay() << ")";
}