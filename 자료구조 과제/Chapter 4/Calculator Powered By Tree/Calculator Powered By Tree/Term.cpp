#include "Term.h"

//////////////////
//������, �Ҹ���//
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
	if (integerValue.empty())							//�����ڸ� ���������� ȣ�� �� ���� ȣ��
	{
		char exceptionCode = 'A';
		throw std::exception(&exceptionCode);
	}
	try
	{
		result = std::stoi(integerValue);				//������ �ƴ� �Ǽ��� ��� ���ܰ� ������.
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