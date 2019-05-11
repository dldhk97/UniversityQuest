#include "Stack.h"



Stack::Stack(int iCapacity)
{
	capacity = iCapacity;
	dataArr = new int[capacity];
	top = -1;
}
Stack::~Stack()
{
	if (dataArr != nullptr)
		delete[] dataArr;
}

void Stack::push(int data)
{
	if (top + 1 >= capacity)
	{
		cout << "������ ���� á���ϴ�.\n";
	}
	else
	{
		dataArr[++top] = data;
	}
}
int Stack::pop()
{
	if (top < 0)
	{
		cout << "������ ����ֽ��ϴ�.\n";
		return INT_MIN;
	}
	else
	{
		return dataArr[top--];
	}
}

void Stack::print()
{
	for (int i = 0; i < top+1; i++)
		cout << dataArr[i] << ", ";
	cout << '\n';
}