#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "1. ť push" << "\n";
		cout << "2. ť pop" << "\n";
		cout << "3. ť print" << "\n";
		cout << "4. EXIT" << "\n";
		cout << "�޴��� �����Ͻʽÿ� : ";
		cin >> userInput;
		if (PUSH <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
	}
	
	return NOT_FOUND;
}

int IOHandler::getInt(string message)
{
	cout << message << "\n";
	int userInput;
	cin >> userInput;
	return userInput;
}

void IOHandler::printMessage(string message)
{
	cout << message << "\n";
}