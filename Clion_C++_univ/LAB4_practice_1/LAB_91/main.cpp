#include <iostream>
#include <string>

class Person {
    //항상 클래스의 기본 접근제어 형식은 private
protected:
    std::string _name{0}; // 파새에서 사용할 수 있게하는게 protected
public:
    explicit Person(std::string&& name) : _name{std::move(name)} {// explicit 이건 선택임 비변환 이라는 뜻
        // 이런 방식으로도 파라미터를 넘겨 줄 수 있음
        std::cout << "Person is constructed!" << std::endl;
    }
    ~Person() {
        std::cout << "Person is destructed!" << std::endl;
    }
    void print() const { //const도 선택임
        std::cout << "Person Name: " << _name << std::endl;
    }
};

class Student : Person { //이런 방식으로 상속임을 나타낼 수 있음!!!! 이거 꼭 기억
    //항상 상속시킬 때는 파생의 경우 생성자에서 기본 클래스의 파라미터 전부 지정해줘야 함
    std::string _schoolName{};
public:
    Student(std::string&& name, std::string&& schoolName) : Person{std::move(name)},_schoolName{std::move(schoolName)} {
        std::cout << "Student is constructed!" << std::endl;
    }

    void print() const { //const도 선택임
        std::cout << "Person Name: " << _name << std::endl;
        std::cout << "School Name: " << _schoolName << std::endl;
    }
    ~Student(){
        std::cout << "Student is destructed!" << std::endl;
    }
};




int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}