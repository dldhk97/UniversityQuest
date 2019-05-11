//20분컷

#include <iostream>
#include "Stack.h"
#include "Queue.h"

using namespace std;

int main()
{
	Stack newStack(10);
	Queue newQueue(10);

	int userInput;
	while (1)
	{
		cout << "1.스택 push\n";
		cout << "2.스택 pop\n";
		cout << "3.스택 print\n";
		cout << "4.큐  add\n";
		cout << "5.큐  remove\n";
		cout << "6.큐  print\n";
		cout << "7.EXIT\n";

		cin >> userInput;
		switch (userInput)
		{
		case 1:
			cin >> userInput;
			newStack.push(userInput);
			break;
		case 2:
			newStack.pop();
			break;
		case 3:
			newStack.print();
			break;
		case 4:
			cin >> userInput;
			newQueue.add(userInput);
			break;
		case 5:
			newQueue.remove();
			break;
		case 6:
			newQueue.print();
			break;
		case 7:
			return 0;
		}
	}

	return 0;
}