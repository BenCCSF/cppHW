#ifndef CABLE_CAR_H
#define CABLE_CAR_H
#include "muniVehicle.h"

class CableCar : public MuniVehicle {
    public:
        void paidFare() 
        { totalFares += 7; }
};
#endif
