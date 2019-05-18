//IOHandler.cpp
#include "IOHandler.h"

//Menu

int IOHandler::getMenu(int menuType)
{
	std::string title, option1, option2, option3, option4;
	switch (menuType)
	{
	case MAINMENU:
		title = "메인 메뉴";
		option1 = "구성원 관리";
		option2 = "도서 관리";
		option3 = "대출 관리";
		option4 = "종료";
		break;
	case USERMENU:
		title = "구성원 관리 메뉴";
		option1 = "구성원 추가";
		option2 = "구성원 변경";
		option3 = "구성원 출력";
		option4 = "메인 메뉴";
		break;
	case BOOKMENU:
		title = "도서 관리 메뉴";
		option1 = "도서 추가";
		option2 = "도서 변경";
		option3 = "도서 출력";
		option4 = "메인 메뉴";
		break;
	case LOANMENU:
		title = "대출 관리 메뉴";
		option1 = "도서 대출";
		option2 = "도서 반납";
		option3 = "대출/반납 정보 출력";
		option4 = "메인 메뉴";
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
		std::cout << "잘못된 입력입니다." << '\n';
	}
}

int IOHandler::getUserType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) 학생 추가" << '\n';
		std::cout << "2) 교수 추가" << '\n';
		std::cin >> userInput;
		userInput += 10;
		if (STUDENT <= userInput && userInput <= PROFESSOR)		//STUDENT = 11, PROFESSOR = 12
			return userInput;
		std::cout << "잘못된 입력입니다." << '\n';
	}
}
int IOHandler::getBookType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) 잡지 추가" << '\n';
		std::cout << "2) 전공책 추가" << '\n';
		std::cin >> userInput;
		userInput += 20;
		if (MAGAZINE <= userInput && userInput <= TEXTBOOK)		//MAGAZINE = 21, TEXTBOOK = 22
			return userInput;
		std::cout << "잘못된 입력입니다." << '\n';
	}
}

Student* IOHandler::getStudent()
{
	std::string name, department, grade, contact;
	int year;
	std::cout << "성명 :";
	std::cin >> name;
	std::cout << "학과 :";
	std::cin >> department;
	std::cout << "학년 :";
	std::cin >> year;
	std::cout << "학점 :";
	std::cin >> grade;
	std::cout << "연락처 :";
	std::cin >> contact;

	Student* newStudent = new Student("NOT_FOUND", name, department, VALID, year, grade, contact);
	return newStudent;
}

Professor* IOHandler::getProfessor()
{
	std::string name, department, major, laboratory;
	std::cout << "성명 :";
	std::cin >> name;
	std::cout << "학과 :";
	std::cin >> department;
	std::cout << "전공 :";
	std::cin >> major;
	std::cout << "연구실 :";
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