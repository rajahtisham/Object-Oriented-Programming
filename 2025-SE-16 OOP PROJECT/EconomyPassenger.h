#ifndef ECONOMYPASSENGER_H
#define ECONOMYPASSENGER_H

#include "Passenger.h"

class EconomyPassenger : public Passenger
{
public:
    // Constructor
    EconomyPassenger(int id, string n)
        : Passenger(id, n)
    {
    }

    // Refund Percentage
    double getRefundPercentage() const override
    {
        return 50.0; // 50%
    }

    // Passenger Type
    string getPassengerType() const override
    {
        return "Economy";
    }

    // Display Details
    void display() const override
    {
        cout << "\n===== Economy Passenger =====\n";
        cout << "Passenger ID: " << passengerID
             << "\nName: " << name
             << "\nType: " << getPassengerType()
             << "\nRefund Percentage: " << getRefundPercentage() << "%"
             << "\n-----------------------------\n";
    }
};

#endif
