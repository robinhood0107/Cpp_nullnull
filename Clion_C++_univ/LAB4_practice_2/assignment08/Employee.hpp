#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
private:
    static int nextId_;
    int id_;
    std::string name_;
    int salary_;

public:
    Employee(std::string name, int salary);
    virtual ~Employee() = default;

    std::string getName() const;
    int getId() const;
    int getSalary() const;

    virtual double calculatePay() const;
    virtual void printDetails(std::ostream& os) const;
};

#endif
