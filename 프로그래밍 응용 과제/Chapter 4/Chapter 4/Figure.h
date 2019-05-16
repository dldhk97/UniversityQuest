//Figure.h
#pragma once

#include <string>

enum FigureType { CIRCLE = 11, TRIANGLE, SQUARE };

class Figure
{
protected:
	int id;
	double posX, posY, area, perimeter;		//면적, 둘레
public:
	void setId(int id);

	int getId();
	double getPosX();
	double getPosY();
	double getArea();
	double getPerimeter();

	virtual void print();
	virtual std::string to_string();
};

