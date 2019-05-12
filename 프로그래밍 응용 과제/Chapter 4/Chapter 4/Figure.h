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
	double getArea();

	virtual void print();
};

