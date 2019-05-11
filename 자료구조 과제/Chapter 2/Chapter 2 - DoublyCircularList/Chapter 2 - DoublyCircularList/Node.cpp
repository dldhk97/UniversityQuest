#include "Node.h"

//Initializer

Node::Node()
{
	//dummy
	previousNode = NULL;
	nextNode = NULL;
}

Node::Node(std::string iBookNum, std::string iBookTitle)
{
	bookData.setNum(iBookNum);
	bookData.setTitle(iBookTitle);
	previousNode = NULL;
	nextNode = NULL;
}

//Getter

std::string Node::getBookNum()
{
	return bookData.getNum();
}
std::string Node::getBookTitle()
{
	return bookData.getTitle();
}
Node *Node::getPreviousNode()
{
	return previousNode;
}
Node *Node::getNextNode()
{
	return nextNode;
}

//Setter

void Node::setPreviousNode(Node *iPreviousNode)
{
	previousNode = iPreviousNode;
}
void Node::setNextNode(Node *iNextNode)
{
	nextNode = iNextNode;
}