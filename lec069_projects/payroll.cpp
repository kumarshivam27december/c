#include <iostream>
#include <vector>
#include <iomanip> // For std::setprecision

class Employee {
private:
    std::string name;
    double hourlyRate;
    double hoursWorked;

public:
    Employee(const std::string& empName, double rate, double hours)
        : name(empName), hourlyRate(rate), hoursWorked(hours) {}

    double calculateSalary() const {
        return hourlyRate * hoursWorked;
    }

    void display() const {
        std::cout << "Name: " << name << "\n"
                  << "Hourly Rate: $" << std::fixed << std::setprecision(2) << hourlyRate << "\n"
                  << "Hours Worked: " << hoursWorked << "\n"
                  << "Salary: $" << std::fixed << std::setprecision(2) << calculateSalary() << "\n";
    }
};

class PayrollSystem {
private:
    std::vector<Employee> employees;

public:
    void addEmployee(const std::string& name, double rate, double hours) {
        employees.emplace_back(name, rate, hours);
    }

    void displayPayroll() const {
        std::cout << "Employee Payroll:\n";
        std::cout << "-----------------\n";
        for (const auto& emp : employees) {
            emp.display();
            std::cout << "-----------------\n";
        }
    }
};

int main() {
    PayrollSystem payroll;

    // Example data
    payroll.addEmployee("John Doe", 20.00, 40);
    payroll.addEmployee("Jane Smith", 25.00, 35);
    payroll.addEmployee("Alice Johnson", 30.00, 45);

    payroll.displayPayroll();

    return 0;
}
