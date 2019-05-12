#include "Square.h"
#include "IOHandler.h"


Square::Square()
{
}

Square::Square(double width, double height)
{
	this->id = NOT_FOUND;
	this->posX = 0;
	this->posY = 0;
	this->width = width;
	this->height = height;
	this->area = width * height;
	this->perimeter = (width + height) * 2;
}

Square::Square(double width, double height, double posX, double posY)
{
	this->id = NOT_FOUND;
	this->posX = posX;
	this->posY = posY;
	this->width = width;
	this->height = height;
	this->area = width * height;
	this->perimeter = (width + height) * 2;
}


Square::~Square()
{
}

void Square::print()
{
	IOHandler ioh;
	ioh.printMessage("Ÿ�� : �簢��");
	ioh.printMessage("ID :" + std::to_string(id));
	ioh.printMessage("���� ���� :" + std::to_string(width));
	ioh.printMessage("���� ���� :" + std::to_string(height));
	ioh.printMessage("���� :" + std::to_string(area));
	ioh.printMessage("�ѷ� :" + std::to_string(perimeter));
	ioh.printMessage("������ 1 :(" + std::to_string(posX) + ", " + std::to_string(posY) + ")");
	ioh.printMessage("������ 2 :(" + std::to_string(posX) + ", " + std::to_string(posY + height) + ")");
	ioh.printMessage("������ 3 :(" + std::to_string(posX + width) + ", " + std::to_string(posY) + ")");
	ioh.printMessage("������ 4 :(" + std::to_string(posX + width) + ", " + std::to_string(posY + height) + ")");
}

std::string Square::to_string()
{
	return std::to_string(SQUARE) + ' ' + std::to_string(id) + ' ' + std::to_string(posX) + ' ' + std::to_string(posY) + ' ' + std::to_string(width) + ' ' + std::to_string(height);
}