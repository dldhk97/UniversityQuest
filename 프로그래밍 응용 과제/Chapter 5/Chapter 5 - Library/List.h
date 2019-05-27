//List.h
#pragma once
#include "Pair.h"
#include "Book.h"

const int DEFAULT_CAPACITY = 10;
const int NOT_FOUND = -1;
const int DEFAULT_DATATYPE_CAPACITY = 2;				//�� ����Ʈ�� ���� �ٸ� ������ Ÿ���� �ִ� ����� ���� �� �ִ���

template <typename dataType>
class List
{
private:
	dataType** dataArr;
	int size;
	int capacity;
	bool isChanged;

	//LastId
	int lastIdCnt;											//����Ʈ�� ����� ������Ÿ���� ����
	Pair<std::string, int>* lastIdArr;						//first�� ������Ÿ���� �̸�, second�� lastId�� ����
	int findLastIdIndexByType(std::string typeName);		//�̹� ����� ���� �ִ� ������Ÿ������ ã�� �ε��� ��ȯ

	//Memory
	void resize(int newCapacity);
public:
	//Initializer
	List();
	~List();
	
	//Control
	void insertData(dataType* data);

	//Getter
	dataType* getData(int index);
	int getSize();
	
	//LastID
	int getLastId(std::string typeName);					//�̹� ����� ���� �ִ� ������Ÿ���̸�, lastID + 1�� ��ȯ
	int getlastIdCnt();
	Pair<std::string, int> getLastIdInfo(int index);
	void AddNewLastId(std::string typeName, int lastId);	//�� lastId �߰�

	//Utlity
	dataType* findDataById(std::string id);
	void insertionSort();
	void insertionSort(List<Book>& bookList);				//���������� LoanInfoŸ�Ը� ���
	bool isEmpty();
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
			if (dataArr[i] != nullptr)
				delete dataArr[i];
		delete[] dataArr;
	}
	if (lastIdArr != nullptr)
		delete[] lastIdArr;
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
//�̹� ����� ���� �ִ� ������Ÿ������ ã�� �ε��� ��ȯ
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
//LastID
//�̹� ����� ���� �ִ� ������Ÿ���̸�, lastID + 1�� ���� �� ��ȯ
template<typename dataType>
int List<dataType>::getLastId(std::string typeName)
{
	int lastIdIndex = findLastIdIndexByType(typeName);
	if (lastIdIndex == NOT_FOUND)
	{
		lastIdArr[lastIdCnt].setFirst(typeName);
		lastIdArr[lastIdCnt++].setSecond(1);
		return 1;
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
template<typename dataType>
void List<dataType>::AddNewLastId(std::string typeName, int lastId)
{
	lastIdArr[lastIdCnt].setFirst(typeName);
	lastIdArr[lastIdCnt++].setSecond(lastId);
}
//Utility
template<typename dataType>
dataType* List<dataType>::findDataById(std::string id)
{
	for (int index = 0; index < size; index++)
		if (dataArr[index]->getId() == id)
			return dataArr[index];
	return nullptr;
}
template<typename dataType> 
void List<dataType>::insertionSort()
{
	int i, j;
	dataType* temp;

	for (i = 0; i < size; i++)
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
void List<dataType>::insertionSort(List<Book>& bookList)
{
	int i, j;
	dataType* temp;

	for (i = 0; i < size; i++)
	{
		j = i;
		while (j > 0 && dataArr[j]->compare(bookList.findDataById(dataArr[j]->getBookId()), bookList.findDataById(dataArr[j - 1]->getBookId()), dataArr[j - 1]))
		{
			temp = dataArr[j - 1];
			dataArr[j - 1] = dataArr[j];
			dataArr[j] = temp;
			j--;
		}
	}
}
template<typename dataType>
bool List<dataType>::isEmpty()
{
	return size <= 0 ? true : false;
}