#include "TaskManager.h"

const std::string FILE_LOCATION = "C:\\shape.dat";

int main()
{
	TaskManager tskMgr;
	IOHandler ioh;
	FigureList fgrList;
	int userInput;
	bool isChanged = false;

	if (!ioh.loadFile(fgrList, FILE_LOCATION))
		return 0;

	while (1)
	{
		userInput = ioh.getMenu();
		if (userInput == EXIT)
			break;

		switch (userInput)
		{
		case INSERT:
			if (tskMgr.insertFigure(fgrList))
				isChanged = true;
			break;
		case DELETE:
			if (tskMgr.deleteFigure(fgrList))
				isChanged = true;
			break;
		case PRINT:
			tskMgr.insertionSort(fgrList);
			tskMgr.printFigureList(fgrList);
			break;
		}
	}
	if (isChanged)
	{
		tskMgr.insertionSort(fgrList);
		ioh.saveFile(fgrList, FILE_LOCATION);
	}
	return 0;
}