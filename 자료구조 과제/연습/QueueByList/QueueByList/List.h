//List.h
#pragma once

#include "Node.h"

class List
{
private:
	Node *head;
public:
	List();
	~List();
	void add(int iData);
	Node *remove();

	void print();
};