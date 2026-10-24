#include <iostream>
#include <string>
using namespace std;

class Person{
    public:
        Person(const string& name): name_{name}{
            cout << "Person is constructed!" << endl;
        }
        void print() const {
            cout << "Person Name: " << name_ << endl;
        }
        ~Person(){
            cout << "Person is destructed!" << endl;
        }
    protected:
        string name_{};
};

class Student : public Person{
        string schoolName_{};
    public:
        Student(const string& name, const string& schoolName) : Person{name},schoolName_{schoolName}{ //:Person{name} 이렇게 부모 꼭 초기화 해주기 (반드시 부모 생성이 되야 자식도 생성됨)            cout << "Student is constructed!" << endl;
            cout << "Student is constructed!" << endl;
        }
    
        void print() const {
            cout << "Person Name: " << name_ << endl;
            cout << "School Name: " << schoolName_ << endl;
        }
        ~Student(){
            cout << "Student is destructed!" << endl;
        }
};

int main() {
    Person p1{"Park"};
    p1.print();

    Student s1 {"Kim", "PNU"};
    s1.print();

    return 0;
}