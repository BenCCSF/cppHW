#ifndef MUNI_VEHICLE_H
#define MUNI_VEHICLE_H

class MuniVehicle {
    protected:
        //Now cable car can access this varible when it is dirived
        int totalFares;
    public:
        MuniVehicle()
        { totalFares = 0; }
  
        int getTotalFares()
        { return totalFares; }

        virtual void paidFare()
        { totalFares += 2; }

};  

#endif
