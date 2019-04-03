#include <iostream>
using namespace std;

#ifndef SURGERY_H
#define SURGERY_H



class Surgery {
    //Similar form ot the pharmacy class (see comments there)
    private:
        double brainCost;
        double heartCost;
        double hipCost;
        double burnCost;
        double appendixCost;
    public:
        Surgery();
        void listOperations();
        //Getters
        double getBrainCost() const
        { return brainCost; }
        double getHeartCost() const
        { return heartCost; }
        double getHipCost() const
        { return hipCost; }
        double getBurnCost() const
        { return burnCost; }
        double getAppednixCost() const
        { return appendixCost; }
};




#endif
