#include "./game_logic.hpp"
#include "./menu_page.hpp"
#include "./game_page.hpp"
#include "./settings_page.hpp"
#include "./rules_page.hpp"

#ifdef __linux__
#include <ncurses.h>
#endif

int main()
{
    int stateProgram = WORKING;
#ifdef __linux__
    initscr();
    echo();
    resizeterm(ABSOLUTE_MAX_ARENA_SIZE, ABSOLUTE_MAX_ARENA_SIZE);
#endif

    i16 optionPage = MENU_OPTION;

    while (stateProgram == WORKING)
    {
        switch (optionPage)
        {
            case MENU_OPTION:
                openMenuPage(optionPage);
                break;
            case GAME_OPTION:
                openGamePage(optionPage);
                break;
            case SETTINGS_OPTION:
                openSettingsPage(optionPage);
                break;
            case RULES_OPTION:
                openRulesPage(optionPage);
                break;
            case EXIT_OPTION:
                stateProgram = EXIT_SUCCESSFUL;
            default:
                stateProgram = EXIT_ERROR;
        }
    }

#ifdef __linux__
    endwin();
#endif

    return stateProgram;
}