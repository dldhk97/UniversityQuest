#include <iostream>

#include "List.h"

using namespace std;

int main()
{
	int userInput;
	List myList;
	while (1)
	{
		cout << "1. 스택 push\n";
		cout << "2. 스택 pop\n";
		cout << "3. 스택 print\n";
		cout << "4. EXIT\n";
		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cin >> userInput;
			myList.push(userInput);
			break;
		case 2:
			cout << myList.pop()->getData() << ": poped\n";
			break;
		case 3:
			myList.print();
			break;
		case 4:
			return 0;
		}
	}
	return 0;
}