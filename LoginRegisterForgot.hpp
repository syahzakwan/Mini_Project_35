#ifndef LOGINREGISTERFORGOT_HPP
#define LOGINREGISTERFORGOT_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class LoginRegisterForgot 
{

public:

    void registerCustomer();
    void loginCustomer();
    void forgotPassword();
    void booking();

private:

    const string customerFile = "customer_data.txt";
    bool checkCustomerExists(const string& username, string& password);

};

class FlightReservationSystem {
private:
    vector<vector<bool>> fcseats;
    vector<vector<bool>> bcseats;
    vector<vector<bool>> ecseats;
    int rows;
    int cols;

    void saveSeatData(const string& filename, const vector<vector<bool>>& seats) {
       ofstream seatFileWrite(filename);
       if (!seatFileWrite) {
        cerr << "Error saving booking data to " << filename << "." << endl;
        return;
       }

       seatFileWrite << seats.size() << " " << seats[0].size() << endl;
       for (const auto& row : seats) {
        for (bool seat : row) {
            seatFileWrite << seat << " ";
        }
        seatFileWrite << endl;
       }

       seatFileWrite.close();
    }

    void loadSeatData(const string& filename, vector<vector<bool>>& seats) {
        ifstream seatFileRead(filename);
        if (!seatFileRead) {
            cerr << "Error loading data for " << filename << "." << endl;
            return;
        }
        
        int fileRows, fileCols;
        seatFileRead >> fileRows >> fileCols;

        if (fileRows != static_cast<int>(seats.size()) || fileCols != static_cast<int>(seats[0].size())) {
            cerr << "Error: Seat data does not match data in " << filename << "." << endl;
            return;
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                int seatStatus;
                seatFileRead >> seatStatus;
                seats[r][c] = static_cast<bool>(seatStatus);
            }
        }
        seatFileRead.close();
    }

public:
    // : rows(rows), cols(cols) 
    FlightReservationSystem(int fcrows, int bcrows, int ecrows, int cols) {
        fcseats.resize(fcrows, vector<bool>(cols, false));
        bcseats.resize(bcrows, vector<bool>(cols, false));
        ecseats.resize(ecrows, vector<bool>(cols, false));

        loadSeatData("firstclass.txt", fcseats);
        loadSeatData("businessclass.txt", bcseats);
        loadSeatData("economyclass.txt", ecseats);
    }

    ~FlightReservationSystem() {
        saveSeatData("firstclass.txt", fcseats);
        saveSeatData("businessclass.txt", bcseats);
        saveSeatData("economyclass.txt", ecseats);
    }

    void displaySeats(const string& className, const vector<vector<bool>>& seats) {
        cout << "\n" << className << "Seat Map (O = Available, X = Booked):\n";
        cout << "        A  B  C    D  E  F  G    H  I  J" << endl;
        for (size_t r = 0; r < seats.size(); ++r) {
            cout << "Row " << setw(2) << r + 1 << " ";
            for (size_t c = 0; c < seats[0].size(); ++c) {
                if (c == 3 || c == 7) {
                cout <<  "  ";
                }
                cout << (seats[r][c] ? " X " : " O ");
            }
            cout << endl;
        }
    }

    void bookSeatsbyClass(){
        int classChoice;
        cout << "Select class to book seats:\n";
        cout << "1. First Class\n";
        cout << "2. Business Class\n";
        cout << "3. Economy Class\n";
        cout << "Enter your choice: ";
        cin >> classChoice;

        if (classChoice < 1 || classChoice >3)
        cout << "Invalid choice. Please enter a number between 1 and 3.\n";
        return;

        vector<vector<bool>>* selectedSeats;
        string className;
        string filename;

        switch (classChoice) {
            case 1:
                selectedSeats = &fcseats;
                className = "First Class";
                filename = "firstclass.txt";
                break;
            case 2:
                selectedSeats = &bcseats;
                className = "Business Class";
                filename = "businessclass.txt";
                break;
            case 3:
                selectedSeats = &ecseats;
                className = "Economy Class";
                filename = "economyclass.txt";
                break;
        }

       cout << "\nDisplaying available seats for " << className << ":\n";
        displaySeats(className, *selectedSeats);

    // Get the number of seats to book
        int numSeats;
        cout << "Enter the number of seats to book in " << className << ": ";
        cin >> numSeats;

    // Validate number of seats
        if (numSeats <= 0) {
            cout << "Invalid number of seats. Returning to the main menu.\n";
            return;
        }

        vector<pair<int, int>> seatSelections;

        for (int i = 0; i < numSeats; ++i) {
            int row, col;
            cout << "Enter seat " << i + 1 << " (Row Col): ";
            cin >> row >> col;

            if (row < 1 || row > static_cast<int>(selectedSeats->size()) || col < 1 || col > static_cast<int>((*selectedSeats)[0].size())) {
                cout << "Invalid seat selection (Row " << row << ", Col " << col << "). Please try again.\n";
                --i; 
            } else {
                seatSelections.emplace_back(row, col);
            }
        }

        for (const auto& seat : seatSelections) {
        (*selectedSeats)[seat.first - 1][seat.second - 1] = true;
        }

        cout << "Successfully booked the following seats in " << className << ":\n";
        for (const auto& seat : seatSelections) {
            cout << "Row " << seat.first << ", Column " << seat.second << "\n";
        }

        
        if (classChoice == 1)
            filename = "first_class.txt";
        else if (classChoice == 2)
            filename = "business_class.txt";
        else
            filename = "economy_class.txt";

        saveSeatData(filename, *selectedSeats);

        bookSeats(seatSelections, *selectedSeats, className);
    }

    void bookSeats(vector<pair<int, int>> seatSelections, vector<vector<bool>>& seats, const string& className) {
        bool allAvailable = true;

        for (const auto& seat : seatSelections) {
            int row = seat.first;
            int col = seat.second;

            if (row < 1 || row > rows || col < 1 || col > cols || seats[row - 1][col - 1]) {
                allAvailable = false;
                cout << className << "Seat (Row " << row << ", Col " << col << ") is either invalid or already booked.\n";
            }
        }

        if (allAvailable) {
            for (const auto& seat : seatSelections) {
                seats[seat.first - 1][seat.second - 1] = true;
            }
            cout << "All selected seats in "<< className <<" have been successfully booked!\n";
        } else {
            cout << "Some seats in " << className << " could not be booked. Please try again.\n";
        }
    }

    void displaySeatsbyClass() {
    cout << "\n--- Displaying Seats by Class ---\n";
    cout << "\nFirst Class:\n";
    displaySeats("First Class", fcseats);
    cout << "\nBusiness Class:\n";
    displaySeats("Business Class", bcseats);
    cout << "\nEconomy Class:\n";
    displaySeats("Economy Class", ecseats);
}

};

#endif
