#pragma once
template <typename T>
class Node
{
private:
	int key;
	T value;
	Node<T> *leftNode;
	Node<T> *rightNode;
public:
	Node(int iKey, T iValue);
	Node(int iKey, T iValue, Node<T> *iLeftNode, Node<T> *iRightNode);
	~Node();

	int getKey();
	T getValue();
	Node<T> *getLeftNode();
	Node<T> *getRightNode();

	void setKey(int iKey);
	void setValue(Node<T> iValue);
	void setLeftNode(Node<T> *iNode);
	void setRightNode(Node<T> *iNode);

};

template <typename T>Node<T>::Node(int iKey, T iValue)
{
	key = iKey;
	value = iValue;
}

template <typename T>Node<T>::Node(int iKey, T iValue, Node<T> *iLeftNode, Node<T> *iRightNode)
{
	key = iKey;
	value = iValue;
	leftNode = iLeftNode;
	rightNode = iRightNode;
}

template <typename T>Node<T>::~Node()
{

}

template <typename T> int Node<T>::getKey()
{
	return key;
}
template <typename T>T Node<T>::getValue()
{
	return value;
}
template <typename T> Node<T> *Node<T>::getLeftNode()
{
	return leftNode;
}
template <typename T> Node<T> *Node<T>::getRightNode()
{
	return rightNode;
}

template <typename T> void Node<T>::setKey(int iKey)
{
	key = iKey;
}
template <typename T> void Node<T>::setValue(Node<T> iValue)
{
	value = iValue;
}
template <typename T> void Node<T>::setLeftNode(Node<T> *iNode)
{
	leftNode = iNode;
}
template <typename T> void Node<T>::setRightNode(Node<T> *iNode)
{
	rightNode = iNode;
}