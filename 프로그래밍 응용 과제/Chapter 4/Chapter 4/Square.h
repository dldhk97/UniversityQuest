#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

class Square : public Figure
{
private:
	double width, height;	//����, ���� ����
public:
	Square();
	Square(double width, double height);
	Square(double width, double height, double posX, double posY);
	~Square();

	virtual void print();
	virtual std::string to_string();
};

