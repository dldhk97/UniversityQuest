#pragma once
#include <iostream>
#include <string>
class Element
{
private:
	bool isOperator;		//true�̸� ������, false�� ��
	std::string value;		//������ Ȥ�� ���� ����Ǵ� ��� ����
public:
	//������, �Ҹ���
	Element();
	Element(char iValue);			//char�� ������ ������
	Element(std::string iValue);	//string���� ������ ��
	~Element();

	//Getter
	bool getIsOperator();							//���������� �ƴ��� ��ȯ
	std::string getStrValue();				//����� value�� string���� ��ȯ
	int getIntValue();						//����� value�� ���� int������ ��ȯ

	//maker
	void setData(std::string iValue);		//���ν� ����
	void setData(char iOperator);			//�����ڷν� ����
};

