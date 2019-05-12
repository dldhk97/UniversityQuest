#pragma once

#include "Figure.h"

class IOHandler;	//predeclaration

const double PIE = 3.14159265359;

class Circle : public Figure
{
private:
	double radius;
public:
	Circle();
	Circle(double radius, double posX, double posY);
	~Circle();

	double getRadius();

	virtual void print();
	virtual std::string to_string();
};

