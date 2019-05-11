#pragma once

#include "Node.h"

class List
{
private:
	Node *head;
	int top;
public:
	List();
	~List();

	void push(int data);
	Node *pop();

	void print();
};

