#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "Employee.hpp"
#include "Manager.hpp"
#include <vector>
#include <memory>
#include <string>

class Department {
private:
    std::string name_;
    std::unique_ptr<Manager> manager_;
    std::vector<std::unique_ptr<Employee>> employees_;

public:
    explicit Department(std::string name);
    const std::string& getName() const;

    void setManager(std::unique_ptr<Manager> manager);
    void addEmployee(std::unique_ptr<Employee> emp);
    std::unique_ptr<Employee> removeEmployee(Employee* emp);
    void printDetails(std::ostream& os) const;
};

#endif