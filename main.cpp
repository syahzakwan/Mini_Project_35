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

#include "LoginRegisterForgot.hpp"
#include "main_menu.hpp"
#include "welcome.hpp"
#include "cancel.hpp"
#include <iostream>

using namespace std;

int main() 
{
    welcomePage();
    LoginRegisterForgot loginregisterforgot;
    mainMenu(loginregisterforgot);
    return 0;
}
