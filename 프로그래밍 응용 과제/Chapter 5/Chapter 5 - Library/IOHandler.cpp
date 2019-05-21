//IOHandler.cpp
#include "IOHandler.h"

//Type Getter
int IOHandler::getUserType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) �л� �߰�" << '\n';
		userInput = getInt("�Է� :");
		userInput += 10;
		if (PROFESSOR <= userInput && userInput <= STUDENT)		//PROFESSOR = 11, STUDENT = 12
			return userInput;
		std::cout << "[SYS]�߸��� �Է��Դϴ�." << '\n';
	}
}
int IOHandler::getBookType()
{
	int userInput;
	while (1)
	{
		std::cout << "1) ���� �߰�" << '\n';
		std::cout << "2) ����å �߰�" << '\n';
		userInput = getInt("�Է� :");
		userInput += 20;
		if (MAGAZINE <= userInput && userInput <= TEXTBOOK)		//MAGAZINE = 21, TEXTBOOK = 22
			return userInput;
		std::cout << "[SYS]�߸��� �Է��Դϴ�." << '\n';
	}
}
//Class Getter
Student* IOHandler::getStudent()
{
	std::string name, department, year, grade, contact;

	name = getString("���� :");
	department = getString("�а� :");
	year = getString("�г� :");
	grade = getString("���� :");
	contact = getString("����ó :");

	return new Student("NOT_FOUND", name, department, VALID, year, grade, contact);
}
Professor* IOHandler::getProfessor()
{
	std::string name, department, major, laboratory;

	name = getString("���� :");
	department = getString("�а� :");
	major = getString("���� :");
	laboratory = getString("������ :");

	return new Professor("NOT_FOUND", name, department, VALID, major, laboratory);
}
Magazine* IOHandler::getMagazine()
{
	std::string title, publisher, volume;

	title = getString("������ :");
	publisher = getString("���ǻ� :");
	Date* publicationDate = getDate("���ǳ⵵ :");
	volume = getString("��/ȣ :");

	return new Magazine("NOT_FOUND", title, publisher, publicationDate, LOANABLE, volume);
}
TextBook* IOHandler::getTextBook()
{
	std::string title, publisher, detailedSubject;

	title = getString("������ :");
	publisher = getString("���ǻ� :");
	Date* publicationDate = getDate("���ǳ⵵ :");
	detailedSubject = getString("���� ���� :");

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
		std::cout << "[SYS]�߸��� �Է��Դϴ�." << '\n';
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
		std::cout << "[SYS]������ ������ ã�ҽ��ϴ�. �����͸� �ҷ��ɴϴ�.\n";
		std::getline(file, notUsingStr);											//ù��° ���� [LastID]�� ��� ó��, ������

		//Read Lists
		fileManager.readLastIdList(userList, bookList, loanInfoList, file);
		fileManager.readUserList(userList, file);
		fileManager.readBookList(bookList, file);
		fileManager.readLoanInfoList(loanInfoList, file);

		file.close();
		return true;
	}
	std::cout << "[SYS]�����Ͱ� �������� �ʽ��ϴ�. �� ������ ������ �����մϴ�.\n";
	fileManager.createEmptyFile(fileDirectory);
	return false;
}
bool IOHandler::writeFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	FileIO fileManager;
	std::ofstream file;
	file.open(fileDirectory);

	std::cout << "[SYS]������ ���Ͽ� �����͸� �����մϴ�.\n";

	//Write Lists
	fileManager.writeLastIdList(userList, bookList, loanInfoList, file);
	fileManager.writeDataList<User>(userList, file);
	fileManager.writeDataList<Book>(bookList, file);
	fileManager.writeDataList<LoanInfo>(loanInfoList, file);
	
	return false;
}