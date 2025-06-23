#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.hpp"

class Manager : public Employee {
public:
    Manager(std::string name, int salary);
    double calculatePay() const override;
};

#endif
