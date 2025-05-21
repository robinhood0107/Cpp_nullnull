#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <string>
using namespace std;

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


//너무 중요해서 여러번 반복함

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라
Shape

//가상 함수의 작동 원리를 제대로 알아야 한다.
// 다형성이랑 관련이 있음
//!!!!!!!!!!!!!!!!!!!!!!(주의)!!!!!!!!!!!!!!!!!!!!!!!!!!
// 함수 오버라이드는 c++에서 절대 하지 말아야 하는 행동 중 하나이다. 함수 재정의가 필요하면 무조건 virtual (가상) 함수 쓰기
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


// 함수 오버라이드 절대 쓰지 말기 

// 함수 재정의가 필요한 경우에는 무조건 virtual 을 사용해야 한다.
//Virtual function (가상 함수 )
//어느 함수를 호출할지는 컴파일 시간에 하지 말고, 실행할 때 결정해 달라는 것. 메모리에 있는 객체를 조사한 후 호출함.
//부모랑 자식이랑 함수명은 같은데 다른 멤버함수를 가질 수 있음

//클래스의 일반 멤버함수와 가상함수의 차이점)
/*
일반 멤버 함수
1. static binding
2. 컴파일러가 컴파일 시간 호출을 결정
3.(중요) 포인터의 타입으로 함수 호출을 결정
4. 클래스명::함수() 호출

가상 함수 (virtual function)
1. dynamic binding
2. 실행 시간에 메모리를 조사해서 함수 호출을 결정
3. (중요) 실제 메모리에 놓인 객체 타입으로 함수 호출 결정 (그니까 현재 가상함수를 가지고 있는 객체가 소유한다)(그래서 부모랑 자식이랑 함수명은 같은데 다른 멤버함수를 가질 수 있음)
4. 현재 위치해 있는 파생 클래스명(주로 자식 클래스가 됨)::함수()
*/

//예시 코드
/*
#include <iostream>

class Mother
{
public:
    virtual void nData() { std::cout << "Mother::nData" << std::endl; }
};
class child : public Mother
{
public:
    virtual void nData() { std::cout << "child::nData" << std::endl; }
};

int main()
{
    Mother s;
    child r;
    Mother* p = &r;

}
*/

    // 위 코드를 컴파일 할때
    // p가 어느객체를 가리킬지 컴파일러가 알수 있을까 ?
    //p->nData();    // child::nData



    /*
    위 문제는 이렇게 해석할 수 있다.
    
    위 코드를 컴파일할 때
    포인터 p가 어떤 객체(어떤 클래스의 인스턴스)를 가리키는지 컴파일러가 알 수 있을까?
    //p->nData();    // child::nData
    */

            //설명:
            // 
            // 
            //              p->nData();               child::nData
            // 
            //이 코드는 다형성(Polymorphism)과 가상 함수(virtual function)의 동작 원리를 설명하기 위한 예시.
            // 
            //Mother* p = &r; 에서 p는 Mother 타입의 포인터이지만, 실제로는 child 객체를 가리키고 있습니다.
            //따라서 p->nData(); 를 호출하면, 컴파일러는 컴파일 시점에는 p가 어떤 객체를 가리키는지 확정할 수 없습니다.
            //
            // 
            //그래서 실행 시점에 p가 가리키는 실제 객체(child)의 nData()가 호출됩니다.
            //이것이 바로 동적 바인딩(dynamic binding)이며, 가상 함수의 핵심 동작 방식입니다.
            // 
            // 
            //즉,
            //•	컴파일러는 p가 어떤 객체를 가리키는지 알 수 없다.
            //•	실행 시점에 실제 객체 타입(child)의 함수가 호출된다.



            // <<<<<<<<<<<<이해를 위해 내가 적어보는 설명>>>>>>>>>>>>>>>>
            // 
            // 
            // 
            //(이게 포인터 p가 Mother 객체 타입의 포인터이긴 한데 실제 주소는 child의 인스턴스의 주소를 가지기 때문)
            // 
            // Mother* p = &r;에서 p는 타입이 Mother*인 포인터입니다.하지만 실제로 p가 가리키는 주소는 child 객체 r의 메모리 주소입니다.
            // 즉, 
            // 포인터의 타입은 Mother* 이지만
            // 실제 가리키는 객체는 child 타입의 인스턴스입니다.
                /*

                이런 상황에서 가상 함수(virtual)를 사용하면,
                p->nData(); 호출 시 실행 시점에 실제 객체 타입(child)의 nData()가 호출됩니다.
                이것이 C++의 다형성과 동적 바인딩의 핵심입니다.

                */

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라

//가상 함수가 아닌 함수를 재정의 하지 말라. (c++ 격언) -> 함수 재정의는 가상함수만 써라


class Manager : public Employee{
    public:
        Manager(const string& name,const int& salary,const string& Department): Employee{name,salary},Department_{Department}{
        }
        void set_goals(){
            cout << "Set goals for " << Department_ << endl;
            years_of_service_ = 0;
            performance_score_ = 0;
        }
        virtual void print_report() const { 
            cout << "Name: " << name_ << endl;
            cout << "Salary: " << salary_ << endl;
            cout << "Years of service: " << years_of_service_ << endl;
            cout << "Performance score: " << performance_score_ << endl;
            cout << "Department: " << Department_ << endl;
        }
    private:
        string Department_{};
};
class Programmer: public Employee{
    public:
        Programmer(const string& name,const int& salary,const string& Language): Employee{name,salary},Language_{Language}{
        }
        void write_code(){
            cout << "Writing code in " << Language_ << endl;
            years_of_service_ = 0;
            performance_score_ = 10;
            
        }
        virtual void print_report() const { 
            cout << "Name: " << name_ << endl;
            cout << "Salary: " << salary_ << endl;
            cout << "Years of service: " << years_of_service_ << endl;
            cout << "Performance score: " << performance_score_ << endl;
            cout << "Language: " << Language_ << endl;
        }
    private:
        string Language_{};
};
class Salesperson: public Employee{
    public:
        Salesperson(const string& name,const int& salary,const int& Sales): Employee{name,salary},Sales_{Sales}{
        }
        void sell(){
            cout << "Selling products, generated " << Sales_ << " in revenue" << endl;
            years_of_service_ = 0;
            performance_score_ = 20;
        }
        virtual void print_report() const { 
            cout << "Name: " << name_ << endl;
            cout << "Salary: " << salary_ << endl;
            cout << "Years of service: " << years_of_service_ << endl;
            cout << "Performance score: " << performance_score_ << endl;
            cout << "Sales: " << Sales_ << endl;
        }
    private:
        int Sales_{};
};

#endif // EMPLOYEE_H