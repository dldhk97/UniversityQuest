#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node *head;		//���߿��Ḯ��Ʈ�� head ���
	Node *tail;		//���߿��Ḯ��Ʈ�� tail ���
	int size;		//���߿��Ḯ��Ʈ�� ���� ������

public:
	//Initializer
	List();			//����Ʈ�� �ʱ�ȭ�մϴ�.

	//Getter
	Node *getHead();	//���߿��Ḯ��Ʈ�� head ����� �ּҸ� �޽��ϴ�.
	Node *getTail();	//���߿��Ḯ��Ʈ�� tail ����� �ּҸ� �޽��ϴ�.

	//Node Control
	void addNodeBySort(Node *iNode);		//��带 �˸°� �����մϴ�.
	void removeNodeByNum(string iBookNum);	//å ��ȣ�� ��带 Ž���Ͽ� �����Ѵٸ� �����մϴ�.
	Node *findNodeByBookData(string iBookData, string dataType);		//å�� ���� Ȥ�� ��ȣ�� Ž���Ͽ� ������ ������ ���� ��带 ��ȯ�մϴ�.

	//User Control
	void readFile(string filePath);			//filePath ����� �ؽ�Ʈ������ �о�鿩 ��带 �߰��մϴ�.

	void addBook();							//����ڿ��� ���� �Է¹޾� ��带 �߰��մϴ�.
	void removeBook();						//����ڿ��� ��ȣ�� �Է¹޾� ��带 �����մϴ�.

	void print(Node *startNode);			//����Ʈ�� startNode���� tail���� ������� ����մϴ�.
	void printR(Node *startNode);			//����Ʈ�� startNode���� head���� �������� ����մϴ�.
	void printAll(Node *startNode);			//����Ʈ�� startNode���� ��� ��带 ������� ����մϴ�.

	void saveFile(string filePath);			//����Ʈ�� ���Ͽ��� �����մϴ�.

	//Utility
	bool isEmpty();							//����Ʈ�� ����ִ��� Ȯ���մϴ�.

	//Control Memory
	void deleteMemory();					//����Ʈ�� ��带 head���� tail���� �����մϴ�.
};

