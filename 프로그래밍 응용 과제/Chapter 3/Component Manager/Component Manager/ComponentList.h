//ComponentList.h
#pragma once
#include "Component.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;
const int STANDARD_WASTE_MEMORY = 3;			//�ִ�뷮�� �����뷮���� n�� ����Ǵ� ��� resize�ϴ� ����

class ComponentList
{
private:
	Component *componentArr;
	int size;				//����ũ��
	int capacity;			//�ִ�뷮

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

