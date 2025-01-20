#include "cancel.hpp"

// Initialize the static vector of bookings
vector<CancelReservation::Booking> CancelReservation::bookings;

// Function to show the cancel menu
void CancelReservation::showCancelMenu() {
    int choice;

    do {
        cout << "\n\t\t\t\t\t1. Confirm cancel reservation" << endl;
        cout << "\t\t\t\t\t2. Check seat status" << endl;
        cout << "\t\t\t\t\t3. Exit" << endl;
        cout << "\n\t\t\t\t\tEnter your choice > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cancelBooking();
                break;
            case 2:
                checkSeatStatus();
                break;
            case 3:
                break;
            default:
                cout << "\n\t\t\t\t\tInvalid choice! Please choose again." << endl;
        }
    } while (choice != 3);
}

// Function to cancel the booking
void CancelReservation::cancelBooking() {
    string customerID;
    bool found = false;

    cout << "\n\t\t\t\t\tEnter your customer ID to cancel reservation: ";
    cin >> customerID;

    // Search for the booking with the provided customer ID
    for (auto it = bookings.begin(); it != bookings.end(); ++it) {
        if (it->customerID == customerID) {
            found = true;
            cout << "\n\t\t\t\t\tBooking found. Cancelling reservation..." << endl;
            bookings.erase(it);  // Remove the booking
            cout << "\t\t\t\t\tReservation canceled successfully!" << endl;
            break;
        }
    }

    if (!found) {
        cout << "\n\t\t\t\t\tNo reservation found with the provided Customer ID." << endl;
    }
}

// Function to check the seat status
void CancelReservation::checkSeatStatus() {
    if (bookings.empty()) {
        cout << "\n\t\t\t\t\tNo bookings found!" << endl;
        return;
    }

    cout << "\n\t\t\t\t\tCurrently reserved seats:" << endl;
    for (const auto& booking : bookings) {
        cout << "\t\t\t\t\tCustomer ID: " << booking.customerID 
             << ", Seat Number: " << booking.seatNumber 
             << ", Class: " << booking.classType << endl;
    }
}
