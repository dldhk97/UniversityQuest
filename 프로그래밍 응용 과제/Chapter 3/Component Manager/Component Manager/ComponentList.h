//ComponentList.h
#pragma once
#include "Component.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;
const int STANDARD_WASTE_MEMORY = 3;			//최대용량이 실제용량보다 n배 낭비되는 경우 resize하는 기준

class ComponentList
{
private:
	Component *componentArr;
	int size;				//실제크기
	int capacity;			//최대용량

	void resize(int newCapacity);
public:
	//Initializer
	ComponentList();
	~ComponentList();

	//Getter
	Component getComponent(int index);
	int getSize();
	int getCapacity();

	//Control
	void insertComponent(Component newComponent);
	void deleteComponent(int index);
	int findComponent(int id);
	int findComponent(string serialNumber);
	int findEmptyId();

	//Utility
	void insertionSort();
};

