#pragma once

#include "Node.h"

template <typename dataType>
class BinarySearchTree
{
private:
	Node<dataType> *root;
	int maxLength;
	std::string whiteSpace;						//�Է¹��� �� �� �ִ���̸�ŭ�� ����
public:
	BinarySearchTree();
	~BinarySearchTree();
	void deleteMemory(Node<dataType> *node);
	
	void insertNode(Node<dataType> *node);
	Node<dataType> *getRoot();

	bool isEmpty();
	void updateWhiteSpace();
	void printAsTree(Node<dataType> *node, int level, bool continuous);
};

template <typename dataType>void BinarySearchTree<dataType>::updateWhiteSpace()
{
	whiteSpace = "";
	for (int i = 0; i < maxLength; i++)
		whiteSpace += " ";
}

template <typename dataType>BinarySearchTree<dataType>::BinarySearchTree()
{
	root = nullptr;
}

template <typename dataType>BinarySearchTree<dataType>::~BinarySearchTree()
{
	if(!isEmpty())
		deleteMemory(root);
}

template <typename dataType>void BinarySearchTree<dataType> ::deleteMemory(Node<dataType> *node)
{
	if (node == nullptr)
		return;
	deleteMemory(node->getLeft());
	deleteMemory(node->getRight());
	delete node;
}

template <typename dataType>void BinarySearchTree<dataType>::insertNode(Node<dataType> *node)
{
	if (node == nullptr)
		return;
	if (node->getData().length() > maxLength)
		maxLength = node->getData().length();
	if (isEmpty())
	{
		root = node;
		return;
	}
	Node<dataType> *indexNode = root;
	while (indexNode != nullptr)
	{
		if (indexNode->getData() > node->getData())
		{
			if (indexNode->getLeft() != nullptr)
			{
				indexNode = indexNode->getLeft();
			}
			else
			{
				indexNode->setLeft(node);
				break;
			}
				
		}
		else if(indexNode->getData() == node->getData())
		{
			char exceptionCode = '0';
			throw std::exception(&exceptionCode);
		}
		else
		{
			if (indexNode->getRight() != nullptr)
			{
				indexNode = indexNode->getRight();
			}
			else
			{
				indexNode->setRight(node);
				break;
			}
		}
	}
}

template <typename dataType>Node<dataType> *BinarySearchTree<dataType>::getRoot()
{
	return root;
}

template <typename dataType>bool BinarySearchTree<dataType>::isEmpty()
{
	return root == nullptr ? true : false;
}

template <typename dataType> void BinarySearchTree<dataType>::printAsTree(Node<dataType> *node, int level, bool continuous)
{
	if (node == NULL)
		return;

	if (continuous == false)
	{
		std::cout << whiteSpace;
		for (int i =  0; i < level - 1; i++)
		{
			std::cout << "     ";										//�� ������ ' --- '�� ��ü �����̴�.
			std::cout << whiteSpace;
		}
	}
	if(node != root)
		std::cout << " --- ";
	int currentLength = node->getData().length();
	for (int i = maxLength - currentLength; i > 0; i--)					//�ִ���̺��� ���ڶ�� ���ڶ���ŭ ��ĭ �߰�
		std::cout << " ";
	std::cout << node->getData();
	if (node->getLeft() == nullptr && node->getRight() != nullptr)		//���� �ڽ��� ���� ������ �ڽ��� ������ --x ǥ��
		std::cout << " --x ";
	printAsTree(node->getLeft(), level + 1, true);
	if(node->getLeft() == nullptr)										//�����ڽ��� ������ ���� ����
		std::cout << "\n";
	printAsTree(node->getRight(), level + 1, false);
	
}