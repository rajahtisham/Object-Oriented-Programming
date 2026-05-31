#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Passenger
{
protected:
    int passengerID;
    string name;

public:
    // Constructor
    Passenger(int id, string n)
        : passengerID(id),
          name(n)
    {
    }

    // Virtual Destructor
    virtual ~Passenger() {}

    // Pure Virtual Functions
    virtual double getRefundPercentage() const = 0;
    virtual string getPassengerType() const = 0;

    // Getters
    int getPassengerID() const { return passengerID; }
    string getName() const { return name; }

    // Display Function
    virtual void display() const
    {
        cout << "Passenger ID: " << passengerID
             << "\nName: " << name
             << "\nType: " << getPassengerType() << endl;
    }
};

#endif
