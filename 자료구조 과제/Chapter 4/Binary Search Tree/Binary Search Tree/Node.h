#pragma once
template <typename dataType>
class Node
{
private:
	dataType data;
	Node *left;
	Node *right;
public:
	Node();
	Node(dataType data);
	~Node();

	dataType getData();
	Node *getLeft();
	Node *getRight();

	void setData(dataType data);
	void setLeft(Node *left);
	void setRight(Node *right);
};

template<typename dataType>Node<dataType>::Node()
{

}
template<typename dataType>Node<dataType>::Node(dataType data)
{
	this->data = data;
}
template<typename dataType>Node<dataType>::~Node()
{

}

template<typename dataType>dataType Node<dataType>::getData()
{
	return this->data;
}
template<typename dataType>Node<dataType> *Node<dataType>::getLeft()
{
	return this->left;
}
template<typename dataType>Node<dataType> *Node<dataType>::getRight()
{
	return this->right;
}

template<typename dataType>void Node<dataType>::setData(dataType data)
{
	this->data = data;
}
template<typename dataType>void Node<dataType>::setLeft(Node *left)
{
	this->left = left;
}
template<typename dataType>void Node<dataType>::setRight(Node *right)
{
	this->right = right;
}