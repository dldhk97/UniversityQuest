#include "IOHandler.h"

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
	double posX, posY;
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

bool IOHandler::loadFile(FigureList &figureList, std::string fileLocation)
{
	std::ifstream openFile(fileLocation);
	if (openFile.is_open())
	{
		int lastId;
		openFile >> lastId;
		figureList.setLastId(lastId);		//������ ID ����

		int figureType, id;
		double posX, posY, width, height;
		while (!openFile.eof())
		{
			openFile >> figureType;			//���� Ÿ�� �˾Ƴ���
			switch (figureType)
			{
				case CIRCLE:
				{
					openFile >> id >> posX >> posY >> width;
					Circle *newCircle = new Circle(width, posX, posY);
					newCircle->setId(id);
					figureList.insertFigure(newCircle);
					break;
				}
				case TRIANGLE:
				{
					openFile >> id >> posX >> posY >> width >> height;
					Triangle *newTriangle = new Triangle(width, height, posX, posY);
					newTriangle->setId(id);
					figureList.insertFigure(newTriangle);
					break;
				}
				case SQUARE:
				{
					openFile >> id >> posX >> posY >> width >> height;
					Square *newSquare = new Square(width, height, posX, posY);
					newSquare->setId(id);
					figureList.insertFigure(newSquare);
					break;
				}
			}
			figureType = -1;
		}
		openFile.close();
		return true;
	}
	std::cout << "������ ���� �� �����ϴ�." << "\n";
	return false;
}
void IOHandler::saveFile(FigureList &figureList, std::string fileLocation)
{
	std::ofstream writeFile(fileLocation);
	if (writeFile.is_open())				//������ �����ִٸ�
	{
		writeFile << figureList.getLastId() << "\n";			//������ id ����
		if (figureList.getSize() <= 0)
		{
			std::cout << "�� ����� �����Ͽ����ϴ�." << "\n";
			return;
		}
		for (int i = 0; i < figureList.getSize(); i++)
		{
			Figure *currentFigure = figureList.getFigure(i);
			writeFile << currentFigure->to_string() << "\n";
		}
		writeFile.close();
		std::cout << "���� ����� �����Ͽ����ϴ�." << "\n";
	}
	else
	{
		std::cout << "������ ������ �� �����ϴ�." << "\n";
	}
}