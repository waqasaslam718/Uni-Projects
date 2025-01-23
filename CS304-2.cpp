#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeId;
    string employeeName;
    double salary;

public:
    Employee() : employeeId(0), employeeName(""), salary(0.0) {}
    virtual void calculateSalary() = 0; 
    virtual void displaySalary() = 0; 
    virtual ~Employee() {} 
};

class RegularEmployee : public Employee {
private:
    double basicSalary;
    double allowances;
    double incomeTax;

public:
    RegularEmployee(int id, string name, double basic, double allow, double tax) {
        employeeId = id;
        employeeName = name;
        basicSalary = basic;
        allowances = allow;
        incomeTax = tax;
    }

    void calculateSalary() override {
        salary = basicSalary + allowances - incomeTax;
    }

    void displaySalary() override {
        cout << "Salary of Regular Employee with basic pay: " << basicSalary
             << ", allowances: " << allowances
             << " and income tax: " << incomeTax << " is given below:\n";
        cout << salary << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    int noOfHours;
    double hourlyRate;

public:
    HourlyEmployee(int id, string name, int hours, double rate) {
        employeeId = id;
        employeeName = name;
        noOfHours = hours;
        hourlyRate = rate;
    }

    void calculateSalary() override {
        salary = noOfHours * hourlyRate;
    }

    void displaySalary() override {
        cout << "Salary of Hourly Employee with hourly rate: " << hourlyRate
             << " and no. of hours: " << noOfHours << " is given below:\n";
        cout << salary << endl;
    }
};

int main() {
    Employee* employees[2];

    // Dataset 1 values
    employees[0] = new RegularEmployee(1, "Umair Aftab", 65000, 30000, 6000);
    employees[1] = new HourlyEmployee(2, "Noman Ali", 25, 1000);

    for (int i = 0; i < 2; ++i) {
        employees[i]->calculateSalary();
        employees[i]->displaySalary();
    }

    cout << "------------------------------" << endl;

    for (int i = 0; i < 2; ++i) {
        delete employees[i];
    }

    return 0;
}
