#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//==================== FLIGHT ====================

class Flight
{
protected:
    string flightNo;
    string origin;
    string destination;
    int totalSeats;
    int availableSeats;

public:
    Flight(string no,
           string org,
           string dest,
           int seats)
    {
        flightNo = no;
        origin = org;
        destination = dest;

        if (seats < 0)
            seats = 0;

        totalSeats = seats;
        availableSeats = seats;
    }

    virtual ~Flight() {}

    virtual double calculateFare() const = 0;
    virtual void display() const = 0;

    string getFlightNo() const
    {
        return flightNo;
    }

    int getAvailableSeats() const
    {
        return availableSeats;
    }

    bool bookSeat()
    {
        if (availableSeats > 0)
        {
            availableSeats--;
            return true;
        }
        return false;
    }

    void cancelSeat()
    {
        if (availableSeats < totalSeats)
            availableSeats++;
    }

    friend ostream& operator<<(ostream& out,
                               const Flight& f)
    {
        out << "Flight No: " << f.flightNo
            << "\nOrigin: " << f.origin
            << "\nDestination: " << f.destination
            << "\nTotal Seats: " << f.totalSeats
            << "\nAvailable Seats: "
            << f.availableSeats;

        return out;
    }
};

//==================== DOMESTIC FLIGHT ====================

class DomesticFlight : public Flight
{
public:
    DomesticFlight(string no,
                   string org,
                   string dest,
                   int seats)
        : Flight(no, org, dest, seats)
    {
    }

    double calculateFare() const
    {
        return 5000.0;
    }

    void display() const
    {
        cout << "\n===== Domestic Flight =====\n";
        cout << *this;
        cout << "\nFare: Rs. "
             << calculateFare();
        cout << "\n--------------------------\n";
    }
};

//==================== INTERNATIONAL FLIGHT ====================

class InternationalFlight : public Flight
{
private:
    bool visaRequired;

public:
    InternationalFlight(string no,
                        string org,
                        string dest,
                        int seats,
                        bool visa)
        : Flight(no, org, dest, seats)
    {
        visaRequired = visa;
    }

    double calculateFare() const
    {
        return 25000.0;
    }

    void display() const
    {
        cout << "\n===== International Flight =====\n";
        cout << *this;

        cout << "\nFare: Rs. "
             << calculateFare();

        cout << "\nVisa Required: "
             << (visaRequired ? "Yes" : "No");

        cout << "\n--------------------------------\n";
    }
};

//==================== PASSENGER ====================

class Passenger
{
protected:
    int passengerID;
    string name;

public:
    Passenger(int id, string n)
    {
        passengerID = id;
        name = n;
    }

    virtual ~Passenger() {}

    virtual double getRefundPercentage() const = 0;
    virtual string getPassengerType() const = 0;

    int getPassengerID() const
    {
        return passengerID;
    }

    string getName() const
    {
        return name;
    }

    virtual void display() const
    {
        cout << "Passenger ID: "
             << passengerID
             << "\nName: "
             << name
             << "\nType: "
             << getPassengerType()
             << endl;
    }
};

//==================== ECONOMY PASSENGER ====================

class EconomyPassenger : public Passenger
{
public:
    EconomyPassenger(int id,
                     string n)
        : Passenger(id, n)
    {
    }

    double getRefundPercentage() const
    {
        return 50.0;
    }

    string getPassengerType() const
    {
        return "Economy";
    }

    void display() const
    {
        cout << "\n===== Economy Passenger =====\n";
        cout << "ID: " << passengerID
             << "\nName: " << name
             << "\nRefund: "
             << getRefundPercentage()
             << "%\n";
    }
};

//==================== BUSINESS PASSENGER ====================

class BusinessPassenger : public Passenger
{
public:
    BusinessPassenger(int id,
                      string n)
        : Passenger(id, n)
    {
    }

    double getRefundPercentage() const
    {
        return 80.0;
    }

    string getPassengerType() const
    {
        return "Business";
    }

