#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
    private:
        string firstName;
        string lastName;
        string address;
        string phoneNumber;

    public:
        //Contstructor
        Contact();

        //Operator overload
        friend bool operator < (Contact const &c1, Contact const &c2)
        { return (c1.getLastName() < c2.getLastName()); }

        //Setters
        void setFirstName(const string &inFirstName)
        { firstName = inFirstName; }
        void setLastName(const string &inLastName)
        { lastName = inLastName; }
        void setAddress(const string &inAddress) 
        { address = inAddress; }
        void setPhoneNumber(const string &inPhoneNumber) 
        { phoneNumber = inPhoneNumber; }

        //Getters
        string getFirstName() const
        { return firstName; }
        string getLastName() const 
        { return lastName; }
        string getAddress() const
        { return address; }
        string getPhoneNumber() const
        { return phoneNumber; }
        
        //Other methods
        void print() const;
        void save(ofstream&) const; //Needs open stream
        void load(string);
};
#endif
