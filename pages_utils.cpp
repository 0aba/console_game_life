#include "./pages_utils.hpp"


#ifdef __linux__
#include <stdio.h> 
        
int _getch()
{
	int key;
	noecho();
	key = getch();
	echo();

	return key;
}

void sleepIteration(u16 milliseconds)
{
	usleep(milliseconds * 1000);
}

void setCursorTerminal(u16 x, u16 y)
{
	move(y, x);
}

void clearTerminal()
{
	setCursorTerminal(0, 0);
	clear();
}
#elif _WIN32


void sleepIteration(u16 milliseconds)
{
	Sleep(milliseconds);
}

void setCursorTerminal(u16 x, u16 y)
{
	COORD coord {(short) x, (short) y}; // указание типа, чтобы при компиляции не было варнингов 

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearTerminal()
{
	setCursorTerminal(0, 0);

	fflush(stdout); // для printf
	system("cls");
}
#endif

