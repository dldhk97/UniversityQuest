#pragma once
#include <iostream>
#include <string>

class Term
{
private:
	std::string integerValue;		//정수가 저장되는 변수
	char operatorValue;				//연산자가 저장되는 변수
public:
	//생성자, 소멸자
	Term();
	Term(std::string integerValue);
	Term(char operatorValue);
	Term(std::string integerValue, char operatorValue);

	//Getter
	bool isOperator();						//연산자인지 아닌지 반환
	std::string getStrValue();				//저장된 value를 string으로 반환
	std::string getStrWithOperator();
	int getIntValue();						//저장된 value를 실제 int값으로 반환
	char getOperatorValue();

	//setter
	void setData(std::string integerValue);	//수로써 저장
	void setData(char operatorValue);		//연산자로써 저장

};

