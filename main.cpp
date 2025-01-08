/*                         GROUP 35
  _________________________________________________________
  |                                   |                   |
  |           NAME                    |      Matric No    |
  |___________________________________|___________________|
  |                                   |                   |
  |         TANG JIN SHEN             |      23301943     |
  |                                   |                   |
  |                                   |                   |
  |                                   |                   | 
  |                                   |                   |
  |                                   |                   |
  |___________________________________|___________________|

  TITLE: AIRLINE RESERVATION SYSTEM  
*/

#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include <iostream>

using namespace std;

int main() {
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);
    return 0;
}
