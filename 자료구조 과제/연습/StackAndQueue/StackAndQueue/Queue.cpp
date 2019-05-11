#include "Queue.h"



Queue::Queue(int iCapacity)
{
	capacity = iCapacity;
	dataArr = new int[capacity];
	front = 0;
	rear = 0;
}
Queue::~Queue()
{
	if (dataArr != nullptr)
		delete[] dataArr;
}

void Queue::add(int data)
{
	if ((rear + 1) % capacity == front)
	{
		cout << "큐가 가득 찼습니다.\n";
	}
	else
	{
		rear = (rear + 1) % capacity;
		dataArr[rear] = data;
	}
}
int Queue::remove()
{
	if (rear == front)
	{
		cout << "큐가 비어있습니다.\n";
		return INT_MIN;
	}
	else
	{
		front = (front + 1) % capacity;
		int temp = dataArr[front];
		dataArr[front] = INT_MIN;
		return temp;
	}
}

void Queue::print()
{
	for (int i = 0; i < capacity; i++)
		cout << dataArr[i] << ", ";
	cout << "\n";
}