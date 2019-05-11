#pragma once
#include <string>
#include "Book.h"

class Node
{
private:
	Node *nextNode;			//���� ����� �����Ͱ�
	Book bookData;			//å
public:
	//Initializer
	Node(std::string iBookNum, std::string iBookTitle);		//��带 å�� ��ȣ�� �������� �����մϴ�.

	//Getter
	std::string getBookNum();				//��� ������ å ��ȣ�� ��ȯ�մϴ�.
	std::string getBookTitle();				//��� ������ å ������ ��ȯ�մϴ�.
	Node *getNextNode();					//���� ����� �ּҰ��� ��ȯ�մϴ�.

	//Setter
	void setNextNode(Node *iNextNode);		//���� ����� �ּҰ��� �����մϴ�.
};

