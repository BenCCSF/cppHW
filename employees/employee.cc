#include <cstring>
#include "employee.h"

Employee::Employee(int number, char* n, char* a) {
    strncpy(name, n, 32);
    name[31] = '\0';
    strncpy(address, a, 64);
    address[63] = '\0';
    employeeNumber = number;
}
Employee::Employee(int number, char* n) {
    strncpy(name, n, 32);
    name[31] = '\0';
    employeeNumber = number;
}
void Employee::setAddress(char* a) {
    strncpy(address, a, 64);
    address[63] = '\0';
}
