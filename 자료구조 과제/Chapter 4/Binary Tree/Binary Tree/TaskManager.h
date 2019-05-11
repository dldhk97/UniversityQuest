#pragma once

#include <iostream>
#include "BinaryTree.h"

template <typename dataType>
class TaskManager
{
public:
	int getSize();

	void printAsTree(BinaryTree<dataType> &iTree);
	void printAsPreorder(BinaryTree<dataType> &iTree);
	void printAsInorder(BinaryTree<dataType> &iTree);
	void printAsPostorder(BinaryTree<dataType> &iTree);
	void printAsLevelorder(BinaryTree<dataType> &iTree);
};

template <typename dataType> int TaskManager<dataType>::getSize()
{
	int userInput;
	while (1)
	{
		std::cout << "노드 개수를 입력하세요 : ";
		std::cin >> userInput;
		if (userInput > 0)
			break;
		std::cout << "노드 개수는 0보다 많아야 합니다." << "\n";
	}
	return userInput;
}

template <typename dataType> void TaskManager<dataType>::printAsTree(BinaryTree<dataType> &iTree)
{
	iTree.printAsTree(iTree.getRoot());
	std::cout << "\n";
}
template <typename dataType> void TaskManager<dataType>::printAsPreorder(BinaryTree<dataType> &iTree)
{
	std::cout << "preorder  : ";
	iTree.preorder(iTree.getRoot());
	std::cout << "\n";
}
template <typename dataType> void TaskManager<dataType>::printAsInorder(BinaryTree<dataType> &iTree)
{
	std::cout << "inorder   : ";
	iTree.inorder(iTree.getRoot());
	std::cout << "\n";
}
template <typename dataType> void TaskManager<dataType>::printAsPostorder(BinaryTree<dataType> &iTree)
{
	std::cout << "postorder : ";
	iTree.postorder(iTree.getRoot());
	std::cout << "\n";
}
template <typename dataType> void TaskManager<dataType>::printAsLevelorder(BinaryTree<dataType> &iTree)
{
	std::cout << "levelorder: ";
	iTree.levelorder(iTree.getRoot());
	std::cout << "\n";
}