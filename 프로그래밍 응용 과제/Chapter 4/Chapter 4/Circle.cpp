#include "Circle.h"
#include "IOHandler.h"


Circle::Circle()
{
}

Circle::Circle(double radius, double posX, double posY)
{
	this->id = NOT_FOUND;
	this->posX = posX;
	this->posY = posY;
	this->radius = radius;
	this->area = radius * radius * PIE;
	this->perimeter = 2 * radius * PIE;
}

Circle::~Circle()
{
}

double Circle::getRadius()
{
	return radius;
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

std::string Circle::to_string()
{
	return std::to_string(CIRCLE) + ' ' + std::to_string(id) + ' ' + std::to_string(posX) + ' ' + std::to_string(posY) + ' ' + std::to_string(radius);
}