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

	void printAsTree(int index);
	void preorder(int index);
	void inorder(int index);
	void postorder(int index);
	void levelorder(int root);
};

template <typename T>void BinaryTree<T>::getWhiteSpace()
{
	for (int i = 0; i < std::to_string(size).length(); i++)
		whiteSpace += " ";
}

template <typename T>BinaryTree<T>::BinaryTree(int iSize)
{
	nodeArr = new Node<T>[iSize + 1];
	size = iSize;
	for (int i = 1; i <= size; i++)							//1~size까지 노드 새로만들어서 1~size 값 부여
		nodeArr[i] = Node<T>(T(i));
	getWhiteSpace();
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

template <typename T> void BinaryTree<T>::printAsTree(int index)
{
	if (index <= size)
	{
		if (index % 2 && index != 1)					//홀수(새로운 브랜치가 생기는걸 의미)는 띄어쓰기 해준다
		{
			std::cout << " ";
			int level = 0;
			for (int i = index; i != 1; i = i / 2)		//인덱스를 계속 반으로 쪼개서 레벨을 알아낸다
				level++;
			for (int i = 0; i < level - 1; i++)			//레벨만큼 탭 해줌
			{
				std::cout << "     ";
				std::cout << whiteSpace;
			}
		}
		if (index != 1)									//첫번째는 ---를 하지 않는다.
		{
			std::cout << " ";
			std::cout << "---";
			for (int i = std::to_string(size).length() + 1 - std::to_string(nodeArr[index].getData().getValue()).length(); i > 0; i--)
				std::cout << " ";
		}
		std::cout << nodeArr[index].getData().getValue();

		if (getLeft(index) > size)						//리프노드면 한줄 띄우기
			std::cout << '\n';
		printAsTree(getLeft(index));
		printAsTree(getRight(index));
	}
}

template <typename T> void BinaryTree<T>::preorder(int index)
{
	if (index <= size)
	{
		nodeArr[index].printData();
		std::cout << " ";
		preorder(getLeft(index));
		preorder(getRight(index));
	}
}
template <typename T> void BinaryTree<T>::inorder(int index)
{
	if (index <= size)
	{
		inorder(getLeft(index));
		nodeArr[index].printData();
		std::cout << " ";
		inorder(getRight(index));
	}
}
template <typename T> void BinaryTree<T>::postorder(int index)
{
	if (index <= size)
	{
		postorder(getLeft(index));
		postorder(getRight(index));
		nodeArr[index].printData();
		std::cout << " ";
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
		nodeArr[index].printData();
		std::cout << " ";
		if (getLeft(index) <= size)
			newQueue.push(getLeft(index));
		if (getRight(index) <= size)
			newQueue.push(getRight(index));
	}
}