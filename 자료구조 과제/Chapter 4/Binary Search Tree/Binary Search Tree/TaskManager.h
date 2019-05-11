#pragma once

#include <iostream>
#include <string>
#include "BinarySearchTree.h"

class TaskManager
{
public:
	std::string getString(std::string message);
	void insertStringAtBST(std::string str, BinarySearchTree<std::string> &bst);
	
	void printBST(BinarySearchTree<std::string> &bst);
	void printException(const char exceptionCode);
};

