//TaskManager.cpp
#include "TaskManager.h"

bool TaskManager::insertFigure(FigureList &figureList)
{
	IOHandler ioh;

	switch (ioh.getFigureType())
	{
		case CIRCLE:
		{
			Circle* newCircle;
			newCircle = ioh.getCircle();
			figureList.insertFigure(newCircle);
			return true;
		}
		case TRIANGLE:
		{
			Triangle* newTriangle;
			newTriangle = ioh.getTriangle();
			figureList.insertFigure(newTriangle);
			return true;
		}
		case SQUARE:
		{
			Square* newSquare;
			newSquare = ioh.getSquare();
			figureList.insertFigure(newSquare);
			return true;
		}
		default:
		{
			ioh.printMessage("도형 생성에 실패하였습니다.");
			return false;
		}
	}
}
bool TaskManager::deleteFigure(FigureList &figureList)
{
	IOHandler ioh;
	if (figureList.getSize() <= 0)
	{
		ioh.printMessage("도형 목록이 비어있습니다.");
		return false;
	}
	int id = ioh.getInt("삭제할 도형의 ID 입력 :");
	int index = figureList.findFigure(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("도형을 찾을 수 없습니다.");
		return false;
	}
	figureList.deleteFigure(index);
	ioh.printMessage("삭제되었습니다.");
	return true;
}
void TaskManager::printFigureList(FigureList &figureList)
{
	IOHandler ioh;
	int size = figureList.getSize();
	for (int i = 0; i < size; i++)
	{
			ioh.printFigure(figureList.getFigure(i));
			ioh.printMessage("");
	}
}
void TaskManager::insertionSort(FigureList &figureList)
{
	figureList.insertionSort();
}