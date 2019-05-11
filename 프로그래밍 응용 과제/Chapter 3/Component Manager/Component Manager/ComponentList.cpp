//ComponentList.cpp
#include "ComponentList.h"

//Initializer
ComponentList::ComponentList()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	componentArr = new Component[capacity];
}

ComponentList::~ComponentList()
{
	if (componentArr != NULL)
	{
		delete[] componentArr;
	}
}

//Getter
Component ComponentList::getComponent(int index)
{
	return componentArr[index];
}
int ComponentList::getSize()
{
	return size;
}
int ComponentList::getCapacity()
{
	return capacity;
}

//Control
void ComponentList::insertComponent(Component newComponent)
{
	if (size >= capacity)						//배열 크기 오버하는지 체크
	{
		resize(capacity * 2);
	}
	if (newComponent.getId() == NOT_FOUND)		//추가할 부품의 ID가 설정되지 않았다면(NOT_FOUND) 사용자가 직접추가한 것
	{
		int newId = findEmptyId();				//ID 오름차순 정렬해서 빈값 중 최저값을 찾는다.
		if (newId == NOT_FOUND)					//빈 ID가 없다면 마지막 ID를 부여
			newComponent.setId(size + 1);
		else
			newComponent.setId(newId);			//빈 ID가 있으면 그 ID를 부여
	}
	componentArr[size++] = newComponent;		//배열끝에 추가
}

void ComponentList::deleteComponent(int index)
{
	componentArr[index] = componentArr[size - 1];
	size--;
	if (size <= capacity / STANDARD_WASTE_MEMORY)		//배열 크기 낭비하는지 체크
	{
		resize(capacity / 2);
	}
}
int ComponentList::findComponent(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (componentArr[i].getId() == id)
		{
			return i;
		}
	}
	return NOT_FOUND;
}
int ComponentList::findComponent(string serialNumber)
{
	for (int i = 0; i < size; i++)
	{
		if (componentArr[i].getSerialNumber() == serialNumber)
		{
			return i;
		}
	}
	return NOT_FOUND;
}

int ComponentList::findEmptyId()					//ID중 빈값을 찾음
{
	int *idList = new int[size];
	int j, temp, result = NOT_FOUND;

	for (int i = 0; i < size; i++)					//ID만 오름차순으로 정렬
	{
		idList[i] = componentArr[i].getId();
		j = i;
		while (j > 0 && idList[j - 1] > idList[j])
		{
			temp = idList[j - 1];
			idList[j - 1] = idList[j];
			idList[j] = temp;
			j--;
		}
	}
	for (int i = 0; i < size; i++)					//ID중에 빈값이 있는지 검사
	{
		if (i+1 < idList[i])
		{
			result = i + 1;
			break;
		}
	}

	delete[] idList;
	return result;
}

//Utility
void ComponentList::resize(int newCapacity)
{
	if (newCapacity < DEFAULT_CAPACITY)
	{
		return;
	}
	Component *tempArr = new Component[size];
	for (int i = 0; i < size; i++)
	{
		tempArr[i] = componentArr[i];
	}
	delete[] componentArr;

	componentArr = new Component[newCapacity];
	for (int i = 0; i < size; i++)
	{
		componentArr[i] = tempArr[i];
	}

	delete[] tempArr;
	capacity = newCapacity;
}


void ComponentList::insertionSort()
{
	int i, j;
	Component temp;

	for (i = 0; i < size; i++)
	{
		j = i;
		
		while (j > 0 && componentArr[j-1].getSerialNumber() > componentArr[j].getSerialNumber())
		{
			temp = componentArr[j - 1];
			componentArr[j - 1] = componentArr[j];
			componentArr[j] = temp;
			j--;
		}
	}

}