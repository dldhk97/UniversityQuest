#pragma once

#include <iostream>
#include "Figure.h"
#include "Circle.h"
#include "Triangle.h"
#include "Square.h"

enum FigureType { CIRCLE = 11, TRIANGLE, SQUARE };

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
	
	int getFigureType(Figure* figure);
	bool compare(Figure* a, Figure* b);
	void insertionSort();
};

