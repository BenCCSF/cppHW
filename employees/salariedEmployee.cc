#include <iostream>
#include "salariedEmployee.h"
using namespace std;

SalariedEmployee::SalariedEmployee(int number, char* n, char* a, double salary) : Employee(number, n, a), weeklyWage(salary) {}

SalariedEmployee::SalariedEmployee(int number, char* n, double salary) : Employee(number, n), weeklyWage(salary) {}

void SalariedEmployee::setWeeklyWage(double salary) {
    if (salary > 0) weeklyWage = salary;
    else {
         cout << "Error: salary must be positve, nonzero number" << endl;
    }
}
void SalariedEmployee::printCheck() const {
    cout << "Printing paycheck for " << this->getName() << " (Salaried Employee)" << endl 
        << "Earnings this week: " << weeklyWage << endl;
}
