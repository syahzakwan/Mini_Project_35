#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Airplane {
private:
    int rows;
    int columns;
    vector<vector<bool>> seats; 

public:
  
    Airplane(int r, int c) : rows(r), columns(c) {
      
        seats.resize(rows, vector<bool>(columns, false));
    }

  
    void displaySeats() {
        cout << "\nSeat Layout (0 = Available, 1 = Reserved):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << (seats[i][j] ? "1 " : "0 ");
            }
            cout << endl;
        }
    }

 
    bool reserveSeat(int row, int col) {
        if (row < 0 || row >= rows || col < 0 || col >= columns) {
            cout << "Invalid seat position.\n";
            return false;
        }
        if (seats[row][col]) {
            cout << "Seat (" << row + 1 << "," << col + 1 << ") is already reserved.\n";
            return false;
        } else {
            seats[row][col] = true;
            cout << "Seat (" << row + 1 << "," << col + 1 << ") has been successfully reserved.\n";
            return true;
        }
    }

   
    void reserveMultipleSeats(int numberOfSeats) {
        int row, col;
        int reservedSeats = 0;

        while (reservedSeats < numberOfSeats) {
            cout << "\nEnter row and column to reserve seat " << reservedSeats + 1 << ": ";
            cin >> row >> col;
  
            row--;
            col--;

            if (reserveSeat(row, col)) {
                reservedSeats++;
      
