//IOHandler.cpp
#include "IOHandler.h"

//Type Getter
int IOHandler::getUserType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) 교수 추가" << '\n';
		std::cout << "2) 학생 추가" << '\n';
		userInput = getInt("입력 :");
		userInput += 10;
		if (PROFESSOR <= userInput && userInput <= STUDENT)		//PROFESSOR = 11, STUDENT = 12
			return userInput;
		std::cout << "[SYS]잘못된 입력입니다." << '\n';
	}
}
int IOHandler::getBookType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) 잡지 추가" << '\n';
		std::cout << "2) 전공책 추가" << '\n';
		userInput = getInt("입력 :");
		userInput += 20;
		if (MAGAZINE <= userInput && userInput <= TEXTBOOK)		//MAGAZINE = 21, TEXTBOOK = 22
			return userInput;
		std::cout << "[SYS]잘못된 입력입니다." << '\n';
	}
}
//Class Getter
Student* IOHandler::getStudent()
{
	std::string name, department, year, grade, contact;

	name = getString("성명 :");
	department = getString("학과 :");
	year = getString("학년 :");
	grade = getString("학점 :");
	contact = getString("연락처 :");

	return new Student("NOT_FOUND", name, department, VALID, year, grade, contact);
}
Professor* IOHandler::getProfessor()
{
	std::string name, department, major, laboratory;

	name = getString("성명 :");
	department = getString("학과 :");
	major = getString("전공 :");
	laboratory = getString("연구실 :");

	return new Professor("NOT_FOUND", name, department, VALID, major, laboratory);
}
Magazine* IOHandler::getMagazine()
{
	std::string title, publisher, volume;

	title = getString("도서명 :");
	publisher = getString("출판사 :");
	Date* publicationDate = getDate("출판년도 :");
	volume = getString("권/호 :");

	return new Magazine("NOT_FOUND", title, publisher, publicationDate, LOANABLE, volume);
}
TextBook* IOHandler::getTextBook()
{
	std::string title, publisher, detailedSubject;

	title = getString("도서명 :");
	publisher = getString("출판사 :");
	Date* publicationDate = getDate("출판년도 :");
	detailedSubject = getString("세부 주제 :");

	return new TextBook("NOT_FOUND", title, publisher, publicationDate, LOANABLE, detailedSubject);
}
//Getter
int IOHandler::getInt(std::string message)
{
	int userInput;
	std::cout << message;
	std::cin >> userInput;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(10, '\n');
	}
	return userInput;
}
std::string IOHandler::getString(std::string message)
{
	std::string userInput;
	std::cout << message;
	std::cin >> userInput;
	return userInput;
}
Date* IOHandler::getDate(std::string message)
{
	std::string userInput;
	std::cout << message;
	while (1)
	{
		std::cin >> userInput;

		if (8 <= userInput.length() && userInput.length() <= 11)
			return new Date(userInput);
		std::cout << "[SYS]잘못된 입력입니다." << '\n';
	}
}
//Display
void IOHandler::displayMessage(std::string message)
{
	std::cout << message << '\n';
}
void IOHandler::displayShortMessage(std::string message, int maxLength)
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
		for (int i = (int)message.length(); i <= maxLength; i++)
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
//File I/O
bool IOHandler::readFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	FileIO fileManager;
	std::ifstream file;
	file.open(fileDirectory);
	if (file.is_open())
	{
		std::string notUsingStr;
		std::cout << "[SYS]데이터 파일을 찾았습니다. 데이터를 불러옵니다.\n";
		std::getline(file, notUsingStr);											//첫번째 줄의 [LastID]는 헤더 처리, 무시함

		//Read Lists
		fileManager.readLastIdList(userList, bookList, loanInfoList, file);
		fileManager.readUserList(userList, file);
		fileManager.readBookList(bookList, file);
		fileManager.readLoanInfoList(loanInfoList, file);

		file.close();
		return true;
	}
	std::cout << "[SYS]데이터가 존재하지 않습니다. 새 데이터 파일을 생성합니다.\n";
	fileManager.createEmptyFile(fileDirectory);
	return false;
}
bool IOHandler::writeFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	FileIO fileManager;
	std::ofstream file;
	file.open(fileDirectory);

	std::cout << "[SYS]데이터 파일에 데이터를 저장합니다.\n";

	//Write Lists
	fileManager.writeLastIdList(userList, bookList, loanInfoList, file);
	fileManager.writeDataList<User>(userList, file);
	fileManager.writeDataList<Book>(bookList, file);
	fileManager.writeDataList<LoanInfo>(loanInfoList, file);
	
	return false;
}