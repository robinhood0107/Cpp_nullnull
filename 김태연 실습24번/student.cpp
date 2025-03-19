#include "student.h"
#include <algorithm>

std::array<Student, STUDENT_COUNT> init_students() {
    return { {
        {1, "Choi", 9.9},
        {2, "Park", 0.1},
        {3, "Kim", 5.0},
        {4, "Lee", 3.0},
        {5, "Moon", 9.5},
        {6, "Kang", 7.0},
        {7, "Jeon", 0.9}
    } };
}

//Implement your code
std::string compare_points(Student& a, Student& b) {
    if (a.points < b.points){
        return b.name + " has more points than " + a.name + "\n";
    }
    else
        return a.name + " has more points than " + b.name + "\n";
}
/*
주의) std::cout은 std::string을 반환하지 않고 std::ostream&을 반환합니다. 즉, cout의 반환값은 string이 아니라 ostream임(아예 직접 콘솔에 쏴버리는 거니까)

아래는 내가 틀린 코드
std::string compare_points(Student& a, Student& b) {
    if (a.points < b.points){
        return std::cout << b.name << " has more points than "<< a.name << std::endl;
    }
    else
        return std::cout << a.name << " has more points than " << b.name << std::endl;
}

해결법1 = 함수 형식을 void로 한다
해결법2 = 출력값을 cout을 쓰는 게 아니라 return b.name + " has more points than " + a.name; 이런 방식으로 문자열 붙여서 사용한다 (추천)
해결법3 = 마지막에 빈 문자열 출력
std::string compare_points(Student& a, Student& b) {
    if (a.points < b.points){
        std::cout << b.name << " has more points than "<< a.name << std::endl;
    }
    else
        std::cout << a.name << " has more points than " << b.name << std::endl;
}
    return ""
해결법4 = printf 쓰던가 (정 안되면 이거라도 해야지)
*/

bool compareByPoints(const Student& a, const Student& b) {
    return a.points < b.points;
}

void my_sort(std::array<Student, STUDENT_COUNT>& students) {
    std::sort(students.begin(), students.end(), compareByPoints);
}

auto get_last(std::array<Student, STUDENT_COUNT>& students) { 
    //auto get_last(std::array<Student, STUDENT_COUNT>& students) 이렇게 하면 안됨,
    //auto는 여기서 std::array<Student, STUDENT_COUNT>::iterator 타입으로 추론됩니다. 이는 반복자(iterator)입니다. 두 번째는 학생 객체를 가리키는 반복자를 반환합니다.
    //두 번째 코드의 결과는 반복자이므로, 실제 객체에 접근하려면 역참조(*)가 필요합니다. 
    //main.cpp에선 이 방법으로 호출해야 함 const Student& student = *it;  // 반복자 역참조로 학생 객체 얻기

    //즉 나는 여기서 const로 가공을 해서 넘겨줘야 함
    //그래서
    /*
    const Student& get_last(const std::array<Student, STUDENT_COUNT>& students) { 
        std::min_element(students.begin(), students.end(), compareByPoints);
        return students[STUDENT_COUNT - 1]; 
    }
    이런방식으로 코드를 작성해야 한다
    */
    return std::min_element(students.begin(), students.end(), compareByPoints); //이거는 구조체 출력
}

auto get_lowest_points(std::array<Student, STUDENT_COUNT>& students) {
    return std::min_element(students.begin(), students.end(), compareByPoints);
}
/*
auto get_lowest_points(std::array<Student, STUDENT_COUNT>& students) {
    return std::min_element(students.begin(), students.end(), compareByPoints)->points; //이 표현 잘 알아두기 이렇게 멤버변수 단일로 접근하고 싶으면 -> 쓰는 것
}
*/
auto get_highest_points(std::array<Student, STUDENT_COUNT>& students) {
    return std::max_element(students.begin(), students.end(), compareByPoints);
}
/*
auto get_highest_points(std::array<Student, STUDENT_COUNT>& students) {
    return std::max_element(students.begin(), students.end(), compareByPoints)->points; //이 표현 잘 알아두기 이렇게 멤버변수 단일로 접근하고 싶으면 -> 쓰는 것
}
*/
void print(const Student& a) {
    std::cout << "ID: " << a.id << ", " << "Name : " << a.name << ", " << "Points : " << a.points << std::endl;
}