#include "IOHandler.h"
#include <typeinfo>	//debug

int IOHandler::getMenu()
{
	int userInput;
	while (1)
	{
		std::cout << "====================================================" << '\n';
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) ���� ����" << '\n';
		std::cout << "3) ���� ���" << '\n';
		std::cout << "4) ����" << "\n";
		std::cout << "====================================================" << '\n';
		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
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
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) �ﰢ�� �߰�" << '\n';
		std::cout << "3) �簢�� �߰�" << '\n';
		std::cin >> userInput;
		if (CIRCLE - 10 <= userInput && userInput <= SQUARE - 10)
			return userInput + 10;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}

Circle *IOHandler::getCircle()
{
	int posX, posY;
	double radius;
	std::cout << "�߽� ��ǥ x �Է� :";
	std::cin >> posX;
	std::cout << "�߽� ��ǥ y �Է� :";
	std::cin >> posY;
	std::cout << "������ �Է� :";
	std::cin >> radius;

	Circle *newCircle = new Circle(radius, posX, posY);
	return newCircle;
}

Triangle *IOHandler::getTriangle()
{
	double width, height;
	std::cout << "���� ���� �Է� :";
	std::cin >> width;
	std::cout << "���� ���� �Է� :";
	std::cin >> height;

	Triangle *newTriangle = new Triangle(width, height);
	return newTriangle;
}
Square *IOHandler::getSquare()
{
	double width, height;
	std::cout << "���� ���� �Է� :";
	std::cin >> width;
	std::cout << "���� ���� �Է� :";
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
	//figureList.setLastId(��Ʈ���̵�);	//�ؾߵȴ�.
	return false;
}
void IOHandler::saveFile(FigureList &figureList)
{

}