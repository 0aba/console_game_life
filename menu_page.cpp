#include "./pages_utils.hpp"
#include "./menu_page.hpp"


void openMenuPage(i16& optionPage)
{
	u16 optionMenu = 1;
	char key;

	while (true)
	{
		clearTerminal();
		setCursorTerminal(0, 0);

		printMenuPage(optionMenu);
		key = _getch();

		if (key == 'w')
		{
			optionMenu = optionMenu == 1 ? 4 : optionMenu - 1;
		}
		else if (key == 's')
		{
			optionMenu = optionMenu == 4 ? 1 : optionMenu + 1;
		}
		else if (key == 'o')
		{
			optionPage = optionMenu;
			break;
		}
	}

	clearTerminal();
	setCursorTerminal(0, 0);
}

void printMenuPage(u16 option)
{
	printFormat("game 'life' V %s by aba\n\n", VERSION_GAME);

	printFormat("'w' - up, 's' - down, 'o' - ok.\n");
	printFormat("Game menu:\n");
	printFormat("\t1) play     %s\n", option == 1 ? "+" : "");
	printFormat("\t2) settings %s\n", option == 2 ? "+" : "");
	printFormat("\t3) rules    %s\n", option == 3 ? "+" : "");
	printFormat("\t4) exit     %s\n\n", option == 4 ? "+" : "");
}
