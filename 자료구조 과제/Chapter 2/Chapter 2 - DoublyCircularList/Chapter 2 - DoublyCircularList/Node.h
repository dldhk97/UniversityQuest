#pragma once
#include <string>
#include "Book.h"

class Node
{
private:
	Node *previousNode;		//���� ����� �����Ͱ�
	Node *nextNode;			//���� ����� �����Ͱ�
	Book bookData;			//å
public:
	//Initializer
	Node();
	Node(std::string iBookNum, std::string iBookTitle);		//��带 å�� ��ȣ�� �������� �����մϴ�.

	//Getter
	std::string getBookNum();				//��� ������ å ��ȣ�� ��ȯ�մϴ�.
	std::string getBookTitle();				//��� ������ å ������ ��ȯ�մϴ�.
	Node *getPreviousNode();				//���� ����� �ּҰ��� ��ȯ�մϴ�.
	Node *getNextNode();					//���� ����� �ּҰ��� ��ȯ�մϴ�.

	//Setter
	void setPreviousNode(Node *iPreviousNode);//���� ����� �ּҰ��� �����մϴ�.
	void setNextNode(Node *iNextNode);		//���� ����� �ּҰ��� �����մϴ�.
};

