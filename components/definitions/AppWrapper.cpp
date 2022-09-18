#include "../headers/AppWrapper.hpp"

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

void AppWrapper::displayGameRules(void)
{
    cout << "Game Rules Displaying" << endl;
    // display game rules
}

Profile* AppWrapper::playNewGame(void) // !!!! whole func
{
    Profile profile;
    profile.name = enterNameScreen();
    profile.score = 0;

    return playGame(&profile);
}

Profile* AppWrapper::playGame(Profile* profile) /// !!! Return
{
    cout << "Play game Displaying" << endl; 

    int gameLength = askNumberQuestions();
    Node* curCommand = this->gameDeck->getHead();

    for (int i = 0; i < gameLength; i++)
    {
        promptQuestion(curCommand) ? profile->score++ : profile->score--;
        curCommand = curCommand->getNext();
    }
    return profile;
}

void AppWrapper::loadPreviousGame(void)
{
    cout << "load prev game Displaying" << endl;
    
    cout << "What is the name of the profile you want to load" << endl;
    std::string tempName;
    tempName = enterNameScreen();
    
    


}

Profile* AppWrapper::checkProfilesFor(std::string name)
{
    for(int i = 0; i < (sizeof(this->profiles)/sizeof(this->profiles[0])); i++)
    {
        if(this->profiles[i].name == name){
            return this->profiles[i];
        }
    }
    return void*;
}

void AppWrapper::addCommand(void){
    cout << "add command Displaying" << endl;
}

void AppWrapper::removeCommand(void)
{
    cout << "remove command Displaying" << endl;
}

void AppWrapper::exitApp(void)
{
    cout << "exit app Displaying" << endl;
    // load profile in csv

}

std::string AppWrapper::enterNameScreen(void)
{
    std::string name;
    char input;

    cout << "Enter your name" << endl;
    getline(cin, name);

    cout << "Is \"" << name << "\" correct?(y/n)" << endl;

     while(cin >> input)
     {
        if(input == 'y')
        {
            break;
        } 
        else if(input == 'n')
        {
            name = enterNameScreen(); // could cause a bug or crash but idc
            break;
        }
     }
    return name;
}

int AppWrapper::askNumberQuestions(void)
{
    int choice;
    cout << "how many questions do you want to answer?(5-30)" << endl;
    
    do{
        cin >> choice;
    } while(!(choice < MAX_NUM_QUESTIONS && choice > MIN_NUM_QUESTIONS));

    return choice;
}

int AppWrapper::promptQuestion(Node* card) //////////
{
    int correctAnsIndex;
    std::string command = card->mData.name;
    std::string descriptions[NUM_POSSIBLE_CHOICES];
    // decide which index is correct
    // get random descriptions, put into arr

    descriptions[correctAnsIndex] = card->mData.description; // !!! description for correct ans
    for (size_t i = 0; i < NUM_POSSIBLE_CHOICES; i++) // fill arr with rand 
    {
        if(i != correctAnsIndex) {
            descriptions[i]; // !!! = rand option
        }
    }

    displayCommandAndQuestion(command, descriptions);
    return askQuestionAnswer(correctAnsIndex);
}

void AppWrapper::displayCommandAndQuestion(std::string command, std::string description[NUM_POSSIBLE_CHOICES])
{
    cout << "% " << command << endl << endl;
    for (int i = 0; i < NUM_POSSIBLE_CHOICES; i++) { cout << i + 1 << ". " << description[i] << endl; }
}

 int AppWrapper::askQuestionAnswer(int correctIndex)
 {
    int choice;
    cout << "What is your choice?" << endl;

     do {
        cin >> choice;
    } while(!(choice < MAX_NUM_QUESTIONS && choice > MIN_NUM_QUESTIONS));

    if (choice - 1 == correctIndex)
    {
        return 1;
    }
    else
    {
        return 0;
    }
 }

