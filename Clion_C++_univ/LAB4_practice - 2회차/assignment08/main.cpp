#include <iostream>
#include <iomanip>
#include "Organization.hpp"

int main() {
    auto org = std::make_unique<Organization>("PNU-CSE");

    auto design = std::make_unique<Department>("Design");
    auto dev = std::make_unique<Department>("Development");
    auto qa = std::make_unique<Department>("QA");

    auto lee = std::make_unique<Manager>("Lee", 80'000'000);
    auto park = std::make_unique<Manager>("Park", 90'000'000);
    auto bae = std::make_unique<Manager>("Bae", 50'000'000);

    Department* d1 = design.get();
    Department* d2 = dev.get();
    Department* d3 = qa.get();

    org->addDept(std::move(design));
    org->addDept(std::move(dev));
    org->addDept(std::move(qa));

    org->setDeptManager(d1, std::move(lee));
    org->setDeptManager(d2, std::move(park));
    org->setDeptManager(d3, std::move(bae));

    auto kim = std::make_unique<Employee>("Kim", 40'000'000);
    auto go = std::make_unique<Employee>("Go", 80'000'000);
    auto jeon = std::make_unique<Employee>("Jeon", 50'000'000);
    auto yoon = std::make_unique<Employee>("Yoon", 30'000'000);

    Employee* jeon_ptr = jeon.get();

    org->addEmpToDept(d1, std::move(kim));
    org->addEmpToDept(d2, std::move(go));
    org->addEmpToDept(d2, std::move(jeon));
    org->addEmpToDept(d3, std::move(yoon));

    std::cout << std::fixed << std::setprecision(0);
    std::cout << "Initial Organization Structure:\n";
    org->print();
    std::cout << "\n";

    org->moveEmp(d2, d3, jeon_ptr);

    org->print();
    std::cout << "\n";

    return 0;
}
