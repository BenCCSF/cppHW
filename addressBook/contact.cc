#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
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

void Contact::save(ofstream &outs) const {
    outs << firstName << '\t' << lastName << '\t'
        << address << '\t' << phoneNumber << endl;
}

void Contact::load(string instr) {
    char data[instr.length() + 1];
    strcpy(data, instr.c_str());
    char * t = strtok(data, "\t");
    firstName = t;
    t = strtok(NULL, "\t");
    lastName = t;
    t = strtok(NULL, "\t");
    address = t;
    t = strtok(NULL, "\t");
    phoneNumber = t;
}
