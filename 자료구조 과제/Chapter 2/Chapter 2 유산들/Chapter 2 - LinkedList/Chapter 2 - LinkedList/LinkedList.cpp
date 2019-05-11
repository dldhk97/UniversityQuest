#include <iostream>
#include "LinkedList.h"

Node::~Node() {}

//������

Node::Node(Book iBookData)
{
	this->bookData = iBookData;
	this->nextNode = NULL;
}

Node::Node(Book iBookData, Node *iNextNode)
{
	this->bookData = iBookData;
	this->nextNode = iNextNode;
}

//Getter�� Setter

Node *Node::getNextNode()
{
	return this->nextNode;
}
void Node::setNextNode(Node *iNextNode)
{
	this->nextNode = iNextNode;
}

Book Node::getBookData()
{
	return this->bookData;
}
void Node::setBookData(Book iBookData)
{
	this->bookData = iBookData;
}

//��尣 ��Ʈ��

void Node::insertNodeAtHead(Node *head)			//���� �տ� ��带 �ֽ��ϴ�.
{
	Node *tempNode = head;						//��尡 ����Ű�� ��带 �ӽ������ϰ�
	head = this;								//��尡 this��带 ����Ű�� �Ѵ�.
	this->setNextNode(tempNode);				//this��尡 �ӽ������ ��带 ����Ű�� �Ѵ�.
}

void Node::insertNodeAtBack(Node *target)		//target��� �ڿ� this��带 �ֽ��ϴ�.
{
	this->setNextNode(target->getNextNode());	//target��� ���� ��带 this��尡 ����Ű�Բ� �ϰ�
	target->setNextNode(this);					//target��尡 this��带 ����Ű�� ��.
}

void Node::insertNodeBySort(Node *start)		//start������ Ž���Ͽ� å�̸��� ��ġ�� �˾Ƽ� �ֽ��ϴ�.	
{
	Node *indexNode = start;
	Node *previousNode = start;
	while (true)
	{
		string thisBookTitle = this->getBookData().getTitle();
		string indexBookTitle = indexNode->getBookData().getTitle();
		int comparedDiffrence = thisBookTitle.compare(indexBookTitle);	//�������� ����� å �̸��� Ž���ҳ�庸�� �ռ��� 0���� �۰�, �ƴϸ� 0���� ũ��.

		if (comparedDiffrence < 0)					//�������� ����� å�̸��� Ž���� å�� �̸����� ���������� �ռ��� �� �տ��� �ִ´�.
		{
			previousNode->setNextNode(this);		//������尡 �������� ��带 ����Ű�� �Ѵ�.
			this->setNextNode(indexNode);			//�������� ��尡 Ž���� ��带 ����Ű�� �Ѵ�.
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//���������� �Դµ��� �� �־��ٸ� �갡 ������ �����.
		{
			this->insertNodeAtBack(indexNode);		//Ž���� ��尡 �������� ��带 ����Ű�� �Ѵ�.
			break;
		}
		previousNode = indexNode;					//������带 Ž���ѳ��� �ٲ۴�.
		indexNode = indexNode->getNextNode();		//Ž���ҳ�带 �������� �ٲ۴�.
	}
}

//������ �����ε�

Node Node::operator=(Node target)
{
	this->bookData = target.bookData;
	this->nextNode = target.nextNode;
	return target;
}