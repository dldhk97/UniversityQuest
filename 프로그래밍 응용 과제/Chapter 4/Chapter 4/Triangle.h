//Triangle.h
#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

class Triangle : public Figure
{
private:
	double width, height;	//����, ���� ����
	double hypotenuse;		//���� ����
public:
	Triangle(double width, double height, double posX, double posY);

	virtual void print();
	virtual std::string to_string();
};

