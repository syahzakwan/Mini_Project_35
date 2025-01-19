#include <iostream>
#include <iomanip>
#include "ClassPrice.cpp"
using namespace std;

// Function to calculate and display the ticket bill
void calculateBill(double economyPrice, double businessPrice, double firstClassPrice, int seatClass, int numSeats) {
    if (numSeats <= 0) {
        cout << "Invalid number of seats. Please enter a positive integer.\n";
        return;
    }

    double pricePerSeat = 0.0;

    // Determine price per seat based on seat class
    switch (seatClass) {
        case 1:
            pricePerSeat = economyPrice;
            break;
        case 2:
            pricePerSeat = businessPrice;
            break;
        case 3:
            pricePerSeat = firstClassPrice;
            break;
        default:
            cout << "Invalid seat class selected. Please try again." << endl;
            return;
    }

    // Calculate and display the bill
    double totalCost = numSeats * pricePerSeat;
    cout << fixed << setprecision(2); // Format output for monetary values
    cout << "\n--- Ticket Bill ---\n";
    cout << "Seat Class: " << (seatClass == 1 ? "Economy" : (seatClass == 2 ? "Business" : "First Class")) << endl;
    cout << "Number of Seats: " << numSeats << endl;
    cout << "Price Per Seat: $" << pricePerSeat << endl;
    cout << "Total Cost: $" << totalCost << endl;
}
