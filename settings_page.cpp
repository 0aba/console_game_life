#include "./pages_utils.hpp"
#include "./settings_page.hpp"


#define ARENA_FORM                0
#define TIME_ITERATIONS_FORM      1
#define PERCENTA_GESGENERATE_FORM 2
#define DEFAULT_FORM              3
#define BACK_TO_MENU              4

void openSettingsPage(i16& optionPage)
{
	optionPage = MENU_OPTION;

	char key;
	u16 formOption = ARENA_FORM;

	while (true)
	{
		printSettingsPage(formOption);
		
		key = _getch();

		if (key == 'w')
		{
			formOption = formOption == 0 ? 4 : formOption - 1;
		}
		else if (key == 's')
		{
			formOption = formOption == 4 ? 0 : formOption + 1;
		}
		else if (key == 'o')
		{
			clearTerminal();
			setCursorTerminal(0, 0);

			if (formOption == ARENA_FORM)
			{
				openChangeArenaForm();
			}
			else if (formOption == TIME_ITERATIONS_FORM)
			{
				openChangeTimeStepAndIterationsForm();
			}
			else if (formOption == PERCENTA_GESGENERATE_FORM)
			{
				openChangePercentagesGenerateForm();
			}
			else if (formOption == DEFAULT_FORM)
			{
				openSetDefaultSettingsForm();
			}
			else if (formOption == BACK_TO_MENU)
			{
				break;
			}
		}

		clearTerminal();
		setCursorTerminal(0, 0);
	}

	clearTerminal();
	setCursorTerminal(0, 0);
}

void printSettingsPage(u16 option)
{
	printFormat("settings 'life' V %s by aba\n\n", VERSION_GAME);

	printFormat("'w' - up, 's' - down, 'o' - ok.\n");
	printFormat("Settings menu:\n");
	printFormat("\t1)Change arena size.                                  %s\n", option == 0 ? "+" : "");
	printFormat("\t2)Time step of development  and number of iterations. %s\n", option == 1 ? "+" : "");
	printFormat("\t3)Change the percentages to generate the field.       %s\n", option == 2 ? "+" : "");
	printFormat("\t4)Back to default settings.                           %s\n", option == 3 ? "+" : "");
	printFormat("\t5)Back to back to menu.                               %s\n\n", option == 4 ? "+" : "");
}

void openChangeArenaForm()
{
	u16 x = __arenaSizeX;
	u16 y = __arenaSizeY;

	printFormat("enter new arena dimensions: '[x] on [y]'\n");
	printFormat("maximum size side %hu on %hu\n", MAX_SIDE_SIZE, MAX_SIDE_SIZE);
	printFormat("input >> ");

	scanFormat("%hu on %hu%*c", &x, &y);

	if (x > MAX_SIDE_SIZE)
	{
		printFormat("error: x > %hu\n", MAX_SIDE_SIZE);
		printFormat("value not change...\n");
		printFormat("Enter for continue....\n\n");
		_getch();
	}
	else
	{
		__arenaSizeX = x;
	}

	if (y > MAX_SIDE_SIZE)
	{
		printFormat("error: y > %hu\n", MAX_SIDE_SIZE);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__arenaSizeY = y;
	}
}

void openChangeTimeStepAndIterationsForm()
{
	u16 time      = __timeStep;
	u16 iteration = __amountIterations;

	printFormat("enter the time interval and number of passages per run: '[interval] and [iterations]' in milliseconds\n");
	printFormat("min-max interval %hu-%hu milliseconds\n", MIN_VALUE_TIME_STEP, MAX_VALUE_TIME_STEP);
	printFormat("min-max iterartions %hu-%hu\n", MIN_VALUE_ITERATIONS, MAX_VALUE_ITERATIONS);
	printFormat("input >> ");

	scanFormat("%hu and %hu%*c", &time, &iteration);

	if (time < MIN_VALUE_TIME_STEP || time > MAX_VALUE_TIME_STEP)
	{
		printFormat("error: time step < %hu or time step > %hu\n", MIN_VALUE_ITERATIONS, MAX_VALUE_TIME_STEP);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__timeStep = time;
	}

	if (iteration < MIN_VALUE_ITERATIONS || iteration > MAX_VALUE_ITERATIONS)
	{
		printFormat("error: iteration < %hu or iteration > %hu\n", MIN_VALUE_ITERATIONS, MAX_VALUE_ITERATIONS);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();  
	}
	else
	{
		__amountIterations = iteration;
	}
}

void openChangePercentagesGenerateForm()
{
	u16 livingPercent  = __LivingPercent;
	u16 wallPercent    = __WallPercent;
	u16 killingPercent = __KillingPercent;
	u16 supportPercent = __SupportPercent;

	printFormat("Add percentages in order: '[living cell],[wall],[killing cell],[support cell]'\n");
	printFormat("min-max percentages for living cell %hu-%hu\n", MIN_VALUE_LIVING, MAX_VALUE_LIVING);
	printFormat("min-max percentages for other cell %hu-%hu\n", MIN_VALUE_SPECIAL_CELL, MAX_VALUE_SPECIAL_CELL);
	printFormat("input >> ");

	scanFormat("%hu,%hu,%hu,%hu%*c", &livingPercent, &wallPercent, &killingPercent, &supportPercent);

	if (livingPercent < MIN_VALUE_LIVING || livingPercent > MAX_VALUE_LIVING)
	{
		printFormat("error: living percent < %hu or living percent > %hu\n", MIN_VALUE_LIVING, MAX_VALUE_LIVING);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__LivingPercent = livingPercent;
	}

	if (wallPercent < MIN_VALUE_SPECIAL_CELL || wallPercent > MAX_VALUE_SPECIAL_CELL)
	{
		printFormat("error: wall percent < %hu or wall percent > %hu\n", MIN_VALUE_SPECIAL_CELL, MAX_VALUE_SPECIAL_CELL);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__WallPercent = wallPercent;
	}

	if (killingPercent < MIN_VALUE_SPECIAL_CELL || killingPercent > MAX_VALUE_SPECIAL_CELL)
	{
		printFormat("error: killing percent < %hu or killing percent > %hu\n", MIN_VALUE_SPECIAL_CELL, MAX_VALUE_SPECIAL_CELL);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__KillingPercent = killingPercent;
	}

	if (supportPercent < MIN_VALUE_SPECIAL_CELL || supportPercent > MAX_VALUE_SPECIAL_CELL)
	{
		printFormat("error: support percent < %hu or support percent > %hu\n", MIN_VALUE_SPECIAL_CELL, MAX_VALUE_SPECIAL_CELL);
		printFormat("value not change...\n");
		printFormat("Enter for continue...\n\n");
		_getch();
	}
	else
	{
		__SupportPercent = supportPercent;
	}
}

void openSetDefaultSettingsForm()
{
	printFormat("are you sure? 'y'  or 'other key for not'\n");

	if (_getch() == 'y')
	{
		__arenaSizeX       = DEFAULT_SIDE_SIZE;
		__arenaSizeY       = DEFAULT_SIDE_SIZE;
		__timeStep         = DEFAULT_TIME_STEP;
		__amountIterations = DEFAULT_ITERATIONS;
		__LivingPercent    = DEFAULT_LIVING;
		__WallPercent      = DEFAULT_SPECIAL_CELL;
		__KillingPercent   = DEFAULT_SPECIAL_CELL;
		__SupportPercent   = DEFAULT_SPECIAL_CELL;
	}
}
