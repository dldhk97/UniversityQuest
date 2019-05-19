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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10 ,'\n');
		}
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
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) �л� �߰�" << '\n';
		std::cin >> userInput;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
		userInput += 10;
		if (PROFESSOR <= userInput && userInput <= STUDENT)		//PROFESSOR = 11, STUDENT = 12
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
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(10, '\n');
		}
		userInput += 20;
		if (MAGAZINE <= userInput && userInput <= TEXTBOOK)		//MAGAZINE = 21, TEXTBOOK = 22
			return userInput;
		std::cout << "�߸��� �Է��Դϴ�." << '\n';
	}
}

Student* IOHandler::getStudent()
{
	std::string name, department, year, grade, contact;
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
Magazine* IOHandler::getMagazine()
{
	std::string title, publisher, publicationDate, volume;
	std::cout << "������ :";
	std::cin >> title;
	std::cout << "���ǻ� :";
	std::cin >> publisher;
	std::cout << "���ǳ⵵ :";
	std::cin >> publicationDate;
	std::cout << "��/ȣ :";
	std::cin >> volume;

	Magazine* newMagazine = new Magazine("NOT_FOUND", title, publisher, publicationDate, LOANABLE, volume);
	return newMagazine;
}
TextBook* IOHandler::getTextBook()
{
	std::string title, publisher, publicationDate, detailedSubject;
	std::cout << "������ :";
	std::cin >> title;
	std::cout << "���ǻ� :";
	std::cin >> publisher;
	std::cout << "���ǳ⵵ :";
	std::cin >> publicationDate;
	std::cout << "���� ���� :";
	std::cin >> detailedSubject;

	TextBook* newTextBook = new TextBook("NOT_FOUND", title, publisher, publicationDate, LOANABLE, detailedSubject);
	return newTextBook;
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
void IOHandler::displayMessageAsCell(std::string message, int maxLength)
{
	std::string newMessage;
	if (message.length() > maxLength)
	{
		int shrinkedLength = maxLength - 2;
		newMessage = message.substr(0, shrinkedLength) + "..";
	}
	else
	{
		newMessage = message;
		for (int i = message.length(); i <= maxLength; i++)
			newMessage += " ";
	}
	std::cout << newMessage << '\t';
}
void IOHandler::displayUser(User* user)
{
	user->display();
}
void IOHandler::displayBook(Book* book)
{
	book->display();
}
void IOHandler::displayLoanInfo(User* user, Book* book, LoanInfo* loanInfo)
{
	loanInfo->display(user, book);
}