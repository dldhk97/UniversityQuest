#include "TaskManager.h"

void TaskManager::insertNode(Tree<Element> &iTree)
{
	IOHanlder ioh;
	Node<Element> newNode(iTree.getSize(),ioh.getElement());
	iTree.insertNode(newNode);
}
void TaskManager::deleteNode(Tree<Element> &iTree)
{
	IOHanlder ioh;
	//int targetKey = ioh.getInt("삭제하려는 노드 입력");
	//iTree.deleteNode();
}
void TaskManager::printNode(Tree<Element> &iTree)
{
	IOHanlder ioh;
	int userInput = ioh.getTourMenu();
	switch (userInput)
	{
	case PREORDER:
		iTree.preorder();
		break;
	case INORDER:
		iTree.inorder();
		break;
	case POSTORDER:
		iTree.postorder();
		break;
	}
}