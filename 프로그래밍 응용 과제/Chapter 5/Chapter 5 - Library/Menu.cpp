#include "Menu.h"

std::string Menu::getMenuTitle(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "���� �޴�";
	case USER:
		return "������ ���� �޴�";
	case BOOK:
		return "���� ���� �޴�";
	case LOAN:
		return "���� ���� �޴�";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption1(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "������ ����";
	case USER:
		return "������ �߰�";
	case BOOK:
		return "���� �߰�";
	case LOAN:
		return "���� ����";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption2(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "���� ����";
	case USER:
		return "������ ����";
	case BOOK:
		return "���� ����";
	case LOAN:
		return "���� �ݳ�";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption3(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "���� ����";
	case USER:
		return "������ ���";
	case BOOK:
		return "���� ���";
	case LOAN:
		return "����/�ݳ� ���� ���";
	default:
		return "ERROR";
	}
}
std::string Menu::getOption4(int menuType)
{
	switch (menuType)
	{
	case MAIN:
		return "����";
	case USER:
		return "���� �޴�";
	case BOOK:
		return "���� �޴�";
	case LOAN:
		return "���� �޴�";
	default:
		return "ERROR";
	}
}

int Menu::getMenu(int menuType)
{
	IOHandler ioh;
	
	int userInput;
	while (1)
	{
		std::cout << "====================================================" << '\n';
		std::cout << "<< " << getMenuTitle(menuType) << " >>" << '\n';
		std::cout << "1) " << getOption1(menuType) << '\n';
		std::cout << "2) " << getOption2(menuType) << '\n';
		std::cout << "3) " << getOption3(menuType) << '\n';
		std::cout << "4) " << getOption4(menuType) << "\n";
		std::cout << "====================================================" << '\n';
		userInput = ioh.getInt("�Է� :");
		if (USER <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "[SYS]�߸��� �Է��Դϴ�." << '\n';
	}
}