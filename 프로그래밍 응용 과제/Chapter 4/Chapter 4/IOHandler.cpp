#include "IOHandler.h"
#include <typeinfo>	//debug

int IOHandler::getMenu()
{
	int userInput;
	while (1)
	{
		std::cout << "====================================================" << '\n';
		std::cout << "1) 도형 추가" << '\n';
		std::cout << "2) 도형 삭제" << '\n';
		std::cout << "3) 도형 출력" << '\n';
		std::cout << "4) 종료" << "\n";
		std::cout << "====================================================" << '\n';
		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "잘못된 입력입니다." << '\n';
	}
}
int IOHandler::getInt(std::string message)
{
	int userInput;
	std::cout << message << "\n";
	std::cin >> userInput;
	return userInput;
}
std::string IOHandler::getString(std::string message)
{
	std::string userInput;
	std::cout << message << "\n";
	std::cin >> userInput;
	return userInput;
}
int IOHandler::getFigureType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) 원형 추가" << '\n';
		std::cout << "2) 삼각형 추가" << '\n';
		std::cout << "3) 사각형 추가" << '\n';
		std::cin >> userInput;
		if (CIRCLE - 10 <= userInput && userInput <= SQUARE - 10)
			return userInput + 10;
		std::cout << "잘못된 입력입니다." << '\n';
	}
}

Circle *IOHandler::getCircle()
{
	int posX, posY;
	double radius;
	std::cout << "중심 좌표 x 입력 :";
	std::cin >> posX;
	std::cout << "중심 좌표 y 입력 :";
	std::cin >> posY;
	std::cout << "반지름 입력 :";
	std::cin >> radius;

	Circle *newCircle = new Circle(radius, posX, posY);
	return newCircle;
}

Triangle *IOHandler::getTriangle()
{
	double width, height;
	std::cout << "가로 길이 입력 :";
	std::cin >> width;
	std::cout << "세로 길이 입력 :";
	std::cin >> height;

	Triangle *newTriangle = new Triangle(width, height);
	return newTriangle;
}
Square *IOHandler::getSquare()
{
	double width, height;
	std::cout << "가로 길이 입력 :";
	std::cin >> width;
	std::cout << "세로 길이 입력 :";
	std::cin >> height;

	Square *newSquare = new Square(width, height);
	return newSquare;
}

void IOHandler::printMessage(std::string message)
{
	std::cout << message << "\n";
}
void IOHandler::printFigure(Figure *figure)
{
	figure->print();
}

bool IOHandler::loadFile(FigureList &figureList)
{
	//figureList.setLastId(라스트아이디);	//해야된다.
	return false;
}
void IOHandler::saveFile(FigureList &figureList)
{

}