실습 095 - class hierarchy
업로드 가능한 파일 수: 2
제출 방식: 개인


목적


이 실습은 클래스의 hierarchy 만드는 연습을 합니다. 



설명


Employee 클래스를 상속 받은 Manager, Programmer, Salesperson 클래스를 구현합니다.





문제


주어진 프로그램이 정상적으로 동작하도록 필요한 클래스들을 구현하시오.



// Employee.h
class Employee {
public:
    Employee(string name, int salary) : name_(name), salary_(salary) {}
    virtual void print_report() const { 
        cout << "Name: " << name_ << endl;
        cout << "Salary: " << salary_ << endl;
        cout << "Years of service: " << years_of_service_ << endl;
        cout << "Performance score: " << performance_score_ << endl;
    }
    string get_name() const {
        return name_;
    }
protected:
    string name_;
    int salary_;
    int years_of_service_ = 0;
    int performance_score_ = 0;
};
// 다른 클래스들도 구현하시오.


//EmployeeTest.cpp

#include "Employee.h"

int main() {
    Manager m = Manager("Alice", 50000, "Marketing");
    Programmer p = Programmer("Bob", 60000, "C++");
    Salesperson s = Salesperson("Charlie", 40000, 100000);

    m.set_goals();
    p.write_code();
    s.sell();

    Employee* e1 = &m;
    Employee* e2 = &p;
    Employee* e3 = &s;

    e1->print_report();
    e2->print_report();
    e3->print_report();
}



입력


없음





출력


Set goals for Marketing

Writing code in C++

Selling products, generated 100000 in revenue

Name: Alice

Salary: 50000

Years of service: 0

Performance score: 0

Department: Marketing

Name: Bob

Salary: 60000

Years of service: 0

Performance score: 10

Language: C++

Name: Charlie

Salary: 40000

Years of service: 0

Performance score: 20

Sales: 100000





제출파일


Employee.h 