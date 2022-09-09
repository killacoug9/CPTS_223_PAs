#include "functions.hpp"

void displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]) {
    for (int i = 0; i < MENU_OPTIONS_LENGTH; i++) 
        cout << i + 1 << ". " << strArr[i] << endl;
}

int defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]){
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

int fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]){
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

void displayGameRules(void){

}

void playGame(void){

}

void loadPreviousGame(void){

}

void addCommand(void){

}

void removeCommand(void){

}

void exitApp(void){

}