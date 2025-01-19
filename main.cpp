/*                         GROUP 35
  _________________________________________________________
  |                                   |                   |
  |           NAME                    |      Matric No    |
  |___________________________________|___________________|
  |                                   |                   |
  |         TANG JIN SHEN             |      23301943     |
  |     GARETT KHOO BOO ZHENG         |      23301528     |
  | AHMAD SYAHIRAN ZAKWAN BIN KARMAH  |      23303512     |
  | NURUL FATIHA ARMANI BINTI MUHAMMAD|      23302501     | 
  |              NIZAM                |                   |
  |                                   |                   |
  |___________________________________|___________________|

  TITLE: AIRLINE RESERVATION SYSTEM  
*/

#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include <iostream>

using namespace std;

int main() 
{
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);
    return 0;
}
