#ifndef HOURLY_EMPLOYEE_H
#define HOURLY_EMPLOYEE_H
#include "employee.h"

class HourlyEmployee : public Employee {
    private:
        double hoursWorked;
        double hourlyWage; 
    public:
        //Constructors
        HourlyEmployee(int, char*, char*, double);
        HourlyEmployee(int, char*, double);
        //Getters
        double getHoursWorked() const
        { return hoursWorked; }
        double getHourlyWage() const
        { return hourlyWage; }
        //Setters
        void setHoursWorked(double);
        void setHourlyWage(double);
        //Other methods
        double calcPay() const
        { return hoursWorked * hourlyWage; }
        void printCheck() const;

};

#endif
