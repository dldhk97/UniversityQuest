#include <iostream>
#include "TaskManager.h"
#include "IOHanlder.h"
#include "Tree.h"


using namespace std;

int main()
{
	IOHanlder ioh;
	TaskManager tskMgr;
	Tree<Element> newTree;

	int userInput;
	while (1)
	{
		userInput = ioh.getMenu();
		if (userInput == EXIT)
		{
			ioh.printMessage("종료합니다.");
			break;
		}
		switch (userInput)
		{
		case INSERT:
			tskMgr.insertNode(newTree);
			break;
		case DELETE:
			tskMgr.deleteNode(newTree);
			break;
		case PRINT:
			tskMgr.printNode(newTree);
			break;
		}
	}

	return 0;
}