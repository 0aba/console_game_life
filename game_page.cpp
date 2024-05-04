#include "./pages_utils.hpp"
#include "./game_page.hpp"


void openGamePage(i16& optionPage)
{
	optionPage = MENU_OPTION;
	clearTerminal();
	setCursorTerminal(0, 0);

	printGamePage();

	giveControlUserArena();

	clearTerminal();
	setCursorTerminal(0, 0);
}

#define OFFSET_TERMINAL_X  0
#define OFFSET_TERMINAL_Y 10

void giveControlUserArena()
{
	Coords coordsArena;
	char key;

	while (true)
	{
		key = _getch();

		switch (key)
		{
		case 'w':
			coordsArena = getCoordAfterOffset(coordsArena, { 0, -1 });
			break;
		case 's':
			coordsArena = getCoordAfterOffset(coordsArena, { 0,  1 });
			break;
		case 'a':
			coordsArena = getCoordAfterOffset(coordsArena, { -1, 0 });
			break;
		case 'd':
			coordsArena = getCoordAfterOffset(coordsArena, { 1,  0 });
			break;
		case 'L':
			__mapGame[coordsArena] = TypeCell::LivingCell;
			printFormat("%c", TypeCell::LivingCell);
			break;
		case 'D':
			__mapGame[coordsArena] = TypeCell::DeadCell;
			printFormat("%c", TypeCell::DeadCell);
			break;
		case 'W':
			__mapGame[coordsArena] = TypeCell::Wall;
			printFormat("%c", TypeCell::Wall);
			break;
		case 'K':
			__mapGame[coordsArena] = TypeCell::KillingCell;
			printFormat("%c", TypeCell::KillingCell);
			break;
		case 'S':
			__mapGame[coordsArena] = TypeCell::LifeSupportCell;
			printFormat("%c", TypeCell::LifeSupportCell);
			break;
		case 'g':
			__mapGame.clear();
			setRandomMapGame();
			updateArena();
			setCursorTerminal(coordsArena.x, coordsArena.y);
			break;
		case 'n':
			iterationOfLife();
			setCursorTerminal(coordsArena.x, coordsArena.y);
			break;
		case 'b':
			return;
        default: break;
		}

		setCursorTerminal(coordsArena.x + OFFSET_TERMINAL_X, coordsArena.y + OFFSET_TERMINAL_Y);
	}
}

void iterationOfLife()
{
	for (int i = 0; i < __amountIterations; i++)
	{
		developmentOfLife();
		sleepIteration(__timeStep);
		updateArena();
	}
}

void updateArena()
{
	for (u16 y = 0; y <= __arenaSizeY; y++)
	{
		for (u16 x = 0; x <= __arenaSizeX; x++)
		{
			setCursorTerminal( x + OFFSET_TERMINAL_X, y + OFFSET_TERMINAL_Y);

			printFormat("%c", __mapGame.find(Coords{ x, y }) != __mapGame.end()
				?
				__mapGame.at(Coords{ x, y }) : TypeCell::DeadCell);
		}

#ifdef __linux__
		refresh();
#endif
	}
}

void printGamePage()
{
	printFormat("game 'life' V %s by aba\n\n", VERSION_GAME);
	
	printFormat("~ 'w' - up, 's' - back, 'a' - left, 'd' -right. \n");
	printFormat("~ Set cell: 'L' - Living Cell, 'D' - Dead Cell, 'W' - Wall, 'K' - Killing Cell, 'S' - life support cell.\n\n");
	printFormat("~ 'g' - generate new arena.\n");
	printFormat("~ 'n' - next iteration in life.\n");
	printFormat("~ 'b' - back to menu.\n\n");

	updateArena();
	setCursorTerminal(OFFSET_TERMINAL_X, OFFSET_TERMINAL_Y);
}