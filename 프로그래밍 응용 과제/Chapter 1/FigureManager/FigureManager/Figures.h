#pragma once
#include <iostream>
#include <string>
#include "Circle.h"

class Figures
{
private:
	Circle *circleArr;		//������ ������ ���� �迭
	int capacity;			//�ִ�ũ��
	int size;				//����ũ��
public:
	//Initializer
	Figures();				//������
	Figures(int iMaxSize);	//�ִ�ũ�� ���� �� ������
	~Figures();				//�Ҹ���, �����迭 ����

	//Methods

	void addFigure();		//����ڿ��� �����͸� �Է¹޾� �ϳ��� ������ �߰�
	void removeFigure();	//����ڿ��� ID�� �Է¹޾� ������ ID�� ���� ����
	void printAll();		//��� ������ ������ ���������� ���

	//Utility

	bool isEmpty();			//���� �迭�� ����ִ��� Ȯ��
	void printExceptionMsg(int iCase);	//���� �޼��� ���
};

