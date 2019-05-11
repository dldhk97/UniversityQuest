#pragma once

#include "IOHandler.h"

class TaskManager
{
public:
	void insertFigure(FigureList &figureList);
	void deleteFigure(FigureList &figureList);
	void printFigureList(FigureList &figureList);
	void insertionSort(FigureList &figureList);
};

