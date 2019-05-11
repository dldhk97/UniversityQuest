//List.cpp
#include "List.h"

List::List()
{
	head = NULL;
}
List::~List()
{

}

void List::add(int iData)
{
	Node *newNode = new Node(iData);
	if (head == NULL)
	{
		head = newNode;
		return;
	}
	Node *indexNode = head;
	while (1)
	{
		if (indexNode->getNextNode() == NULL)
		{
			indexNode->setNextNode(newNode);
			break;
		}
		indexNode = indexNode->getNextNode();
	}
}

Node *List::remove()
{
	if (head == NULL)
		return NULL;
	Node *indexNode = head;
	head = head->getNextNode();
	return indexNode;
}

void List::print()
{
	if (head == NULL)
	{
		return;
	}
	Node *indexNode = head;
	while (1)
	{
		if (indexNode == NULL)
		{
			break;
		}
		std::cout << indexNode->getData() << ", ";
		indexNode = indexNode->getNextNode();
	}
	std::cout << "\n";
}