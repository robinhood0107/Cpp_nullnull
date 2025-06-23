#include "Department.hpp"
#include <vector>
#include <memory>
#include <string>
#include <iostream>
#include <algorithm>

// Implement your code


//항상 생각!!! unique_ptr 파라미터로 보내버릴 때는 move 사용하는 것
Department::Department(std::string name):name_{std::move(name)}{} //이게 핵심이네... unique포인터는 함수인자로 전달할때는 무조건 std::move를 사용해야 함

const std::string& Department::getName() const {
    return name_;
}

void Department::setManager(std::unique_ptr<Manager> manager) {
    manager_ = std::move(manager); //이렇게 manger_라는 내부 class에 집어 넣어버림
}

void Department::addEmployee(std::unique_ptr<Employee> emp){
    employees_.push_back(std::move(emp));
}

std::unique_ptr<Employee> Department::removeEmployee(Employee* emp){
    for (auto lt = employees_.begin(); lt != employees_.end(); ++lt) {
        if (lt->get() == emp) {
            //여기서 lt는 이터레이터라서 "->"로 멤버참조해야 unique_ptr의 원소로 들어가게 되는 것 그래서 -> 쓰는 거다
            //만약에 이터레이터로 받지 않았다면(자체가 unique_ptr이었으면) .을 썼겠지
            //Employee*를 찾는데 찾았으면 unique포인터를 get()메소드로 소유권이전(추출)하는거고 못찾았으면 empolyees_ 백터에서 삭제하면 됨. 삭제는 그냥 erase()로 하면 된다
            auto removed = std::move(*lt);//이 함수를 꼭 기억해라 //- `*it`은 해당 iterator가 가리키는 **unique_ptr 객체** 자체를 반환합니다(참조, 즉 lvalue).
            /*
            - `it`는 iterator,
            - `*it`는 각 원소(즉, unique_ptr &)
            - unique_ptr은 "복사"가 안 되고 반드시 "이동"만 가능
            - **그래서 `std::move(*it)`로 소유권을 옮기는 것**
            - 파라미터든가 대입이라던가 아무튼 지금 상태에서 누군가가 복사하는 행동하면 move 무조건임
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