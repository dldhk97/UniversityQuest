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

	void insertNodeAtHead(Node *head);							//제일 앞에 노드를 넣습니다.
	void insertNodeAtBack(Node *target);						//target노드 뒤에 현재노드를 넣습니다.
	void insertNodeBySort(Node *start);							//start노드부터 탐색하여 책이름순 위치에 알아서 넣습니다.

	Node operator=(Node target);
};