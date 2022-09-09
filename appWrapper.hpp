#include "functions.cpp"

class AppWrapper 
{
public:
    // Constructor
    AppWrapper(bool fancyMenuActive = false);

    // will automatically run the whole application including support proceses and the game itself, imports the files and calls the actual game (i.e. appRun)
    int run();

    // attempts to import commands from csv and load them into obj member. Displays to console on failure and returns true. returns false if no problems occur during runtime.
    int importCommands();

    // attempts to import profiles from csv and load them into obj member. Displays to console on failure and returns true. returns false if no problems occur during runtime.
    int importProfiles();


private:
    Menu menuListObj = {
        .functions = {
            displayGameRules, 
            playGame, 
            loadPreviousGame, 
            addCommand, 
            removeCommand, 
            exitApp
        }, 
        .strs = {
            "Game Rules",
            "Play Game",
            "Load Previous Game",
            "Add Command",
            "Remove Command",
            "Exit"
        }
    };
    int_func_ptr menuDisplayMethod;
    
    // called by run(). Runs the application by displaying menu and then calling the appropriate user selction func
    int appRun();

    // exececutes the menu option function given by the int option passed in as param
    void executeOption(int option);

    //
    void displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]);

    //
    int defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]);

    // used info found from https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
    int fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]); 

    // displays the rules of how to play the game
    void displayGameRules(void);

    //
    void playGame(void);

    //
    void loadPreviousGame(void);

    //
    void addCommand(void);

    //
    void removeCommand(void);

    //
    void exitApp(void);
};