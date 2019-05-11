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

	void insertNodeAtHead(DNode *head);							//���� �տ� ��带 �ֽ��ϴ�.
	void insertNodeAtFront(DNode *target);						//target��� �տ� �����带 �ֽ��ϴ�.
	void insertNodeAtBack(DNode *target);						//target��� �ڿ� �����带 �ֽ��ϴ�.
	DNode *insertNodeBySort(DNode *start);						//start������ Ž���Ͽ� å�̸��� ��ġ�� �˾Ƽ� �ֽ��ϴ�.	�׸���, this��尡 ����������� ��ȯ�ϰ� �ƴϸ� NULL�� ��ȯ�մϴ�.

	DNode *findNodeByBookData(std::string iBookData, std::string dataType);	//this������ Ž���Ͽ� iBookData�� �����ϸ� �� ��带 ��ȯ�մϴ�. dataType�� num �Ǵ� title�� �� �� �ֽ��ϴ�.

	DNode operator=(DNode target);
};

