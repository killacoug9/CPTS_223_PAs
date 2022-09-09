#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib> 
#include <string>
#include <exception>
//#include <ncurses.h>

// for getch 
#include <unistd.h>
#include <termios.h>

using namespace std;
using std::cout;
using std::endl;

#define PROFILES_LENGTH 10 // this is just a rough constant for the profiles size
#define MENU_OPTIONS_LENGTH 6
/* Menu Options */

using void_func_ptr = void (*)();
using int_func_ptr = int (*)(const char**, void_func_ptr);

typedef struct Menu 
{
    void_func_ptr functions[MENU_OPTIONS_LENGTH];
    const char* strs[MENU_OPTIONS_LENGTH];
};

// emulate the same functionality as system("pause") thats on windows
void systemPause();

// used to get line without them clicking enter, alternative to <ncurses>, found from https://stackoverflow.com/questions/421860/capture-characters-from-standard-input-without-waiting-for-enter-to-be-pressed
char getch(); // 

