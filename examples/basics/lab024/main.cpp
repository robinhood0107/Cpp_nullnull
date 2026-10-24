//
// Created by pjjpj on 25. 4. 2.
//
#include <iostream>
#include <iostream>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

constexpr size_t STUDENT_COUNT = 7;

struct Student {
    int id;
    std::string name;
    double points;
};

std::array<Student, STUDENT_COUNT> init_students();
const Student& get_last(const std::array<Student, STUDENT_COUNT>& students);
std::string compare_points(const Student& s1, const Student& s2);
const Student& get_lowest_points(const std::array<Student, STUDENT_COUNT>& students);
const Student& get_highest_points(const std::array<Student, STUDENT_COUNT>& students);
void my_sort(std::array<Student, STUDENT_COUNT>& students);
void print(const Student& s);

int main() {
    std::array<Student, STUDENT_COUNT> students = init_students();

    const Student& last_student = get_last(students);
    std::cout << "Last student: ";
    print(last_student);

    std::cout << compare_points(students[0], students[1]) << std::endl;

    const Student& lowest_student = get_lowest_points(students);
    std::cout << "Student with the lowest points: ";
    print(lowest_student);

    const Student& highest_student = get_highest_points(students);
    std::cout << "Student with the highest points: ";
    print(highest_student);

    std::cout << "Before sorting:" << std::endl;
    for (const auto& s : students) print(s);

    my_sort(students);

    std::cout << "After sorting:" << std::endl;
    for (const auto& s : students) print(s);

    return 0;
}

std::array<Student, STUDENT_COUNT> init_students() {
    return {{
        {1, "Choi", 9.9},
        {2, "Park", 0.1},
        {3, "Kim", 5.0},
        {4, "Lee", 3.0},
        {5, "Moon", 9.5},
        {6, "Kang", 7.0},
        {7, "Jeon", 0.9}
    }};
}

//Implement your code
//이거랑 sort함수 확실하게 외워가라
bool comparemy(const Student& s1,const Student& s2){
      return s1.points < s2.points;
}

void my_sort(array<Student, STUDENT_COUNT>& students){
        sort(students.begin(),students.end(),comparemy);
}

//이 bool값 comparemy랑 mysort 무조건 암기해두기!!!! 꺾쇠 방향도 반드시 제대로
//bool값 comparemy는 get_lowest_points, get_highest_points 여기에 적용됨
//min_element max_element도 마찬가지로 bool값 사용함(마지막에 역참조 필수)
const Student& get_last(const std::array<Student, STUDENT_COUNT>& students){
    return students[6];
}
string compare_points(const Student& s1, const Student& s2){


}
const Student& get_lowest_points(const array<Student, STUDENT_COUNT>& students){


}
const Student& get_highest_points(const array<Student, STUDENT_COUNT>& students){


}
void print(const Student& s){

}




