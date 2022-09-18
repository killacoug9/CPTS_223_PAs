#pragma once

//#include "..../appFunctions.hpp"
//#include ".../appFunctions.hpp"
#include "../../appFunctions.hpp"
#include "./List.hpp"

#define NUM_POSSIBLE_CHOICES 3
#define MIN_NUM_QUESTIONS 5
#define MAX_NUM_QUESTIONS 30


typedef struct Profile {
    std::string name;
    int score;
};

typedef struct Command {
    std::string name;
    std::string description;
};

// typedef struct GameData {
//     const char* name;
//     int score;
// };


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
            &AppWrapper::displayGameRules, 
            &AppWrapper::playGame, 
            &AppWrapper::loadPreviousGame, 
            &AppWrapper::addCommand, 
            &AppWrapper::removeCommand, 
            &AppWrapper::exitApp,
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
    int maxQuestionsAmount;
    List* gameDeck;
    Profile profiles[PROFILES_LENGTH];
    Command Commands[];

    
    // called by run(). Runs the application by displaying menu and then calling the appropriate user selction func
    int appRun();

    // exececutes the menu option function given by the int option passed in as param
    void executeOption(int option);

    // displays the rules of how to play the game
    void displayGameRules(void);

    // 
    Profile* playNewGame();

    //
    Profile* playGame(Profile* profile);

    //
    void loadPreviousGame(void);

    // whecks the profile arr for a profile denotated by (name)
    Profile* checkProfilesFor(std::string name);

    //
    void addCommand(void);

    //
    void removeCommand(void);

    //
    void exitApp(void);

    // play game functions \/ \/ \/

    // will prompt them to enter their name, then ask them to confirm its correct, returns their name.
    std::string enterNameScreen();

   // asks how many questions they want. returns the number of questions(match length) they wanna answer
   int askNumberQuestions();

    // will decide what descriptions to display, and which command to display, as well as call the display unction. returns if thye got it right or wrong
   int promptQuestion(Node* card);

    // will display the options for descriptions and the command ur answering for
   void displayCommandAndQuestion(std::string command, std::string description[NUM_POSSIBLE_CHOICES]);

    // returns 0 if they got it worng, 1 if they got it right
    int askQuestionAnswer(int correctIndex);
   
   
};