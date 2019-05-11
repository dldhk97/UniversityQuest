#pragma once

const int DEFAULT_CAPACITY = 2;

template <typename dataType>
class Queue
{
private:
	int front;
	int rear;
	int capacity;
	int size;
	dataType *dataArr;

	void resize(int newCapacity);
public:
	Queue();
	~Queue();

	void push(dataType data);
	dataType pop();

	bool isEmpty();
	bool isFull();

	void print();
};

template<typename dataType>void Queue<dataType>::resize(int newCapacity)
{
	dataType *tempArr = new dataType[capacity];
	int saveIndex = 1;
	for (int index = (front + 1) % capacity; index != (rear + 1 ) % capacity; index = (index + 1) % capacity)
		tempArr[saveIndex++] = dataArr[index];
	delete[] dataArr;
	dataArr = new dataType[newCapacity];
	//debug
	cout << "===debug===\n";
	for (int i = 0; i <= size; i++)
		cout << tempArr[i] << ", ";
	cout << "\n===debug===\n";
	//for (int index = 0; index < capacity; index++)
	for (int i = 0; i <= size; i++)
		dataArr[i] = tempArr[i];
	delete[] tempArr;

	front = 0;
	rear = size;
	cout << capacity << "->" << newCapacity << "\n";
	capacity = newCapacity;
}

template<typename dataType>Queue<dataType>::Queue()
{
	capacity = DEFAULT_CAPACITY;
	dataArr = new dataType[capacity];
	front = 0;
	rear = 0;
}

template<typename dataType>Queue<dataType>::~Queue()
{
	if (dataArr)
		delete[] dataArr;
}

template<typename dataType>void Queue<dataType>::push(dataType data)
{
	if (isFull())
		resize(capacity * 2);
	rear = (rear + 1) % capacity;
	size++;
	dataArr[rear] = data;
}

template<typename dataType>dataType Queue<dataType>::pop()
{
	if (isEmpty())
		return INT_MIN;
	front = (front + 1) % capacity;
	size--;
	dataType result = dataArr[front];
	if (size < capacity / 4 && capacity > DEFAULT_CAPACITY)
		resize(capacity / 2);
	return result;
}

template<typename dataType>bool Queue<dataType>::isEmpty()
{
	return front == rear ? true : false;
}
template<typename dataType>bool Queue<dataType>::isFull()
{
	return (rear + 1) % capacity == front ? true : false;
}

template<typename dataType>void Queue<dataType>::print()
{
	cout << "=====print=====\n";
	for (int index = (front + 1) % capacity; index != (rear + 1) % capacity; index = (index + 1) % capacity)
	{
		cout << dataArr[index] << ", ";
	}
	cout << "\n=====end=====\n";
}