#ifndef INTERNATIONALFLIGHT_H
#define INTERNATIONALFLIGHT_H

#include "Flight.h"

class InternationalFlight : public Flight
{
private:
    bool visaRequired;

public:
    // Constructor
    InternationalFlight(string no, string org, string dest, int seats, bool visa)
        : Flight(no, org, dest, seats),
          visaRequired(visa)
    {
    }

    // International fare calculation
    double calculateFare() const override
    {
        return 25000.0;
    }

    // Getter
    bool isVisaRequired() const
    {
        return visaRequired;
    }

    // Display flight details
    void display() const override
    {
        cout << "\n===== International Flight =====\n";
        cout << *this;
        cout << "\nFare: Rs. " << calculateFare();
        cout << "\nVisa Required: " << (visaRequired ? "Yes" : "No");
        cout << "\n--------------------------------\n";
    }
};

#endif
