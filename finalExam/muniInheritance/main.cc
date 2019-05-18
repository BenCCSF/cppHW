#include <iostream>
#include "cableCar.h"
using namespace std;

int main() {
    //First we create a cable car object
    CableCar testCar;
    // Now pay two fares
    for (int i=0; i<2; i++) {
        testCar.paidFare();
    }
    //Finally: print out the total fares
    cout << "The total fare is: $" << testCar.getTotalFares() << endl;

    return 0;
}
