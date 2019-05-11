#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node *last;		//ȯ�����Ḯ��Ʈ�� last ���
	int size;		//ȯ�����Ḯ��Ʈ�� ���� ������

public:
	//Initializer
	List();			//����Ʈ�� �ʱ�ȭ�մϴ�.

	//Getter
	Node *getLast();	//���Ḯ��Ʈ�� last ����� �ּҸ� �޽��ϴ�.

	//Node Control
	void addNodeBySort(Node *iNode);		//��带 �˸°� �����մϴ�.
	void removeNodeByNum(string iBookNum);	//å ��ȣ�� ��带 Ž���Ͽ� �����Ѵٸ� �����մϴ�.

	//User Control
	void readFile(string filePath);			//filePath ����� �ؽ�Ʈ������ �о�鿩 ��带 �߰��մϴ�.
	void addBook();							//����ڿ��� ���� �Է¹޾� ��带 �߰��մϴ�.
	void removeBook();						//����ڿ��� ��ȣ�� �Է¹޾� ��带 �����մϴ�.
	void print();							//����Ʈ�� ó������ last���� ����մϴ�.
	void saveFile(string filePath);			//����Ʈ�� ���Ͽ��� �����մϴ�.

	//Control Memory
	void deleteMemory();					//����Ʈ�� ��带 ó������ last���� �����մϴ�.
};

