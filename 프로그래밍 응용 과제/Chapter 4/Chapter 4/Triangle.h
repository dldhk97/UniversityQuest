//Triangle.h
#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

class Triangle : public Figure
{
private:
	double width, height;	//가로, 세로 길이
	double hypotenuse;		//빗변 길이
public:
	Triangle(double width, double height, double posX, double posY);

	virtual void print();
	virtual std::string to_string();
};

