#pragma once
#include <string>
#include "Book.h"

class Node
{
private:
	Node *nextNode;			//다음 노드의 포인터값
	Book bookData;			//책
public:
	//Initializer
	Node(std::string iBookNum, std::string iBookTitle);		//노드를 책의 번호와 제목으로 생성합니다.

	//Getter
	std::string getBookNum();				//노드 내부의 책 번호를 반환합니다.
	std::string getBookTitle();				//노드 내부의 책 제목을 반환합니다.
	Node *getNextNode();					//다음 노드의 주소값을 반환합니다.

	//Setter
	void setNextNode(Node *iNextNode);		//다음 노드의 주소값을 설정합니다.
};

