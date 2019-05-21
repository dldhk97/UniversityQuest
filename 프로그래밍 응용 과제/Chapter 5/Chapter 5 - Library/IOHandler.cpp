//IOHandler.cpp
#include "IOHandler.h"

//Menu

int IOHandler::getMenu(int menuType)
{
	std::string title, option1, option2, option3, option4;
	switch (menuType)
	{
	case MAIN:
		title = "���� �޴�";
		option1 = "������ ����";
		option2 = "���� ����";
		option3 = "���� ����";
		option4 = "����";
		break;
	case USER:
		title = "������ ���� �޴�";
		option1 = "������ �߰�";
		option2 = "������ ����";
		option3 = "������ ���";
		option4 = "���� �޴�";
		break;
	case BOOK:
		title = "���� ���� �޴�";
		option1 = "���� �߰�";
		option2 = "���� ����";
		option3 = "���� ���";
		option4 = "���� �޴�";
		break;
	case LOAN:
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
		userInput = getInt("�Է� :");
		if (USER <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "[SYS]�߸��� �Է��Դϴ�." << '\n';
	}
}

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
//File I/O
bool IOHandler::readFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	std::ifstream file;
	std::string currentLine;
	file.open(fileDirectory);
	if (file.is_open())
	{
		std::cout << "[SYS]������ ������ ã�ҽ��ϴ�. �����͸� �ҷ��ɴϴ�.\n";
		std::getline(file, currentLine);
		//Read LastIDList
		while (1)
		{
			std::string listType, classStr, dataTypeName, lastId;
			file >> listType;

			if (listType == "[UserList]")
				break;

			file >> classStr >> dataTypeName >> lastId;
			dataTypeName = classStr + " " + dataTypeName;
			switch (std::stoi(listType))
			{
			case USER:
				userList.AddNewLastId(dataTypeName, std::stoi(lastId));
				break;
			case BOOK:
				bookList.AddNewLastId(dataTypeName, std::stoi(lastId));
				break;
			case LOAN:
				loanInfoList.AddNewLastId(dataTypeName, std::stoi(lastId));
				break;
			}
		}
		//Read User List
		while (1)
		{
			std::string dataType, id, name, department, userState;
			file >> dataType;

			if (dataType == "[BookList]")
				break;

			file >> id >> name >> department >> userState;
			if (std::stoi(dataType) == PROFESSOR)
			{
				std::string major, laboratory;
				file >> major >> laboratory;
				Professor* newProfessor = new Professor(id, name, department, std::stoi(userState), major, laboratory);
				userList.insertData(newProfessor);
			}
			else
			{
				std::string year, grade, contact;
				file >> year >> grade >> contact;
				Student* newStudent = new Student(id, name, department, std::stoi(userState), year, grade, contact);
				userList.insertData(newStudent);
			}
		}
		//Read Book List
		while (1)
		{
			std::string dataType, id, title, publisher, publicationDate, bookState;
			file >> dataType;

			if (dataType == "[LoanInfoList]")
				break;

			file >> id >> title >> publisher >> publicationDate >> bookState;
			if (std::stoi(dataType) == MAGAZINE)
			{
				std::string volume;
				file >> volume;
				Magazine* newMagazine = new Magazine(id, title, publisher, new Date(publicationDate), std::stoi(bookState), volume);
				bookList.insertData(newMagazine);
			}
			else
			{
				std::string detailedSubject;
				file >> detailedSubject;
				TextBook* newTextBook = new TextBook(id, title, publisher, new Date(publicationDate), std::stoi(bookState), detailedSubject);
				bookList.insertData(newTextBook);
			}
		}
		//Read LoanInfo List
		while (1)
		{
			std::string state, serial, loanerId, bookId, loanedDate;
			file >> state >> serial >> loanerId >> bookId >> loanedDate;
			LoanInfo* newLoanInfo;
			if (state == "")
				break;
			else if (state == "1")
			{
				std::string returnDate, period;
				file >> returnDate >> period;
				newLoanInfo = new LoanInfo(serial, loanerId, bookId, new Date(loanedDate), new Date(returnDate), std::stoi(period));
			}
			else
			{
				newLoanInfo = new LoanInfo(serial, loanerId, bookId, new Date(loanedDate), nullptr, NOT_FOUND);
			}
			loanInfoList.insertData(newLoanInfo);
		}

		file.close();
		return true;
	}
	std::cout << "[SYS]�����Ͱ� �������� �ʽ��ϴ�. �� ������ ������ �����մϴ�.\n";
	createEmptyFile(fileDirectory);
	return false;
}
void IOHandler::createEmptyFile(const std::string fileDirectory)
{
	std::ofstream newFile;
	newFile.open(fileDirectory);
	newFile.close();
}
bool IOHandler::writeFile(const std::string fileDirectory, List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList)
{
	std::ofstream file;
	file.open(fileDirectory);

	std::cout << "[SYS]������ ���Ͽ� �����͸� �����մϴ�.\n";

	//Last ID Write
	file << "[LastID]" << "\n";
	for (int i = 0; i < userList.getlastIdCnt(); i++)
		file << USER << " " << userList.getLastIdInfo(i).getFirst() << " " << userList.getLastIdInfo(i).getSecond() << "\n";
	for (int i = 0; i < bookList.getlastIdCnt(); i++)
		file << BOOK << " " << bookList.getLastIdInfo(i).getFirst() << " " << bookList.getLastIdInfo(i).getSecond() << "\n";
	for (int i = 0; i < loanInfoList.getlastIdCnt(); i++)
		file << LOAN << " " << loanInfoList.getLastIdInfo(i).getFirst() << " " << loanInfoList.getLastIdInfo(i).getSecond() << "\n";
	file << "\n";
	
	//UserList Write
	file << "[UserList]" << "\n";
	for (int i = 0; i < userList.getSize(); i++)
		file << userList.getData(i)->to_string() << "\n";
	file << "\n";
	//BookList Write
	file << "[BookList]" << "\n";
	for (int i = 0; i < bookList.getSize(); i++)
		file << bookList.getData(i)->to_string() << "\n";
	file << "\n";
	//LoanInfoList Write
	file << "[LoanInfoList]" << "\n";
	for (int i = 0; i < loanInfoList.getSize(); i++)
		file << loanInfoList.getData(i)->to_string() << "\n";

	return false;
}