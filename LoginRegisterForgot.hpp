#ifndef LOGINREGISTERFORGOT_HPP
#define LOGINREGISTERFORGOT_HPP

#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

class LoginRegisterForgot {
public:
    void registerUser();
    void loginUser();
    void forgotPassword();
    void booking();
private:
    const string databaseFile = "user_data.txt";
    bool checkUserExists(const string& username, string& password);
};

class FlightReservationSystem {
private:
    vector<vector<bool>> seats;
    int rows;
    int cols;

public:
    FlightReservationSystem(int rows, int cols) : rows(rows), cols(cols) {
        seats.resize(rows, vector<bool>(cols, false));
        loadSeatData();
    }

    ~FlightReservationSystem() {
        saveSeatData();
    }

    void displaySeats() {
        cout << "\nSeat Map (O = Available, X = Booked):\n";
        cout << "       ";
        for (int c = 0; c < cols; ++c) {
            cout << setw(2) << c + 1 << " ";
        }
        cout << endl;

        for (int r = 0; r < rows; ++r) {
            cout << "Row " << setw(2) << r + 1 << " ";
            for (int c = 0; c < cols; ++c) {
                cout << (seats[r][c] ? " X " : " O ");
            }
            cout << endl;
        }
    }

    void bookSeats(vector<pair<int, int>> seatSelections) {
        bool allAvailable = true;

        for (const auto& seat : seatSelections) {
            int row = seat.first;
            int col = seat.second;

            if (row < 1 || row > rows || col < 1 || col > cols || seats[row - 1][col - 1]) {
                allAvailable = false;
                cout << "Seat (Row " << row << ", Col " << col << ") is either invalid or already booked.\n";
            }
        }

        if (allAvailable) {
            for (const auto& seat : seatSelections) {
                seats[seat.first - 1][seat.second - 1] = true;
            }
            cout << "All selected seats have been successfully booked!\n";
        } else {
            cout << "Some seats could not be booked. Please try again.\n";
        }
    }

    void saveSeatData() {
       ofstream seatFileWrite("booking.txt");
       if (!seatFileWrite) {
        cerr << "Error saving booking data to file.\n";
        return;
       }
       seatFileWrite << rows << " " << cols << endl;
       for (const auto& row : seats) {
        for (bool seat : row) {
            seatFileWrite << seat << " ";
        }
        seatFileWrite << endl;
       }

       seatFileWrite.close();
    }

    void loadSeatData() {
        ifstream seatFileRead("booking.txt");
        if (!seatFileRead) {
            cerr << "Error loading data." << endl;
            return;
        }
        
        int fileRows, fileCols;
        seatFileRead >> fileRows >> fileCols;

        if (fileRows != rows || fileCols != cols) {
            cerr << "Error: Seat data does not match." << endl;
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

};

#endif // LOGINREGISTERFORGOT_HPP
