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
//?닿굅??sort?⑥닔 ?뺤떎?섍쾶 ?몄썙媛??
bool comparemy(const Student& s1,const Student& s2){
      return s1.points < s2.points;
}

void my_sort(array<Student, STUDENT_COUNT>& students){
        sort(students.begin(),students.end(),comparemy);
}

//??bool媛?comparemy??mysort 臾댁“嫄??붽린?대몢湲?!!! 爰얠뇿 諛⑺뼢??諛섎뱶???쒕?濡?
//bool媛?comparemy??get_lowest_points, get_highest_points ?ш린???곸슜??
//min_element max_element??留덉갔媛吏濡?bool媛??ъ슜??留덉?留됱뿉 ??갭議??꾩닔)
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




