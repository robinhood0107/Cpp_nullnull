#include <string>
#include <iostream>
// Implement your code


class Student{
public:
    Student() = default;
    Student(const std::string& str): name{str}{}
    Student(std::string&& s): name{std::forward<std::string>(s)}{}
    Student(const std::string& str, int y): name{str}, year{y}{}
    Student(std::string&& s, int y): name{std::forward<std::string>(s)}, year{y}{}
    friend std::ostream& operator<<(std::ostream& os, const Student& s){
        if(s.year==0)
            os << s.name;
        else
            os << s.name << " " << s.year;
        return os;
    }
private:
    std::string name{};
    int year{1};
};