#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {
    private:
        int employeeNumber;
        char name[32];
        char address[64];
    public:
        //Constructor
        Employee(int, char*, char*);
        Employee(int, char*); //Initialize without address
        virtual ~Employee() = default;
        //Getters 
        int getEmployeeNumber() const 
        { return employeeNumber; }
        const char* getName() const
        { return name; }
        const char* getAddress() const
        { return address; }
        //Setter 
        void setAddress(char*);
        //Virtual Methods
        virtual double calcPay() const = 0;
        virtual void printCheck() const = 0;
};


#endif
