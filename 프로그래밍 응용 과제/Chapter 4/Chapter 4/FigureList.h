#pragma once

#include "Figure.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;

class FigureList
{
private:
	Figure **dataArr;
	int size;
	int capacity;
	int lastId;

	void resize(int newCapacity);
public:
	FigureList();
	~FigureList();

	Figure *getFigure(int index);
	int getSize();
	int getCapacity();
	int getLastId();

	void setLastId(int lastId);

	void insertFigure(Figure *newFigure);
	void deleteFigure(int index);

	int findFigure(int id);
	
	void insertionSort();
};

