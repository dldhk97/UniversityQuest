#include "Node.h"



Node::Node()
{
	nextNode = NULL;
	previousNode = NULL;
}

Node::Node(int iData)
{
	data = iData;
	nextNode = NULL;
	previousNode = NULL;
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
Node *Node::getPreviousNode()
{
	return previousNode;
}

void Node::setData(int iData)
{
	data = iData;	
}
void Node::setNextNode(Node *iNode)
{
	if(this != NULL)
		nextNode = iNode;
}
void Node::setPreviousNode(Node *iNode)
{
	if(this != NULL)
		previousNode = iNode;
}