#ifndef SALARIED_EMPLOYEE_H
#define SALARIED_EMPLOYEE_H
#include "employee.h"

class SalariedEmployee : public Employee {
    private:
        double weeklyWage;
    public:
        //Constructors
        SalariedEmployee(int, char*, char*, double);
        SalariedEmployee(int, char*, double);
        //Getters
        double getWeeklyWage() const
        { return weeklyWage; }
        //Setters
        void setWeeklyWage(double);
        //Other methods
        double calcPay() const //Prints yearly salary
        { return 52 * weeklyWage; }
        void printCheck() const; //Prints for one week
};

#endif
