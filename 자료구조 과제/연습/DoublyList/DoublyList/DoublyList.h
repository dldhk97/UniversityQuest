#pragma once

#include "Node.h"

class DoublyList
{
private:
	Node *head;
public:
	DoublyList();
	~DoublyList();

	void insertNode(Node *iNode);
	void deleteNode(int iValue);

	Node *findNode(int iValue);
	void print();

};

