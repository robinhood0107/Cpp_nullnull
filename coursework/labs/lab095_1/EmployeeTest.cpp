#include "Employee.h"

int main() {
    Manager m = Manager("Alice", 50000, "Marketing");
    Programmer p = Programmer("Bob", 60000, "C++");
    Salesperson s = Salesperson("Charlie", 40000, 100000);

    m.set_goals();
    p.write_code();
    s.sell();

    Employee* e1 = &m;
    Employee* e2 = &p;
    Employee* e3 = &s;

    e1->print_report();
    e2->print_report();
    e3->print_report();
}