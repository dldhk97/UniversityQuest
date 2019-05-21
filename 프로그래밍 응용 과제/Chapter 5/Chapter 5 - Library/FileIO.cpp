#include "FileIO.h"

//Read File
void FileIO::readLastIdList(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, std::ifstream& file)
{
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
}
void FileIO::readUserList(List<User>& userList, std::ifstream& file)
{
	while (1)
	{
		User* newUser;
		std::string dataType, id, name, department, userState;
		file >> dataType;

		if (dataType == "[BookList]")
			break;

		file >> id >> name >> department >> userState;
		if (std::stoi(dataType) == PROFESSOR)
		{
			std::string major, laboratory;
			file >> major >> laboratory;
			newUser = new Professor(id, name, department, std::stoi(userState), major, laboratory);
		}
		else
		{
			std::string year, grade, contact;
			file >> year >> grade >> contact;
			newUser = new Student(id, name, department, std::stoi(userState), year, grade, contact);
		}
		userList.insertData(newUser);
	}
}
void FileIO::readBookList(List<Book>& bookList, std::ifstream& file)
{
	while (1)
	{
		Book* newBook;
		std::string dataType, id, title, publisher, publicationDate, bookState;
		file >> dataType;

		if (dataType == "[LoanInfoList]")
			break;

		file >> id >> title >> publisher >> publicationDate >> bookState;
		if (std::stoi(dataType) == MAGAZINE)
		{
			std::string volume;
			file >> volume;
			newBook = new Magazine(id, title, publisher, new Date(publicationDate), std::stoi(bookState), volume);
		}
		else
		{
			std::string detailedSubject;
			file >> detailedSubject;
			newBook = new TextBook(id, title, publisher, new Date(publicationDate), std::stoi(bookState), detailedSubject);
		}
		bookList.insertData(newBook);
	}
}
void FileIO::readLoanInfoList(List<LoanInfo>& loanInfoList, std::ifstream& file)
{
	while (1)
	{
		LoanInfo* newLoanInfo;
		std::string state, serial, loanerId, bookId, loanedDate;
		file >> state;

		if (state == "")
			break;

		file >> serial >> loanerId >> bookId >> loanedDate;
		if (std::stoi(state) == NOT_FOUND)
		{
			newLoanInfo = new LoanInfo(serial, loanerId, bookId, new Date(loanedDate), nullptr, NOT_FOUND);
		}
		else
		{
			std::string returnDate, period;
			file >> returnDate >> period;
			newLoanInfo = new LoanInfo(serial, loanerId, bookId, new Date(loanedDate), new Date(returnDate), std::stoi(period));
		}
		loanInfoList.insertData(newLoanInfo);
	}
}
//Create File
void FileIO::createEmptyFile(const std::string fileDirectory)
{
	std::ofstream newFile;
	newFile.open(fileDirectory);
	newFile.close();
}
//Write File
void FileIO::writeLastIdList(List<User>& userList, List<Book>& bookList, List<LoanInfo>& loanInfoList, std::ofstream& file)
{
	file << "[LastID]" << "\n";
	for (int i = 0; i < userList.getlastIdCnt(); i++)
		file << USER << " " << userList.getLastIdInfo(i).getFirst() << " " << userList.getLastIdInfo(i).getSecond() << "\n";
	for (int i = 0; i < bookList.getlastIdCnt(); i++)
		file << BOOK << " " << bookList.getLastIdInfo(i).getFirst() << " " << bookList.getLastIdInfo(i).getSecond() << "\n";
	for (int i = 0; i < loanInfoList.getlastIdCnt(); i++)
		file << LOAN << " " << loanInfoList.getLastIdInfo(i).getFirst() << " " << loanInfoList.getLastIdInfo(i).getSecond() << "\n";
	file << "\n";
}