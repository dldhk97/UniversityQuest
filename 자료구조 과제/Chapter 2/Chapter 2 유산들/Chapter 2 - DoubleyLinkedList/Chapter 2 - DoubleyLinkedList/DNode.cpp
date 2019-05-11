#include "DNode.h"

DNode::DNode()
{
}
DNode::DNode(Book iBookData)
{
	this->bookData = iBookData;
	this->previousNode = NULL;
	this->nextNode = NULL;
}

DNode::~DNode()
{
}


void DNode::addNewNode(Book iBookData)
{
	this->setBookData(iBookData);
	this->setPreviousNode(NULL);
	this->setNextNode(NULL);
}
void DNode::addNewNode(Book iBookData, DNode *previousNode, DNode *nextNode)
{
	this->setBookData(iBookData);
	this->setPreviousNode(previousNode);
	this->setNextNode(nextNode);
}

void DNode::setBookData(Book iBookData)
{
	this->bookData = iBookData;
}
Book DNode::getBookData()
{
	return this->bookData;
}

void DNode::setNextNode(DNode *iNode)
{
	if (this != NULL)
		this->nextNode = iNode;
}
DNode *DNode::getNextNode()
{
	return this->nextNode;
}

void DNode::setPreviousNode(DNode *iNode)
{
	if(this != NULL)
		this->previousNode = iNode;
}
DNode *DNode::getPreviousNode()
{
	return this->previousNode;
}


void DNode::insertNodeAtHead(DNode *head)			//���� �տ� ��带 �ֽ��ϴ�.
{
	DNode *tempNode = head;						//��尡 ����Ű�� ��带 �ӽ������ϰ�
	head = this;								//��尡 this��带 ����Ű�� �Ѵ�.

	this->setNextNode(tempNode);				//this����� �������� ���� ��� ���� �Ѵ�.
	this->setPreviousNode(NULL);				//this����� ���� ���� NULLó���Ѵ�.(this�� ����̹Ƿ�)
	tempNode->setPreviousNode(this);			//���� ��� ����� ���� ���� this����̴�.
}

void DNode::insertNodeAtFront(DNode *target)	//target��� �տ� this��带 �ֽ��ϴ�.
{
	if (target->getPreviousNode() == NULL)		//target��尡 head��� ���տ� �ִ� �ڵ� ȣ��
	{
		this->insertNodeAtHead(target);
	}
	else
	{
		target->getPreviousNode()->setNextNode(this);	//target����� ���� ����� ������带 this���� �Ѵ�.
		this->setPreviousNode(target->getPreviousNode());//this����� ������带 target����� �������� �Ѵ�.
		this->setNextNode(target);						//this ����� ���� ���� target����̴�.
		target->setPreviousNode(this);					//target����� ���� ��带 this���� �Ѵ�.
	}
}

void DNode::insertNodeAtBack(DNode *target)			//target��� �ڿ� this��带 �ֽ��ϴ�.
{
	this->setNextNode(target->getNextNode());		//this����� �������� target����� ��������̴�.
	this->setPreviousNode(target);					//this����� �������� target����̴�.
	target->getNextNode()->setPreviousNode(this);	//target��� ��������� �������� this����̴�.
	target->setNextNode(this);						//target����� �������� this����̴�.
}

DNode *DNode::insertNodeBySort(DNode *start)			//start������ Ž���Ͽ� å�̸��� ��ġ�� �˾Ƽ� �ֽ��ϴ�.	
{
	DNode *indexNode = start;
	while (true)
	{
		std::string thisBookTitle = this->getBookData().getTitle();
		std::string indexBookTitle = indexNode->getBookData().getTitle();
		int comparedDifference = thisBookTitle.compare(indexBookTitle);	//�������� ����� å �̸��� Ž���ҳ�庸�� �ռ��� 0���� �۰�, �ƴϸ� 0���� ũ��.

		if (comparedDifference < 0)					//�������� ����� å�̸��� Ž���� å�� �̸����� ���������� �ռ��� �� �տ��� �ִ´�.
		{
			this->insertNodeAtFront(indexNode);
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//���������� �Դµ��� �� �־��ٸ� �갡 ������ �����.
		{
			this->insertNodeAtBack(indexNode);		//Ž���� ��尡 �������� ��带 ����Ű�� �Ѵ�.
			return this;
		}
		indexNode = indexNode->getNextNode();		//Ž���ҳ�带 �������� �ٲ۴�.
	}
	return NULL;
}

DNode *DNode::findNodeByBookData(std::string iBookData, std::string dataType)
{
	DNode *indexNode = this;
	std::string indexBookData;

	while (true)
	{
		if (dataType == "num")		//������Ÿ���� å�� �������� �������� �Ǵ�
		{
			indexBookData = indexNode->getBookData().getNum();
		}
		else
		{
			indexBookData = indexNode->getBookData().getTitle();
		}

		if (indexBookData == iBookData)					//ã������ å ������ �����ϸ�
		{
			return indexNode;
		}
		else if (indexNode->getNextNode() == NULL)			//���������� �Դµ��� ��ã���� NULL������ ��ȯ
		{
			return NULL;
		}
		indexNode = indexNode->getNextNode();		//Ž���ҳ�带 �������� �ٲ۴�.
	}
}

//������ �����ε�
DNode DNode::operator=(DNode target)
{
	this->bookData = target.bookData;
	this->nextNode = target.nextNode;
	return target;
}