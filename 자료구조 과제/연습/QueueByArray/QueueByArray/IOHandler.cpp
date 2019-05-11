#include "IOHandler.h"

int IOHandler::getMenu()
{
	int userInput;
	while (true)
	{
		cout << "1. 큐 push" << "\n";
		cout << "2. 큐 pop" << "\n";
		cout << "3. 큐 print" << "\n";
		cout << "4. EXIT" << "\n";
		cout << "메뉴를 선택하십시오 : ";
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