#include "Circle.h"
#include "IOHandler.h"


Circle::Circle()
{
}

Circle::Circle(double radius, int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->radius = radius;
	this->area = radius * radius * PIE;
	this->perimeter = 2 * radius * PIE;
}

Circle::~Circle()
{
}


void Circle::print()
{
	IOHandler ioh;
	ioh.printMessage("타입 : 원형");
	ioh.printMessage("ID :" + std::to_string(id));
	ioh.printMessage("중심좌표 :(" + std::to_string(posX) + ", " + std::to_string(posY) + ")");
	ioh.printMessage("반지름 :" + std::to_string(radius));
	ioh.printMessage("면적 :" + std::to_string(area));
	ioh.printMessage("둘레 :" + std::to_string(perimeter));
}