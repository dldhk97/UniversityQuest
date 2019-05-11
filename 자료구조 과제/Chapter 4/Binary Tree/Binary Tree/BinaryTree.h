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

template <typename T>void BinaryTree<T>::getWhiteSpace()	//입력받은 값 중 최대값의 길이(magic number)만큼 기준 공백을 만든다.
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
	getWhiteSpace();										//앞으로 입력을 추가로 받을일이 없으니 기준 공백계산.
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
	for (int i = index; i != 1; i = i / 2)		//인덱스를 계속 반으로 쪼개서 레벨을 알아낸다
		level++;
	return level;
}

template <typename T> void BinaryTree<T>::printAsTree(int index)
{
	if (index <= size)
	{
		if (index % 2 && index != 1)						//홀수(새로운 브랜치)는 (레벨-1)번 반복하여 띄어쓰기 해준다
		{
			std::cout << " ";
			int level = getLevel(index);
			
			for (int i = 0; i < level - 1; i++)				//레벨 - 1만큼 띄어쓰기 해줌
			{
				std::cout << "     ";
				std::cout << whiteSpace;
			}
		}
		if (index != 1)										//첫번째는 --- 를 하지 않는다.
		{
			std::cout << " --- ";
			int maxLength = std::to_string(size).length();
			int currentLength = std::to_string(nodeArr[index].getData().getValue()).length();
			for (int i = maxLength - currentLength; i > 0; i--)	//최대 길이까지 길이가 모자라다면 공백으로 채움
				std::cout << " ";
		}
		std::cout << nodeArr[index].getData();				//노드 출력

		if (getLeft(index) > size)							//리프노드(왼쪽자식 없음)면 한줄 띄우기
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