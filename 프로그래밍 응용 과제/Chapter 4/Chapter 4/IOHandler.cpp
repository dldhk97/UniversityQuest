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

bool IOHandler::loadFile(FigureList &figureList, std::string fileLocation)
{
	//figureList.setLastId(��Ʈ���̵�);	//�ؾߵȴ�.
	std::ifstream openFile(fileLocation);
	if (openFile.is_open())
	{
		std::string line;
		std::string tempArr[6];
		int saveIndex, previousIndex;

		/*while (getline(openFile, line))
		{
			saveIndex = 0;
			previousIndex = 0;
			for (int i = 0; i < line.length(); i++)
			{
				if (line[i] == ' ' || i == line.length() - 1)
				{
					if (i == line.length() - 1)
						i++;
					string tempStr = line.substr(previousIndex, i - previousIndex);
					tempArr[saveIndex++] = tempStr;
					previousIndex = i + 1;
				}
			}
			iList.insertComponent(Component(stoi(tempArr[0]), tempArr[1], tempArr[2], tempArr[3], tempArr[4], tempArr[5]));
		}*/
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
		if (figureList.getSize() <= 0)			//list�� ����ִٸ� ���� ����
		{
			writeFile << "";
			std::cout << "�� ����� �����Ͽ����ϴ�." << "\n";
			return;
		}
		for (int i = 0; i < figureList.getSize(); i++)
		{
			Figure *currentFigure = figureList.getFigure(i);
			if (typeid(*currentFigure).name() == typeid(Circle).name())
			{
				writeFile << typeid(*currentFigure).name() << currentFigure->getId() << " " 
					<< currentFigure->getPosX() << " " << currentFigure->getPosY() << " "
					//<< currentFigure->getRadius() << " " << currentFigure->getComponentName() << " "
					<< currentFigure->getArea() << " " << currentFigure->getPerimeter() << "\n";
			}
			else if (typeid(*currentFigure).name() == typeid(Triangle).name())
			{

			}
			else if (typeid(*currentFigure).name() == typeid(Square).name())
			{

			}
			
		}
		writeFile.close();
		std::cout << "���� ����� �����Ͽ����ϴ�." << "\n";
	}
	else
	{
		std::cout << "������ ������ �� �����ϴ�." << "\n";
	}
}