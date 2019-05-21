#pragma once

template <typename dataType1, typename dataType2>
class Pair
{
private:
	dataType1 first;
	dataType2 second;
public:
	Pair();
	Pair(dataType1 first, dataType2 second);

	//Getter
	dataType1 getFirst();
	dataType2 getSecond();

	//Setter
	void setFirst(dataType1 first);
	void setSecond(dataType2 second);

};

template <typename dataType1, typename dataType2>
Pair<dataType1, dataType2>::Pair()
{
	this->first = "";
	this->second = -1;
}
template <typename dataType1, typename dataType2>
Pair<dataType1, dataType2>::Pair(dataType1 first, dataType2 second)
{
	this->first = first;
	this->second = second;
}
template <typename dataType1, typename dataType2>
dataType1 Pair<dataType1, dataType2>::getFirst()
{
	return first;
}
template <typename dataType1, typename dataType2>
dataType2 Pair<dataType1, dataType2>::getSecond()
{
	return second;
}

template <typename dataType1, typename dataType2>
void Pair<dataType1, dataType2>::setFirst(dataType1 first)
{
	this->first = first;
}
template <typename dataType1, typename dataType2>
void Pair<dataType1, dataType2>::setSecond(dataType2 second)
{
	this->second = second;
}