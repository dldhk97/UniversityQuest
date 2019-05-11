#include <iostream>
#include "Book.h"
using namespace std;

class Node
{
private:
	Book bookData;
	Node *nextNode;
public:
	~Node();
	Node(Book iBookData);
	Node(Book iBookData, Node *iNextNode);

	Node *getNextNode();
	void setNextNode(Node *iNextNode);

	Book getBookData();
	void setBookData(Book iBookData);

	void insertNodeAtHead(Node *head);							//���� �տ� ��带 �ֽ��ϴ�.
	void insertNodeAtBack(Node *target);						//target��� �ڿ� �����带 �ֽ��ϴ�.
	void insertNodeBySort(Node *start);							//start������ Ž���Ͽ� å�̸��� ��ġ�� �˾Ƽ� �ֽ��ϴ�.

	Node operator=(Node target);
};