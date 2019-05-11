#include "List.h"



List::List()
{
	top = -1;
	head = new Node();
}


List::~List()
{
}

void List::push(int data)
{
	Node *indexNode = head;
	for (int i = 0; i <= top; i++)
	{
		indexNode = indexNode->getNextNode();
	}
	Node *newNode = new Node(data);
	indexNode->setNextNode(newNode);
	top++;
}

Node *List::pop()
{
	if (top < 0)
		return NULL;
	Node *indexNode = head;
	for (int i = 0; i <= top; i++)
	{
		indexNode = indexNode->getNextNode();
	}
	delete indexNode;
	top--;
	return indexNode;
}

void List::print()
{
	Node *indexNode = head;
	for (int i = 0; i <= top + 1; i++)
	{
		if(i > 0)
			std::cout << indexNode->getData() << ", ";
		indexNode = indexNode->getNextNode();
	}
	std::cout << "\n";
}