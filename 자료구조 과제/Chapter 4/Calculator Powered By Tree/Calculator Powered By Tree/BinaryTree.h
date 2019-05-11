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
	std::string whiteSpace;					//�Էµ� ���� ū ���� ���̸�ŭ�� ����

	void deleteMemory(Node<T> *iNode);
	void updateMaxLength(int newLength);
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

template <typename T>void BinaryTree<T>::updateMaxLength(int newLength)
{
	if (newLength > maxLength)			//����� ������� ���� �ִ���̺��� ũ�� ����
		maxLength = newLength;
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
				if (currentTerm.getStrValue()[0] == '~' || currentTerm.getStrValue()[0] == '#')	//���׿����� ���
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
				updateMaxLength(std::to_string(result).length());
			}
			else
			{
				Node<T> *newNode = new Node<T>(currentTerm);
				newStack.push(newNode);
				updateMaxLength(std::to_string(currentTerm.getIntValue()).length());
			}
		}
		for (int i = 0; i < maxLength + 4; i++)
			whiteSpace += " ";
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

	if (continuous == false)									//���ο� �귣ġ�̸� level - 1 ��ŭ �������. ���� ó���� whitespace�� ������ش�.
	{
		std::cout << whiteSpace;
		for (int i = 0; i < level - 1; i++)
		{
			std::cout << "     ";								//�̰��� ���̴� ' --- '�� ���̿� �����ϴ�.
			std::cout << whiteSpace;
		}
	}

	if(iNode != root)
		std::cout << " --- ";

	int currentLength = std::to_string(iNode->getData().getIntValue()).length();
	for (int i = maxLength - currentLength; i > 0 ; i--)		//�ִ���̺��� ������̰� ���ڶ�� �����κ��� �����߰�
		std::cout << " ";
	
	if (!iNode->getData().isOperator())							//�̹����� ������ ���ڰ��� ���� ����, ������ ����(4���� ����)��ŭ ����.
		std::cout << "    ";
	std::cout << iNode->getStrWithOperator();
	printAsTree(iNode->getLeft(), level + 1, true);
	printAsTree(iNode->getRight(), level + 1, false);
	if (iNode->getLeft() == nullptr)							//�����ڽ��� ������ ����
		std::cout << "\n";
}