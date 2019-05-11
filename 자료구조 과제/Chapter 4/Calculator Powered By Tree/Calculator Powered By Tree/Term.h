#pragma once
#include <iostream>
#include <string>

class Term
{
private:
	std::string integerValue;		//������ ����Ǵ� ����
	char operatorValue;				//�����ڰ� ����Ǵ� ����
public:
	//������, �Ҹ���
	Term();
	Term(std::string integerValue);
	Term(char operatorValue);
	Term(std::string integerValue, char operatorValue);

	//Getter
	bool isOperator();						//���������� �ƴ��� ��ȯ
	std::string getStrValue();				//����� value�� string���� ��ȯ
	std::string getStrWithOperator();
	int getIntValue();						//����� value�� ���� int������ ��ȯ
	char getOperatorValue();

	//setter
	void setData(std::string integerValue);	//���ν� ����
	void setData(char operatorValue);		//�����ڷν� ����

};

