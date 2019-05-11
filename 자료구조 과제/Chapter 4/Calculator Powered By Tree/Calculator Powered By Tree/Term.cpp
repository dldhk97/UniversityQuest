#include "Term.h"

//////////////////
//생성자, 소멸자//
//////////////////
Term::Term()
{
}
Term::Term(std::string integerValue)
{
	this->integerValue = integerValue;
	this->operatorValue = '$';
}
Term::Term(char operatorValue)
{
	this->operatorValue = operatorValue;
}
Term::Term(std::string integerValue, char operatorValue)
{
	this->integerValue = integerValue;
	this->operatorValue = operatorValue;
}

//////////
//Getter//
//////////
bool Term::isOperator()
{
	return operatorValue == '$' ? false : true;
}
std::string Term::getStrValue()
{
	return isOperator() ? std::string(1, operatorValue) : integerValue;
}
std::string Term::getStrWithOperator()
{
	return isOperator() ? std::string(1, operatorValue) + " (" + integerValue + ")" : integerValue;
}

int Term::getIntValue()
{
	int result;
	if (integerValue.empty())							//연산자를 정수형으로 호출 시 예외 호출
	{
		char exceptionCode = 'A';
		throw std::exception(&exceptionCode);
	}
	try
	{
		result = std::stoi(integerValue);				//정수가 아닌 실수인 경우 예외가 잡힌다.
	}
	catch (std::exception e)
	{
		char exceptionCode = '5';
		throw std::exception(&exceptionCode);
	}
	return result;
}

char Term::getOperatorValue()
{
	return operatorValue;
}

//////////
//setter//
//////////
void Term::setData(std::string integerValue)
{
	this->integerValue = integerValue;
	this->operatorValue = '$';
}
void Term::setData(char operatorValue)
{
	this->operatorValue = operatorValue;
}