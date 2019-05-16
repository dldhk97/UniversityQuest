//Figure.cpp
#include "Figure.h"

void Figure::setId(int id)
{
	this->id = id;
}

int Figure::getId()
{
	return id;
}
double Figure::getPosX()
{
	return posX;
}
double Figure::getPosY()
{
	return posY;
}
double Figure::getArea()
{
	return area;
}
double Figure::getPerimeter()
{
	return perimeter;
}

void Figure::print()
{

}
std::string Figure::to_string()
{
	return "";
}