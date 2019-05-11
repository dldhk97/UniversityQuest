#pragma once

const int DEFAULT_CAPACITY = 10;

template <typename T>
class Queue
{
private:
	int front;
	int rear;
	int size;
	int capacity;
	T *dataArr;
	
	void resize(int newCapacity);
public:
	Queue();
	~Queue();
	void push(T data);
	T pop();

	bool isEmpty();
	bool isFull();
};

template <typename T>void Queue<T>::resize(int newCapacity)
{
	T *tempArr = new T[capacity];
	int saveIndex = 1;
	for (int i = (front + 1) % capacity; i != (rear + 1) % capacity; i = (i + 1) % capacity)
	{
		tempArr[saveIndex++] = dataArr[i];
	}
	delete[] dataArr;
	dataArr = new T[newCapacity];
	for (int i = 1; i < size + 1; i++)
	{
		dataArr[i] = tempArr[i];
	}
	delete[] tempArr;
	capacity = newCapacity;
	front = 0;
	rear = size;
}

template <typename T>Queue<T>::Queue()
{
	front = 0;
	rear = 0;
	size = 0;
	capacity = DEFAULT_CAPACITY;
	dataArr = new T[capacity];
}

template <typename T>Queue<T>::~Queue()
{
	if (dataArr != nullptr)
		delete[] dataArr;
}

template <typename T>void Queue<T>::push(T data)
{
	if (isFull())
		resize(capacity * 2);
	rear = (rear + 1) % capacity;
	dataArr[rear] = data;
	size++;
}

template <typename T>T Queue<T>::pop()
{
	if (isEmpty())
		return INT_MIN;
	front = (front + 1) % capacity;
	T result = dataArr[front];
	size--;
	if (capacity > DEFAULT_CAPACITY && size <= capacity / 4)
		resize(capacity / 2);
	return result;
}

template <typename T>bool Queue<T>::isEmpty()
{
	return size == 0 ? true : false;
}

template <typename T>bool Queue<T>::isFull()
{
	return size + 1 == capacity ? true : false;
}