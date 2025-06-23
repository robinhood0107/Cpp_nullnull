과제 008 - Modeling an Organization Structure
Requested files: main.cpp, IOrganization.hpp, Organization.hpp, Organization.cpp, Department.hpp, Department.cpp, Employee.hpp, Employee.cpp, Manager.hpp, Manager.cpp (다운로드)
제출 방식: 개인
Goal
Write a C++17 program to model an organization structure including departments, managers, and employees. The program must support creating departments, assigning managers, hiring employees, moving employees between departments, and printing the organizational structure with calculated monthly salaries.

Concept Explanation
This problem is designed to reinforce object-oriented programming principles such as inheritance, polymorphism, encapsulation, and interface-based design. It also emphasizes the use of smart pointers for dynamic memory management and introduces formatted I/O handling using iomanip. Students will develop and organize their code in multiple files and handle composite object structures.

Abstract base classes and interface design
Smart pointers (std::unique_ptr)
Inheritance and method overriding
Monthly salary calculation with business rules
Formatted output and ID auto-generation
Safe object management and object graph manipulation
Classes or Functions to Implement
class IOrganization: Abstract base class for high-level operations.
virtual void addDept(std::unique_ptr<Department> dept) = 0;
virtual void addEmpToDept(Department* dept, std::unique_ptr<Employee> emp) = 0;
virtual void setDeptManager(Department* dept, std::unique_ptr<Manager> manager) = 0;
virtual bool moveEmp(Department* from, Department* to, Employee* emp) = 0;
virtual void print() const = 0;
class Employee
Employee(std::string name, int salary);
std::string getName() const;
int getId() const; — Automatically assigned unique ID
int getSalary() const;
virtual double calculatePay() const; — Monthly pay = salary / 12
virtual void printDetails(std::ostream&) const;
class Manager : public Employee
Manager(std::string name, int salary);
double calculatePay() const override; — Includes a 10% leadership bonus
class Department
Department(std::string name);
void setManager(std::unique_ptr<Manager>); — Also adds the manager to employees
void addEmployee(std::unique_ptr<Employee>);
std::unique_ptr removeEmployee(Employee*);
void printDetails(std::ostream&) const;
class Organization : public IOrganization
Organization(std::string name);
Overrides all IOrganization methods
Manages ownership of departments and employees via unique pointers
Constraints
All dynamic memory must be managed using std::unique_ptr.
Each employee and manager must be constructed using std::make_unique.
Employees must have unique auto-generated IDs.
Manager's monthly pay includes 10% annual bonus, divided monthly.
Employee movement between departments must validate department membership.
Print functions must format output with indents and labels.
Submission Files
Employee.cpp
Manager.cpp
Department.cpp
Organization.cpp
Input/Output Example
Initial Organization Structure:
Organization: PNU-CSE
Design
    |---Manager: Lee 1 (Annual: 80000000, Monthly Pay: 7333333)
    |---Kim 4 (Annual: 40000000, Monthly Pay: 3333333)
Development
    |---Manager: Park 2 (Annual: 90000000, Monthly Pay: 8250000)
    |---Go 5 (Annual: 80000000, Monthly Pay: 6666666)
    |---Jeon 6 (Annual: 50000000, Monthly Pay: 4166666)
QA
    |---Manager: Bae 3 (Annual: 50000000, Monthly Pay: 4583333)
    |---Yoon 7 (Annual: 30000000, Monthly Pay: 2500000)

Organization: PNU-CSE
Design
    |---Manager: Lee 1 (Annual: 80000000, Monthly Pay: 7333333)
    |---Kim 4 (Annual: 40000000, Monthly Pay: 3333333)
Development
    |---Manager: Park 2 (Annual: 90000000, Monthly Pay: 8250000)
    |---Go 5 (Annual: 80000000, Monthly Pay: 6666666)
QA
    |---Manager: Bae 3 (Annual: 50000000, Monthly Pay: 4583333)
    |---Yoon 7 (Annual: 30000000, Monthly Pay: 2500000)
    |---Jeon 6 (Annual: 50000000, Monthly Pay: 4166666)