#include "Organization.hpp"

#include "Department.hpp"
#include "Manager.hpp"
#include "Employee.hpp"
#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>
using namespace std;


//명심 --> override는 헤더에만 명시하는 거다

// Implement your code
Organization::Organization(std::string name):name_{std::move(name)} {

}
void Organization::addDept(std::unique_ptr<Department> dept){
    departments_.push_back(std::move(dept)); //복사 불가!!! 인자로 넣을수만 있다!!!!
}
void Organization::addEmpToDept(Department* dept, std::unique_ptr<Employee> emp){
    dept->addEmployee(std::move(emp));
    //전달받은 dept(부서 포인터)의 addEmployee(std::unique_ptr<Employee>)를 호출해서 직원(Employee)을 부서에 추가
}

void Organization::setDeptManager(Department *dept, std::unique_ptr<Manager> manager){
    dept->setManager(std::move(manager));
}
bool Organization::moveEmp(Department* from, Department* to, Employee* emp){
    //먼저 from 부서에서 해당 직원을 removeEmployee 같은 함수로 꺼냅니다 (std::unique_ptr<Employee> 반환)
    //그리고 그 직원(unique_ptr)이 유효하면, to 부서의 addEmployee/혹은 Organization의 addEmpToDept로 옮깁니다(소유권 이동).
    //(틀림)to->addEmployee(emp); //addEmployee에는 무조건 std::unique_ptr<Employee>가 들어가야 됨!!! Employee*는 들어가면 안된다!!!!

    auto removed = from->removeEmployee(emp); //애초에 Department가 class라서 Department의 메소드인 removeEmployee를 -> 을 통해서 멤버참조 할수 있는 거임
    //항상 생각해야 하는게 removeEmployee는 std::unique_ptr<Employee>를 반환한다!!!!!!이걸 이용하는 거야 !!!!!!
    if (removed) {
        to->addEmployee(std::move(removed)); // 소유권 이동 OK //std::unique_ptr가 함수 인자로 들어갈 땐 무조건 move 써 (소유권 이전은 .get() ->get() 함수인자로 들어갈 땐 std::move())
        return true;
    }
    return false;
}

void Organization::print() const{
    std::cout << "Organization: " << name_ << std::endl;
    for (const auto& dept : departments_) {
        dept->printDetails(std::cout); //이렇게 os출력을 하는 함수를 아예 호출해버리는 거다!!!!
    }
}
