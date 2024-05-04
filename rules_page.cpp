#include "./pages_utils.hpp"
#include "./rules_page.hpp"


void openRulesPage(i16& optionPage)
{
	optionPage = MENU_OPTION;
	printRulesPage();
	_getch();

	clearTerminal();
	setCursorTerminal(0, 0);
}

void printRulesPage()
{
	printFormat("rules 'life' V %s by aba\n\n", VERSION_GAME);

	printFormat("Type cell:\n");
	printFormat("\t'#' - living cell.\n");
	printFormat("\t'_' - dead cell.\n");
	printFormat("\t'W' - wall, occupies a cell and does not interact with other cells.\n");
	printFormat("\t'K' - Killing cell, kills neighbors if they are alive. Has a higher priority than the life support cell.\n");
	printFormat("\t'S' - Life support cell, supports the life of cells, even if condition (rule 1) is not met.\n\n");

	printFormat("Rules:\n");
	printFormat("\t~ If a dead cell is surrounded by exactly 3 living ones, then it becomes alive.\n");
	printFormat("\t~ If a living cell is surrounded by 2 or 3 living ones, then it remains alive, otherwise it is either from loneliness or from overcrowding.\n\n");

	printFormat("Enter for back to menu...");
}
