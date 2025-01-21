/*                         GROUP 35
  ____________________________________________________________
  |                                      |                   |
  |              NAME                    |      Matric No    |
  |______________________________________|___________________|
  |                                      |                   |
  |            TANG JIN SHEN             |      23301943     |
  |        GARETT KHOO BOO ZHENG         |      23301528     |
  |   AHMAD SYAHIRAN ZAKWAN BIN KARMAH   |      23303512     |
  |  NURUL FATIHA ARMANI BINTI MUHAMMAD  |      23302501     | 
  |               NIZAM                  |                   |
  | NUR FARZANA IZZATI BINTI BARZAN SHAH |      23303059     |
  |______________________________________|___________________|

  TITLE: AIRLINE RESERVATION SYSTEM  
*/
#include <iostream>
#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include "cancel.hpp"
#include "destination.hpp"
#include "checkmax.hpp"
#include "maxseats.hpp"


using namespace std;

int main() 
{
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);


    bool economySeats[ECONOMY_SEATS] = {false}; 
    bool firstClassSeats[FIRST_CLASS_SEATS] = {false};
    bool businessClassSeats[BUSINESS_CLASS_SEATS] = {false};

    int choice;

    do {
        cin >> choice;

        switch (choice) {
            case 1: 
                if (isClassFullyBooked(economySeats, ECONOMY_SEATS)) {
                    cout << "\nAll economy class seats are fully booked. Returning to the main menu.\n";
                } else {
                    cout << "\nEconomy class seats are available. Proceeding with booking...\n";
                    
                }
                break;

            case 2: 
                if (isClassFullyBooked(businessClassSeats, BUSINESS_CLASS_SEATS)) {
                    cout << "\nAll business-class seats are fully booked. Returning to the main menu.\n";
                } else {
                    cout << "\nBusiness-class seats are available. Proceeding with booking...\n";
                    
                }
                break;

            case 3: 
                if (isClassFullyBooked(firstClassSeats, FIRST_CLASS_SEATS)) {
                    cout << "\nAll first-class seats are fully booked. Returning to the main menu.\n";
                } else {
                    cout << "\nFirst-class seats are available. Proceeding with booking...\n";
                    
                }
                break;

            case 4: 
                cout << "Exiting the system. Thank you!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);


     string destinations[TOTAL_DESTINATION] = {
        "India", "China", "Indonesia", "Pakistan", "Bangladesh", "Japan", "Philippines", "Vietnam", "Iran",
        "Turkiye", "Thailand", "Myanmar", "South Korea", "Iraq", "Afghanistan", "Yemen", "Uzbekistan", "Malaysia",
        "Saudi Arabia", "Nepal", "North Korea","Syria", "Sri Lanka", "Kazakhstan", "Cambodia", "Jordan", "United Arab Emirates",
         "Tajikistan", "Azerbaijan", "Laos", "Turkmenistan", "Kyrgyzstan","Singapore", "Lebanon", "Palestine", "Oman", "Kuwait", 
         "Georgia", "Mongolia", "Qatar", "Armenia", "Bahrain", "Timor Leste", "Cyprus", "Bhutan", "Maldives","Brunei"
    };

    string chosenDestination = selectDestination(destinations);
    cout << "You have chosen: " << chosenDestination << endl;
    return 0;
}
