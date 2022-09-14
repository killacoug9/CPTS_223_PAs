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

    // this->menuListObj.functions[0] = &AppWrapper::displayGameRules; 
    // this->menuListObj.functions[1] = &AppWrapper::playGame; 
    // this->menuListObj.functions[2] = &AppWrapper::loadPreviousGame;
    // this->menuListObj.functions[3] = &AppWrapper::addCommand;
    // this->menuListObj.functions[4] = &AppWrapper::removeCommand;
    // this->menuListObj.functions[5] = &AppWrapper::exitApp;
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
    executeOption(this->menuDisplayMethod(this->menuListObj.strs));

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
    return (this->*menuListObj.functions[option - 1])() ;
}

void AppWrapper::displayGameRules(void){
    cout << "Game Rules Displaying" << endl;
}

void AppWrapper::playGame(void){
    cout << "Play game Displaying" << endl;
}

void AppWrapper::loadPreviousGame(void){
    cout << "load prev game Displaying" << endl;
}

void AppWrapper::addCommand(void){
    cout << "add command Displaying" << endl;
}

void AppWrapper::removeCommand(void){
    cout << "remove command Displaying" << endl;
}

void AppWrapper::exitApp(void){
    cout << "exit app Displaying" << endl;
}

