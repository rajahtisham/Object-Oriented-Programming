#include <iostream>

#include "Airline.h"
#include "DomesticFlight.h"
#include "InternationalFlight.h"
#include "EconomyPassenger.h"
#include "BusinessPassenger.h"

using namespace std;

int main()
{
    Airline airline;
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n AIRLINE RESERVATION SYSTEM";
        cout << "\n====================================";
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
        cout << "\n12. System Statistics";
        cout << "\n0. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        try
        {
            switch (choice)
            {
            case 1:
            {
                string no, origin, destination;
                int seats;

                cout << "\nFlight Number: ";
                cin >> no;
                cout << "Origin: ";
                cin >> origin;
                cout << "Destination: ";
                cin >> destination;
                cout << "Total Seats: ";
                cin >> seats;

                airline.addFlight(new DomesticFlight(no, origin, destination, seats));
                break;
            }

            case 2:
            {
                string no, origin, destination;
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
                cout << "Visa Required (1=Yes, 0=No): ";
                cin >> visa;

                airline.addFlight(new InternationalFlight(no, origin, destination, seats, visa));
                break;
            }

            case 3:
            {
                int id;
                string name;

                cout << "\nPassenger ID: ";
                cin >> id;
                cout << "Name: ";
                cin >> name;

                airline.addPassenger(new EconomyPassenger(id, name));
                break;
            }

            case 4:
            {
                int id;
                string name;

                cout << "\nPassenger ID: ";
                cin >> id;
                cout << "Name: ";
                cin >> name;

                airline.addPassenger(new BusinessPassenger(id, name));
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

                airline.bookTicket(passengerID, flightNo);
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
                cout << "\nTotal Flights: " << airline.totalFlights();
                cout << "\nTotal Passengers: " << airline.totalPassengers();
                cout << "\nTotal Tickets: " << airline.totalTickets();
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
        catch (const exception& e)
        {
            cout << "\n" << e.what() << endl;
        }
        catch (...)
        {
            cout << "\nUnknown Error Occurred!\n";
        }

    } while (choice != 0);

    return 0;
}
