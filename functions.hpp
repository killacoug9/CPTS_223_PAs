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

void displayGameRules(void);

void playGame(void);

void loadPreviousGame(void);

void addCommand(void);

void removeCommand(void);

void exitApp(void);