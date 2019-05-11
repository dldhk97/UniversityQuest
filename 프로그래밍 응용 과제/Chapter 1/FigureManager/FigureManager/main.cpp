#include <iostream>
#include "Figures.h"

using namespace std;

const int maxSize = 10;		//최대크기

void printMenu()
{
	std::cout << "====================================================\n";
	std::cout << "1).  도형 추가\n";
	std::cout << "2).  도형 삭제\n";
	std::cout << "3).  도형 출력\n";
	std::cout << "4).  종료\n";
	std::cout << "====================================================\n";
}

int main()
{
	Figures newFigures(maxSize);
	int consoleInput = -1;
	while (consoleInput != 4)
	{
		printMenu();
		cin >> consoleInput;

		switch (consoleInput)
		{
		case 1:
			newFigures.addFigure();
			break;
		case 2:
			newFigures.removeFigure();
			break;
		case 3:
			newFigures.printAll();
			break;
		}
	}
	std::cout << "프로그램을 종료합니다.\n";
}