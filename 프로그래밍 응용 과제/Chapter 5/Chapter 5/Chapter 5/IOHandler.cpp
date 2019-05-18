//IOHandler.cpp
#include "IOHandler.h"

//Menu

int IOHandler::getMenu(int menuType)
{
	std::string title, option1, option2, option3, option4;
	switch (menuType)
	{
	case MAINMENU:
		title = "���� �޴�";
		option1 = "������ ����";
		option2 = "���� ����";
		option3 = "���� ����";
		option4 = "����";
		break;
	case USERMENU:
		title = "������ ���� �޴�";
		option1 = "������ �߰�";
		option2 = "������ ����";
		option3 = "������ ���";
		option4 = "���� �޴�";
		break;
	case BOOKMENU:
		title = "���� ���� �޴�";
		option1 = "���� �߰�";
		option2 = "���� ����";
		option3 = "���� ���";
		option4 = "���� �޴�";
		break;
	case LOANMENU:
		title = "���� ���� �޴�";
		option1 = "���� ����";
		option2 = "���� �ݳ�";
		option3 = "����/�ݳ� ���� ���";
		option4 = "���� �޴�";
		break;
	}

	int userInput;
	while (1)
	{
		std::cout << "====================================================" << '\n';
		std::cout << "<< " << title << " >>" << '\n';
		std::cout << "1) " << option1 << '\n';
		std::cout << "2) " << option2 << '\n';
		std::cout << "3) " << option3 << '\n';
		std::cout << "4) " << option4 << "\n";
		std::cout << "====================================================" << '\n';
		std::cin >> userInput;

		if (USERMENU <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}

int IOHandler::getUserType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) �л� �߰�" << '\n';
		std::cout << "2) ���� �߰�" << '\n';
		std::cin >> userInput;
		userInput += 10;
		if (STUDENT <= userInput && userInput <= PROFESSOR)		//STUDENT = 11, PROFESSOR = 12
			return userInput;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}
int IOHandler::getBookType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) ����å �߰�" << '\n';
		std::cin >> userInput;
		userInput += 20;
		if (MAGAZINE <= userInput && userInput <= TEXTBOOK)		//MAGAZINE = 21, TEXTBOOK = 22
			return userInput;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}

Student* IOHandler::getStudent()
{
	std::string name, department, grade, contact;
	int year;
	std::cout << "���� :";
	std::cin >> name;
	std::cout << "�а� :";
	std::cin >> department;
	std::cout << "�г� :";
	std::cin >> year;
	std::cout << "���� :";
	std::cin >> grade;
	std::cout << "����ó :";
	std::cin >> contact;

	Student* newStudent = new Student("NOT_FOUND", name, department, VALID, year, grade, contact);
	return newStudent;
}

Professor* IOHandler::getProfessor()
{
	std::string name, department, major, laboratory;
	std::cout << "���� :";
	std::cin >> name;
	std::cout << "�а� :";
	std::cin >> department;
	std::cout << "���� :";
	std::cin >> major;
	std::cout << "������ :";
	std::cin >> laboratory;

	Professor* newProfessor = new Professor("NOT_FOUND", name, department, VALID, major, laboratory);
	return newProfessor;
}

int IOHandler::getInt(std::string message)
{
	int userInput;
	std::cout << message;
	std::cin >> userInput;
	return userInput;
}
std::string IOHandler::getString(std::string message)
{
	std::string userInput;
	std::cout << message;
	std::cin >> userInput;
	return userInput;
}

void IOHandler::displayMessage(std::string message)
{
	std::cout << message << '\n';
}
void IOHandler::displayUser(User* user)
{
	user->display();
}