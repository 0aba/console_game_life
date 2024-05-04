#ifndef PAGES_UTILS_HPP
#define PAGES_UTILS_HPP

#include <stdlib.h>
#include "./game_logic.hpp"


#ifdef __linux__
#include <unistd.h>
#include <ncurses.h>

#define printFormat printw
#define scanFormat scanw

int _getch();

#elif _WIN32
#include <windows.h>
#include <conio.h> // _getch()

#define printFormat printf
// fseek решает проблему со скипом scanf
#define scanFormat fseek(stdin, 0, SEEK_END); scanf 

#endif

void sleepIteration(u16 seconds);

void setCursorTerminal(u16 x, u16 y);

void clearTerminal();
#endif