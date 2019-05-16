//TaskManager.cpp
#include "TaskManager.h"

bool TaskManager::insertFigure(FigureList &figureList)
{
	IOHandler ioh;
	
	int figureType = ioh.getFigureType();

	if (figureType == CIRCLE)
	{
		Circle* newCircle;
		newCircle = ioh.getCircle();
		figureList.insertFigure(newCircle);
	}
	else if (figureType == TRIANGLE)
	{
		Triangle* newTriangle;
		newTriangle = ioh.getTriangle();
		figureList.insertFigure(newTriangle);
	}
	else if (figureType == SQUARE)
	{
		Square* newSquare;
		newSquare = ioh.getSquare();
		figureList.insertFigure(newSquare);
	}
	return true;
}
bool TaskManager::deleteFigure(FigureList &figureList)
{
	IOHandler ioh;
	if (figureList.getSize() <= 0)
	{
		ioh.printMessage("���� ����� ����ֽ��ϴ�.");
		return false;
	}
	int id = ioh.getInt("������ ������ ID �Է� :");
	int index = figureList.findFigure(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("������ ã�� �� �����ϴ�.");
		return false;
	}
	figureList.deleteFigure(index);
	ioh.printMessage("�����Ǿ����ϴ�.");
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