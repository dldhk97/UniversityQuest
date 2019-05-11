#pragma once
#include <iostream>
#include "Node.h"
#include "Formula.h"

template <typename T>
class BinaryTree
{
private:
	Node<T> *root;
	int maxLength;

	void deleteMemory(Node<T> *iNode);
public:
	~BinaryTree();

	Node<T> *getRoot();

	void calculateAsTree(Formula &postfix);
	void preorder(Node<T> *iNode);
	void printAsTree(Node<T> *iNode, int level, bool continuous);
};

template <typename T>void BinaryTree<T>::deleteMemory(Node<T> *iNode)
{
	if (iNode == nullptr)
		return;
	deleteMemory(iNode->getLeft());
	deleteMemory(iNode->getRight());
	delete iNode;
}

template <typename T>BinaryTree<T>::~BinaryTree()
{
	deleteMemory(root);
}

template <typename T>Node<T> *BinaryTree<T>::getRoot()
{
	return root;
}

template <typename T>void BinaryTree<T>::calculateAsTree(Formula &postfix)
{
	if (postfix.getSize() == 1)
	{
		root = new Node<T>(postfix.getTerm(0));
		maxLength = std::to_string(postfix.getTerm(0).getIntValue()).length();
	}
	else
	{
		Stack<Node<T>*> newStack;
		for (int i = 0; i < postfix.getSize(); i++)
		{
			T currentTerm = postfix.getTerm(i);
			if (currentTerm.isOperator())
			{
				int result;
				Node<T> *root = new Node<T>();
				this->root = root;
				if (currentTerm.getStrValue()[0] == '~' || currentTerm.getStrValue()[0] == '#')	//단항연산자 계산
				{
					Node<T> *C = newStack.pop();
					result = postfix.processUnaryOperator(C->getData().getIntValue(), currentTerm.getStrValue()[0]);
					root->setData(Term(std::to_string(result), currentTerm.getStrValue()[0]));
					root->setLeft(C);
				}
				else
				{
					Node<T> *A = newStack.pop();
					Node<T> *B = newStack.pop();
					result = postfix.processOperator(B->getData().getIntValue(), A->getData().getIntValue(), currentTerm.getStrValue()[0]);
					root->setData(Term(std::to_string(result), currentTerm.getStrValue()[0]));
					root->setLeft(B);
					root->setRight(A);
				}
				newStack.push(root);
				if (std::to_string(result).length() > maxLength)
					maxLength = std::to_string(result).length();
			}
			else
			{
				Node<T> *newNode = new Node<T>(currentTerm);
				newStack.push(newNode);
				if (std::to_string(currentTerm.getIntValue()).length() > maxLength)
					maxLength = std::to_string(currentTerm.getIntValue()).length();
			}
		}
	}
}

template <typename T> void BinaryTree<T>::preorder(Node<T> *iNode)
{
	if (iNode == nullptr)
		return;
	iNode->print();
	preorder(iNode->getLeft());
	preorder(iNode->getRight());
}

template <typename T> void BinaryTree<T>::printAsTree(Node<T> *iNode, int level, bool continuous)
{
	if (iNode == nullptr)
		return;
	
	std::string whiteSpace;
	for (int i = 0; i < maxLength + 4; i++)
		whiteSpace += " ";

	if (continuous == false)
	{
		std::cout << whiteSpace;
		for (int i = 1; i < level; i++)
		{
			std::cout << "     ";
			std::cout << whiteSpace;
		}
	}
	if(iNode != root)
		std::cout << " --- ";
	for (int i = maxLength - std::to_string(iNode->getData().getIntValue()).length() ; i > 0 ; i--)
		std::cout << " ";
	
	if (!iNode->getData().isOperator())
		std::cout << "    ";
	std::cout << iNode->getAsString();
	printAsTree(iNode->getLeft(), level + 1, true);
	printAsTree(iNode->getRight(), level + 1, false);
	if (iNode->getLeft() == nullptr)
		std::cout << "\n";
}