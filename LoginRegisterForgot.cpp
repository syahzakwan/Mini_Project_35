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
