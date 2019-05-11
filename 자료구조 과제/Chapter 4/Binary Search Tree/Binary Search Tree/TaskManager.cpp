#include "TaskManager.h"

std::string TaskManager::getString(std::string message)
{
	std::string userInput;
	std::cout << message;
	getline(std::cin, userInput);
	return userInput;
}

void TaskManager::insertStringAtBST(std::string str, BinarySearchTree<std::string> &bst)
{
	Node<std::string> *newNode = new Node<std::string>(str);
	try
	{
		bst.insertNode(newNode);
	}
	catch (std::exception exceptionCode)
	{
		printException(*exceptionCode.what());
	}
}

void TaskManager::printBST(BinarySearchTree<std::string> &bst)
{
	bst.updateWhiteSpace();
	bst.printAsTree(bst.getRoot(), 0, true);
}

void TaskManager::printException(const char exceptionCode)
{
	std::string exceptionMessage;
	switch (exceptionCode)
	{
	case '0':
		exceptionMessage = "동일한 노드가 이미 존재합니다.";
		break;
	default:
		exceptionMessage = "알 수 없는 오류입니다.";
		break;
	}
	std::cout << "[ERROR:" << exceptionCode << "]" << exceptionMessage << "\n";
}