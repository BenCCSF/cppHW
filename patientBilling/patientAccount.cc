#include <iostream>
#include "pharmacy.h"
#include "surgery.h"
#include "patientAccount.h"
using namespace std;

PatientAccount::PatientAccount() {
    days = 0;
    charges = 0;
    pharma = new Pharmacy();
    sur = new Surgery();
}

PatientAccount::~PatientAccount() {
    days = 0;
    charges = 0;
    delete pharma;
    delete sur; 
}

double PatientAccount::getTotalCost() const {
    return charges + days * 100; //Cost per day is $100
}

void PatientAccount::addPharmaCost() {
    int userChoice;
    cout << "What service did the patient use (Select a number)" << endl;
    pharma->listDrugs();
    cin >> userChoice;
    while (!cin || (userChoice < 1) || (userChoice > 5)) {
        cout << "Error: Invalid input (Select a number between 1 and 5)";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> userChoice;
    }
    switch(userChoice) {
        case 1:
            charges += pharma->getPKCost();
            break;
        case 2: 
            charges += pharma->getAnthCost();
            break;
        case 3:
            charges += pharma->getAntiBioCost();
            break;
        case 4:
            charges += pharma->getAntiSepCost();
            break;
        case 5: 
            charges += pharma->getStimCost();
    }
}
void PatientAccount::addSurgeryCost() {
    int userChoice;
    cout << "What service did the patient use (Select a number)" << endl;
    sur->listOperations();
    cin >> userChoice;
    while (!cin || (userChoice < 1) || (userChoice > 5)) {
        cout << "Error: Invalid input (Select a number between 1 and 5)";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> userChoice;
    }
    switch(userChoice) {
        case 1:
            charges += sur->getBrainCost();
            break;
        case 2: 
            charges += sur->getHeartCost();
            break;
        case 3:
            charges += sur->getHipCost();
            break;
        case 4:
            charges += sur->getBurnCost();
            break;
        case 5: 
            charges += sur->getAppednixCost();
    }
}
