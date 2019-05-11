#pragma once
#include <iostream>
#include "Node.h"

template <typename T>
class Tree
{
private:
	Node<T> *root;
	int size;
public:
	Tree();
	~Tree();

	Node<T> *getRoot();
	void setRoot(Node<T> *iNode);

	Node<T> insertNode(Node<T> iNode);
	
	void deleteNode(Node<T> iNode);

	void preorder();
	void inorder();
	void postorder();

	bool isEmpty();
	int getSize();

};

template <typename T>Tree<T>::Tree()
{
	root = NULL;
	size = 0;
}

template <typename T>Tree<T>::~Tree()
{

}

template <typename T> Node<T> *Tree<T>::getRoot()
{
	return root;
}
template <typename T> void Tree<T>::setRoot(Node<T> *iNode)
{
	root = iNode;
}

template <typename T> Node<T> Tree<T>::insertNode(Node<T> iNode)
{
	//if (iNode == NULL) return iNode;
	return iNode;
}
template <typename T> void Tree<T>::deleteNode(Node<T> iNode)
{

}

template <typename T> void Tree<T>::preorder()
{

}
template <typename T> void Tree<T>::inorder()
{

}
template <typename T> void Tree<T>::postorder()
{

}

template <typename T> bool Tree<T>::isEmpty()
{
	return root == NULL;
}

template <typename T> int Tree<T>::getSize()
{
	return size;
}