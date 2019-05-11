#pragma once
#include <iostream>

using namespace std;

class Stack
{
private:
	int top;
	int capacity;

	int *dataArr;
public:
	Stack(int iCapacity);
	~Stack();

	void push(int data);
	int pop();

	void print();

};

