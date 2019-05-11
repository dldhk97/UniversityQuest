#pragma once

#include "Tree.h"
#include "Element.h"
#include "IOHanlder.h"

class TaskManager
{
public:
	void insertNode(Tree<Element> &iTree);
	void deleteNode(Tree<Element> &iTree);
	void printNode(Tree<Element> &iTree);
};

