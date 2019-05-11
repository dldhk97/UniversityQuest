//main.cpp
#include <iostream>

#include "List.h"

using namespace std;

int main()
{
	int userInput;
	List myQueue;
	while (1)
	{
		cout << "1. Queue Add\n";
		cout << "2. Queue Remove\n";
		cout << "3. Queue Print\n";
		cout << "4. Exit\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cin >> userInput;
			myQueue.add(userInput);
			break;
		case 2:
			cout << myQueue.remove()->getData() << " : removed \n";
			break;
		case 3:
			myQueue.print();
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}