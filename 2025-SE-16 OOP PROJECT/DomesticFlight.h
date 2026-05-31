#ifndef DOMESTICFLIGHT_H
#define DOMESTICFLIGHT_H

#include "Flight.h"

class DomesticFlight : public Flight
{
public:
    // Constructor
    DomesticFlight(string no, string org, string dest, int seats)
        : Flight(no, org, dest, seats)
    {
    }

    // Domestic fare calculation
    double calculateFare() const override
    {
        return 5000.0;
    }

    // Display flight details
    void display() const override
    {
        cout << "\n===== Domestic Flight =====\n";
        cout << *this;
        cout << "\nFare: Rs. " << calculateFare()
             << "\n---------------------------\n";
    }
};

#endif
