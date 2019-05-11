#pragma once

#include "Element.h"

template <typename T>
class Node
{
private:
	T data;
public:
	Node();
	Node(T iData);

	T getData();

	void setData(T iData);
	void printData();
};

template <typename T> Node<T>::Node()
{
	data = NULL;
}
template <typename T> Node<T>::Node(T iData)
{
	data = iData;
}

template <typename T> T Node<T>::getData()
{
	return data;
}

template <typename T> void Node<T>::setData(T iData)
{
	data = iData;
}

template <typename T> void Node<T>::printData()
{
	std::cout << data;
}