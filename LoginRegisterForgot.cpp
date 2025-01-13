#include "LoginRegisterForgot.hpp"

bool LoginRegisterForgot::checkUserExists(const string& username, string& password) 
{
    ifstream infile(databaseFile);
    string fileUsername, filePassword;

    while (getline(infile, fileUsername) && getline(infile, filePassword)) {
        if (fileUsername == username) {
            password = filePassword;
            return true;
        }
    }
    return false;
}

void LoginRegisterForgot::registerUser() 
{
    string username, password;
    cout <<"\n" << endl;
    cout << "\t\t\t\t\t\t\t     Enter username: ";
    cin.ignore(); 
    getline(cin, username);

    string dummyPassword;
    if (checkUserExists(username, dummyPassword)) {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                    This username already exists                  !" << endl;
        cout << "\t\t\t\t\t!                      Please try again later                      !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
        return;
    }

    cout << "\t\t\t\t\t\t\t     Enter password: ";
    getline(cin, password);

    ofstream outfile(databaseFile, ios::app);
    if (outfile.is_open()) {
        outfile << username << '\n' << password << '\n';
         cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                      Register succesfull!!!!                     |" << endl;
        cout << "\t\t\t\t\t|                             Welcome !!!                          |" << endl;
        cout << "\t\t\t\t\t\t\t\t   "                  << username<< "\t\t\t\t\t"                   <<endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;
    } else {
        cout << "\t\t\t\t\t\t\t     Error: Unable to open file for writing.\n";
    }
    outfile.close();
}

void LoginRegisterForgot::loginUser() 
{
    string username, password, storedPassword;
    cout << "\t\t\t\t\t\t\t     Enter username: ";
    cin.ignore();
    getline(cin, username);
    cout << "\t\t\t\t\t\t\t     Enter password: ";
    getline(cin, password);

    if (checkUserExists(username, storedPassword) && storedPassword == password) {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t|                                                                  |" << endl;
        cout << "\t\t\t\t\t|                      Login succesfull!!!!                        |" << endl;
        cout << "\t\t\t\t\t|                         Welcome back!!                           |" << endl;
        cout << "\t\t\t\t\t\t\t\t  "                  << username<< "\t\t\t\t\t"                   <<endl;
        cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
        cout <<"\n\n" << endl;
    } else {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                    Invalid Username or Password                  !" << endl;
        cout << "\t\t\t\t\t!                        Please try again later                    !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout <<"\n\n" << endl;
    }
}

void LoginRegisterForgot::forgotPassword() 
{
    string username, storedPassword;
    cout << "\t\t\t\t\t\t\t     Enter your username: ";
    cin.ignore();
    getline(cin, username);

    if (checkUserExists(username, storedPassword)) {
        cout << "\t\t\t\t\t\t\t     Your password is: " << storedPassword << "\n\n\n";
    } else {
        cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
        cout << "\t\t\t\t\t!                                                                  !" << endl;
        cout << "\t\t\t\t\t!                       Username not found!!                       !" << endl;
        cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
        cout << "\n\n" << endl;
    }
}

void LoginRegisterForgot::booking()
{
    int rows = 30;
    int cols = 6;
    FlightReservationSystem system(rows, cols);

    int choice;
    do {
        cout << "\n--- Flight Ticket Reservation System ---\n";
        cout << "1. Display Available Seats\n";
        cout << "2. Book Seats\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            system.displaySeats();
            break;
        case 2: {
            int numSeats;
            cout << "Enter the number of seats to book: ";
            cin >> numSeats;

            if (cin.fail() || numSeats <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a positive integer.\n";
                break;
            }

            vector<pair<int, int>> seatSelections;
            for (int i = 0; i < numSeats; ++i) {
                int row, col;
                cout << "Enter row and column for seat " << i + 1 << " (e.g., 1 2): ";
                cin >> row >> col;

                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter valid row and column numbers.\n";
                    --i; // Retry the current seat input
                    continue;
                }

                seatSelections.emplace_back(row, col);
            }

            system.bookSeats(seatSelections);
            break;
        }
        case 3:
            cout << "Exiting the system. Thank you!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

}
