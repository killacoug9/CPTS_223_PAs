/*
critera: 

Commands should be stored in a file called commands.csv, in the form  
command, ”description” 
 For example, the first row could be:  
ls, “Short for lists; displays the file and directory names in the current 
working directory.” 
  
Please note that you should place “” around your description so that it is 
interpreted as one value in the .csv file. Each command,”description” pair 
should be placed on its own line in the file. Commands may be added and 
removed from the file through the program. At least the following 30 
commands should be supported at the beginning of the game: 



Player profiles must be stored in a file called profiles.csv. Each profile 
includes a name and current points. The format for a profile is name,points. 

Upon startup of the program, the Linux command and description pairs 
from commands.csv must be loaded into a singly linked list that was 
constructed from a 2 parameter template (see “Play Game Requirement” 
design considerations). All commands may be inserted at the front of the list 
as they are read from the file. Also, the user name and points pairs 
from profiles.csv must be loaded into a profiles array. All user name 
and points pairs must also be loaded at the front (index 0) of the array. Is 
this a poor design decision? You will discuss this as part of the assignment! 
See the “Other Requirements” section. 
*/

#include "functions.cpp"

using namespace std;
using std::cout;
using std::endl;

#define PROFILES_LENGTH 10 // this is just a rough constant for the profiles size
#define MENU_OPTIONS_LENGTH 6
/* Menu Options */

using func_ptr = void (*)();

    // void* menuOptions[][MENU_OPTIONS_COLS] = {
    //     {(void*)"Game Rules", (func_ptr)displayGameRules},
    //     {(void*)"Play Game", (func_ptr)playGame},
    //     {(void*)"Load Previous Game", (func_ptr)loadPreviousGame},
    //     {(void*)"Add Command", (func_ptr)addCommand},
    //     {(void*)"Remove Command", (func_ptr)removeCommand},
    //     {(void*)"Exit", (func_ptr)exitApp}
    // };

void systemPause();

char getch(); // 

void displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH]);

void defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH], int input);

int fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH], int input);

void appWrap(func_ptr menu);

int main(int argc, char *argv[]) {

    func_ptr menuFunc[MENU_OPTIONS_LENGTH] = {
        displayGameRules, 
        playGame, 
        loadPreviousGame, 
        addCommand, 
        removeCommand, 
        exitApp
    };

    const char* menuStr[MENU_OPTIONS_LENGTH] = {
        "Game Rules",
        "Play Game",
        "Load Previous Game",
        "Add Command",
        "Remove Command",
        "Exit"
    };

    int profiles[PROFILES_LENGTH];

    int userMenuOption;

    // try to load commands and descriptions into LL, if fails then print and quit.
    {}
    {
        cout << "Failed to import 'commands.csv' to LL" << endl;
        cout << "The program will now quit" << endl;
        systemPause();
    }

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
    
    fancyMenu(menuStr, menuFunc, userMenuOption);
   

    //cout << "\033[1;31mbold red text\033[0m\n";

    return 0;
}

void displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH]) {
    for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
        cout << i + 1 << ". " << strArr[i] << endl;
}

void defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH], int input){
     do 
    {
        system("clear");
        displayMenu(strArr, funcArr);

        cout << "Enter choice: ";
        cin.clear();
        cin.ignore(123, '\n');
    } while (!(cin >> input));
}



int fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], func_ptr funcArr[MENU_OPTIONS_LENGTH], int input){
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
    // _getch to get input before enter key
    for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
            (choice == i + 1) ? (cout << inverse << i + 1 << ". " << reset << strArr[i] << endl) : (cout << i + 1 << ". " << strArr[i] << endl);

    while ((ch = getch()) != '\n') {
        system("clear");
        // switch(ch) {
        //     case 'w': 
        //         choice > 1 ? choice-- : 0;
        //     break;
        //     case 's':
        //         choice < MENU_OPTIONS_LENGTH - 1 ? choice++ : 0;
        //     break;
        // }
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

        //cin.clear();
        //cin.ignore(123, '\n');
    }  

    return choice; 
}

void systemPause() {
    printf("Press any key to continue . . .");
    std::cin.get();
}

char getch() {
        char buf = 0;
        struct termios old = {0};
        if (tcgetattr(0, &old) < 0)
                perror("tcsetattr()");
        old.c_lflag &= ~ICANON;
        old.c_lflag &= ~ECHO;
        old.c_cc[VMIN] = 1;
        old.c_cc[VTIME] = 0;
        if (tcsetattr(0, TCSANOW, &old) < 0)
                perror("tcsetattr ICANON");
        if (read(0, &buf, 1) < 0)
                perror ("read()");
        old.c_lflag |= ICANON;
        old.c_lflag |= ECHO;
        if (tcsetattr(0, TCSADRAIN, &old) < 0)
                perror ("tcsetattr ~ICANON");
        return (buf);
}