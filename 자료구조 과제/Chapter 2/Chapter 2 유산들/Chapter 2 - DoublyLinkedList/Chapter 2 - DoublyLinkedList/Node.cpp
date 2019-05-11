#include "Node.h"

//Initializer

Node::Node(std::string iBookNum, std::string iBookTitle)
{
	bookData.setNum(iBookNum);
	bookData.setTitle(iBookTitle);
	nextNode = NULL;
	previousNode = NULL;
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
Node *Node::getNextNode()
{
	return nextNode;
}

Node *Node::getPreviousNode()
{
	return previousNode;
}

//Setter

void Node::setNextNode(Node *iNextNode)
{
	nextNode = iNextNode;
}
void Node::setPreviousNode(Node *iPreviousNode)
{
	previousNode = iPreviousNode;
}