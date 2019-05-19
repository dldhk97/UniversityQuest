#pragma once

#include "Pair.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;
const int DATATYPE_CAPACITY = 2;

template <typename dataType>
class List
{
private:
	dataType** dataArr;
	int size;
	int capacity;
	bool isChanged;

	//LastId
	int dataTypeCnt;
	Pair<std::string, int> *lastIdArr;
	int getDataTypeIndex(std::string typeName);

	//Memory
	void resize(int newCapacity);
public:
	//Initializer
	List();
	~List();
	
	//Control
	void insertData(dataType* data);
	void deleteData(int index);

	//Getter
	dataType* getData(int index);
	int getSize();
	int getLastId(std::string typeName);

	//Utlity
	int findData(std::string id);
	void insertionSort();
};
//Initializer
template<typename dataType> 
List<dataType>::List()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	isChanged = false;
	dataArr = new dataType* [capacity];
	lastIdArr = new Pair<std::string, int>[DATATYPE_CAPACITY];
	dataTypeCnt = 0;
}
template<typename dataType> 
List<dataType>::~List()
{
	if (dataArr != nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			if (dataArr[i] != nullptr)
				delete dataArr[i];
		}
		delete[] dataArr;
	}
}
//Memory
template<typename dataType>
void List<dataType>::resize(int newCapacity)
{
	if (newCapacity < DEFAULT_CAPACITY)
		return;
	dataType** tempArr = new dataType* [size];
	for (int i = 0; i < size; i++)
		tempArr[i] = dataArr[i];
	delete[] dataArr;
	dataArr = new dataType* [newCapacity];
	for (int i = 0; i < size; i++)
		dataArr[i] = tempArr[i];
	delete[] tempArr;
	capacity = newCapacity;
}
//LastID
template<typename dataType>
int List<dataType>::getDataTypeIndex(std::string typeName)
{
	for (int i = 0; i < dataTypeCnt; i++)
	{
		if (lastIdArr[i].getFirst() == typeName)
			return i;
	}
	return NOT_FOUND;
}
//Control
template<typename dataType>
void List<dataType>::insertData(dataType* data)
{
	if (size >= capacity)
		resize(capacity * 2);
	dataArr[size++] = data;
}
template<typename dataType>
void List<dataType>::deleteData(int index)
{
	delete dataArr[index];
	dataArr[index] = dataArr[size - 1];
	dataArr[size - 1] = nullptr;
	size--;
	if (size <= capacity / 4)
		resize(capacity / 2);
}
//Getter
template<typename dataType> 
dataType* List<dataType>::getData(int index)
{
	return dataArr[index];
}
template<typename dataType> 
int List<dataType>::getSize()
{
	return size;
}
template<typename dataType>
int List<dataType>::getLastId(std::string typeName)
{
	int dataTypeIndex = getDataTypeIndex(typeName);
	if (dataTypeIndex == NOT_FOUND)
	{
		lastIdArr[dataTypeCnt].setFirst(typeName);
		lastIdArr[dataTypeCnt].setSecond(1);
		return lastIdArr[dataTypeCnt++].getSecond();
	}
	else
	{
		lastIdArr[dataTypeIndex].setSecond(lastIdArr[dataTypeIndex].getSecond() + 1);
		return lastIdArr[dataTypeIndex].getSecond();
	}
}
//Utility
template<typename dataType> 
int List<dataType>::findData(std::string id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getId() == id)
			return index;
	return NOT_FOUND;
}
template<typename dataType> 
void List<dataType>::insertionSort()
{
	int i, j;
	dataType* temp;

	for (i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && dataArr[j - 1]->getId() > dataArr[j]->getId())
		{
			temp = dataArr[j - 1];
			dataArr[j - 1] = dataArr[j];
			dataArr[j] = temp;
			j--;
		}
	}
}
