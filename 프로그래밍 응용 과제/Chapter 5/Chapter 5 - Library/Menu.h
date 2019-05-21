#pragma once

#include "IOHandler.h"

class Menu
{
	std::string getMenuTitle(int menuType);
	std::string getOption1(int menuType);
	std::string getOption2(int menuType);
	std::string getOption3(int menuType);
	std::string getOption4(int menuType);
public:
	int getMenu(int menuType);
};

