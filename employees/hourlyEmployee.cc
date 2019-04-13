#include <iostream>
#include "hourlyEmployee.h"
using namespace std;

HourlyEmployee::HourlyEmployee(int number, char* n, char* a, double wage) : Employee(number, n, a), hourlyWage(wage) {}

HourlyEmployee::HourlyEmployee(int number, char* n, double wage) : Employee(number, n), hourlyWage(wage) {}

void HourlyEmployee::setHourlyWage(double wage) {
    if (wage > 0) hourlyWage = wage;
    else {
        cout << "Error: wage must be positve, nonzero number" << endl;
    }
}
void HourlyEmployee::setHoursWorked(double hours) {
    if (hours > 0) hoursWorked = hours;
    else {
        cout << "Error: hours worked must be positve, nonzero number" << endl;
    }
}
void HourlyEmployee::printCheck() const {
    cout << "Printing paycheck for " << this->getName() << " (Hourly Employee)" << endl
        << "Hourly wage: " << hourlyWage << endl
        << "Hours worked: " << hoursWorked << endl
        << "Total pay: " << calcPay() << endl;
}

