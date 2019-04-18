#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
    private:
        Contact* next;
        string firstName;
        string lastName;
        string address;
        string phoneNumber;

    public:
        //Contstructor
        Contact();

        //Setters
        void setNext(Contact* const &inNext)
        { next = inNext; }
        void setFirstName(const string &inFirstName)
        { firstName = inFirstName; }
        void setLastName(const string &inLastName)
        { lastName = inLastName; }
        void setAddress(const string &inAddress) 
        { address = inAddress; }
        void setPhoneNumber(const string &inPhoneNumber) 
        { phoneNumber = inPhoneNumber; }

        //Getters
        Contact* getNext() const 
        { return next; }
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
