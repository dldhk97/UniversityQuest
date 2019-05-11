#pragma once
#include <iostream>
#include <string>
class Element
{
private:
	bool isOperator;		//true이면 연산자, false면 수
	std::string value;		//연산자 혹은 수가 저장되는 멤버 변수
public:
	//생성자, 소멸자
	Element();
	Element(char iValue);			//char로 들어오면 연산자
	Element(std::string iValue);	//string으로 들어오면 수
	~Element();

	//Getter
	bool getIsOperator();							//연산자인지 아닌지 반환
	std::string getStrValue();				//저장된 value를 string으로 반환
	int getIntValue();						//저장된 value를 실제 int값으로 반환

	//maker
	void setData(std::string iValue);		//수로써 저장
	void setData(char iOperator);			//연산자로써 저장
};

