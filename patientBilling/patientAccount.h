#include <iostream>
#include "surgery.h"
#include "pharmacy.h"
using namespace std;

#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

class PatientAccount {
    private:
        //Day should not be able to be negative and thus is unsigned
        unsigned int days; 
        double charges; //Charges for services - this is a double for accuracy
        //Below are pointers to surgery and pharmacy objects attached to this patient's account
        Surgery* sur;
        Pharmacy* pharma;

    public:
        PatientAccount();
        ~PatientAccount();
        void addPharmaCost();
        void addSurgeryCost();
        void setDays(unsigned int num) 
        { days = num; }
        //Getters
        double getTotalCost() const; //This should calculate the cost and return it
        int getDays() const 
        { return days; }
        
};

#endif
