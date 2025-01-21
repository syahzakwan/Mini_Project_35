#include <iostream>
#include <limits>
#include "destination.hpp"

using namespace std;

void displayDestinations(const string destinations[]) {
    cout << "\nAvailable Destinations:\n";
    for (int i = 0; i < TOTAL_DESTINATION; i++) {
        cout << i + 1 << ". " << destinations[i] << endl;
    }
}

string selectDestination(const string destinations[]) {
    int choice;
    do {
        displayDestinations(destinations);
        cout << "\nEnter the number of your chosen destination: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > TOTAL_DESTINATION) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid choice. Please try again.\n";
        } else {
            return destinations[choice - 1];
        }
    } while (true);
}