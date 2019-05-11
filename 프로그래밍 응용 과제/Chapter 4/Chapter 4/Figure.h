#pragma once

#include <string>

class Figure
{
protected:
	int id, posX, posY;
	double area, perimeter;		//����, �ѷ�
public:
	Figure();
	~Figure();

	void setId(int id);
	int getId();
	double getArea();

	virtual void print();
};

