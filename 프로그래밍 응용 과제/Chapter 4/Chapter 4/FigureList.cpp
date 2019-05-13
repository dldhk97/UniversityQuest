#include "FigureList.h"

FigureList::FigureList()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	lastId = 0;
	dataArr = new Figure*[capacity];
}
FigureList::~FigureList()
{
	if (dataArr != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if(dataArr[i] != nullptr)
				delete dataArr[i];
		}
		delete[] dataArr;
	}
}

Figure *FigureList::getFigure(int index)
{
	return dataArr[index];
}
int FigureList::getSize()
{
	return size;
}
int FigureList::getCapacity()
{
	return capacity;
}

int FigureList::getLastId()
{
	return lastId;	
}

void FigureList::setLastId(int lastId)
{
	this->lastId = lastId;
}

void FigureList::insertFigure(Figure *newFigure)
{
	if (size >= capacity)
		resize(capacity * 2);
	if(newFigure->getId() == NOT_FOUND)
		newFigure->setId(++lastId);
	dataArr[size++] = newFigure;
}
void FigureList::deleteFigure(int index)
{
	delete dataArr[index];
	dataArr[index] = dataArr[size - 1];
	dataArr[size - 1] = nullptr;
	size--;
	if (size <= capacity / 4)
		resize(capacity / 2);
}

int FigureList::findFigure(int id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getId() == id)
			return index;
	return NOT_FOUND;
}

//Utility
void FigureList::resize(int newCapacity)
{
	if (newCapacity < DEFAULT_CAPACITY)
		return;
	Figure **tempArr = new Figure*[size];
	for (int i = 0; i < size; i++)
		tempArr[i] = dataArr[i];
	delete[] dataArr;
	dataArr = new Figure *[newCapacity];
	for (int i = 0; i < size; i++)
		dataArr[i] = tempArr[i];
	delete[] tempArr;
	capacity = newCapacity;
}

void FigureList::insertionSort()
{
	int i, j;
	Figure *temp;

	for (i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && dataArr[j - 1]->getArea() > dataArr[j]->getArea())
		{
			temp = dataArr[j - 1];
			dataArr[j - 1] = dataArr[j];
			dataArr[j] = temp;
			j--;
		}
	}
}