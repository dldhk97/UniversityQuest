#include "Triangle.h"
#include "IOHandler.h"

Triangle::Triangle()
{
}
Triangle::Triangle(double width, double height)
{
	this->posX = 0;
	this->posY = 0;
	this->width = width;
	this->height = height;
	this->area = width * height / 2;
	this->hypotenuse = sqrt(width * width + height * height);
	this->perimeter = width + height + this->hypotenuse;
}
Triangle::Triangle(double width, double height, int posX, int posY)
{
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
	this->area = width * height / 2;
	this->hypotenuse = sqrt(width * width + height * height);
	this->perimeter = width + height + this->hypotenuse;
}


Triangle::~Triangle()
{
}

void Triangle::print()
{
	IOHandler ioh;
	ioh.printMessage("Ÿ�� : �ﰢ��");
	ioh.printMessage("ID :" + std::to_string(id));
	ioh.printMessage("���� ���� :" + std::to_string(width));
	ioh.printMessage("���� ���� :" + std::to_string(height));
	ioh.printMessage("���� :" + std::to_string(area));
	ioh.printMessage("�ѷ� :" + std::to_string(perimeter));
	ioh.printMessage("���� ���� :" + std::to_string(hypotenuse));
	ioh.printMessage("������ 1 :(" + std::to_string(posX) + ", " + std::to_string(posY) + ")");
	ioh.printMessage("������ 2 :(" + std::to_string(posX) + ", " + std::to_string(posY + (int)height) + ")");
	ioh.printMessage("������ 3 :(" + std::to_string(posX + (int)width) + ", " + std::to_string(posY) + ")");
}