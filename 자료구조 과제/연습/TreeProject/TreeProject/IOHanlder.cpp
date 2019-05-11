#include "IOHanlder.h"

int IOHanlder::getMenu()
{
	int userInput;
	while (1)
	{
		std::cout << "------------------" << '\n';
		std::cout << "1. ������ �߰�" << '\n';
		std::cout << "2. ������ ����" << '\n';
		std::cout << "3. ������ ���" << '\n';
		std::cout << "4. ����" << '\n';
		std::cout << "------------------" << '\n';
		
		std::cin >> userInput;
		if (INSERT <= userInput && userInput <= EXIT)
		{
			return userInput;
		}
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}

Element IOHanlder::getElement()
{
	//���߿� �ڱ������ν� ����� ����ҰŸ�, �����ڸ� char�� �־�ߵ�
	std::string userInput;
	std::cout << "�� Ȥ�� �����ڸ� �Է��ϼ���." << '\n';
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
		std::cout << "1. ������ȸ" << '\n';
		std::cout << "2. ������ȸ" << '\n';
		std::cout << "3. ������ȸ" << '\n';
		std::cout << "------------------" << '\n';

		std::cin >> userInput;
		userInput += 10;
		if (PREORDER <= userInput && userInput <= POSTORDER)
		{
			return userInput;
		}
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
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