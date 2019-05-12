#include "TaskManager.h"

void TaskManager::insertFigure(FigureList &figureList)
{
	IOHandler ioh;
	
	int figureType = ioh.getFigureType();

	if (figureType == CIRCLE)
	{
		Circle *newCircle;
		newCircle = ioh.getCircle();
		figureList.insertFigure(newCircle);
	}
	else if (figureType == TRIANGLE)
	{
		Triangle *newTriangle;
		newTriangle = ioh.getTriangle();
		figureList.insertFigure(newTriangle);
	}
	else if (figureType == SQUARE)
	{
		Square *newSquare;
		newSquare = ioh.getSquare();
		figureList.insertFigure(newSquare);
	}
}
void TaskManager::deleteFigure(FigureList &figureList)
{
	IOHandler ioh;
	if (figureList.getSize() <= 0)
	{
		ioh.printMessage("���� ����� ����ֽ��ϴ�.");
		return;
	}
	int id = ioh.getInt("������ ������ ID �Է� :");
	int index = figureList.findFigure(id);
	if (index == NOT_FOUND)
	{
		ioh.printMessage("������ ã�� �� �����ϴ�.");
		return;
	}
	figureList.deleteFigure(index);
	ioh.printMessage("�����Ǿ����ϴ�.");
}
void TaskManager::printFigureList(FigureList &figureList)
{
	IOHandler ioh;
	int size = figureList.getSize();
	for (int i = 0; i < size; i++)
	{
		if (typeid(*figureList.getFigure(i)).name() == typeid(Circle).name())
		{
			ioh.printFigure(figureList.getFigure(i));
			ioh.printMessage("");
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (typeid(*figureList.getFigure(i)).name() == typeid(Triangle).name())
		{
			ioh.printFigure(figureList.getFigure(i));
			ioh.printMessage("");
		}
	}
	for (int i = 0; i < size; i++)
	{
		if (typeid(*figureList.getFigure(i)).name() == typeid(Square).name())
		{
			ioh.printFigure(figureList.getFigure(i));
			ioh.printMessage("");
		}
	}
}
void TaskManager::insertionSort(FigureList &figureList)
{
	figureList.insertionSort();
}