    void display() const
    {
        cout << "\n===== Business Passenger =====\n";
        cout << "ID: " << passengerID
             << "\nName: " << name
             << "\nRefund: "
             << getRefundPercentage()
             << "%\n";
    }
};
//==================== TICKET ====================

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
    Ticket(int id = 0,
           int pid = 0,
           string pname = "",
           string fno = "",
           double f = 0.0)
    {
        ticketID = id;
        passengerID = pid;
        passengerName = pname;
        flightNo = fno;
        fare = f;
        booked = true;
    }

    int getTicketID() const
    {
        return ticketID;
    }

    int getPassengerID() const
    {
        return passengerID;
    }

    string getPassengerName() const
    {
        return passengerName;
    }

    string getFlightNo() const
    {
        return flightNo;
    }

    double getFare() const
    {
        return fare;
    }

    bool isBooked() const
    {
        return booked;
    }

    void cancelTicket()
    {
        if(booked)
            booked = false;
    }

    bool operator==(const Ticket& other) const
    {
        return ticketID == other.ticketID;
    }

    friend ostream& operator<<(ostream& out,
                               const Ticket& t)
    {
        out << "\nTicket ID: "
            << t.ticketID
            << "\nPassenger ID: "
            << t.passengerID
            << "\nPassenger Name: "
            << t.passengerName
            << "\nFlight No: "
            << t.flightNo
            << "\nFare: Rs. "
            << t.fare
            << "\nStatus: "
            << (t.booked ? "Booked" : "Cancelled")
            << "\n---------------------------";

        return out;
    }
};

//==================== EXCEPTIONS ====================

class FlightFullException : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Flight is full!";
    }
};

class PassengerNotFoundException : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Passenger not found!";
    }
};

class FlightNotFoundException : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Flight not found!";
    }
};

class DuplicatePassengerException : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Passenger ID already exists!";
    }
};

class TicketNotFoundException : public exception
{
public:
    const char* what() const throw()
    {
        return "Error: Ticket not found!";
    }
};

//==================== TEMPLATE FUNCTION ====================

template <typename T>
void displayAll(const vector<T*>& items)
{
    for(size_t i = 0; i < items.size(); i++)
    {
        items[i]->display();
    }
}
//==================== AIRLINE ====================

class Airline
{
private:
    vector<Flight*> flights;
    vector<Passenger*> passengers;
    vector<Ticket> tickets;

public:

    ~Airline()
    {
        for(size_t i = 0; i < flights.size(); i++)
            delete flights[i];

        for(size_t i = 0; i < passengers.size(); i++)
            delete passengers[i];
    }

    //==================== ADD FLIGHT ====================

    void addFlight(Flight* flight)
    {
        for(size_t i = 0; i < flights.size(); i++)
        {
            if(flights[i]->getFlightNo()
               == flight->getFlightNo())
            {
                cout << "\nFlight Number Already Exists!\n";
                delete flight;
                return;
            }
        }

        flights.push_back(flight);

        cout << "\nFlight Added Successfully!\n";
    }

    //==================== ADD PASSENGER ====================

    void addPassenger(Passenger* passenger)
    {
        for(size_t i = 0; i < passengers.size(); i++)
        {
            if(passengers[i]->getPassengerID()
               == passenger->getPassengerID())
            {
                throw DuplicatePassengerException();
            }
        }

        passengers.push_back(passenger);

        cout << "\nPassenger Registered Successfully!\n";
    }

    //==================== DISPLAY FLIGHTS ====================

    void displayFlights() const
    {
        if(flights.empty())
        {
            cout << "\nNo Flights Available.\n";
            return;
        }

        displayAll(flights);
    }

    //==================== DISPLAY PASSENGERS ====================

    void displayPassengers() const
    {
        if(passengers.empty())
        {
            cout << "\nNo Passengers Registered.\n";
            return;
        }

        displayAll(passengers);
    }

    //==================== BOOK TICKET ====================

