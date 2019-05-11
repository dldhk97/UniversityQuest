#include "Circle.h"

//Initializer

Circle::Circle()
{

}
Circle::~Circle()
{
}

//Getter,Setter

void Circle::setData()		//����ڿ��� �� ������ �Է¹޴´�.
{

	std::string inputID;
	int inputPosX;
	int inputPosY;
	double inputRadius;

	std::cout << "ID�� �Է����ּ��� : ";
	std::cin >> inputID;
	std::cout << "X��ǥ�� �Է����ּ��� : ";
	std::cin >> inputPosX;
	std::cout << "Y��ǥ�� �Է����ּ��� : ";
	std::cin >> inputPosY;
	std::cout << "�������� �Է����ּ��� : ";
	std::cin >> inputRadius;

	id = inputID;
	posX = inputPosX;
	posY = inputPosY;
	radius = inputRadius;
	area = getArea();
}
std::string Circle::getId()		//id��ȯ
{
	return id;
}
double Circle::getArea()		//������*������*3.141592�� ���� ������ȯ
{
	return radius * radius * PIE;
}

//Methods

void Circle::print()
{
	std::cout << "ID : " << id << '\n';
	std::cout << "��ǥ(x,y) : (" << posX << "," << posY << ")" << '\n';
	std::cout << "������ : " << radius << '\n';
	std::cout << "���� : " << area << '\n';
}

