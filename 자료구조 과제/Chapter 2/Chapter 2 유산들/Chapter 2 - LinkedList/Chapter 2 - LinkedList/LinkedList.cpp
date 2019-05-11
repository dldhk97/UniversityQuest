#include <iostream>
#include "LinkedList.h"

Node::~Node() {}

//생성자

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

//Getter와 Setter

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

//노드간 컨트롤

void Node::insertNodeAtHead(Node *head)			//제일 앞에 노드를 넣습니다.
{
	Node *tempNode = head;						//헤드가 가르키는 노드를 임시저장하고
	head = this;								//헤드가 this노드를 가르키게 한다.
	this->setNextNode(tempNode);				//this노드가 임시저장된 노드를 가르키게 한다.
}

void Node::insertNodeAtBack(Node *target)		//target노드 뒤에 this노드를 넣습니다.
{
	this->setNextNode(target->getNextNode());	//target노드 뒤의 노드를 this노드가 가르키게끔 하고
	target->setNextNode(this);					//target노드가 this노드를 가르키게 함.
}

void Node::insertNodeBySort(Node *start)		//start노드부터 탐색하여 책이름순 위치에 알아서 넣습니다.	
{
	Node *indexNode = start;
	Node *previousNode = start;
	while (true)
	{
		string thisBookTitle = this->getBookData().getTitle();
		string indexBookTitle = indexNode->getBookData().getTitle();
		int comparedDiffrence = thisBookTitle.compare(indexBookTitle);	//넣으려는 노드의 책 이름이 탐색할노드보다 앞서면 0보다 작고, 아니면 0보다 크다.

		if (comparedDiffrence < 0)					//넣으려는 노드의 책이름이 탐색한 책의 이름보다 사전순으로 앞서면 그 앞에다 넣는다.
		{
			previousNode->setNextNode(this);		//이전노드가 넣으려는 노드를 가르키게 한다.
			this->setNextNode(indexNode);			//넣으려는 노드가 탐색한 노드를 가르키게 한다.
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//마지막까지 왔는데도 못 넣었다면 얘가 마지막 노드임.
		{
			this->insertNodeAtBack(indexNode);		//탐색한 노드가 넣으려는 노드를 가르키게 한다.
			break;
		}
		previousNode = indexNode;					//이전노드를 탐색한노드로 바꾼다.
		indexNode = indexNode->getNextNode();		//탐색할노드를 다음노드로 바꾼다.
	}
}

//연산자 오버로딩

Node Node::operator=(Node target)
{
	this->bookData = target.bookData;
	this->nextNode = target.nextNode;
	return target;
}