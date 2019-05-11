#pragma once
#include <iostream>
#include <string>

using namespace std;

enum {PUSH = 1, POP, PRINT, EXIT};
const int NOT_FOUND = -1;

class IOHandler
{
public:
	int getMenu();
	int getInt(string message);

	void printMessage(string message);
};

