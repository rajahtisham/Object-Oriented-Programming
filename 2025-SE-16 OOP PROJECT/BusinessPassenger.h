#ifndef BUSINESSPASSENGER_H
#define BUSINESSPASSENGER_H

#include "Passenger.h"

class BusinessPassenger : public Passenger
{
public:
    // Constructor
    BusinessPassenger(int id, string n)
        : Passenger(id, n)
    {
    }

    // Refund Percentage
    double getRefundPercentage() const override
    {
        return 80.0; // 80%
    }

    // Passenger Type
    string getPassengerType() const override
    {
        return "Business";
    }

    // Display Details
    void display() const override
    {
        cout << "\n===== Business Passenger =====\n";
        cout << "Passenger ID: " << passengerID
             << "\nName: " << name
             << "\nType: " << getPassengerType()
             << "\nRefund Percentage: " << getRefundPercentage() << "%"
             << "\n------------------------------\n";
    }
};

#endif
