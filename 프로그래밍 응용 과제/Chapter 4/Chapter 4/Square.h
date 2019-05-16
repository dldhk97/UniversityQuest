//Square.h
#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

class Square : public Figure
{
private:
	double width, height;	//가로, 세로 길이
public:
	Square(double width, double height, double posX, double posY);

	virtual void print();
	virtual std::string to_string();
};

