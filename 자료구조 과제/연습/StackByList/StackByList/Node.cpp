#include "Node.h"



Node::Node()
{
	nextNode = NULL;
	data = INT_MIN;
}

Node::Node(int data)
{
	this->data = data;
}

Node::~Node()
{
}

int Node::getData()
{
	return data;
}
Node *Node::getNextNode()
{
	return nextNode;
}

void Node::setData(int data)
{
	this->data = data;
}
void Node::setNextNode(Node *node)
{
	this->nextNode = node;
}