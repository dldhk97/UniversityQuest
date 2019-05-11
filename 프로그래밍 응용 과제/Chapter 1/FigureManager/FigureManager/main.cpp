#include <iostream>
#include "Figures.h"

using namespace std;

const int maxSize = 10;		//�ִ�ũ��

void printMenu()
{
	std::cout << "====================================================\n";
	std::cout << "1).  ���� �߰�\n";
	std::cout << "2).  ���� ����\n";
	std::cout << "3).  ���� ���\n";
	std::cout << "4).  ����\n";
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
	std::cout << "���α׷��� �����մϴ�.\n";
}