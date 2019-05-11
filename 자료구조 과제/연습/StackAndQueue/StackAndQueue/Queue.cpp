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
		cout << "ť�� ���� á���ϴ�.\n";
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
		cout << "ť�� ����ֽ��ϴ�.\n";
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