#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

// Exception for Full Flight
class FlightFullException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Flight is full. No Seats Available!";
    }
};

// Exception for Invalid Passenger
class PassengerNotFoundException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Passenger not found!";
    }
};

// Exception for Invalid Flight
class FlightNotFoundException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Flight not found!";
    }
};

// Exception for Duplicate Passenger ID
class DuplicatePassengerException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Passenger ID already exists!";
    }
};

// Exception for Invalid Ticket
class TicketNotFoundException : public exception
{
public:
    virtual const char* what() const throw()
    {
        return "Error: Ticket not found!";
    }
};

#endif
