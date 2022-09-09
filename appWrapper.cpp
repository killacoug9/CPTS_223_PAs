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