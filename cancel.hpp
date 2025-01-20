#ifndef CANCEL_HPP
#define CANCEL_HPP

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CancelReservation {
public:
    // Structure to store customer booking details
    struct Booking {
        string customerID;
        string seatNumber;
        string classType;
    };

    // Vector to store all bookings
    static vector<Booking> bookings;

    // Function to show the cancel menu
    void showCancelMenu();

    // Function to cancel the booking
    void cancelBooking();

    // Function to check the seat status
    void checkSeatStatus();
};

#endif
