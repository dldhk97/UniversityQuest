#include "Element.h"

//////////////////
//생성자, 소멸자//
//////////////////
Element::Element()
{
}

Element::Element(char iValue)
{
	value = iValue;
	isOperator = true;
}


Element::Element(std::string iValue)
{
	value = iValue;
	isOperator = false;
}

Element::~Element()
{
}

//////////
//Getter//
//////////
bool Element::getIsOperator()
{
	return isOperator;
}
std::string Element::getStrValue()
{
	return value;
}
int Element::getIntValue()
{
	int result = INT_MIN;
	if (isOperator)
		return result;
	try
	{
		result = std::stoi(value);				//정수가 아닌 실수인 경우 예외가 잡힌다.
	}
	catch (std::exception e)
	{
		char exceptionCode = '5';
		throw std::exception(&exceptionCode);
	}
	return result;
}

//////////
//setter//
//////////
void Element::setData(std::string iValue)
{
	value = iValue;
	isOperator = false;
}
void Element::setData(char iOperator)
{
	value = iOperator;
	isOperator = true;
}