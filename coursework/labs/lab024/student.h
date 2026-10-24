#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <array>
#include <string>

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

#endif // STUDENT_H