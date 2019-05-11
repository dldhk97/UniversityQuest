#pragma once
#include <iostream>
#include <string>
#include "Term.h"

class Polynomial
{
private:
	Term *arr;			//���� ���� ������ �迭
	int size;			//�迭�� ���� �뷮
	int capacity;		//�迭�� �ִ� �뷮
public:
	Polynomial();			//�������Դϴ�.
	~Polynomial();	//�޸𸮸� �����մϴ�.

	//getter
	int getSize();			//�迭�� ���� �뷮�� �˾Ƴ��ϴ�.
	int getCoe(int index);	//Ư�� ��ġ�� ���� ����� �˾Ƴ��ϴ�.
	int getIdx(int index);	//Ư�� ��ġ�� ���� ������ �˾Ƴ��ϴ�.

	//Methods
	void addTerm(int coe, int idx);	//����� ������ �Է¹޾� ���ο� ���� ���մϴ�.
	void removeTerm(int idx);		//������ �Է¹޾� �ش�Ǵ� ���� �����մϴ�.
	void resizeCapacity(int iCapacity);	//ũ�⸦ �Է¹޾� �迭�� �ִ�뷮�� �������մϴ�.

	//Operators
	Polynomial operator+(Polynomial target);	//���� �������Դϴ�.
	Polynomial operator*(Polynomial target);	//���� �������Դϴ�.

	//UserControl
	void makeNewPolynomial();		//���׽� Ŭ������ ���� �߰��մϴ�.
	void print();					//���׽��� ����մϴ�.
};

