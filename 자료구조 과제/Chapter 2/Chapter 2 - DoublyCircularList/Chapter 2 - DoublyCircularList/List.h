#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node *head;		//ȯ�����Ḯ��Ʈ�� ���� ��� ���
	int size;		//ȯ�����Ḯ��Ʈ�� ���� ������

public:
	//Initializer
	List();			//����Ʈ�� �ʱ�ȭ�մϴ�.
	~List();

	//Getter
	Node *getHead();	//���Ḯ��Ʈ�� head ����� �ּҸ� �޽��ϴ�.

	//Node Control
	void addNodeBySort(Node *iNode);		//��带 �˸°� �����մϴ�.
	void removeNodeByNum(string iBookNum);	//å ��ȣ�� ��带 Ž���Ͽ� �����Ѵٸ� �����մϴ�.

	//User Control
	void readFile(string filePath);			//filePath ����� �ؽ�Ʈ������ �о�鿩 ��带 �߰��մϴ�.
	void addBook();							//����ڿ��� ���� �Է¹޾� ��带 �߰��մϴ�.
	void removeBook();						//����ڿ��� ��ȣ�� �Է¹޾� ��带 �����մϴ�.

	Node *findNodeByBookData(string iBookData, string dataType);

	void print(Node *startNode);			//����Ʈ�� startNode���� ������ ������ ������� ����մϴ�.
	void printR(Node *startNode);			//����Ʈ�� startNode���� head���� �������� ����մϴ�.
	void printAll(Node *startNode);			//����Ʈ�� startNode���� ��� ��带 ������� ����մϴ�.

	void saveFile(string filePath);			//����Ʈ�� ���Ͽ��� �����մϴ�.

	//Utility
	bool isEmpty();							//����Ʈ�� ����ִ��� Ȯ���մϴ�.
};

