#ifndef LOGINREGISTERFORGOT_HPP
#define LOGINREGISTERFORGOT_HPP

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LoginRegisterForgot {
public:
    void registerUser();
    void loginUser();
    void forgotPassword();
private:
    const string databaseFile = "user_data.txt"; // File to store user data
    bool checkUserExists(const string& username, string& password);
};

#endif // LOGINREGISTERFORGOT_HPP
