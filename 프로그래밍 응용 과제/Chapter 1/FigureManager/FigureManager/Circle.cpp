#include "Circle.h"

//Initializer

Circle::Circle()
{

}
Circle::~Circle()
{
}

//Getter,Setter

void Circle::setData()		//사용자에게 각 정보를 입력받는다.
{

	std::string inputID;
	int inputPosX;
	int inputPosY;
	double inputRadius;

	std::cout << "ID를 입력해주세요 : ";
	std::cin >> inputID;
	std::cout << "X좌표를 입력해주세요 : ";
	std::cin >> inputPosX;
	std::cout << "Y좌표를 입력해주세요 : ";
	std::cin >> inputPosY;
	std::cout << "반지름을 입력해주세요 : ";
	std::cin >> inputRadius;

	id = inputID;
	posX = inputPosX;
	posY = inputPosY;
	radius = inputRadius;
	area = getArea();
}
std::string Circle::getId()		//id반환
{
	return id;
}
double Circle::getArea()		//반지름*반지름*3.141592로 원의 면적반환
{
	return radius * radius * PIE;
}

//Methods

void Circle::print()
{
	std::cout << "ID : " << id << '\n';
	std::cout << "좌표(x,y) : (" << posX << "," << posY << ")" << '\n';
	std::cout << "반지름 : " << radius << '\n';
	std::cout << "면적 : " << area << '\n';
}

