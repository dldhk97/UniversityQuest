//IOHandler.cpp
#include "IOHandler.h"

//Menu

int IOHandler::getMenu(int menuType)
{
	std::string title, option1, option2, option3, option4;
	switch (menuType)
	{
	case MAIN:
		title = "메인 메뉴";
		option1 = "구성원 관리";
		option2 = "도서 관리";
		option3 = "대출 관리";
		option4 = "종료";
		break;
	case USER:
		title = "구성원 관리 메뉴";
		option1 = "구성원 추가";
		option2 = "구성원 변경";
		option3 = "구성원 출력";
		option4 = "메인 메뉴";
		break;
	case BOOK:
		title = "도서 관리 메뉴";
		option1 = "도서 추가";
		option2 = "도서 변경";
		option3 = "도서 출력";
		option4 = "메인 메뉴";
		break;
	case LOAN:
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
		userInput = getInt("입력 :");
		if (USER <= userInput && userInput <= EXIT)
			return userInput;
		std::cout << "[SYS]잘못된 입력입니다." << '\n';
	}
}

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
		std::cout << "[SYS]데이터 파일을 찾았습니다. 데이터를 불러옵니다.\n";
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
	std::cout << "[SYS]데이터가 존재하지 않습니다. 새 데이터 파일을 생성합니다.\n";
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

	std::cout << "[SYS]데이터 파일에 데이터를 저장합니다.\n";

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