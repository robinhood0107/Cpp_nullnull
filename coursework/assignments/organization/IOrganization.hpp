#ifndef IORGANIZATION_H
#define IORGANIZATION_H

#include <memory>
#include <vector>

class Employee;
class Department;
class Manager;

class IOrganization {
public:
    virtual ~IOrganization() = default;
    virtual void addDept(std::unique_ptr<Department> dept) = 0;
    virtual void addEmpToDept(Department* dept, std::unique_ptr<Employee> emp) = 0;
    virtual void setDeptManager(Department* dept, std::unique_ptr<Manager> manager) = 0;
    virtual bool moveEmp(Department* from, Department* to, Employee* emp) = 0;
    virtual void print() const = 0;
};

#endif
