#include <iostream>
#include <iomanip>
#include "Excel.h"

void test_case1() {
    Table data = {
        {Cell("Name"), Cell("C++"), Cell("Java")},
        {Cell("Kim"), Cell(87), Cell(75.7)},
        {Cell("Lee"), Cell(90), Cell(80.6)},
        {Cell("Park"), Cell(70), Cell(90.0)}
    };
    Excel excel(data);
    std::cout << excel.display();

    double score = excel.average(2, 2, 4, 2);
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "C++ Avg. Score: " << score << "\n";

    score = excel.average(2, 3, 4, 3);
    std::cout << "Java Avg. Score: " << score << "\n";
}

void test_case2() {
    Table data = {
        {Cell("Student"), Cell("Math"), Cell("Physics")},
        {Cell("Alice"), Cell(92), Cell(88.5)},
        {Cell("Bob"), Cell(78), Cell(90.0)},
        {Cell("Charlie"), Cell(85), Cell(85.5)}
    };
    Excel excel(data);
    std::cout << excel.display();

    double mathAvg = excel.average(2, 2, 4, 2);
    double physicsAvg = excel.average(2, 3, 4, 3);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Math Avg. Score: " << mathAvg << "\n";
    std::cout << "Physics Avg. Score: " << physicsAvg << "\n";
}

void test_case3() {
    Table data = {
        {Cell("Item"), Cell("Price")},
        {Cell("Pen"), Cell(1.5)},
        {Cell("Notebook"), Cell(2.8)},
        {Cell("Eraser"), Cell(0.8)}
    };
    Excel excel(data);
    std::cout << excel.display();

    double priceAvg = excel.average(2, 2, 4, 2);

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Average Price: " << priceAvg << "\n";
}

int main() {
    int choice;
    std::cout << "Select Test Case (1, 2, 3): ";
    std::cin >> choice;

    if (choice == 1) {
        test_case1();
    } else if (choice == 2) {
        test_case2();
    } else if (choice == 3) {
        test_case3();
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