    void bookTicket(int passengerID,
                    string flightNo)
    {
        Passenger* passenger = NULL;
        Flight* flight = NULL;

        // Find Passenger
        for(size_t i = 0; i < passengers.size(); i++)
        {
            if(passengers[i]->getPassengerID()
               == passengerID)
            {
                passenger = passengers[i];
                break;
            }
        }

        if(passenger == NULL)
            throw PassengerNotFoundException();

        // Find Flight
        for(size_t i = 0; i < flights.size(); i++)
        {
            if(flights[i]->getFlightNo()
               == flightNo)
            {
                flight = flights[i];
                break;
            }
        }

        if(flight == NULL)
            throw FlightNotFoundException();

        // Check Seat Availability
        if(!flight->bookSeat())
        {
            throw FlightFullException();
        }

        Ticket ticket(
            tickets.size() + 1,
            passenger->getPassengerID(),
            passenger->getName(),
            flight->getFlightNo(),
            flight->calculateFare()
        );

        tickets.push_back(ticket);

        cout << "\nTicket Booked Successfully!\n";
        cout << ticket << endl;
    }

    //==================== CANCEL TICKET ====================

    void cancelTicket(int ticketID)
    {
        for(size_t i = 0; i < tickets.size(); i++)
        {
            if(tickets[i].getTicketID()
               == ticketID)
            {
                if(tickets[i].isBooked())
                {
                    string flightNo =
                        tickets[i].getFlightNo();

                    tickets[i].cancelTicket();

                    for(size_t j = 0;
                        j < flights.size();
                        j++)
                    {
                        if(flights[j]->getFlightNo()
                           == flightNo)
                        {
                            flights[j]->cancelSeat();
                            break;
                        }
                    }
                }

                cout << "\nTicket Cancelled Successfully!\n";
                return;
            }
        }

        throw TicketNotFoundException();
    }

    //==================== DISPLAY TICKETS ====================

    void displayTickets() const
    {
        if(tickets.empty())
        {
            cout << "\nNo Tickets Found.\n";
            return;
        }

        for(size_t i = 0; i < tickets.size(); i++)
        {
            cout << tickets[i] << endl;
        }
    }

    //==================== SAVE DATA ====================

    void saveData()
    {
        ofstream file("tickets.txt");

        if(!file)
        {
            cout << "\nUnable To Open File!\n";
            return;
        }

        for(size_t i = 0; i < tickets.size(); i++)
        {
            file
            << tickets[i].getTicketID() << ","
            << tickets[i].getPassengerID() << ","
            << tickets[i].getPassengerName() << ","
            << tickets[i].getFlightNo() << ","
            << tickets[i].getFare()
            << endl;
        }

        file.close();

        cout << "\nData Saved Successfully!\n";
    }

    //==================== LOAD DATA ====================

    void loadData()
    {
        ifstream file("tickets.txt");

        if(!file)
        {
            cout << "\nNo Saved File Found.\n";
            return;
        }

        string line;

        cout << "\n===== SAVED DATA =====\n";

        while(getline(file, line))
        {
            cout << line << endl;
        }

        file.close();
    }

    //==================== STATISTICS ====================

    int totalFlights() const
    {
        return flights.size();
    }

    int totalPassengers() const
    {
        return passengers.size();
    }

    int totalTickets() const
    {
        return tickets.size();
    }
};
//==================== MAIN FUNCTION ====================

