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


typedef struct Menu {
    void_func_ptr functions[MENU_OPTIONS_LENGTH];
    const char* strs[MENU_OPTIONS_LENGTH];
};

void systemPause();

char getch(); // 

void displayMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]);

int defaultMenuNav(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]);

int fancyMenu(const char* strArr[MENU_OPTIONS_LENGTH], void_func_ptr funcArr[MENU_OPTIONS_LENGTH]);


void displayGameRules(void);

void playGame(void);

void loadPreviousGame(void);

void addCommand(void);

void removeCommand(void);

void exitApp(void);