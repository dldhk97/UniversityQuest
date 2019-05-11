#pragma once

#include <iostream>
#include <string>
#include "Formula.h"
#include "BinaryTree.h"

class TaskManager
{
public:
	void getInfix(std::string &infix);
	void saveAsPostfix(const std::string infix, Formula &postfix);
	void saveAsTree(Formula &postfix , BinaryTree<Term> &formulaTree);

	void printAsPostfix(Formula &postfix);
	void printAsPreorder(BinaryTree<Term> &formulaTree);
	void printAsTree(BinaryTree<Term> &formulaTree);
	void printRoot(BinaryTree<Term> &formulaTree);

	void printException(const char exceptionCode);
};

