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
	int lastIdCnt;										//리스트에 저장된 데이터타입의 개수
	Pair<std::string, int>* lastIdArr;					//first에 데이터타입의 이름, second에 lastId를 저장
	int findLastIdIndexByType(std::string typeName);	//이미 저장된 적이 있는 데이터타입인지 찾고 인덱스 반환

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
	int getlastIdCnt();
	Pair<std::string, int> getLastIdInfo(int index);

	//Setter
	void AddNewLastId(std::string typeName, int lastId);	//새 lastId 추가

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
	lastIdCnt = 0;
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
int List<dataType>::findLastIdIndexByType(std::string typeName)
{
	for (int i = 0; i < lastIdCnt; i++)
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
	int lastIdIndex = findLastIdIndexByType(typeName);
	if (lastIdIndex == NOT_FOUND)
	{
		lastIdArr[lastIdCnt].setFirst(typeName);
		lastIdArr[lastIdCnt].setSecond(1);
		return lastIdArr[lastIdCnt++].getSecond();
	}
	else
	{
		int newLastId = lastIdArr[lastIdIndex].getSecond() + 1;
		lastIdArr[lastIdIndex].setSecond(newLastId);
		return lastIdArr[lastIdIndex].getSecond();
	}
}
template<typename dataType>
int List<dataType>::getlastIdCnt()
{
	return lastIdCnt;
}
template<typename dataType>
Pair<std::string, int> List<dataType>::getLastIdInfo(int index)
{
	return lastIdArr[index];
}
//Setter
template<typename dataType>
void List<dataType>::AddNewLastId(std::string typeName, int lastId)
{
	lastIdArr[lastIdCnt].setFirst(typeName);
	lastIdArr[lastIdCnt++].setSecond(lastId);
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