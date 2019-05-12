#include "IOHandler.h"

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
	double posX, posY;
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

bool IOHandler::loadFile(FigureList &figureList, std::string fileLocation)
{
	std::ifstream openFile(fileLocation);
	if (openFile.is_open())
	{
		int lastId;
		openFile >> lastId;
		figureList.setLastId(lastId);		//마지막 ID 갱신

		int figureType, id;
		double posX, posY, width, height;
		while (!openFile.eof())
		{
			openFile >> figureType;			//도형 타입 알아내기
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
	std::cout << "파일을 읽을 수 없습니다." << "\n";
	return false;
}
void IOHandler::saveFile(FigureList &figureList, std::string fileLocation)
{
	std::ofstream writeFile(fileLocation);
	if (writeFile.is_open())				//파일이 열려있다면
	{
		writeFile << figureList.getLastId() << "\n";			//마지막 id 저장
		if (figureList.getSize() <= 0)
		{
			std::cout << "빈 목록을 저장하였습니다." << "\n";
			return;
		}
		for (int i = 0; i < figureList.getSize(); i++)
		{
			Figure *currentFigure = figureList.getFigure(i);
			writeFile << currentFigure->to_string() << "\n";
		}
		writeFile.close();
		std::cout << "도형 목록을 저장하였습니다." << "\n";
	}
	else
	{
		std::cout << "파일을 저장할 수 없습니다." << "\n";
	}
}