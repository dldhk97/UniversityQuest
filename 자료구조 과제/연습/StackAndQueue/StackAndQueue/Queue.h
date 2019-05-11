#pragma once
#include <iostream>

using namespace std;

class Queue
{
private:
	int front;
	int rear;
	int capacity;

	int *dataArr;

public:
	Queue(int iCapacity);
	~Queue();

	void add(int data);
	int remove();

	void print();

};

