#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>

using namespace std;

class Ticket
{
private:
    int ticketID;
    int passengerID;
    string passengerName;
    string flightNo;
    double fare;
    bool booked;

public:
    // Constructor
    Ticket(int id = 0, int pid = 0, string pname = "", string fno = "", double f = 0.0)
        : ticketID(id),
          passengerID(pid),
          passengerName(pname),
          flightNo(fno),
          fare(f),
          booked(true)
    {
    }

    // Getters
    int getTicketID() const { return ticketID; }
    int getPassengerID() const { return passengerID; }
    string getPassengerName() const { return passengerName; }
    string getFlightNo() const { return flightNo; }
    double getFare() const { return fare; }
    bool isBooked() const { return booked; }

    // Cancel Ticket
    void cancelTicket()
    {
        booked = false;
    }

    // Operator Overloading (Required)
    bool operator==(const Ticket& other) const
    {
        return ticketID == other.ticketID;
    }

    // Output Operator Overloading
    friend ostream& operator<<(ostream& out, const Ticket& t)
    {
        out << "Ticket ID: " << t.ticketID
            << "\nPassenger ID: " << t.passengerID
            << "\nPassenger Name: " << t.passengerName
            << "\nFlight No: " << t.flightNo
            << "\nFare: Rs. " << t.fare
            << "\nStatus: " << (t.booked ? "Booked" : "Cancelled")
            << "\n---------------------------";

        return out;
    }
};

#endif
