//TaskManager.h
#pragma once

#include "IOHandler.h"

class TaskManager
{
public:
	bool insertFigure(FigureList &figureList);
	bool deleteFigure(FigureList &figureList);
	void printFigureList(FigureList &figureList);
	void insertionSort(FigureList &figureList);
};

