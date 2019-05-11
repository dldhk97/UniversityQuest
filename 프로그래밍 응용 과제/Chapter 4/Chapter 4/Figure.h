#pragma once

#include <string>

class Figure
{
protected:
	int id, posX, posY;
	double area, perimeter;		//면적, 둘레
public:
	Figure();
	~Figure();

	void setId(int id);
	int getId();
	double getArea();

	virtual void print();
};

