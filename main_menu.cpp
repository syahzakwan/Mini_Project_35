#include "main_menu.hpp"
#include <iostream>

using namespace std;

void mainMenu(LoginRegisterForgot &loginregisterforgot) 
{
    int choice;

    do 
    {
    cout << "\t\t\t\t\t ___________________________________________________________________"  << endl;
    cout << "\t\t\t\t\t|                                                                  |" << endl;
    cout << "\t\t\t\t\t|                            Main Menu                             |" << endl;
    cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
    cout << "\t\t\t\t\t|                                                                  |" << endl;
    cout << "\t\t\t\t\t|                  Press 1 ---- 1) Login Customer ID               |" << endl;
    cout << "\t\t\t\t\t|                  Press 2 ---- 2) Register Customer ID            |" << endl;
    cout << "\t\t\t\t\t|                  Press 3 ---- 3) Forget password                 |" << endl;
    cout << "\t\t\t\t\t|                  Press 4 ---- 4) Airline ticket reservation      |" << endl;
    cout << "\t\t\t\t\t|                  Press 5 ---- 5) Ticket bill                     |" << endl;
    cout << "\t\t\t\t\t|                  Press 6 ---- 6) Cancel reservation              |" << endl;
    cout << "\t\t\t\t\t|                  Press 7 ---- 7) Exit                            |" << endl;
    cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
    cout << "\n"<< endl;
    cout << "\t\t\t\t\t                     Enter your choice > ";
        cin >> choice;

        switch (choice) 
        {
        case 1:
            loginregisterforgot.loginCustomer();
            break;
        case 2:
            loginregisterforgot.registerCustomer();
            break;
        case 3:
            loginregisterforgot.forgotPassword();
            break;
        case 4:
            loginregisterforgot.booking();
            break;
        case 5:

        case 6:
            cancel.cancelBooking();
            break;
        
        case 7:
            cout << "\n" << endl;
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t|                                                                  |" << endl;
            cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
            cout << "\t\t\t\t\t|                                                                  |" << endl;
            cout << "\t\t\t\t\t|                  Thank you for using Group 35                    |" << endl;
            cout << "\t\t\t\t\t|                  airline reservation system!!!                   |" << endl;
            cout << "\t\t\t\t\t|                       Have a nice day!!!!!                       |" << endl; 
            cout << "\t\t\t\t\t|                                                                  |" << endl;
            cout << "\t\t\t\t\t|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << endl;
            cout << "\t\t\t\t\t|__________________________________________________________________|" << endl;
            cout <<"\n\n";
            break;
            
        default:
            cout << "\n" << endl;
            cout << "\t\t\t\t\t ___________________________________________________________________" << endl;
            cout << "\t\t\t\t\t!                                                                  !" << endl;
            cout << "\t\t\t\t\t!                            Invalid!!!!                           !" << endl;
            cout << "\t\t\t\t\t!        Please enter your choice according to main menu above!!!  !" << endl;
            cout << "\t\t\t\t\t!__________________________________________________________________!" << endl;
            cout << "\n\n" << endl;
        }
        
    } while (choice != 7);
}
