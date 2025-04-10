#include "student.h"
#include <iostream>

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
