#include <iostream>
#include "employee.h"
#include "hourlyEmployee.h"
#include "salariedEmployee.h"
using namespace std;

//An example function that can be used on the whole list
void fullWeekWorked(Employee* workers[], const int &maxWorkers) {
    //Sets all hourly employees to having worked one week
    HourlyEmployee* person;
    for (int i=0; i<maxWorkers; i++) {
        //Casting is used here to access methods exclusive to HourlyEmployee from a pointer to Employee 
        person = dynamic_cast<HourlyEmployee*>(workers[i]);
        if (person != nullptr) {
            person->setHoursWorked(40);
        }
    }
}

int main() {
    const int MAX_WORKERS = 10;
    char employee1Name[32] = "Foo"; //Defining these here because they need to exist in memory when the objects are created
    char employee2Name[32] = "Bar";
    char employee3Name[32] = "Foo2";
    char employee4Name[32] = "Bar2";
    //Creating empty array of employees
    Employee* workers[MAX_WORKERS];
    for (int i=0; i<MAX_WORKERS; i++) {
        workers[i] = nullptr;
    }

    //Making some test employees
    workers[0] = new HourlyEmployee(1, employee1Name, 15.00);
    workers[1] = new SalariedEmployee(2, employee2Name, 600.00);
    workers[2] = new HourlyEmployee(3, employee3Name, 20.00);
    workers[3] = new SalariedEmployee(4, employee4Name, 900.00);
    fullWeekWorked(workers, MAX_WORKERS);
    //Now printing their paychecks
    for (int i=0; i<MAX_WORKERS; i++) {
        if(workers[i] != nullptr) {
            workers[i]->printCheck();
        }
    }
    //Now deleteing the employees that exist
    for (int i=0; i<MAX_WORKERS; i++) {
        if(workers[i] != nullptr) {
            delete workers[i];
        }
    }
    return 0;
}
