#include "TaskManager.h"

const std::string FILE_LOCATION = "C:\\Users\\Administrator\\source\repos\\dldhk97\\UniversityQuest\\프로그래밍 응용 과제\\Chapter 4\\shape.dat";

int main()
{
	TaskManager tskMgr;
	IOHandler ioh;
	FigureList fgrList;

	int userInput;
	while (1)
	{
		userInput = ioh.getMenu();
		if (userInput == EXIT)
			break;

		switch (userInput)
		{
		case INSERT:
			tskMgr.insertFigure(fgrList);
			break;
		case DELETE:
			tskMgr.deleteFigure(fgrList);
			break;
		case PRINT:
			tskMgr.insertionSort(fgrList);
			tskMgr.printFigureList(fgrList);
			break;
		}
	}

	return 0;
}