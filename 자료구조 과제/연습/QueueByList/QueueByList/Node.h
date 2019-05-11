//Node.h
#pragma once

#include <iostream>

class Node
{
private:
	Node *nextNode;
	int data;
public:
	Node();
	Node(int iData);
	~Node();

	Node *getNextNode();
	int getData();

	void setNextNode(Node *iNode);
	void setData(int iData);
};