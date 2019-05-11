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


void DNode::insertNodeAtHead(DNode *head)			//제일 앞에 노드를 넣습니다.
{
	DNode *tempNode = head;						//헤드가 가르키는 노드를 임시저장하고
	head = this;								//헤드가 this노드를 가르키게 한다.

	this->setNextNode(tempNode);				//this노드의 다음노드는 이전 헤드 노드로 한다.
	this->setPreviousNode(NULL);				//this노드의 이전 노드는 NULL처리한다.(this가 헤드이므로)
	tempNode->setPreviousNode(this);			//이전 헤드 노드의 이전 노드는 this노드이다.
}

void DNode::insertNodeAtFront(DNode *target)	//target노드 앞에 this노드를 넣습니다.
{
	if (target->getPreviousNode() == NULL)		//target노드가 head라면 헤드앞에 넣는 코드 호출
	{
		this->insertNodeAtHead(target);
	}
	else
	{
		target->getPreviousNode()->setNextNode(this);	//target노드의 이전 노드의 다음노드를 this노드로 한다.
		this->setPreviousNode(target->getPreviousNode());//this노드의 이전노드를 target노드의 이전노드로 한다.
		this->setNextNode(target);						//this 노드의 다음 노드는 target노드이다.
		target->setPreviousNode(this);					//target노드의 이전 노드를 this노드로 한다.
	}
}

void DNode::insertNodeAtBack(DNode *target)			//target노드 뒤에 this노드를 넣습니다.
{
	this->setNextNode(target->getNextNode());		//this노드의 다음노드는 target노드의 다음노드이다.
	this->setPreviousNode(target);					//this노드의 이전노드는 target노드이다.
	target->getNextNode()->setPreviousNode(this);	//target노드 다음노드의 이전노드는 this노드이다.
	target->setNextNode(this);						//target노드의 다음노드는 this노드이다.
}

DNode *DNode::insertNodeBySort(DNode *start)			//start노드부터 탐색하여 책이름순 위치에 알아서 넣습니다.	
{
	DNode *indexNode = start;
	while (true)
	{
		std::string thisBookTitle = this->getBookData().getTitle();
		std::string indexBookTitle = indexNode->getBookData().getTitle();
		int comparedDifference = thisBookTitle.compare(indexBookTitle);	//넣으려는 노드의 책 이름이 탐색할노드보다 앞서면 0보다 작고, 아니면 0보다 크다.

		if (comparedDifference < 0)					//넣으려는 노드의 책이름이 탐색한 책의 이름보다 사전순으로 앞서면 그 앞에다 넣는다.
		{
			this->insertNodeAtFront(indexNode);
			break;
		}
		else if (indexNode->getNextNode() == NULL)	//마지막까지 왔는데도 못 넣었다면 얘가 마지막 노드임.
		{
			this->insertNodeAtBack(indexNode);		//탐색한 노드가 넣으려는 노드를 가르키게 한다.
			return this;
		}
		indexNode = indexNode->getNextNode();		//탐색할노드를 다음노드로 바꾼다.
	}
	return NULL;
}

DNode *DNode::findNodeByBookData(std::string iBookData, std::string dataType)
{
	DNode *indexNode = this;
	std::string indexBookData;

	while (true)
	{
		if (dataType == "num")		//데이터타입이 책의 숫자인지 제목인지 판단
		{
			indexBookData = indexNode->getBookData().getNum();
		}
		else
		{
			indexBookData = indexNode->getBookData().getTitle();
		}

		if (indexBookData == iBookData)					//찾으려는 책 정보와 동일하면
		{
			return indexNode;
		}
		else if (indexNode->getNextNode() == NULL)			//마지막까지 왔는데도 못찾으면 NULL포인터 반환
		{
			return NULL;
		}
		indexNode = indexNode->getNextNode();		//탐색할노드를 다음노드로 바꾼다.
	}
}

//연산자 오버로딩
DNode DNode::operator=(DNode target)
{
	this->bookData = target.bookData;
	this->nextNode = target.nextNode;
	return target;
}