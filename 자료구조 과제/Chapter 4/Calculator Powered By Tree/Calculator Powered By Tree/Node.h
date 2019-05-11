#pragma once

template <typename T>
class Node
{
private:
	T data;
	Node *left;
	Node *right;
public:
	Node();
	Node(T iData);
	~Node();

	T getData();
	Node *getLeft();
	Node *getRight();

	void setData(T iData);
	void setLeft(Node *iNode);
	void setRight(Node *iNode);

	void print();
	std::string getAsString();
};

//initializer
template <typename T>Node<T>::Node()
{

}
template <typename T>Node<T>::Node(T iData)
{
	data = iData;
}
template <typename T>Node<T>::~Node()
{

}

//getter
template <typename T>T Node<T>::getData()
{
	if (this == nullptr)
	{
		char exceptionCode = 'C';
		throw std::exception(&exceptionCode);
	}
	return data;
}

template <typename T>Node<T> *Node<T>::getLeft()
{
	return left == nullptr ? nullptr : left;
}

template <typename T>Node<T> *Node<T>::getRight()
{
	return right == nullptr ? nullptr : right;
}

//setter
template <typename T>void Node<T>::setData(T iData)
{
	data = iData;
}
template <typename T>void Node<T>::setLeft(Node *iNode)
{
	left = iNode;
}
template <typename T>void Node<T>::setRight(Node *iNode)
{
	right = iNode;
}

template <typename T>void Node<T>::print()
{
	std::cout << data.getStrValue() << " ";
}

template <typename T>std::string Node<T>::getAsString()
{
	return data.getStrWithOperator();
}