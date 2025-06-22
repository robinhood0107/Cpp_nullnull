#ifndef ORGANIZATION_H
#define ORGANIZATION_H

#include "IOrganization.hpp"
#include "Department.hpp"
#include "Manager.hpp"
#include "Employee.hpp"
#include <vector>
#include <memory>

class Organization : public IOrganization {
private:
    std::string name_;
    std::vector<std::unique_ptr<Department>> departments_;

public:
    explicit Organization(std::string name);

    void addDept(std::unique_ptr<Department> dept) override;
    void addEmpToDept(Department* dept, std::unique_ptr<Employee> emp) override;
    void setDeptManager(Department* dept, std::unique_ptr<Manager> manager) override;
    bool moveEmp(Department* from, Department* to, Employee* emp) override;
    void print() const override;
};

#endif
