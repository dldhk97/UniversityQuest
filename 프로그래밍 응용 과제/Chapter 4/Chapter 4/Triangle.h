#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

class Triangle : public Figure
{
private:
	double width, height;	//����, ���� ����
	double hypotenuse;		//���� ����
public:
	Triangle();
	Triangle(double width, double height);
	Triangle(double width, double height, int posX, int posY);
	~Triangle();

	virtual void print();
};

