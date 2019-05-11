#include "IOHanlder.h"

int IOHanlder::getMenu()
{
	int userInput;
	while (1)
	{
		std::cout << "------------------" << '\n';
		std::cout << "1. 데이터 추가" << '\n';
		std::cout << "2. 데이터 삭제" << '\n';
		std::cout << "3. 데이터 출력" << '\n';
		std::cout << "4. 종료" << '\n';
		std::cout << "------------------" << '\n';
		
		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		std::cout << "잘못된 입력입니다." << '\n';
	}
}

Element IOHanlder::getElement()
{
	//나중에 자구과제로써 계산기로 사용할거면, 연산자면 char로 넣어야됨
	std::string userInput;
	std::cout << "수 혹은 연산자를 입력하세요." << '\n';
	std::cin >> userInput;
	Element newElement(userInput);
	return newElement;
}

int IOHanlder::getTourMenu()
{
	int userInput;
	while (1)
	{
		std::cout << "------------------" << '\n';
		std::cout << "1. 전위순회" << '\n';
		std::cout << "2. 중위순회" << '\n';
		std::cout << "3. 후위순회" << '\n';
		std::cout << "------------------" << '\n';

		std::cin >> userInput;
		userInput += 10;
		if (PREORDER <= userInput && userInput <= POSTORDER)
		{
			return userInput;
		}
		std::cout << "잘못된 입력입니다." << '\n';
	}
}

void IOHanlder::printMessage(std::string Message)
{
	std::cout << Message << '\n';
}

int IOHanlder::getInt(std::string message)
{
	int userInput;
	while(1)
	{
		std::cout << message << '\n';
		std::cin >> userInput;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else
		{
			break;
		}
	}
	return userInput;
}
std::string IOHanlder::getString(std::string message)
{
	std::string userInput;
	while (1)
	{
		std::cout << message << '\n';
		std::cin >> userInput;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore();
		}
		else
		{
			break;
		}
	}
	return userInput;
}