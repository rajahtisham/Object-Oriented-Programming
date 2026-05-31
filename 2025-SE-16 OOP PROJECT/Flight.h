#ifndef FLIGHT_H
#define FLIGHT_H

#include <iostream>
#include <string>

using namespace std;

// Abstract Base Class
class Flight
{
protected:
    string flightNo;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;

public:
    // Constructor
    Flight(string no, string org, string dest, int seats)
        : flightNo(no),
          origin(org),
          destination(dest),
          totalSeats(seats),
          availableSeats(seats)
    {
    }

    // Virtual Destructor
    virtual ~Flight() {}

    // Pure Virtual Functions (Abstraction)
    virtual double calculateFare() const = 0;
    virtual void display() const = 0;

    // Getters
    string getFlightNo() const { return flightNo; }
    string getOrigin() const { return origin; }
    string getDestination() const { return destination; }
    int getAvailableSeats() const { return availableSeats; }
    int getTotalSeats() const { return totalSeats; }

    // Seat Booking
    bool bookSeat()
    {
        if (availableSeats > 0)
        {
            availableSeats--;
            return true;
        }
        return false;
    }

    // Seat Cancellation
    void cancelSeat()
    {
        if (availableSeats < totalSeats)
        {
            availableSeats++;
        }
    }

    // Operator Overloading
    friend ostream& operator<<(ostream& out, const Flight& f)
    {
        out << "Flight No: " << f.flightNo
            << "\nOrigin: " << f.origin
            << "\nDestination: " << f.destination
            << "\nTotal Seats: " << f.totalSeats
            << "\nAvailable Seats: " << f.availableSeats;

        return out;
    }
};

#endif
