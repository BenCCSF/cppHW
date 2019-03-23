#include <iostream>
#include "contact.h"
using namespace std;

Contact::Contact() {
    //Intiate contact with all values null
    next = nullptr;
    firstName = "\0";
    lastName = "\0";
    address = "\0";
    phoneNumber = "\0";
}

void Contact::print() const {
    cout << "Name: " << firstName << " " << lastName << endl;
    cout << "Address: " << address << endl;
    cout << "Phone Number: " << phoneNumber << endl;
}
