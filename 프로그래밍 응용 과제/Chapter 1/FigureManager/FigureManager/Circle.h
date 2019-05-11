#pragma once
#include <iostream>
#include <string>

const double PIE = 3.14159265359;		//������ ����

class Circle
{
private:
	std::string id;				//������ ID
	int posX, posY;				//������ ��ǥ
	double radius, area;		//������ ������, ����
public:
	//Initializer

	Circle();					//�⺻ ������
	~Circle();					//�Ҹ���

	//Getter,Setter

	void setData();				//������ ������ ����
	std::string getId();		//������ ID ��ȯ
	double getArea();			//������ ���� ��ȯ

	//methods
	void print();				//������ ���� ���

};

