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

bool IOHandler::loadFile(FigureList &figureList, std::string fileLocation)
{
	//figureList.setLastId(라스트아이디);	//해야된다.
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
	std::cout << "파일을 읽을 수 없습니다." << "\n";
	return false;
}
void IOHandler::saveFile(FigureList &figureList, std::string fileLocation)
{
	std::ofstream writeFile(fileLocation);
	if (writeFile.is_open())				//파일이 열려있다면
	{
		if (figureList.getSize() <= 0)			//list가 비어있다면 공백 저장
		{
			writeFile << "";
			std::cout << "빈 목록을 저장하였습니다." << "\n";
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
		std::cout << "도형 목록을 저장하였습니다." << "\n";
	}
	else
	{
		std::cout << "파일을 저장할 수 없습니다." << "\n";
	}
}