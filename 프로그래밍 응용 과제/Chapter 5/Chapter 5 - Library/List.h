#pragma once

#include "Pair.h"
#include "Book.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;
const int DEFAULT_DATATYPE_CAPACITY = 2;			//이 리스트가 서로 다른 데이터타입을 몇개까지 가질 수 있는지

template <typename dataType>
class List
{
private:
	dataType** dataArr;
	int size;
	int capacity;
	bool isChanged;

	//LastId
	int dataTypeSize;								//리스트에 저장된 데이터타입의 개수
	Pair<std::string, int> *lastIdArr;				//first에 데이터타입의 이름, second에 lastId를 저장
	int findDataTypeIndex(std::string typeName);	//이미 저장된 적이 있는 데이터타입인지 찾고 인덱스 반환

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
	int getLastId(std::string typeName);			//이미 저장된 적이 있는 데이터타입이면, lastID + 1을 반환

	//Utlity
	int findDataById(std::string id);
	int findDataByLoanerId(std::string id);
	void insertionSort();
	void insertionSort(List<dataType>& bookList);
};
//Initializer
template<typename dataType> 
List<dataType>::List()
{
	capacity = DEFAULT_CAPACITY;
	size = 0;
	isChanged = false;
	dataArr = new dataType* [capacity];
	lastIdArr = new Pair<std::string, int>[DEFAULT_DATATYPE_CAPACITY];
	dataTypeSize = 0;
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
//이미 저장된 적이 있는 데이터타입인지 찾고 인덱스 반환
template<typename dataType>
int List<dataType>::findDataTypeIndex(std::string typeName)
{
	for (int i = 0; i < dataTypeSize; i++)
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
//이미 저장된 적이 있는 데이터타입이면, lastID + 1을 갱신 후 반환
template<typename dataType>
int List<dataType>::getLastId(std::string typeName)
{
	int dataTypeIndex = findDataTypeIndex(typeName);
	if (dataTypeIndex == NOT_FOUND)
	{
		lastIdArr[dataTypeSize].setFirst(typeName);
		lastIdArr[dataTypeSize].setSecond(1);
		return lastIdArr[dataTypeSize++].getSecond();
	}
	else
	{
		int newLastId = lastIdArr[dataTypeIndex].getSecond() + 1;
		lastIdArr[dataTypeIndex].setSecond(newLastId);
		return lastIdArr[dataTypeIndex].getSecond();
	}
}
//Utility
template<typename dataType> 
int List<dataType>::findDataById(std::string id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getId() == id)
			return index;
	return NOT_FOUND;
}
//LoanInfo만을 위한 메소드 : 대출자의 id로 도서를 찾아 반환
template<typename dataType>
int List<dataType>::findDataByLoanerId(std::string id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getLoanerId() == id)
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
		while (j > 0 && dataArr[j-1]->compare(dataArr[j]))
		{
			temp = dataArr[j - 1];
			dataArr[j - 1] = dataArr[j];
			dataArr[j] = temp;
			j--;
		}
	}
}
template<typename dataType>
void List<dataType>::insertionSort(List<dataType>& bookList)
{
	int i, j;
	dataType* temp;

	for (i = 1; i < size; i++)
	{
		j = i;
		
		Book currentBook = bookList.getData(bookList.findDataById(dataArr[j]->getId()));
		Book targetBook = bookList.getData(bookList.findDataById(dataArr[j - 1]->getId()));
		while (j > 0 && dataArr[j - 1]->compare(currentBook, targetBook, dataArr[j]))
		{
			temp = dataArr[j - 1];
			dataArr[j - 1] = dataArr[j];
			dataArr[j] = temp;
			j--;
		}
	}
}