int main()
{
    Airline airline;

    int choice;

    do
    {
        cout << "\n\t\t\t\t====================================";
        cout << "\n\t\t\t\t   AIRLINE RESERVATION SYSTEM";
        cout << "\n\t\t\t\t====================================";

        cout << "\n1. Add Domestic Flight";
        cout << "\n2. Add International Flight";
        cout << "\n3. Register Economy Passenger";
        cout << "\n4. Register Business Passenger";
        cout << "\n5. View Flights";
        cout << "\n6. View Passengers";
        cout << "\n7. Book Ticket";
        cout << "\n8. Cancel Ticket";
        cout << "\n9. View Tickets";
        cout << "\n10. Save Data";
        cout << "\n11. Load Data";
        cout << "\n12. Statistics";
        cout << "\n0. Exit";

        cout << "\n\nEnter Choice: ";
        cin >> choice;

        try
        {
            switch(choice)
            {
                case 1:
                {
                    string no;
                    string origin;
                    string destination;
                    int seats;

                    cout << "\nFlight Number: ";
                    cin >> no;

                    cout << "Origin: ";
                    cin >> origin;

                    cout << "Destination: ";
                    cin >> destination;

                    cout << "Total Seats: ";
                    cin >> seats;

                    if(seats <= 0)
                    {
                        cout << "Invalid Number of Seats!\n";
                        break;
                    }

                    airline.addFlight(
                        new DomesticFlight(
                            no,
                            origin,
                            destination,
                            seats
                        )
                    );

                    break;
                }

                case 2:
                {
                    string no;
                    string origin;
                    string destination;
                    int seats;
                    bool visa;

                    cout << "\nFlight Number: ";
                    cin >> no;

                    cout << "Origin: ";
                    cin >> origin;

                    cout << "Destination: ";
                    cin >> destination;

                    cout << "Total Seats: ";
                    cin >> seats;

                    cout << "Visa Required (1=Yes 0=No): ";
                    cin >> visa;

                    if(seats <= 0)
                    {
                        cout << "Invalid Number of Seats!\n";
                        break;
                    }

                    airline.addFlight(
                        new InternationalFlight(
                            no,
                            origin,
                            destination,
                            seats,
                            visa
                        )
                    );

                    break;
                }

                case 3:
                {
                    int id;
                    string name;

                    cout << "\nPassenger ID: ";
                    cin >> id;

                    cout << "Passenger Name: ";
                    cin >> name;

                    if(id <= 0)
                    {
                        cout << "Invalid Passenger ID!\n";
                        break;
                    }

                    airline.addPassenger(
                        new EconomyPassenger(
                            id,
                            name
                        )
                    );

                    break;
                }

                case 4:
                {
                    int id;
                    string name;

                    cout << "\nPassenger ID: ";
                    cin >> id;

                    cout << "Passenger Name: ";
                    cin >> name;

                    if(id <= 0)
                    {
                        cout << "Invalid Passenger ID!\n";
                        break;
                    }

                    airline.addPassenger(
                        new BusinessPassenger(
                            id,
                            name
                        )
                    );

                    break;
                }

                case 5:
                {
                    airline.displayFlights();
                    break;
                }

                case 6:
                {
                    airline.displayPassengers();
                    break;
                }

                case 7:
                {
                    int passengerID;
                    string flightNo;

                    cout << "\nPassenger ID: ";
                    cin >> passengerID;

                    cout << "Flight Number: ";
                    cin >> flightNo;

                    airline.bookTicket(
                        passengerID,
                        flightNo
                    );

                    break;
                }

                case 8:
                {
                    int ticketID;

                    cout << "\nTicket ID: ";
                    cin >> ticketID;

                    airline.cancelTicket(ticketID);

                    break;
                }

                case 9:
                {
                    airline.displayTickets();
                    break;
                }

                case 10:
                {
                    airline.saveData();
                    break;
                }

                case 11:
                {
                    airline.loadData();
                    break;
                }

                case 12:
                {
                    cout << "\n===== SYSTEM STATISTICS =====";

                    cout << "\nTotal Flights: "
                         << airline.totalFlights();

                    cout << "\nTotal Passengers: "
                         << airline.totalPassengers();

                    cout << "\nTotal Tickets: "
                         << airline.totalTickets();

                    cout << "\n";
                    break;
                }

                case 0:
                {
                    cout << "\nThank You For Using The System!\n";
                    break;
                }

                default:
                {
                    cout << "\nInvalid Choice!\n";
                }
            }
        }
        catch(const exception& e)
        {
            cout << "\n" << e.what() << endl;
        }
        catch(...)
        {
            cout << "\nUnknown Error Occurred!\n";
        }

    } while(choice != 0);

    return 0;
}
