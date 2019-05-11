#pragma once
#include <iostream>

const int DEFAULT_CAPACITY = 8;

template <typename dataType>
class Stack
{
private:
	dataType *dataArr;
	int top;
	int capacity;

	//크기 확대 및 수축
	void resize(int iCapacity);
public:
	//생성자, 소멸자
	Stack();
	~Stack();

	//push,pop
	void push(dataType iData);
	dataType pop();

	//Getter
	int getSize();
	dataType peek();

	//유틸리티
	bool isEmpty();
};


//템플릿 클래스라 아래쪽에 소스가 있음

template <typename dataType> Stack<dataType>::Stack()
{
	capacity = DEFAULT_CAPACITY;
	dataArr = new dataType[capacity];
	top = -1;
}


template <typename dataType> Stack<dataType>::~Stack()
{
	if(dataArr != nullptr)
		delete[] dataArr;
}

template <typename dataType> void Stack<dataType>::resize(int iCapacity)
{
	dataType *tempArr = new  dataType[top + 1];
	for (int i = 0; i < top + 1; i++)
		tempArr[i] = dataArr[i];
	delete[] dataArr;

	dataArr = new dataType[iCapacity];
	for (int i = 0; i < top + 1; i++)
		dataArr[i] = tempArr[i];
	delete[] tempArr;

	capacity = iCapacity;

}

template <typename dataType> void Stack<dataType>::push(dataType iData)
{
	if (getSize() == capacity)
		resize(capacity * 2);
	dataArr[++top] = iData;
}
template <typename dataType> dataType Stack<dataType>::pop()
{
	if (isEmpty())
	{
		char exceptionCode = 'B';
		throw std::exception(&exceptionCode);
	}
	if (getSize() < capacity / 4 && capacity > DEFAULT_CAPACITY)
		resize(capacity / 2);
	return dataArr[top--];
}

template <typename dataType> int Stack<dataType>::getSize()
{
	return top + 1;
}
template <typename dataType> dataType Stack<dataType>::peek()
{
	return dataArr[top];
}

template <typename dataType> bool Stack<dataType>::isEmpty()
{
	return top <= -1;
}