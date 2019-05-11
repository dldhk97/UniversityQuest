#pragma once

#include <iostream>

class Node
{
private:
	Node *nextNode;
	int data;
public:
	Node();
	Node(int data);
	~Node();

	int getData();
	Node *getNextNode();

	void setData(int data);
	void setNextNode(Node *node);
};

