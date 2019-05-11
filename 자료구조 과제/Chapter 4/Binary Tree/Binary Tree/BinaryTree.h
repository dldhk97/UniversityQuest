#pragma once

#include <iostream>
#include <string>
#include "Node.h"
#include "Queue.h"

template <typename T>
class BinaryTree
{
private:
	Node<T> *nodeArr;
	int size;

	std::string whiteSpace;
	void getWhiteSpace();
public:
	BinaryTree(int iSize);
	~BinaryTree();

	int getLeft(int index);
	int getRight(int index);
	int getRoot();
	int getLevel(int index);

	void printAsTree(int index);
	void preorder(int index);
	void inorder(int index);
	void postorder(int index);
	void levelorder(int root);
};

template <typename T>void BinaryTree<T>::getWhiteSpace()	//�Է¹��� �� �� �ִ밪�� ����(magic number)��ŭ ���� ������ �����.
{
	for (int i = 0; i < std::to_string(size).length(); i++)
		whiteSpace += " ";
}

template <typename T>BinaryTree<T>::BinaryTree(int iSize)
{
	nodeArr = new Node<T>[iSize + 1];
	size = iSize;
	for (int i = 1; i <= size; i++)							//1~size���� ��� ���θ��� 1~size �� �ο�
		nodeArr[i] = Node<T>(T(i));
	getWhiteSpace();										//������ �Է��� �߰��� �������� ������ ���� ������.
}

template <typename T>BinaryTree<T>::~BinaryTree()
{
	if(nodeArr != nullptr)
		delete[] nodeArr;
}

template <typename T> int BinaryTree<T>::getLeft(int index)
{
	return index * 2;
}


template <typename T> int BinaryTree<T>::getRight(int index)
{
	return index * 2 + 1;
}

template <typename T> int BinaryTree<T>::getRoot()
{
	return 1;
}

template <typename T> int BinaryTree<T>::getLevel(int index)
{
	int level = 0;
	for (int i = index; i != 1; i = i / 2)		//�ε����� ��� ������ �ɰ��� ������ �˾Ƴ���
		level++;
	return level;
}

template <typename T> void BinaryTree<T>::printAsTree(int index)
{
	if (index <= size)
	{
		if (index % 2 && index != 1)						//Ȧ��(���ο� �귣ġ)�� (����-1)�� �ݺ��Ͽ� ���� ���ش�
		{
			std::cout << " ";
			int level = getLevel(index);
			
			for (int i = 0; i < level - 1; i++)				//���� - 1��ŭ ���� ����
			{
				std::cout << "     ";
				std::cout << whiteSpace;
			}
		}
		if (index != 1)										//ù��°�� --- �� ���� �ʴ´�.
		{
			std::cout << " --- ";
			int maxLength = std::to_string(size).length();
			int currentLength = std::to_string(nodeArr[index].getData().getValue()).length();
			for (int i = maxLength - currentLength; i > 0; i--)	//�ִ� ���̱��� ���̰� ���ڶ�ٸ� �������� ä��
				std::cout << " ";
		}
		std::cout << nodeArr[index].getData();				//��� ���

		if (getLeft(index) > size)							//�������(�����ڽ� ����)�� ���� ����
			std::cout << '\n';
		printAsTree(getLeft(index));
		printAsTree(getRight(index));
	}
}

template <typename T> void BinaryTree<T>::preorder(int index)
{
	if (index <= size)
	{
		std::cout << nodeArr[index].getData() << " ";
		preorder(getLeft(index));
		preorder(getRight(index));
	}
}
template <typename T> void BinaryTree<T>::inorder(int index)
{
	if (index <= size)
	{
		inorder(getLeft(index));
		std::cout << nodeArr[index].getData() << " ";
		inorder(getRight(index));
	}
}
template <typename T> void BinaryTree<T>::postorder(int index)
{
	if (index <= size)
	{
		postorder(getLeft(index));
		postorder(getRight(index));
		std::cout << nodeArr[index].getData() << " ";
	}
}
template <typename T> void BinaryTree<T>::levelorder(int root)
{
	Queue<int> newQueue;
	int index;
	newQueue.push(root);
	while (!newQueue.isEmpty())
	{
		index = newQueue.pop();
		std::cout << nodeArr[index].getData() << " ";
		if (getLeft(index) <= size)
			newQueue.push(getLeft(index));
		if (getRight(index) <= size)
			newQueue.push(getRight(index));
	}
}