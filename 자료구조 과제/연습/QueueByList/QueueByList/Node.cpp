//Node.cpp
#include "Node.h"

Node::Node()
{
	nextNode = NULL;
}

Node::Node(int iData)
{
	nextNode = NULL;
	data = iData;
}

Node::~Node()
{

}

Node *Node::getNextNode()
{
	return nextNode;
}

int Node::getData()
{
	if (this == nullptr)
		return NULL;
	return data;
}

void Node::setNextNode(Node *iNode)
{
	this->nextNode = iNode;
}

void Node::setData(int iData)
{
	this->data = iData;
}