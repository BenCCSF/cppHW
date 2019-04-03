#include <iostream>
using namespace std;

#ifndef PHARMACY_H
#define PHARMACY_H


class Pharmacy {
    private:
        double pkCost;
        double anthCost;
        double antiBioCost;
        double antiSepCost;
        double stimCost;
    public:
        //Costs cannot be changed in this version, but they are varibles so that they could change in future versions.
        //Constructor
        Pharmacy();
        //Other methods
        void listDrugs() const;

        //Getters
        double getPKCost() const
        { return pkCost; }
        double getAnthCost() const
        { return anthCost; }
        double getAntiBioCost() const
        { return antiBioCost; }
        double getAntiSepCost() const
        { return antiSepCost; }
        double getStimCost() const
        { return stimCost; }
};

#endif
