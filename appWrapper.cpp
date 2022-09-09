#include "appWrapper.hpp"

AppWrapper::AppWrapper(bool isFancyMenu) 
{
    // this->menuListObj.functions = {
    //     displayGameRules, 
    //     playGame, 
    //     loadPreviousGame, 
    //     addCommand, 
    //     removeCommand, 
    //     exitApp
    // };
    // const char* menuStr[MENU_OPTIONS_LENGTH] = {
    //     "Game Rules",
    //     "Play Game",
    //     "Load Previous Game",
    //     "Add Command",
    //     "Remove Command",
    //     "Exit"
    // };
    if (isFancyMenu)
        { this->menuDisplayMethod = (int_func_ptr)&fancyMenu; }
    else
        { this->menuDisplayMethod = (int_func_ptr)&defaultMenuNav; }

}

void AppWrapper::displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]) {
    for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
        cout << i + 1 << ". " << strArr[i] << endl;
}

int AppWrapper::defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]){
    int input;
     do 
    {
        system("clear");
        displayMenu(strArr, funcArr);

        cout << "Enter choice: ";
        cin.clear();
        cin.ignore(123, '\n');
    } while (!(cin >> input));
    return input;
}

int AppWrapper::fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]){
 /*
black        30         40
red          31         41
green        32         42
yellow       33         43
blue         34         44
magenta      35         45
cyan         36         46
white        37         47

reset             0  (everything back to normal)
bold/bright       1  (often a brighter shade of the same colour)
underline         4
inverse           7  (swap foreground and background colours)
bold/bright off  21
underline off    24
inverse off      27
*/
    const std::string red("\033[0;31m"); 
    const std::string white("\033[0;37m"); 
    const std::string reset("\033[0m");
    const std::string inverse("\033[7m");

    //cout << red << "red text" << reset << endl;

    int choice = 1;
    char ch;

    system("clear"); // clear screen

    // _getch to get input before enter key
    for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
            (choice == i + 1) ? (cout << inverse << i + 1 << ". " << reset << strArr[i] << endl) : (cout << i + 1 << ". " << strArr[i] << endl);

    while ((ch = getch()) != '\n') {
        system("clear");
        if(ch =='w')
        { 
            choice > 1 ? choice-- : 0;
        } else if(ch =='s')
        {
            choice < MENU_OPTIONS_LENGTH ? choice++ : 0;
        }

        for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
            (choice == i + 1) ? (cout << inverse << i + 1 << ". " << reset << strArr[i] << endl) : (cout << i + 1 << ". " << strArr[i] << endl);
            //(choice == i + 1) ? (cout << white << i + 1 << ". " << reset << strArr[i] << endl) : (cout << i + 1 << ". " << strArr[i] << endl);
    }  

    return choice; 
}

int AppWrapper::run() 
{
    int profiles[PROFILES_LENGTH];
    int userMenuOption;

    bool commandsStatus = importCommands(), profilesStatus = importProfiles(); // false means no problems occcured
    
    if (!commandsStatus && !profilesStatus)
        this->appRun();

    return 0;
}

int AppWrapper::appRun() 
{ 
    executeOption(this->menuDisplayMethod(this->menuListObj.strs, *this->menuListObj.functions));

    return 0;
}

int AppWrapper::importCommands()
{
     // try to load commands and descriptions into LL, if fails then print and quit.
    {}
    {
        cout << "Failed to import 'commands.csv' to LL" << endl;
        cout << "The program will now quit" << endl;
        systemPause();
    }
    return false;
}

int AppWrapper::importProfiles()
{
    // try to load in the profiles arr into the 
    {
        // while condition
            // resize arr, add to front
    }
    {
        cout << "Failed to import 'profiles.csv' to LL" << endl;
        cout << "The program will now quit" << endl;
        systemPause();
    }
    return false;
}

void AppWrapper::executeOption(int option)
{
    return this->menuListObj.functions[option - 1]();
}

void AppWrapper::displayGameRules(void){

}

void AppWrapper::playGame(void){

}

void AppWrapper::loadPreviousGame(void){

}

void AppWrapper::addCommand(void){

}

void AppWrapper::removeCommand(void){

}

void AppWrapper::exitApp(void){

}

