#include "cancel.hpp"
#include <iostream>
#include <map>

using namespace std;

map<int, string> seatStatus = {
    {101, "Available"},
    {102, "Booked"},
    {103, "Available"},
    {104, "Booked"},
    {105, "Available"}
};

void Cancel::cancelReservation() {
    int choice;
    cout << " __________________________________________________________________ " << endl;
    cout << "|____________________ Cancel Reservation Menu _____________________|" << endl;
    cout << "|                                                                  |" << endl;
    cout << "|                  1) Confirm Cancel Reservation                   |" << endl;
    cout << "|                  2) Check Seat Status                            |" << endl;
    cout << "|                  3) Back to Main Menu                            |" << endl;
    cout << "|__________________________________________________________________|" << endl;
   cout << "\n"<< endl;
    cout << "\t\t\t\t\t           Enter your choice > ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter Booking ID to confirm cancellation: ";
            int bookingID;
            cin >> bookingID;
            confirmCancellation(bookingID);
            break;
        case 2:
            cout << "Enter Booking ID to check seat status: ";
            cin >> bookingID;
            checkSeatStatus(bookingID);
            break;
        default:
            cout << "Invalid option! Returning to main menu..." << endl;
            break;
    }
}

void Cancel::checkSeatStatus(int bookingID) {
    cout << "Checking seat status for Booking ID: " << bookingID << endl;

    if(seatStatus.find(bookingID) != seatStatus.end()) {
        cout << "Seat Status: " << seatStatus[bookingID] << endl;
    } else {
        cout << "Invalid Booking ID!" << endl;
    }

    char confirmCancel;
    cout << "Would you like to cancel this seat reservation (Y/N)? ";
    cin >> confirmCancel;
    if(confirmCancel == 'Y' || confirmCancel == 'y') {
        confirmCancellation(bookingID);
    }
}

void Cancel::confirmCancellation(int bookingID) {
    if(seatStatus.find(bookingID) != seatStatus.end()) {
        if(seatStatus[bookingID] == "Booked") {
            seatStatus[bookingID] = "Available";
            cout << "The reservation for Booking ID " << bookingID << " has been successfully cancelled." << endl;
        } else {
            cout << "No reservation found for this Booking ID!" << endl;
        }
    } else {
        cout << "Invalid Booking ID!" << endl;
    }
}
