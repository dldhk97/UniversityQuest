#include "IOHandler.h"
#include "Queue.h"

using namespace std;

int main()
{
	Queue<int> newQueue;
	IOHandler ioh;
	int userInput;
	while (true)
	{
		userInput = ioh.getMenu();
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case PUSH:
			userInput = ioh.getInt("Type data : ");
			newQueue.push(userInput);
			break;
		case POP:
			userInput = newQueue.pop();
			ioh.printMessage(to_string(userInput));
			break;
		case PRINT:
			newQueue.print();
			break;
		}
	}

	return 0;
}