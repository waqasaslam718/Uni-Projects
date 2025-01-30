#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    int empId;
    string empName;
    float empSalary;

public:
    void setId(int id) {
        empId = id;
    }

    void setName(const string &name) {
        empName = name;
    }

    void setSalary(float salary) {
        empSalary = salary;
    }

    int getId() const {
        return empId;
    }

    const string &getName() const {
        return empName;
    }

    float getSalary() const {
        return empSalary;
    }

    // Default constructor
    Employee() : empId(0), empName(""), empSalary(0.0) {}

    // Parameterized constructor
    Employee(int id, const string &name, float salary) {
        setId(id);
        setName(name);
        setSalary(salary);
    }

    // Copy constructor
    Employee(const Employee &e) : empId(e.empId), empName(e.empName), empSalary(e.empSalary) {}

    void display() const {
        cout << "Employee Id: " << getId() << endl;
        cout << "Employee Name: " << getName() << endl;
        cout << "Employee Salary: " << getSalary() << endl << endl;
    }

    ~Employee() {
        // No manual memory management required
    }
};

int main() {
    Employee emp1(10, "Ali", 50000);
    Employee emp2 = emp1; // Copy constructor will be called here

    cout << "The data members of object 1:" << endl;
    emp1.display();

    cout << "The data members of object 2:" << endl;
    emp2.display();

    system("pause");
    return 0;
}
