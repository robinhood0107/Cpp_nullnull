#include "Department.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

// Implement your code
Department::Department(std::string name):name_{std::move(name)}{ //이게 핵심이네... unique포인터는 함수인자로 전달할때는 무조건 std::move를 사용해야 함
}
const std::string& Department::getName() const {
    return name_;
}

void Department::setManager(std::unique_ptr<Manager> manager){
    manager_ = std::move(manager);
}
void Department::addEmployee(std::unique_ptr<Employee> emp){
    employees_.push_back(std::move(emp));

}
std::unique_ptr<Employee> Department::removeEmployee(Employee* emp){
    for (auto lt = employees_.begin(); lt != employees_.end(); ++lt) {
        if (lt->get() == emp) {
            //여기서 lt는 이터레이터라서 "->"로 멤버참조해야 unique_ptr의 원소로 들어가게 되는 것 그래서 -> 쓰는 거다
            //Employee*를 찾는데 찾았으면 unique포인터를 get()메소드로 소유권이전(추출)하는거고 못찾았으면 empolyees_ 백터에서 삭제하면 됨. 삭제는 그냥 erase()로 하면 된다
            auto removed = std::move(*lt);//이 함수를 꼭 기억해라 //- `*it`은 해당 iterator가 가리키는 **unique_ptr 객체** 자체를 반환합니다(참조, 즉 lvalue).
            /*
            - `it`는 iterator,
            - `*it`는 각 원소(즉, unique_ptr &)
            - unique_ptr은 "복사"가 안 되고 반드시 "이동"만 가능
            - **그래서 `std::move(*it)`로 소유권을 옮기는 것**
            */
            employees_.erase(lt); //erase를 사용하려면 무조건 이터레이터가 필요해서 for(;;) 문이 필요함. (금지) 범위기반 for문 사용 금지
            return removed;
        }
    }
    return nullptr; //내가 틀린 부분: 이거 위치 매우매우 조심해라 !!!! for문 밖에 있어야 한다!!!!!
}
void Department::printDetails(std::ostream& os) const {
    os << getName() << std::endl;
    if (manager_) {
        os << "    |---Manager: ";
        manager_->printDetails(os); //이렇게 std::unique_ptr<Manager> 인 자료형 Manager class의 상속받은 메소드 printDetails (부모인 Employee에서 상속받은 거임) 를 멤버 참조한거다!!!
        //존나게 중요함
        os << std::endl;
    }
    for (const auto& emp : employees_) {
        // 매니저는 별도 필드에 있으니 employees_ 중 매니저와 동일 포인터는 건너뜀

        os << "    |---";
        emp->printDetails(os); //이건 std::unique_ptr<Employee> 인 자료형 Employee class의 메소드 printDetails 그대로 참고
        os << std::endl;
    }
}



/*
 *for (const auto& emp : employees_) 함수 관련 질문
 *
 *
        질문 :: `if (manager_ && emp.get() == manager_.get()) continue;` 이 조건문 없어도 되는거지?

        답변 ::  네, 맞습니다!
                `if (manager_ && emp.get() == manager_.get()) continue;`
                이 조건문은 **매니저와 일반 직원이 섞여 있을 때**(즉, 매니저도 employees_ 벡터에 같이 있을 때)
                **중복 출력을 막으려고 사용하는 코드**입니다.
                #### **하지만, 지금 구조(권장 구조)에서는 조건문이 필요 없습니다!**
                - 매니저는 멤버 변수로만 관리합니다. `manager_`
                - 일반 직원은 벡터로만 관리합니다. `employees_`
                - 출력 시 printDetails에서 매니저만 별도로 출력, 직원만 별도로 for문으로 출력합니다.

                즉, **직원 리스트()에 매니저를 넣지 않으면`employees_`**
                `(manager_ && emp.get() == manager_.get()) continue;`
                이 코드는 필요 없습니다. (실제로 조건이 걸릴 일이 없음)


                ### **정리**
                - 매니저는 setManager로만 관리하고, employees_에는 넣지 않는 구조 => 조건문 삭제 OK!
                - 만약 매니저를 employees_에도 넣는 옛날 코드만 있을 때는 중복 방지용으로 필요할 수 있습니다.

         */