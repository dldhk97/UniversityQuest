//IOHandler.h
#pragma once

#include "ComponentList.h"
#include <iostream>
#include <fstream>

enum Menu { INSERT = 1, DELETE, PRINT, EXIT };

class IOHandler
{
public:
	int getMenu();
	Component getComponent();
	void printComponent(Component iComponent);
	void printMessage(string Message);

	int getInt(string message);
	string getString(string message);

	bool readFile(ComponentList &iList, int argc, char *argv[]);
	void saveFile(ComponentList &iList, char *argv[]);
};

