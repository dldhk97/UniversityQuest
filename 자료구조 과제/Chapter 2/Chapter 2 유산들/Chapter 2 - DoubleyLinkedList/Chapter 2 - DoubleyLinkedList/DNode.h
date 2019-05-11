#pragma once
#include "Book.h"
#include "string"
class DNode
{
private:
	Book bookData;
	DNode *nextNode;
	DNode *previousNode;

public:
	DNode();
	DNode(Book iBookData);
	~DNode();

	void addNewNode(Book iBookData);
	void addNewNode(Book iBookData, DNode *previousNode, DNode *nextNode);

	void setBookData(Book iBookData);
	Book getBookData();

	void setNextNode(DNode *iNode);
	DNode *getNextNode();
	
	void setPreviousNode(DNode *iNode);
	DNode *getPreviousNode();

	void insertNodeAtHead(DNode *head);							//제일 앞에 노드를 넣습니다.
	void insertNodeAtFront(DNode *target);						//target노드 앞에 현재노드를 넣습니다.
	void insertNodeAtBack(DNode *target);						//target노드 뒤에 현재노드를 넣습니다.
	DNode *insertNodeBySort(DNode *start);						//start노드부터 탐색하여 책이름순 위치에 알아서 넣습니다.	그리고, this노드가 마지막노드라면 반환하고 아니면 NULL을 반환합니다.

	DNode *findNodeByBookData(std::string iBookData, std::string dataType);	//this노드부터 탐색하여 iBookData가 동일하면 그 노드를 반환합니다. dataType은 num 또는 title이 될 수 있습니다.

	DNode operator=(DNode target);
};

