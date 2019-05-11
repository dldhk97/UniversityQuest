#include "DoublyList.h"



DoublyList::DoublyList()
{
	head = NULL;
}


DoublyList::~DoublyList()
{
	while (1)
	{
		if (head == NULL)
			break;
		Node *targetNode = head;
		head = head->getNextNode();
		delete targetNode;
	}
}

void DoublyList::insertNode(Node *iNode)
{
	if (head == NULL)
	{
		head = iNode;
		return;
	}
		
	Node *targetNode = findNode(iNode->getData());
	if (targetNode != NULL)
	{
		std::cout << "동일한 값의 노드가 존재합니다.\n";
	}
	else
	{
		iNode->setNextNode(head);
		head->setPreviousNode(iNode);
		head = iNode;
		std::cout << "헤드노드로 추가됨\n";
	}
	
}
void DoublyList::deleteNode(int iValue)
{
	Node *targetNode = findNode(iValue);
	if (targetNode)
	{
		if (targetNode == head) 
		{
			head = targetNode->getNextNode();
			head->setPreviousNode(NULL);
			std::cout << "헤드노드 삭제됨\n";
			delete targetNode;
		}
		else if(targetNode->getNextNode() == NULL)
		{
			targetNode->getPreviousNode()->setNextNode(NULL);
			std::cout << "테일노드 삭제됨\n";
			delete targetNode;
		}
		else
		{
			Node *tempPreviousNode = targetNode->getPreviousNode();
			Node *tempNextNode = targetNode->getNextNode();
			tempPreviousNode->setNextNode(tempNextNode);
			tempNextNode->setPreviousNode(tempPreviousNode);
			std::cout << "중간노드 삭제됨\n";
			delete targetNode;
		}
	}
	else
	{
		std::cout << "대상 노드가 없습니다.\n";
	}
}

Node *DoublyList::findNode(int iValue)
{
	Node *indexNode = head;
	while (1)
	{
		if (indexNode == NULL)
		{
			return NULL;
		}
		else if (indexNode->getData() == iValue)
		{
			return indexNode;	
		}
		else
		{
			indexNode = indexNode->getNextNode();
		}
	}
}

void DoublyList::print()
{
	Node *indexNode = head;
	while (1)
	{
		if (indexNode == NULL)
		{
			break;
		}
		else
		{
			std::cout << indexNode->getData() << ", ";
			indexNode = indexNode->getNextNode();
		}
	}
	std::cout << '\n';
}