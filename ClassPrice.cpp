#include <iostream>
#include <string>
using namespace std;

int Dprices();

class FlightTicket {
private:
    double economyPrice;
    double businessPrice;
    double firstClassPrice;

public:
   
    FlightTicket(double economy, double business, double firstClass) 
        : economyPrice(economy), businessPrice(business), firstClassPrice(firstClass) {}


    void displayPrice(int seatClass) {
        switch (seatClass) {
            case 1: 
                cout << "The ticket price for Economy Class is: $" << economyPrice << endl;
                break;
            case 2:
                cout << "The ticket price for Business Class is: $" << businessPrice << endl;
                break;
            case 3:
                cout << "The ticket price for First Class is: $" << firstClassPrice << endl;
                break;
            default:
                cout << "Invalid seat class selected. Please try again." << endl;
                break;
        }
    }

    
    void displaySeatClasses() {
        cout << "\nAvailable Seat Classes:" << endl;
        cout << "1. Economy Class" << endl;
        cout << "2. Business Class" << endl;
        cout << "3. First Class" << endl;
    }
};

int Dprices() {
    double economyPrice = 199.99;
    double businessPrice = 499.99;
    double firstClassPrice = 999.99;
  
    FlightTicket ticket(economyPrice, businessPrice, firstClassPrice);

    int seatClass;
    bool validSelection = false;

    cout << "Welcome to the Flight Ticket Booking System!" << endl;

    while (!validSelection) {
        ticket.displaySeatClasses();
        cout << "Please select a seat class (1/2/3): ";
        cin >> seatClass;

        
        if (seatClass >= 1 && seatClass <= 3) {
            ticket.displayPrice(seatClass);
            validSelection = true; 
        } else {
            cout << "Invalid selection. Please select a valid seat class.\n";
        }
    }


    return 0;
}
