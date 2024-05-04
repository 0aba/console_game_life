#ifndef SETTINGS_PAGE_HPP
#define SETTINGS_PAGE_HPP

#include "./my_types.hpp"


void openSettingsPage(i16& optionPage);
void printSettingsPage(u16 option);

void openChangeArenaForm();
void openChangeTimeStepAndIterationsForm();
void openChangePercentagesGenerateForm();
void openSetDefaultSettingsForm();

#endif