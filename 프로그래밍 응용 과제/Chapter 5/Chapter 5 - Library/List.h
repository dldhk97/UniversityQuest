#pragma once

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;

template <typename dataType>
class List
{
private:
	dataType** dataArr;
	int size;
	int capacity;
	int lastId;					//lastID가 두개 필요한가??? debug!!!!!!!!!!!
	bool isChanged;

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

	//increaseAndGetLastId
	int increaseAndGetLastId();

	//Utlity
	int findData(std::string id);
	void insertionSort();
};
//Initializer
template<typename dataType> List<dataType>::List()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	lastId = 0;
	isChanged = false;
	dataArr = new dataType* [capacity];
}
template<typename dataType> List<dataType>::~List()
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
template<typename dataType> void List<dataType>::resize(int newCapacity)
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
//Control
template<typename dataType> void List<dataType>::insertData(dataType* data)
{
	if (size >= capacity)
		resize(capacity * 2);	
	dataArr[size++] = data;
}
template<typename dataType> void List<dataType>::deleteData(int index)
{
	delete dataArr[index];
	dataArr[index] = dataArr[size - 1];
	dataArr[size - 1] = nullptr;
	size--;
	if (size <= capacity / 4)
		resize(capacity / 2);
}
//Getter
template<typename dataType> dataType* List<dataType>::getData(int index)
{
	return dataArr[index];
}
template<typename dataType> int List<dataType>::getSize()
{
	return size;
}
//Setter
//lastId를 증가시키고 반환합니다.
template<typename dataType> int List<dataType>::increaseAndGetLastId()
{
	return ++lastId;
}
//Utility
template<typename dataType> int List<dataType>::findData(std::string id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getId() == id)
			return index;
	return NOT_FOUND;
}
template<typename dataType> void List<dataType>::insertionSort()
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
