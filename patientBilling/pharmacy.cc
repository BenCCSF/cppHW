#include <iostream>
#include "pharmacy.h"
using namespace std;

Pharmacy::Pharmacy() {
    pkCost = 500.00;
    anthCost = 1000.00;
    antiBioCost = 200.00;
    antiSepCost = 100.00;
    stimCost = 750.00;
}

void Pharmacy::listDrugs() const {
    cout << "1. Painkillers ($500)" << endl
        << "2. Anesthesia ($1000)" << endl
        << "3. Antibiotics ($200)" << endl
        << "4. Antiseptic ($100)" << endl
        << "5. Stimulants ($750)" << endl;
}
