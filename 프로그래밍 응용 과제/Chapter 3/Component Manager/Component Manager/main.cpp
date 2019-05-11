//main.cpp
#include "ComponentList.h"
#include "TaskManager.h"
#include "IOHandler.h"

using namespace std;

int main(int argc, char *argv[])
{
	ComponentList sList;
	TaskManager tskMgr;
	IOHandler ioh;

	if (!ioh.readFile(sList, argc, argv))
	{
		ioh.printMessage("파일을 읽을 수 없습니다.");
		return 0;
	}

	while (1)
	{
		int userInput = ioh.getMenu();
		if (userInput == EXIT)
		{
			ioh.saveFile(sList, argv);
			break;
		}
		switch (userInput)
		{
		case INSERT:
			tskMgr.insertComponent(sList);
			break;
		case DELETE:
			tskMgr.deleteComponent(sList);
			break;
		case PRINT:
			tskMgr.insertionSort(sList);
			tskMgr.printComponent(sList);
			break;
		}
	}
	
	return 0;
}