#pragma once

#include <iostream>

class Node
{
private:
	int data;
	Node *nextNode;
	Node *previousNode;
public:
	Node();
	Node(int iData);
	~Node();

	int getData();
	Node *getNextNode();
	Node *getPreviousNode();

	void setData(int iData);
	void setNextNode(Node *iNode);
	void setPreviousNode(Node *iNode);
};

