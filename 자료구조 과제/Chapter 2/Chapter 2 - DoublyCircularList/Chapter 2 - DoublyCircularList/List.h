#pragma once
#include <iostream>
#include <fstream>
#include "Node.h"

using namespace std;

class List
{
private:
	Node *head;		//환형연결리스트의 더미 헤드 노드
	int size;		//환형연결리스트의 실제 사이즈

public:
	//Initializer
	List();			//리스트를 초기화합니다.
	~List();

	//Getter
	Node *getHead();	//연결리스트의 head 노드의 주소를 받습니다.

	//Node Control
	void addNodeBySort(Node *iNode);		//노드를 알맞게 삽입합니다.
	void removeNodeByNum(string iBookNum);	//책 번호로 노드를 탐색하여 존재한다면 삭제합니다.

	//User Control
	void readFile(string filePath);			//filePath 경로의 텍스트파일을 읽어들여 노드를 추가합니다.
	void addBook();							//사용자에게 값을 입력받아 노드를 추가합니다.
	void removeBook();						//사용자에게 번호를 입력받아 노드를 삭제합니다.

	Node *findNodeByBookData(string iBookData, string dataType);

	void print(Node *startNode);			//리스트를 startNode부터 마지막 노드까지 순서대로 출력합니다.
	void printR(Node *startNode);			//리스트를 startNode부터 head까지 역순으로 출력합니다.
	void printAll(Node *startNode);			//리스트를 startNode부터 모든 노드를 순서대로 출력합니다.

	void saveFile(string filePath);			//리스트를 파일에다 저장합니다.

	//Utility
	bool isEmpty();							//리스트가 비어있는지 확인합니다.
};

