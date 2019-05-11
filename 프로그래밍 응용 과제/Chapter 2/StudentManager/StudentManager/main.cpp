//main.cpp
#include "StudentList.h"
#include "TaskManager.h"
#include "IOHandler.h"

using namespace std;

int main()
{
	StudentList sList;
	TaskManager tskMgr;
	IOHandler ioh;

	while (1)
	{
		int userInput = ioh.getMenu();
		if (userInput == EXIT)
			break;
		switch (userInput)
		{
		case INSERT:
			tskMgr.insertStudent(sList);
			break;
		case DELETE:
			tskMgr.deleteStudent(sList);
			break;
		case PRINT:
			tskMgr.insertionSort(sList);
			tskMgr.printStudent(sList);
			break;
		}
	}
	return 0;
}