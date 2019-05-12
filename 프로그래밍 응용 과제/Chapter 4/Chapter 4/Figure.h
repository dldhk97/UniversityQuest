#pragma once

#include <string>

class Figure
{
protected:
	int id;
	double posX, posY, area, perimeter;		//����, �ѷ�
public:
	Figure();
	~Figure();

	void setId(int id);

	int getId();
	double getPosX();
	double getPosY();
	double getArea();
	double getPerimeter();

	virtual void print();
};

